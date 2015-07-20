#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

unsigned int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0/(static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand()*fraction*(max - min + 1) + min);
}

unsigned int getGuess(int n)
{
	int g;
	do {
		std::cout << "Guess #" << n << ": ";
		if(std::cin >> g)
			;
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while(g < 1 || g > 100);
	return static_cast<unsigned int>(g);
}

bool playAgain()
{
	char yesorno;
	while(true) {
		std::cout << "Would you like to play again (y/n)? ";
		std::cin >> yesorno;
		switch(yesorno) {
			case 'y':
				return true;
			case 'n':
				return false;
			default:
				continue;
		}
	}
}


int main()
{
	srand(static_cast<unsigned int>(time(0)));

	do {
		unsigned int answer = getRandomNumber(1, 100);
		std::cout << "Let's play a game. "						<<
					 "I'm thinking of a number 1-100. "			<<
					 "You have 7 tries to guess what it is.\n";

		int nguess = 0;
		while(true) {
			nguess++;
			unsigned int guess = getGuess(nguess);
			if(guess == answer) {
				std::cout << "Correct! You win!\n";
				break;
			} else if(nguess >= 7) {
				std::cout << "Sorry, you lose. The correct number was " << answer << ".\n";
				break;
			} else if(guess < answer) {
				std::cout << "Your guess is too low.\n";
			} else {
				std::cout << "Your guess is too high.\n";
			}
		}

	} while(playAgain());

	std::cout << "Thank you for playing.\n";

	return 0;
}
