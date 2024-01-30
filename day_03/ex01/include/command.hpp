#pragma once

#include <iostream>
#include <vector>
#include <utility>

class Command {
	public: 
		Command(int id, std::string date, std::string client) {
			this->id = id;
			this->date = date;
			this->client = client;
		}
		virtual ~Command() {}
		Command(const Command& other) {
			*this = other;
		}
		Command& operator=(const Command& other) {
			if (this == &other) {
				return *this;
			}
			this->id = other.id;
			this->date = other.date;
			this->client = other.client;
			this->articles = other.articles;
			return *this;
		}
		// use by other classes. 
		void saveArticle(std::string article, int queantity, float price) {
			articles.push_back(std::make_pair(article, queantity));
			prices.push_back(price);
		}

		float getTotalPrice() {
			float total = 0;
			for (size_t i = 0; i < prices.size(); i++) {
				total += prices[i] * articles[i].second;
			}
			return total;
		}
	protected:
		int id;
		std::string date;
		std::string client;
		std::vector<std::pair<std::string, int> > articles;
		std::vector<float> prices;
};