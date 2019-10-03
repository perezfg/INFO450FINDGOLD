#include <iostream>
#include <time.h>
using namespace std;
const int SIZE = 10;
void hiddenGameBoard();
void ruleBoard();
int main() {
	int bomb = 0;
	char choice;
	int x, y;
	int points = 0;
	do {
		char realGameBoard[SIZE][SIZE] = {' '};
		int countX = 1;
		int countY = 1;
		int guess = 5;
		hiddenGameBoard();
		ruleBoard();
		srand(time(NULL));
		int goldCount = 0;
		int bombCount = 0;
		while (goldCount < 5) {
			int gold1 = (rand() % (SIZE-2))+2;
			int gold2 = (rand() % (SIZE-2))+2;
			realGameBoard[gold1][gold2] = 'G';
			goldCount++;
		}
		cout << endl;
		while (bombCount < 1) {
			int bomb1 = (rand() % (SIZE-2))+2;
			int bomb2 = (rand() % (SIZE-2))+2;
			realGameBoard[bomb1][bomb2] = 'B';
			bombCount++;
		}
		do {
			cout << "Enter x coordinate: " << endl;
			cin >> x;
			cout << "Enter y coordinates: " << endl;
			cin >> y;
			x++;
			y++;
			if (realGameBoard[x][y] == 'G') {
				cout << "You found GOLD!! Only " << ++guess << " guesses to go! You have " << ++points << " points!" << endl << endl;
				realGameBoard[x][y] = 'F';
			}
			else if (realGameBoard[x][y] == 'B') {

				cout << "BOMB! Game Over!" << endl << endl;
				bomb++;
			}
			else {
				cout << "Too bad... you have " << --guess << " guesses to go!" << endl << endl;
			}
			if (guess == 0) {
				cout << "You earned " << points << " points" << endl;
			}
		} while (bomb == 0 && guess != 0);
		cout << "You earned " << points << " points" << endl;
		cout << "Better Luck Next Time" << endl;
		cout << "Here's your board" << endl;
		for (int y = 0; y < SIZE; y++) {
			for (int x = 0; x < SIZE; x++) {
				if (x == 1 && y == 1) {
					cout << "_";
				}
				else if (x <= 1 && y <= 1) {
					cout << " ";
				}
				else if (x <= SIZE && y == 1) {
					cout << "_";
				}
				else if (y <= SIZE && x == 1) {
					cout << "|";
				}
				else if (x <= SIZE && y == 0) {
					cout << countX++;
				}
				else if (y <= SIZE && x == 0) {
					cout << countY++;
				}
				else if (realGameBoard[x][y] == 'F') {
					cout << "F";
				}
				else if (realGameBoard[x][y] == 'G') {
					cout << "G";
				}
				else if (realGameBoard[x][y] == 'B') {
					cout << "B";
				}
				else {
					cout << " ";
				}
				cout << " ";
			}
			cout << endl;
		}
		cout << "Play again? Enter 'Y'" << endl;
		cin >> choice;

		//start--;
	} while ((choice == 'y' || choice == 'Y'));

	//system("pause");
	return 0;
}

void hiddenGameBoard() {
	int countX = 1;
	int countY = 1;
	char hiddenArray[SIZE][SIZE] = { };
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			if (x == 1 && y == 1) {
				cout << "_";
			}
			else if (x <= 1 && y <= 1) {
				cout << " ";
			}
			else if (x <= SIZE && y == 1) {
				cout << "_";
			}
			else if (y <= SIZE && x == 1) {
				cout << "|";
			}
			else if (x <= SIZE && y == 0) {
				cout << countX++;
			}
			else if (y <= SIZE && x == 0) {
				cout << countY++;
			}
			else {
				cout << "?";
			}
			cout << " ";
		}
		cout << endl;
	}

}
void ruleBoard() {
	cout << "   __________________" << endl;
	cout << "** ****************** **" << endl;
	cout << "**     Find Gold!     **" << endl;
	cout << "** You have 5 guesses,**" << endl;
	cout << "**  5 pieces of gold  **" << endl;
	cout << "**     and 1 bomb     **" << endl;
	cout << "**     Good Luck!     **" << endl;
}