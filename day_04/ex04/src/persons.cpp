#include "persons.hpp"

std::string Person::getName() {return (_name);}


Headmaster::Headmaster()
{
	_secretary = std::make_shared<Secretary>();
}


Person& Person::operator=(const Person& p_person)
{
	_name = p_person._name;
	_currentRoom = p_person._currentRoom;
	return (*this);
}
Person::Person(const Person& p_person)
{
	_name = p_person._name;
	_currentRoom = p_person._currentRoom;
}

Student& Student::operator=(const Student& p_student)
{
	_subscribedCourse = p_student._subscribedCourse;
	return (*this);
}
Student::Student(const Student& p_student)
{
	_subscribedCourse = p_student._subscribedCourse;
}


void Headmaster::formProcessing()
{
	std::stack<std::shared_ptr<Form> > invalidForms;
	std::cout << "Processing forms: " << _formToValidate.size() << std::endl;
	while (!_formToValidate.empty())
	{
		auto form = _formToValidate.top();
		std::cout << "Processing form: " << form->getTextForm() << std::endl;
		if (validateForm(form))
		{
			std::cout << "Form" << form->getTextForm() << " is valid" << std::endl;
			sign(form);
			executeForm(form);
		}
		else
		{
			std::cout << "Form" << form->getTextForm() << " is invalid" << std::endl;
			invalidForms.push(form);
		}
		_formToValidate.pop();
	}
	while (!invalidForms.empty())
	{
		_formToValidate.push(invalidForms.top());
		invalidForms.pop();
	}
}

bool Headmaster::executeForm(std::shared_ptr<Form> p_form)
{
	if (p_form->isSighed())
	{
		p_form->execute();
		return true;
	}
	return false;
}

std::shared_ptr<Form> Secretary::createForm(FormType p_formType)
{
	std::shared_ptr<Form> form = nullptr;
	switch (p_formType)
	{
		case FormType::CourseFinished:
			form = std::make_shared<CourseFinishedForm>(FormType::CourseFinished);
			break;
		case FormType::NeedMoreClassRoom:
			form = std::make_shared<NeedMoreClassRoomForm>(FormType::NeedMoreClassRoom);
			break;
		case FormType::NeedCourseCreation:
			form = std::make_shared<NeedCourseCreationForm>(FormType::NeedCourseCreation);
			break;
		case FormType::SubscriptionToCourse:
			form = std::make_shared<SubscriptionToCourseForm>(FormType::SubscriptionToCourse);
			break;
		default:
			break;
	}
	return form;
}

void  Headmaster::graduateStudent(Professor* p_professor, std::shared_ptr<Student> p_student, std::shared_ptr<Course> p_course)
{
	std::shared_ptr<Form> form = _secretary->createForm(FormType::CourseFinished);
	p_professor->fillForm(form);
	if (validateForm(form))
	{
		if (p_student->getNumberOfClassAttended(p_course) >= p_course->getNumberOfClassToGraduate())
		{
			sign(form);
			executeForm(form);
			p_student->graduate(p_course);
		}
		else
		{
			std::cout << "Student: " << p_student->getName() << " not graduated from course: " << p_course->getName() << std::endl;
		}
	}
	else 
	{
		std::cout << "validate graduateStudent form fail\n";
	}
}

std::shared_ptr<Course> Headmaster::createCourse(Professor* p_professor)
{
	std::shared_ptr<NeedCourseCreationForm> form = std::dynamic_pointer_cast<NeedCourseCreationForm>(_secretary->createForm(FormType::NeedCourseCreation));
	
	p_professor->fillForm(form);
	if (validateForm(form))
	{
		sign(form);
		std::shared_ptr<Course> newCourse = std::make_shared<Course>(form->getTextForm());
		newCourse->assign(p_professor);
		newCourse->setMaxNumberOfStudents(form->getMaximumNumberOfStudent());
		newCourse->setNumberOfClasToGraduate(form->getNumberOfClassToGraduate());
		p_professor->assignCourse(newCourse);
		executeForm(form);
		return newCourse;
	}
	return nullptr;
}

bool Headmaster::subscribeStudentToCourse(Student* p_student, std::shared_ptr<Course> p_course)
{
	std::shared_ptr<Form> form = _secretary->createForm(FormType::SubscriptionToCourse);
	p_student->fillForm(form);
	if (validateForm(form))
	{
		sign(form);
		if (p_course->subscribe(p_student))
		{
			executeForm(form);
			p_student->subscribe(p_course.get());
			return true;
		}
	}
	std::cout << "validate subscribeStudentToCourse form fail\n";
	return false;
}



Professor& Professor::operator=(const Professor& p_professor)
{
	if (this == &p_professor)
		return (*this);
	_currentCourse = p_professor._currentCourse;
	_headmaster = p_professor._headmaster;
	_studentsToGraduate = p_professor._studentsToGraduate;
	return (*this);
}
Professor::Professor(const Professor& p_professor)
{
	_currentCourse = p_professor._currentCourse;
	_headmaster = p_professor._headmaster;
	_studentsToGraduate = p_professor._studentsToGraduate;

}

