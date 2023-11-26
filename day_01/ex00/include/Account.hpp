#pragma once 

#include <iostream>
#include <exception>

struct Account {

public: 
	Account(void) {};
	Account(int, int); // id, value
	~Account();
	Account(const Account&);
	Account& operator=(const Account&);

	void addValue(double);
	void removeValue(double);
	const double& getValue() const { return m_value; }
	const long long& getId() const { return m_id; }
	void setId(long long);

	class InvalidInputValue: public std::exception
	{
		virtual const char* what() const throw() {return "Input value was invalid";}
	};

private: 
	long long m_id;
	double m_value;

};
std::ostream& operator<< (std::ostream& p_os, const Account& p_account);
