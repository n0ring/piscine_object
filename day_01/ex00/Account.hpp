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
	const int& getValue() const { return m_value; }
	const int& getId() const { return m_id; }
private: 
	Account(void) {};
	int m_id;
	int m_value;
};

// std::ostream& operator << (std::ostream& p_os, const Account& p_account)
// {
// 	p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "]";
// 	return (p_os);
// }