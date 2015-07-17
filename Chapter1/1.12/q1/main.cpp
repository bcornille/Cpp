#include <iostream>

int readNumber()
{
	int num = 0;
	std::cout << "Enter a number: ";
	std::cin >> num;
	return num;
}

void writeAnswer(int n)
{
	std::cout << "The sum of the entered numbers is " << n << std::endl;
}

int main()
{
	int x = readNumber();
	int y = readNumber();
	int z = x + y;
	writeAnswer(z);

	return 0;
}
