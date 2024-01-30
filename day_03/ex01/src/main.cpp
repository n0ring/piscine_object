
#include <iostream>

#include "command.hpp"
#include "thuesdayDiscount.hpp"
#include "PackageReductionDiscountCommand.hpp"

int main() {
	Command c(1, "01/01/2021", "John Doe");
	c.saveArticle("Apple", 2, 100);
	c.saveArticle("Orange", 3, 200);
	c.saveArticle("Banana", 4, 300);
	std::cout << "Total price: " << c.getTotalPrice() << std::endl;

	ThuesdayDiscount td(2, "02/01/2021", "John Doe");
	td.addActicle("Apple", 2, 100);
	td.addActicle("Orange", 3, 200);
	td.addActicle("Banana", 4, 300);
	std::cout << "Total price if Thuesday: " << td.getTotalPrice() << std::endl;
	
	PackageReductionDiscountCommand pr(3, "02/01/2021", "John Doe");
	pr.addActicle("Apple", 2, 100);
	pr.addActicle("Orange", 3, 200);
	pr.addActicle("Banana", 4, 300);
	std::cout << "Total price if total more then 150: " << pr.getTotalPrice() << std::endl;
	
	return 0;
}