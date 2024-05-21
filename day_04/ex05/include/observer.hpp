#include <iostream>
#include <set>
#include <algorithm>
#include <string>


// colors for cout 
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"

enum class Event
{
	RingBell,
    StartClass
};


class IObserver {
public:
    virtual ~IObserver() {}
    virtual void update(const Event &event) = 0;
};

class ISubject {
private:
    std::set<IObserver*> observers;

public:
	virtual ~ISubject() {}
    void attach(IObserver *observer) {
        observers.insert(observer);
    }

    void detach(IObserver *observer) {
		if (observers.count(observer))
			observers.erase(observer);
    }

    void notify(Event event) {
        for (IObserver *observer : observers) {
            if (observer)   
                observer->update(event);
        }
    }
};
