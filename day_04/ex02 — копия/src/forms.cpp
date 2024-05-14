#include "forms.hpp"

Form& Form::operator=(const Form& p_form)
{
	if (this == &p_form)
		return (*this);
	_formType = p_form._formType;
	return (*this);
}
Form::Form(const Form& p_form)
{
	*this = p_form;
}