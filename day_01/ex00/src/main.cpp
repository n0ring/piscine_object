#include <iostream>
#include <cassert>
#include "Bank.hpp"


int bankTest() {
    // Test create account
    Bank bank;
    int id = bank.createAccount();
    assert(bank[id].getId() == id);
    assert(bank[id].getValue() == 0);
    std::cout << "Bank createAccount OK\n";

    // Test delete account
    bank.deleteAccount(id);
    bool isExcep = false;
    try
    {
        bank[id];
    }
    catch(const std::exception& e)
    {
        isExcep = true;
    }
    assert(isExcep);
    std::cout << "Bank deleteAccount OK\n";

	// Test add liquidity
    bank.addLiquidity(1000);
    assert(bank.getLiquidity() == 1000);
    std::cout << "Bank addLiquidity OK\n";

    // Test give loan
    int id1 = bank.createAccount();
    bank.giveLoan(id1, 100);
    bank.giveLoan(id1, 100);
    assert(bank[id1].getValue() == 200);
    std::cout << "Bank giveLoan OK\n";

	// Test repay loan
	bank.repayLoan(id1, 100);
	bank.repayLoan(id1, 100);
	assert(bank[id1].getValue() == 0);

	// Test get loans
	assert(bank.getLoans(id1).size() == 0);
    bank.giveLoan(id1, 100);
    bank.giveLoan(id1, 100);
	assert(bank.getLoans(id1).size() == 2);
	// bank.getLoans(id1)[0] = 50; // will not compile
	std::cout << "Bank getLoans OK\n";

    // Test add value to account
    int id2 = bank.createAccount();
    bank.addValueToAccount(id2, 50);
    assert(bank[id2].getValue() == 50 - 50 * COMMISION);
    std::cout << "Bank addValueToAccount OK\n";

    // Test remove value from account
    int id3 = bank.createAccount();
    bank.addValueToAccount(id3, 100);
    bank.removeValueFromAccount(id3, 50);
    assert(bank[id3].getValue() == 50 - 100 * COMMISION);
    std::cout << "Bank removeValueFromAccount OK\n";

    // Test change account ID
    int id4 = bank.createAccount();
    int id5 = bank.createAccount();

    bank.changeId(id4, 42);
    assert(bank[42].getId() == 42);
	bool assertException = false;
	try
	{
		bank.changeId(42, id5);
	}
	catch(const std::exception& e)
	{
		assertException = true;
	}
	assert(assertException);
    std::cout << "Bank changeId OK\n";

    std::cout << "All Bank tests passed!\n";
	std::cout << bank << std::endl;
    return 0;
}

void accountTest() {
    // Test create account
    Account a(0, 100);
    assert(a.getId() == 0);
    assert(a.getValue() == 100);
    std::cout << "Account create OK\n";

    // Test set ID
    Account b(0, 10);
    int newId = 42;
    b.setId(newId);
    assert(b.getId() == newId);
    std::cout << "Account setId OK\n";

    // Test add value
    Account c(0, 0);
    c.addValue(100);
    assert(c.getValue() == 100);
    std::cout << "Account addValue OK\n";

    // Test remove value
    Account d(0, 100);
    d.removeValue(50);
    assert(d.getValue() == 50);
	bool assertException = false;
	try
	{
		d.removeValue(100);
	}
	catch(const std::exception& e)
	{
		assertException = true;
	}
	assert(assertException);
    std::cout << "Account removeValue OK\n";

    // Test invalid input value
    Account e(0, 100);
    bool isExcep = false;
    try
    {
        e.addValue(-50);
    }
    catch(const std::exception& e)
    {
        isExcep = true;
    }
    assert(isExcep);
    std::cout << "Account addValue exception OK\n";

    std::cout << "All acoount tests passed!\n";
}

int main() {
	accountTest();
	bankTest();
    return 0;
}

