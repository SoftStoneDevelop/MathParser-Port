#include <cstdlib>
#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Base constructor\n";
	}

	Base(const Base& base)
	{
		std::cout << "Base copy constructor\n";
	}

	Base(Base&& base)
	{
		std::cout << "Base move constructor\n";
	}
};

class Base2
{
public:
	Base2(Base& base) : base{base}
	{
		std::cout << "Base2 constructor\n";
	}

	Base& base;
};

int main() 
{
	std::cout << "Hello bich\n";
	Base b;
	Base2 b2(b);
	char word;
	std::cin >> word;
	return EXIT_SUCCESS;
}