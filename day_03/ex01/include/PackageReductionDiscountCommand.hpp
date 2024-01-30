#pragma once 

#include "command.hpp"

// here we use Open/close principle.
// we can add new discount without changing the code.
// and do it by delegating save article to the base class.
class PackageReductionDiscountCommand : public Command {
	public:
		PackageReductionDiscountCommand(int id, std::string date, std::string client) : Command(id, date, client) {
			isDiscounted = false;
		}

		void addActicle(std::string article, int quantity, float price) {
			saveArticle(article, quantity, price);
			if (!isDiscounted && getTotalPrice() > 150) {
				saveArticle("discount", 1, -10);// haha i know 
				isDiscounted = true;
			}
		}

	private:
		bool isDiscounted;
};