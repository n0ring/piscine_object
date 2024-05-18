#include <memory>
#include <iostream>
#include <thread>
#include "ListSingletons.hpp"
#include "persons.hpp"
#include "forms.hpp"


// factory method patter to create the form (secretary.createForm) 
// command pattern: the headmaster will receive the form, process it and execute it
// form here is like a command
// headmaster is the invoker and receiver

int main() {
	Secretary secretary;
	Headmaster headmaster;

	std::shared_ptr<Form> formCourseFinished = secretary.createForm(FormType::CourseFinished);
	std::shared_ptr<Form> formNeedMoreClassRoom = secretary.createForm(FormType::NeedMoreClassRoom);
	std::shared_ptr<Form> formNeedCourseCreation = secretary.createForm(FormType::NeedCourseCreation);
	std::shared_ptr<Form> formSubscriptionToCourse = secretary.createForm(FormType::SubscriptionToCourse);

	std::shared_ptr<Form> invalidForm = secretary.createForm(FormType::CourseFinished);

	formCourseFinished->fillForm("I finished the course");
	formNeedMoreClassRoom->fillForm("We need more classrooms");
	formNeedCourseCreation->fillForm("We need a new course");
	formSubscriptionToCourse->fillForm("I want to subscribe to a course");

	headmaster.receiveForm(formCourseFinished);
	headmaster.receiveForm(formNeedMoreClassRoom);
	headmaster.receiveForm(formNeedCourseCreation);
	headmaster.receiveForm(formSubscriptionToCourse);

	headmaster.formProcessing();
	
	invalidForm->execute(); // invalid attempt to execute a form
	return 0;
}