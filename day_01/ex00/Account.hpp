#pragma once 

#include <iostream>
#include <exception>

struct Account {

public: 
	Account(void) {};
	Account(int, int);
	~Account();
	Account(const Account&);
	Account& operator=(const Account&);

	void addValue(int);
	void removeValue(int);
	const int& getValue() const { return m_value; }
	const int& getId() const { return m_id; }
	void setId(int);

	class InvalidInputValue: public std::exception
	{
		virtual const char* what() const throw() {return "Input value was invalid";}
	};
private: 
	int m_id;
	int m_value;
};

// std::ostream& operator << (std::ostream& p_os, const Account& p_account)
// {
// 	p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "]";
// 	return (p_os);
// }