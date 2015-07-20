#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

const int nguesses = 7;
const int nummin = 1;
const int nummax = 100;

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
	} while(g < nummin || g > nummax);
	return static_cast<unsigned int>(g);
}

void playGame(int n, int ans)
{
	int nguess = 0;
	while(true) {
		nguess++;
		unsigned int guess = getGuess(nguess);
		if(guess == ans) {
			std::cout << "Correct! You win!\n";
			return;
		} else if(nguess >= n) {
			std::cout << "Sorry, you lose. The correct number was " << ans << ".\n";
			return;
		} else if(guess < ans) {
			std::cout << "Your guess is too low.\n";
		} else {
			std::cout << "Your guess is too high.\n";
		}
	}
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
		unsigned int answer = getRandomNumber(nummin, nummax);
		std::cout << "Let's play a game. "											<<
					 "I'm thinking of a number " << nummin << "-" << nummax << ". "	<<
					 "You have " << nguesses << " tries to guess what it is.\n";
		playGame(nguesses, answer);
	} while(playAgain());

	std::cout << "Thank you for playing.\n";

	return 0;
}
