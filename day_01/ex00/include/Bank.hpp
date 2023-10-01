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
	long long createAccount(); // id auto
	void deleteAccount(long long);
	void giveLoan(long long, double);
	void repayLoan(long long, double);
	void addValueToAccount(long long, double); // take 5 %
	void removeValueFromAccount(long long, double);
	void changeId(long long, long long);
	void addLiquidity(double);

	// getters
	const double& getLiquidity();
	const Account& operator[](long long) const;
	const std::vector<double>& getLoans(long long);

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

	friend std::ostream& operator<< (std::ostream& p_os, const Bank& p_bank);
private:
	double liquidity;
	std::map<long long, Account>	clientAccounts; // [id, account]
	long long						nextId;
	std::map<long long, std::vector<double> >	loans; // id, list of loans
	std::deque<long long>			removedId; // check on create acc
};

std::ostream& operator<< (std::ostream& p_os, const Bank& p_bank);
