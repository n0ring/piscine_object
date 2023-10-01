#include "Bank.hpp"

Bank::Bank() : liquidity(0) {}

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


int Bank::createAccount() {
	int id;
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

void Bank::deleteAccount(int id) {
	if (clientAccounts.count(id) == 0) {
		throw AccountNotfound();
	}
	liquidity += clientAccounts[id].getValue();
	clientAccounts.erase(id);
	removedId.push_back(id);
}

void Bank::giveLoan(int id, int amount) {
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

void Bank::repayLoan(int id, int paymant) {
	if (clientAccounts.count(id) == 0) {
		throw AccountNotfound();
	}
	if (paymant < 0 || loans.count(id) == 0) {
		throw InvalidInputValue();
	}
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
	std::sort(loans[id].begin(), loans[id].end(), std::greater<int>());
	while (loans[id].size() > 0 && loans[id].back() == 0) {
		loans[id].pop_back();
	}
	if (paymant > 0) {
		addValueToAccount(id, paymant);
	}
}

void Bank::addValueToAccount(int id, int amount) {
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

void Bank::removeValueFromAccount(int id, int amount) {
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

void Bank::changeId(int oldId, int newId) {
	if (clientAccounts.count(oldId) == 0) {
		throw AccountNotfound();
	}
	clientAccounts[oldId].setId(newId);
	clientAccounts[newId] = clientAccounts[oldId];
	clientAccounts.erase(oldId);
}

void Bank::addLiquidity(int amount) {
    if (amount < 0) {
		throw InvalidInputValue();
	}
	liquidity += amount;
}

int Bank::getLiquidity() const {
	return liquidity;
}

Account& Bank::operator[](int id) {
    return clientAccounts.at(id);
}
