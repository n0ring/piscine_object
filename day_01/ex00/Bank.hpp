#pragma once 

#include <map>
#include "Account.hpp"

struct Bank
{
public:
	Bank(void);
	~Bank();
	Bank(const Bank&);
	Bank& operator=(const Bank&);

	// Account manager
	void createAccount(); // id auto
	void deleteAccount(int);
	void giveLoan(int, int);

	void addValueToAccount(int, int); // take 5 %
	void removeValueFromAccount(int, int);

private:
	int liquidity;
	std::map<long long, Account> clientAccounts;


	friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
	{
		p_os << "Bank informations : " << std::endl;
		p_os << "Liquidity : " << p_bank.liquidity << std::endl;
		for (auto &clientAccount : p_bank.clientAccounts)
        p_os << *clientAccount << std::endl;
		return (p_os);
	}
};
