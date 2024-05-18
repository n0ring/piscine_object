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

// @command
class Form
{
private:
	FormType _formType;
	bool	sighed;

protected:
	bool executed;
	std::string _formText;

public:
	Form() = default;
	Form(FormType p_formType) : _formType(p_formType), sighed(false), executed(false) {}
	virtual ~Form() {}
	Form& operator=(const Form& p_form);
	Form(const Form& p_form);

	virtual void execute() = 0;
	virtual void fillForm(std::string text)
	{
		_formText = text;
	}
	void sigh() { sighed = true; }
	FormType getFormType() { return _formType; }
	bool isSighed() { return sighed; }
	const std::string& getTextForm() const { return _formText; }
};

// @concreteCommand
class CourseFinishedForm : public Form
{
private:

public:
	CourseFinishedForm(FormType p_formType) : Form(p_formType) { std::cout << "CourseFinishedForm created" << std::endl;}
	CourseFinishedForm() { std::cout << "CourseFinishedForm created" << std::endl; }
	void execute() override 
	{
		if (isSighed())
		{
			std::cout << "Form CourseFinishedForm: [";
			std::cout << _formText;
			std::cout << "] executed" << std::endl;
		}
		else
			std::cout << "Form CourseFinishedForm not sighed\n";
	}
};

// @concreteCommand
class NeedMoreClassRoomForm : public Form
{
private:
public:
	NeedMoreClassRoomForm(FormType p_formType) : Form(p_formType) { std::cout << "NeedMoreClassRoomForm created" << std::endl;}
	NeedMoreClassRoomForm() { std::cout << "NeedMoreClassRoomForm created" << std::endl; }
	void execute() override
	{
		if (isSighed())
		{
			std::cout << "Form NeedMoreClassRoomForm: [";
			std::cout << _formText;
			std::cout << "] executed" << std::endl;
		}
		else
			std::cout << "Form NeedMoreClassRoomForm not sighed\n";
	}
	
};


// @concreteCommand
class NeedCourseCreationForm : public Form
{
private:
	int _numberOfClassToGraduate;
	int _maximumNumberOfStudent;
public:
	NeedCourseCreationForm(FormType p_formType) : Form(p_formType) { std::cout << "NeedCourseCreationForm created" << std::endl; }
	NeedCourseCreationForm() { std::cout << "NeedCourseCreationForm created" << std::endl; }
	void setNumberOfClasToGraduate(int n) { _numberOfClassToGraduate = n; }
	void setMaxNumberOfStudents(int n ) { _maximumNumberOfStudent = n; }
	
	int getNumberOfClassToGraduate() {return _numberOfClassToGraduate;}
	int getMaximumNumberOfStudent() {return _maximumNumberOfStudent;}
	
	void execute() override 
	{
		if (isSighed())
		{
			std::cout << "Form NeedCourseCreationForm: [";
			std::cout << _formText;
			std::cout << " numberOfClassToGraduate: " << _numberOfClassToGraduate;
			std::cout << " maximumNumberOfStudent: " << _maximumNumberOfStudent;
			std::cout << "] executed" << std::endl;
		}
		else 
			std::cout << "Form NeedCourseCreationForm not sighed\n";
	}

};

// @concreteCommand
class SubscriptionToCourseForm : public Form
{
private:

public:
	SubscriptionToCourseForm(FormType p_formType) : Form(p_formType) { std::cout << "SubscriptionToCourseForm created" << std::endl; }
	SubscriptionToCourseForm() { std::cout << "SubscriptionToCourseForm created" << std::endl; }
	void execute() override 
	{
		if (isSighed())
		{
			std::cout << "Form SubscriptionToCourseForm: [";
			std::cout << _formText;
			std::cout << "] executed" << std::endl;
		}
		else 
			std::cout << "Form SubscriptionToCourseForm not sighed\n";
	}
};
