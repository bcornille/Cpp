#include <iostream>

int main()
{
	// Define the uninitialized variable x
	int x;

	// Print out the value of x to the screen.
	// This code is not deterministice, i.e. does not always give the same results.
	std::cout << x;
	std::cout << "\n";

	return 0;
}
