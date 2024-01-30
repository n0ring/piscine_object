#pragma once

#include "command.hpp"

// here we use Open/close principle.
// we can add new discount without changing the code.
// and do it by delegating save article to the base class.
class ThuesdayDiscount : public Command {
	public: 
		ThuesdayDiscount(int id, std::string date, std::string client) : Command(id, date, client) {}
		virtual ~ThuesdayDiscount() {}
		ThuesdayDiscount(const ThuesdayDiscount& other) : Command(other) {}
		ThuesdayDiscount& operator=(const ThuesdayDiscount& other) {
			if (this == &other) {
				return *this;
			}
			Command::operator=(other);
			return *this;
		}

		void addActicle(std::string article, int quantity, float price) {
			float priceWithDiscount = price * 0.9;
			saveArticle(article, quantity, priceWithDiscount);
		}
};
