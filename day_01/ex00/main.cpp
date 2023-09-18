// #include "Bank.hpp"
#include "Account.hpp"

void accountTest() {
	{
		Account a(0, 100);
		Account b(a);
		Account c(0, 200);
		c = a;
		assert(a.getId() == b.getId());
		assert(a.getValue() == b.getValue());
		assert(a.getId() == c.getId());
		assert(a.getValue() == c.getValue());
		std::cout << "Account constructors OK\n";
	}
	{
		Account a(0, 100);
		assert(a.getValue() == 100);
		std::cout << "Account getValue OK\n";
		bool isExcep = false;
		try
		{
			a.addValue(-100);
		}
		catch(const std::exception& e)
		{
			isExcep = true;
		}
		assert(isExcep);
	}
	{
		Account a(0, 100);
		assert(a.getId() == 0);
		std::cout << "Account getId OK\n";
	}




}

int main() {
	accountTest();
	return 0;
}