#pragma once 

class Gear {
public:
	Gear() {}
	~Gear() {}
	Gear& operator=(const Gear& rhs) {
		if (this == &rhs)
			return *this;
		return *this;
	}
	Gear(const Gear& rhs) {
		*this = rhs;
	}
private:
	

};