#pragma once 

#include <iostream>
#include <vector>

enum class FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class Form
{
private:
	FormType _formType;

public:
	Form() = default;
	Form(FormType p_formType) : _formType(p_formType) {}
	virtual ~Form() {}
	Form& operator=(const Form& p_form);
	Form(const Form& p_form);

	virtual void execute() = 0;
};

class CourseFinishedForm : public Form
{
private:

public:
	void execute() override;
};

class NeedMoreClassRoomForm : public Form
{
private:

public:
	void execute() override;
};

class NeedCourseCreationForm : public Form
{
private:

public:
	void execute() override ;
};

class SubscriptionToCourseForm : public Form
{
private:

public:
	void execute() override;
};
