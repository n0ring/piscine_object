#pragma once 

#include <iostream>

struct Account {

public: 
	Account(int, int);
	~Account();
	Account(const Account&);
	Account& operator=(const Account&);

	void addValue(int);
	void removeValue(int);
	const int& getValue() const { return value; }
	const int& getId() const { return id; }
private: 
	Account(void) {};
	int id;
	int value;
};

std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
	p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "]";
	return (p_os);
}