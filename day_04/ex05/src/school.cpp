#include "School.hpp"

const std::vector<std::string> hogwartsProfessors = {
        "Remus Lupin",
        "Minerva McGonagall",
        "Severus Snape",
        "Pomona Sprout",
        "Filius Flitwick",
        "Horace Slughorn",
        "Gilderoy Lockhart",
        "Mad-Eye Moody (Barty Crouch Jr.)",
        "Dolores Umbridge",
        "Sybill Trelawney",
        "Rubeus Hagrid",
        "Quirinus Quirrell",
        "Bathilda Bagshot",
        "Aurora Sinistra",
        "Charity Burbage",
        "Cuthbert Binns",
        "Rolanda Hooch"
    };
const  std::vector<std::string> hogwartsStudents = {
        "Harry Potter",
        "Hermione Granger",
        "Ron Weasley",
        "Draco Malfoy",
        "Neville Longbottom",
        "Luna Lovegood",
        "Ginny Weasley",
        "Fred Weasley",
        "George Weasley",
        "Cedric Diggory",
        "Cho Chang",
        "Seamus Finnigan",
        "Dean Thomas",
        "Lavender Brown",
        "Parvati Patil",
        "Padma Patil",
        "Pansy Parkinson",
        "Blaise Zabini",
        "Susan Bones",
        "Hannah Abbott"
    };
const std::vector<std::string> hogwartsCourses = {
        "Defense Against the Dark Arts",
        "Transfiguration",
        "Potions",
        "Herbology",
        "Charms"
    };

void paintLogo();

School::School()
{
	int courseIdx = 0;
	m_headmaster = std::make_shared<Headmaster>("Albus Dumbledore");
	while (m_professors.size() < k_maxNumberOfProfessors)
		recruteProfessor();
	while (m_students.size() < k_maxNumberOfStudents)
		recruteStudent();

	for (auto& professor : m_professors)
	{
		m_courses.push_back(professor->createCourse(hogwartsCourses[courseIdx++], k_numberOfClassForGraduation, k_maxNumberOfStudentsOnCourse));
		m_classrooms.push_back(professor->createClassRoom("Classroom"));
		professor->setClassRoom(m_courses.back(), m_classrooms.back());
	}

	for (auto& student : m_students)
	{
		for (auto& course : m_courses)
			student->subscribeToCourse(course);
	}
	for (auto& student : m_students)
		m_headmaster->attach(student.get());
	for (auto& professor : m_professors)
		m_headmaster->attach(professor.get());
	paintLogo();
}


void School::recruteProfessor()
{
	if (m_professorIdx == hogwartsProfessors.size())
		m_professorIdx = 0;
	std::shared_ptr<Professor> professor = std::make_shared<Professor>(hogwartsProfessors[m_professorIdx++], m_headmaster);
	m_professors.push_back(professor);
}

void School::recruteStudent()
{
	if (m_studentIdx == hogwartsStudents.size())
		m_studentIdx = 0;
	std::shared_ptr<Student> student = std::make_shared<Student>(hogwartsStudents[m_studentIdx++], m_headmaster.get());
	m_students.push_back(student);
}

std::shared_ptr<Secretary> School::getSecretary()
{
	return m_headmaster->getSecretary();
}

std::shared_ptr<Course> School::getCourse(std::string p_name)
{
	return std::make_shared<Course>(p_name);
}

void School::requestRingBell()
{
	m_headmaster->notify(Event::RingBell);
}


void School::launchClasses()
{
	if (m_currentTime != DayTime::CLASSES)
	{
		m_currentTime = DayTime::CLASSES;
		std::cout << YELLOW << "Classes are starting\n" << BLACK;
		requestRingBell(); // to all go to class
		m_headmaster->notify(Event::StartClass);
	}
	else 
	{
		std::cout << RED << "Classes are already started\n" << BLACK;
	}
}

void School::doRecreation()
{
	switch (m_currentTime)
	{
	case DayTime::CLASSES:
		std::cout << GREEN << "Recreation time\n" << BLACK;
		requestRingBell();
		m_currentTime = DayTime::RECREATION;
		break;
	case DayTime::LUNCH:
		std::cout << GREEN << "Recreation time\n" << BLACK;
		m_currentTime = DayTime::RECREATION;
		break;
	case DayTime::RECREATION:
		std::cout << RED << "Recreation is already started\n" << BLACK;
		break;
	case DayTime::NONE:
		std::cout << RED << "Classes are not started yet\n" << BLACK;
		break;
	default:
		break;
	}
}

