#pragma once 

#include <vector>
#include "course.hpp"
#include "persons.hpp"
#include "ListSingletons.hpp"

enum class DayTime
{
	CLASSES,
	LUNCH,
	RECREATION,
	NONE
};

class School 
{
public:
	School();
	const std::shared_ptr<Headmaster> getHeadmaster() const {return m_headmaster;}
	void recruteProfessor();
	void recruteStudent();
	std::shared_ptr<Secretary> getSecretary();
	std::vector<std::shared_ptr<Student>> getStudents() {return m_students;}
	std::vector<std::shared_ptr<Professor>> getProfessors() {return m_professors;}
	std::shared_ptr<Course> getCourse(std::string p_name);
	void requestRingBell(); // go from classes to lunch
	void launchClasses(); // start classes
	void runDayRoutine();
	void graduationCeremony();



private:
	const size_t k_maxNumberOfStudents = 10;
	const size_t k_maxNumberOfProfessors = 5;
	const int k_maxNumberOfStudentsOnCourse = 10;
	const int k_numberOfClassForGraduation = 1;

	void doRecreation();
	void launchLunch();
	std::shared_ptr<Headmaster> m_headmaster;
	std::vector<std::shared_ptr<Student> > m_students;
	std::vector<std::shared_ptr<Professor> > m_professors;
	std::vector<std::shared_ptr<Course> > m_courses;
	std::vector<std::shared_ptr<Classroom> > m_classrooms;

	size_t m_professorIdx = 0;
	size_t m_studentIdx = 0;
	DayTime m_currentTime = DayTime::NONE;
};