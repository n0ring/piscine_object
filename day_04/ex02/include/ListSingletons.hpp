#pragma once 

#include <iostream>
#include <vector>
#include <memory>
#include <mutex>
#include "persons.hpp"
#include "course.hpp"
#include "rooms.hpp"


class Student;
class StudentList;

template <typename T>
class BasicList {
public:
	BasicList() = default;
	BasicList(const BasicList&) = default;
	BasicList& operator=(const BasicList&) = default;
	virtual ~BasicList() {}

	void addElement(std::shared_ptr<T> element) {
		_mutex.lock();
		elements.push_back(element);
		_mutex.unlock();
	}
	void removeElement(std::shared_ptr<T> element) {
		_mutex.lock();
		for (auto it = elements.begin(); it != elements.end(); ++it) {
			if (*it == element) {
				elements.erase(it);
				break;
			}
		}
		_mutex.unlock();
	}
	int size() {
		return elements.size();
	}

protected: 
	std::vector<std::shared_ptr<T> > elements;
private:
	std::mutex _mutex;
};

template <typename T>
class SingletonList : public BasicList<T> 
{
public:
	static SingletonList& getInstance()
	{
		static SingletonList _instance;
		return _instance;
	}
	~SingletonList() {}
private:
	SingletonList() = default;
};

class StudentList : public SingletonList<Student> {};
class StaffList : public SingletonList<Staff> {};
class CourseList : public SingletonList<Course> {};
class RoomList : public SingletonList<Room> {};