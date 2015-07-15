#include <iostream>

int main()
{
	// The terminal prints a statement asking for a number.
	std::cout << "Enter a number: ";
	int x = 0;
	// A number is read from console input and stored in x.
	std::cin >> x;
	std::cout << "You entered " << x << std::endl;
	return 0;
}
