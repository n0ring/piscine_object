#include "Bank.hpp"

Bank::Bank() : liquidity(0), nextId(1) {}

Bank::~Bank() {}

Bank::Bank(const Bank& other) {
	liquidity = other.liquidity;
	clientAccounts = other.clientAccounts;
	nextId = other.nextId;
	loans = other.loans;
	removedId = other.removedId;
}

Bank& Bank::operator=(const Bank& other) {
	if (this != &other) {
		liquidity = other.liquidity;
		clientAccounts = other.clientAccounts;
		nextId = other.nextId;
		loans = other.loans;
		removedId = other.removedId;
	}
	return *this;
}


long long Bank::createAccount() {
	long long id;
	if (removedId.size() > 0) {
		id = removedId.front();
		removedId.pop_front();
		clientAccounts[id] = Account(id, 0);
	} else {
		clientAccounts[nextId] = Account(nextId, 0);
		id = nextId;
		nextId++;
	}
	return id;
}

void Bank::deleteAccount(long long id) {
	if (clientAccounts.count(id) == 0) {
		throw AccountNotfound();
	}
	liquidity += clientAccounts[id].getValue();
	clientAccounts.erase(id);
	removedId.push_back(id);
}

void Bank::giveLoan(long long  id, double amount) {
	if (clientAccounts.count(id) == 0) {
		throw AccountNotfound();
	}
	if (liquidity < amount) {
		throw LiquidityNotEnough();
	}
	liquidity -= amount;
	loans[id].push_back(amount);
	clientAccounts[id].addValue(amount);
}

void Bank::repayLoan(long long id, double paymant) {
	if (clientAccounts.count(id) == 0) {
		throw AccountNotfound();
	}
	if (paymant < 0 || loans.count(id) == 0 || paymant > clientAccounts[id].getValue()) {
		throw InvalidInputValue();
	}
	clientAccounts[id].removeValue(paymant);
	for (size_t i = 0; paymant > 0 && i < loans[id].size(); i++) {
		if (paymant >= loans[id][i]) {
			paymant -= loans[id][i];
			loans[id][i] = 0;
		}
		else {
			loans[id][i] -= paymant;
			paymant = 0;
		}
	}
	std::sort(loans[id].begin(), loans[id].end(), std::greater<double>());
	while (loans[id].size() > 0 && loans[id].back() == 0) {
		loans[id].pop_back();
	}
	if (paymant > 0) {
		clientAccounts[id].addValue(paymant);
	}
}

const std::vector<double>& Bank::getLoans(long long id) {
	if (clientAccounts.count(id) == 0) {
		throw AccountNotfound();
	}
	return loans[id];
}

void Bank::addValueToAccount(long long id, double amount) {
	if (clientAccounts.count(id) == 0) {
		throw AccountNotfound();
	}
	if (amount < 0) {
		throw InvalidInputValue();
	}
	liquidity += amount * COMMISION;
	amount -= amount * COMMISION;
	clientAccounts[id].addValue(amount);
	
}

void Bank::removeValueFromAccount(long long id, double amount) {
	if (clientAccounts.count(id) == 0) {
		throw AccountNotfound();
	}
	try {
		clientAccounts[id].removeValue(amount);
	}
	catch(const std::exception& e) {
		throw e;
	}
}

void Bank::changeId(long long oldId, long long newId) {
	if (clientAccounts.count(oldId) == 0) {
		throw AccountNotfound();
	}
	if (clientAccounts.count(newId) != 0) {
		throw InvalidInputValue();
	}
	clientAccounts[oldId].setId(newId);
	clientAccounts[newId] = clientAccounts[oldId];
	clientAccounts.erase(oldId);
}

void Bank::addLiquidity(double amount) {
    if (amount < 0) {
		throw InvalidInputValue();
	}
	liquidity += amount;
}

const double& Bank::getLiquidity() {
	return liquidity;
}

const Account& Bank::operator[](long long id) const {
    return clientAccounts.at(id);
}


std::ostream& operator<< (std::ostream& p_os, const Bank& p_bank)
	{
		p_os << "Bank informations : " << std::endl;
		p_os << "Liquidity : " << p_bank.liquidity << std::endl;
		p_os << "Accounts : " << std::endl;
		for (std::map<long long, Account>::const_iterator it = p_bank.clientAccounts.begin(); it != p_bank.clientAccounts.end(); it++) {
			p_os << it->second << std::endl;
			p_os << "Loans : ";
			if (p_bank.loans.count(it->first) == 0) {
				p_os << "No loans" << std::endl;
				continue;
			}
			for (size_t i = 0; i < p_bank.loans.at(it->first).size(); i++) {
				p_os << p_bank.loans.at(it->first)[i] << " ";
			}
			p_os << std::endl;
		}
		return (p_os);
	}