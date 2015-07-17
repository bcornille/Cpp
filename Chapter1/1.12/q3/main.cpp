#include "io.hpp"

int main()
{
	int x = readNumber();
	int y = readNumber();
	int z = x + y;
	writeAnswer(z);

	return 0;
}
