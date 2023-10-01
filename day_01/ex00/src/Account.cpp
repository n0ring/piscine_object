#include "Account.hpp"

Account::Account(int id, int value) : m_id(id), m_value(value) {
}

Account::~Account() {

}

Account::Account(const Account& other) {
	m_id = other.m_id;
	m_value = other.m_value;
}
Account& Account::operator=(const Account& other) {
	if (this != &other) {
		m_id = other.m_id;
		m_value = other.m_value;
	}
	return *this;
}

void Account::addValue(double inputVal) {
	if (inputVal < 0) {
		throw Account::InvalidInputValue();
	}
	m_value += inputVal;
}

void Account::removeValue(double removeVal) {
	if (removeVal > m_value) {
		throw Account::InvalidInputValue();
	}
	m_value -= removeVal;
}

void Account::setId(long long newId) {
	m_id = newId;
}


std::ostream& operator<< (std::ostream& p_os, const Account& p_account) {
	p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "]";
	return (p_os);
}
