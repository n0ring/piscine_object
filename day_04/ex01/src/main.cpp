#include <memory>
#include <iostream>
#include "ListSingletons.hpp"
#include <thread>

// thread worker
void thread_worker() {
	for (int i = 0; i < 10000; i++) {
		StudentList::getInstance().addElement(std::make_shared<Student>());
		StaffList::getInstance().addElement(std::make_shared<Professor>());
		StaffList::getInstance().addElement(std::make_shared<Headmaster>());
		StaffList::getInstance().addElement(std::make_shared<Secretary>());
		CourseList::getInstance().addElement(std::make_shared<Course>());
		RoomList::getInstance().addElement(std::make_shared<Classroom>());
		RoomList::getInstance().addElement(std::make_shared<SecretarialOffice>());
		RoomList::getInstance().addElement(std::make_shared<HeadmasterOffice>());
		RoomList::getInstance().addElement(std::make_shared<StaffRestRoom>());
		RoomList::getInstance().addElement(std::make_shared<Courtyard>());
	}
	std::cout << "student list: " << StudentList::getInstance().size() << std::endl;
	std::cout << "staff list: " << StaffList::getInstance().size() << std::endl;
	std::cout << "course list: " << CourseList::getInstance().size() << std::endl;
	std::cout << "room list: " << RoomList::getInstance().size() << std::endl;
	
	std::cout << "-----end of thread-----" << std::endl;
}

int main() {
	std::thread t1(thread_worker);
	std::thread t2(thread_worker);
	t1.join();
	t2.join();
	return 0;
}