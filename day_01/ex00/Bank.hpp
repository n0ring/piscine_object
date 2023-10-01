#pragma once 

#include <map>
#include <deque>
#include <vector>
#include "Account.hpp"

#define COMMISION 0.05
struct Bank
{
public:
	Bank(void);
	~Bank();
	Bank(const Bank&);
	Bank& operator=(const Bank&);

	// Account manager
	int createAccount(); // id auto
	void deleteAccount(int);
	void giveLoan(int, int);
	void repayLoan(int, int);
	void addValueToAccount(int, int); // take 5 %
	void removeValueFromAccount(int, int);
	void changeId(int, int);
	
	void addLiquidity(int);

	// getters
	int getLiquidity() const;
	Account& operator[](int);

	// exceptions
	class AccountNotfound: public std::exception
	{
		virtual const char* what() const throw() {return "Account not found";}
	};

	class LiquidityNotEnough: public std::exception
	{
		virtual const char* what() const throw() {return "Liquidity not enough";}
	};

	class InvalidInputValue: public std::exception
	{
		virtual const char* what() const throw() {return "Input value was invalid";}
	};
private:
	int liquidity;
	std::map<long long, Account>	clientAccounts; // [id, account]
	long long						nextId;
	std::map<int, std::vector<int> >	loans; // id, list of loans
	std::deque<long long>			removedId; // check on create acc


	// friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
	// {
	// 	p_os << "Bank informations : " << std::endl;
	// 	p_os << "Liquidity : " << p_bank.liquidity << std::endl;
	// 	for (auto &clientAccount : p_bank.clientAccounts)
    //     p_os << *clientAccount << std::endl;
	// 	return (p_os);
	// }
};
