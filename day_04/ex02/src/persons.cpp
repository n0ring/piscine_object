#include "persons.hpp"

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
	while (!_formToValidate.empty())
	{
		auto form = _formToValidate.top();
		if (validateForm(form))
		{
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