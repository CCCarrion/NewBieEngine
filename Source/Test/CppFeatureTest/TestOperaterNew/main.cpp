#include <iostream>
#include <string>


class TestA{

public:
	TestA() { std::cout << "Test A with no initialization"<<std::endl; }

	TestA(char* name) {
		std::cout << "Test A with initialization"<<name << std::endl;
	}

	~TestA() { std::cout << "Test A is destroyed"<<std::endl; }
};

void* ::operator new(size_t size)
{
	void* address = malloc(size);
	std::cout << "use new  of "<<size<<" address is "<<address<< std::endl;
	return address;
}

void ::operator delete(void* address)
{
	std::cout << "use delete  of " << address << std::endl;
	free (address);
}

void main()
{
	TestA* ta = new TestA();
	TestA* taN = new TestA("TAN");

	delete ta,delete taN;
	getchar();
}