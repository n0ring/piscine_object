#include <iostream>
#include <set>
#include <algorithm>
#include <string>


enum class Event
{
	RingBell
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
            observer->update(event);
        }
    }
};
