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

void Account::addValue(int inputVal) {
	if (inputVal < 0) {
		throw Account::InvalidInputValue();
	}
	m_value += inputVal;
}

void Account::removeValue(int removeVal) {
	if (m_value - removeVal < 0) {
		throw Account::InvalidInputValue();
	}
	m_value -= removeVal;
}

void Account::setId(int newId) {
	m_id = newId;
}
