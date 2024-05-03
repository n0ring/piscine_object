#include <iostream>

class A {
	public: 
		virtual void f() {
			std::cout << "A::f();\n";
		}

};

class B : public A {
	public:
		void f() {
			std::cout << "B::f();\n";
		}
};

int main() {
	A* b = new B();
	b->f();
	std::cout << sizeof(A) << std::endl;
	std::cout << sizeof(B) << std::endl;

}

int ret()
{
	return 42;
}


int main()
{
	int a;

	a = ret();
}

// functions 
// printf 
// visualizator 