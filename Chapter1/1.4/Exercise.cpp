#include <iostream>

int doubleNumber(int x)
{
	return 2*x;
}

int main()
{
	int i = 0;
	std::cout << "Enter a number: ";
	std::cin >> i;
	std::cout << "The number you entered doubled is " << doubleNumber(i) << std::endl;

	return 0;
}
