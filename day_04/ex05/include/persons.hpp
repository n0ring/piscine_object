#pragma once 

#include <iostream>
#include <stack>
#include <memory>
#include <map>
#include "forms.hpp"
#include "course.hpp"
#include "rooms.hpp"
#include "observer.hpp"

class Form;
class CourseFinishedForm;
class NeedMoreClassRoomForm;
class NeedCourseCreationForm;
class SubscriptionToCourseForm;
class Course;
class Room;
class Classroom;
class Headmaster;

class Professor;
class Student;
class Secretary;


class Person
{
private:
	std::string _name;
	Room* _currentRoom;
public:
	Person() = default;
	Person(std::string& p_name) : _name(p_name) {}
	virtual ~Person() {}
	Person& operator=(const Person& p_person);
	Person(const Person& p_person);
	std::string getName();
	Room*room() {return (_currentRoom);}


	void attendClass(Classroom* p_classroom);
	void exitClass();
	void enterRoom(Room* p_room) {_currentRoom = p_room;}
};

class Staff : public Person
{
private:

public:
	Staff() = default;
	Staff(std::string p_name) : Person(p_name) {}
	void sign(std::shared_ptr<Form> p_form) {p_form->sigh();}
};

class Student : public Person, public IObserver
{
private:
	std::map<Course*, int > _subscribedCourse; // course and number of class attended

	std::vector<std::shared_ptr<Course> > _graduatedCourses;
	std::stack<std::shared_ptr<Course> > _coursesToSubscribe;
	Headmaster* _headmaster;
	size_t currentRoomIdx = 0;
public:
	Student() = default;
	Student(std::string p_name, Headmaster* headmaster) : Person(p_name), _headmaster(headmaster) {}
	~Student() {}
	Student& operator=(const Student& p_student);
	Student(const Student& p_student);
	

	void graduate(std::shared_ptr<Course> p_course);
	void subscribe(Course* p_course);
	void subscribeToCourse(std::shared_ptr<Course> p_course);
	void fillForm(std::shared_ptr<Form> p_form);
	void removeCourse(Course* p_course);

	bool attendCourse(Course* p_course);
	int getNumberOfClassAttended(std::shared_ptr<Course> p_course);

    void update(const Event& event) override;
};

class Headmaster : public Staff, public ISubject
{
private:
	std::stack<std::shared_ptr<Form> > _formToValidate;
	std::shared_ptr<Secretary> _secretary;
	
public:
	Headmaster();
	Headmaster(std::string p_name) : Staff(p_name) {}
	void receiveForm(std::shared_ptr<Form> p_form) {_formToValidate.push(p_form);}
	
	bool validateForm(std::shared_ptr<Form> p_form) {return p_form->getTextForm().empty() == false;}
	bool executeForm(std::shared_ptr<Form> p_form);
// api as mediator 
	void formProcessing();
	void graduateStudent(Professor* p_professor, std::shared_ptr<Student> p_student, std::shared_ptr<Course> p_course);
	std::shared_ptr<Course> createCourse(Professor* p_professor);
	bool subscribeStudentToCourse(Student* p_student, std::shared_ptr<Course> p_course);
	std::shared_ptr<Classroom> createClassRoom(Professor* p_professor);
	bool assignClassroomToCourse(std::shared_ptr<Course> p_course, std::shared_ptr<Classroom> p_classroom);
	std::shared_ptr<Secretary> getSecretary() {return _secretary;}
};

class Secretary : public Staff
{
private:

public:
	std::shared_ptr<Form> createForm(FormType p_formType);
	void archiveForm();
};

struct courseInfo
{
	std::string name;
	int numberOfClassToGraduate;
	int nmaximumNumberOfStudent;
};

class Professor : public Staff, public IObserver
{
private:
	std::shared_ptr<Course> _currentCourse;
	std::shared_ptr<Headmaster> _headmaster;
	std::stack<std::pair<std::shared_ptr<Student>, std::shared_ptr<Course>>> _studentsToGraduate;
	std::stack<courseInfo> _courseToCreate;
	std::string			_roomName;
public:
	Professor() = default;
	Professor(std::string p_name, std::shared_ptr<Headmaster> headmaster) : Staff(p_name), _headmaster(headmaster) {}
	~Professor() {}
	Professor& operator=(const Professor& p_professor);
	Professor(const Professor& p_professor);
	void assignCourse(std::shared_ptr<Course> p_course) {_currentCourse = p_course;}
	void doClass();
	void closeCourse();

	bool gradeStudent(std::shared_ptr<Student> p_student, std::shared_ptr<Course> p_course);
	std::shared_ptr<Course> createCourse(std::string courseName, int numberOfClass,int maxStudent);
	
	std::shared_ptr<Classroom> createClassRoom(std::string roomName);
	void fillForm(std::shared_ptr<Form> p_form);
	bool setClassRoom(std::shared_ptr<Course> p_course, std::shared_ptr<Classroom> p_classroom);
	
	void teach();
	void graduateAllStudent(std::vector<std::shared_ptr<Student> > p_students);
    void update(const Event& event) override; // observer api
};