void School::launchLunch()
{
	switch (m_currentTime)
	{
	case DayTime::CLASSES:
		std::cout << GREEN << "Lunch time\n" << BLACK;
		m_currentTime = DayTime::LUNCH;
		requestRingBell();
		break;
	case DayTime::LUNCH:
		std::cout << RED << "Lunch is already started\n" << BLACK;
		break;
	case DayTime::RECREATION:
		std::cout << GREEN << "Lunch time\n" << BLACK;
		m_currentTime = DayTime::LUNCH;
		break;
	case DayTime::NONE:
		std::cout << RED << "Classes are not started yet\n" << BLACK;
		break;
	default:
		break;
	}
}








void School::runDayRoutine()
{
	launchClasses(); // 1. launch classes
	doRecreation(); // 2. allow student and professor to go on recreation 
	launchClasses(); // 3. launch classes
	launchLunch(); // 4. launch lunch
	launchClasses(); // 5. launch classes
	doRecreation(); // 6. allow student and professor to go on recreation 
	launchClasses(); // 7. launch classes
	doRecreation();
}


void paintLogo()
{
	std::cout << "           ^              ^" << std::endl;
	std::cout << "           ^              ^" << std::endl;
    std::cout << "          / \\            / \\" << std::endl;
    std::cout << "          / \\            / \\" << std::endl;
    std::cout << "         /   \\          /   \\" << std::endl;
    std::cout << "         /   \\          /   \\" << std::endl;
    std::cout << "        /     \\        /     \\" << std::endl;
    std::cout << "        /     \\        /     \\" << std::endl;
    std::cout << "       /_______\\      /_______\\" << std::endl;
    std::cout << "       /_______\\      /_______\\" << std::endl;
    std::cout << "      /|       |\\    /|       |\\" << std::endl;
    std::cout << "      /|       |\\    /|       |\\" << std::endl;
    std::cout << "     / |       | \\  / |       | \\" << std::endl;
    std::cout << "     / |       | \\  / |       | \\" << std::endl;
    std::cout << "    /  |       |  \\/  |       |  \\" << std::endl;
    std::cout << "    /  |       |  \\/  |       |  \\" << std::endl;
    std::cout << "   /___|_______|___\\/___|_______|___\\" << std::endl;
    std::cout << "   /___|_______|___\\/___|_______|___\\" << std::endl;
    std::cout << "   |               ||               |" << std::endl;
    std::cout << "   |               ||               |" << std::endl;
    std::cout << "   |      ____     ||     ____      |" << std::endl;
    std::cout << "   |      ____     ||     ____      |" << std::endl;
    std::cout << "   |     |    |    ||    |    |     |" << std::endl;
    std::cout << "   |     |    |    ||    |    |     |" << std::endl;
    std::cout << "   |_____|____|____||____|____|_____|" << std::endl;
    std::cout << "   |_____|____|____||____|____|_____|" << std::endl;
    std::cout << "   |                 ||               |" << std::endl;
    std::cout << "   |                 ||               |" << std::endl;
    std::cout << "   |_________________||_______________|" << std::endl;
    std::cout << "   |_________________||_______________|" << std::endl;
    std::cout << "    |               |  |               |" << std::endl;
    std::cout << "    |               |  |               |" << std::endl;
    std::cout << "    |      ____     |  |     ____      |" << std::endl;
    std::cout << "    |      ____     |  |     ____      |" << std::endl;
    std::cout << "    |     |    |    |  |    |    |     |" << std::endl;
    std::cout << "    |     |    |    |  |    |    |     |" << std::endl;
    std::cout << "    |_____|____|____|  |____|____|_____|" << std::endl;
    std::cout << "    |_____|____|____|  |____|____|_____|" << std::endl;
    std::cout << "    |                 |  |               |" << std::endl;
    std::cout << "    |_________________|  |_______________|" << std::endl;
}


void School::graduationCeremony()
{
	m_professors[0]->graduateAllStudent(m_students);
}