void Professor::fillForm(std::shared_ptr<Form> p_form)
{
	std::shared_ptr<NeedCourseCreationForm> formPtr = nullptr;

	std::string p_text;
	std::cout << "Professor: " << getName() << " fill form" << std::endl;

	switch (p_form->getFormType())
	{
	case FormType::CourseFinished:
		p_text = "<" + _studentsToGraduate.top().first->getName() + "> has finished the course <<" + _studentsToGraduate.top().second->getName() + ">>";
		_studentsToGraduate.pop();
		break;
	case FormType::NeedCourseCreation:
		p_text = _courseToCreate.top().name;
		formPtr = std::dynamic_pointer_cast<NeedCourseCreationForm>(p_form);
		formPtr->setMaxNumberOfStudents(_courseToCreate.top().nmaximumNumberOfStudent);
		formPtr->setNumberOfClasToGraduate(_courseToCreate.top().numberOfClassToGraduate);
		_courseToCreate.pop();
		break;
	case FormType::NeedMoreClassRoom:
		p_text = _roomName;
		break;
	default:
		assert(false);
		break;
	}
	std::cout << "Form filled by Professor: " << p_text << std::endl;
	p_form->fillForm(p_text);
}

bool Professor::gradeStudent(std::shared_ptr<Student> p_student, std::shared_ptr<Course> p_course)
{
	if (!_headmaster)
	{
		std::cout << "No headmaster assigned" << std::endl;
		return false;
	}
	_studentsToGraduate.push({p_student, p_course});
	_headmaster->graduateStudent(this, p_student, p_course);

	return true;
}

void Professor::teach()
{
	if (_currentCourse)
	{
		std::cout << "Professor: " << getName() << " is teaching course: " << _currentCourse->getName() << std::endl;
		_currentCourse->teachStudent();
	}
	else 
	{
		std::cout << "Professor: " << getName() << " has no course to teach" << std::endl;
	}

}

std::shared_ptr<Course> Professor::createCourse(std::string courseName, int numberOfClass,int maxStudent)
{
	courseInfo info;

	info.name = courseName;
	info.numberOfClassToGraduate = numberOfClass;
	info.nmaximumNumberOfStudent = maxStudent;
	std::shared_ptr<Course> newCourse;

	_courseToCreate.push(info);
	newCourse = _headmaster->createCourse(this);

	return newCourse;
}
std::shared_ptr<Classroom> Headmaster::createClassRoom(Professor* p_professor)
{
	std::shared_ptr<Form> form = _secretary->createForm(FormType::NeedMoreClassRoom);
	p_professor->fillForm(form);
	if (validateForm(form))
	{
		sign(form);
		executeForm(form);
		return std::make_shared<Classroom>(form->getTextForm());
	}
	return nullptr;
}

std::shared_ptr<Classroom> Professor::createClassRoom(std::string roomName)
{
	_roomName = roomName;
	return _headmaster->createClassRoom(this);
}

bool Headmaster::assignClassroomToCourse(std::shared_ptr<Course> p_course, std::shared_ptr<Classroom> p_classroom)
{
	if (p_course->assignToClassRoom(p_classroom))
	{
		p_classroom->assignCourse(p_course);
		return true;
	}
	return false;
}

bool Professor::setClassRoom(std::shared_ptr<Course> p_course, std::shared_ptr<Classroom> p_classroom)
{
	return _headmaster->assignClassroomToCourse(p_course, p_classroom);
}

void Student::fillForm(std::shared_ptr<Form> p_form)
{
	std::string p_text;
	std::cout << "Student: " << getName() << " fill form" << std::endl;

	switch (p_form->getFormType())
	{
	case FormType::SubscriptionToCourse:
		p_text = _coursesToSubscribe.top()->getName();
		_coursesToSubscribe.pop();
		break;
	default:
		assert(false);
		break;
	}
	std::cout << "Form filled by Student: " << p_text << std::endl;
	p_form->fillForm(p_text);
}

void Student::subscribeToCourse(std::shared_ptr<Course> p_course)
{
	_coursesToSubscribe.push(p_course);
	_headmaster->subscribeStudentToCourse(this, p_course);
	// call head master to subscribe
}

void Student::subscribe(Course* p_course)
{
	_subscribedCourse[p_course] = 0;
	std::cout << "Student: " << getName() << " subscribed to course: " << p_course->getName() << std::endl;
}

void Student::graduate(std::shared_ptr<Course> p_course)
{
	_graduatedCourses.push_back(p_course);
}

bool  Student::attendCourse(Course* p_course)
{
	if (_subscribedCourse.count(p_course))
	{
		_subscribedCourse[p_course]++;
		std::cout << "Student: " << getName() << " attend course: " << p_course->getName() << std::endl;
		return true;
	}
	std::cout << "Student: " << getName() << " not subscribed to course: " << p_course->getName() << std::endl;
	return false;
}

int Student::getNumberOfClassAttended(std::shared_ptr<Course> p_course)
{
	if (_subscribedCourse.count(p_course.get()))
	{
		return _subscribedCourse[p_course.get()];
	}
	return 0;
}
