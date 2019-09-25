#include <iostream>
#include <time.h>
using namespace std;
const int SIZE = 10;
void hiddenGameBoard();
void ruleBoard();
int main() {
	int bomb = 0;
	int guess = 5;
	char choice;
	int x, y;
	int points = 0;
	int realGameBoard[8][8];
	do {
		hiddenGameBoard();
		ruleBoard();
		srand(time(NULL));
		for (int goldCount = 0; goldCount != 5; goldCount++) {
			int gold1 = (rand() % 7) + 1;
			int gold2 = (rand() % 7) + 1;
			realGameBoard[gold1][gold2] = 3;
		}
		cout << endl;
		for (int bombCount = 0; bombCount != 1; bombCount++) {
			int bomb1 = (rand() % 7) + 1;
			int bomb2 = (rand() % 7) + 1;
			realGameBoard[bomb1][bomb2] = 2;
		}
		do {
			cout << "Enter x coordinate: " << endl;
			cin >> x;
			cout << "Enter y coordinates: " << endl;
			cin >> y;
			if (realGameBoard[x][y] == 3) {
				cout << "You found GOLD!! Only " << ++guess << " guesses to go!" << endl << endl;
				realGameBoard[x][y] = 'F';
				points++;

			}
			else if (realGameBoard[x][y] == 2) {

				cout << "BOMB! Game Over!" << endl << endl;
				bomb++;
			}
			else {
				cout << "Too bad... you have " << --guess << " guesses to go!" << endl << endl;
			}
		} while (bomb == 0 && guess !=0&&points!=5);
		for (int outX = 0; outX < SIZE; outX++) {
			for (int outY = 0; outY < SIZE; outY++) {
				if (realGameBoard[outX][outY] == 3) {
					realGameBoard[outX][outY] ='G';
				}
				else if (realGameBoard[outX][outY] == 2) {
					realGameBoard[outX][outY] = 'B';
				}
				else {
					realGameBoard[outX][outY] = ' ';
					--guess;
				}
			}
		}
		cout << "You earned " << points << " points" << endl;
		cout << "Better Luck Next Time" << endl;
		cout << "Here's your board" << endl;
		cout << "   1  2  3  4  5  6  7  8" << endl;
		cout << "  _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		cout << "1 | " << realGameBoard[0][0] << " " << realGameBoard[1][0] << " " << realGameBoard[2][0] << " " << realGameBoard[3][0] << " " << realGameBoard[4][0] << " " << realGameBoard[5][0] << " " << realGameBoard[6][0] << " " << realGameBoard[7][0] << endl;
		cout << "2 | " << realGameBoard[0][1] << " " << realGameBoard[1][1] << " " << realGameBoard[2][1] << " " << realGameBoard[3][1] << " " << realGameBoard[4][1] << " " << realGameBoard[5][1] << " " << realGameBoard[6][1] << " " << realGameBoard[7][1] << endl;
		cout << "3 | " << realGameBoard[0][2] << " " << realGameBoard[1][2] << " " << realGameBoard[2][2] << " " << realGameBoard[3][2] << " " << realGameBoard[4][2] << " " << realGameBoard[5][2] << " " << realGameBoard[6][2] << " " << realGameBoard[7][2] << endl;
		cout << "4 | " << realGameBoard[0][3] << " " << realGameBoard[1][3] << " " << realGameBoard[2][3] << " " << realGameBoard[3][3] << " " << realGameBoard[4][3] << " " << realGameBoard[5][3] << " " << realGameBoard[6][3] << " " << realGameBoard[7][3] << endl;
		cout << "5 | " << realGameBoard[0][4] << " " << realGameBoard[1][4] << " " << realGameBoard[2][4] << " " << realGameBoard[3][4] << " " << realGameBoard[4][4] << " " << realGameBoard[5][4] << " " << realGameBoard[6][4] << " " << realGameBoard[7][4] << endl;
		cout << "6 | " << realGameBoard[0][5] << " " << realGameBoard[1][5] << " " << realGameBoard[2][5] << " " << realGameBoard[3][5] << " " << realGameBoard[4][5] << " " << realGameBoard[5][5] << " " << realGameBoard[6][5] << " " << realGameBoard[7][5] << endl;
		cout << "7 | " << realGameBoard[0][6] << " " << realGameBoard[1][6] << " " << realGameBoard[2][6] << " " << realGameBoard[3][6] << " " << realGameBoard[4][6] << " " << realGameBoard[5][6] << " " << realGameBoard[6][6] << " " << realGameBoard[7][6] << endl;
		cout << "8 | " << realGameBoard[0][7] << " " << realGameBoard[1][7] << " " << realGameBoard[2][7] << " " << realGameBoard[3][7] << " " << realGameBoard[4][7] << " " << realGameBoard[5][7] << " " << realGameBoard[6][7] << " " << realGameBoard[7][7] << endl;
		cout << "Play again? Enter 'Y'" << endl;
		cin >> choice;

		//start--;
	} while ((choice == 'y' || choice == 'Y'));

	//system("pause");
	return 0;
}

void hiddenGameBoard() {
	char hiddenArray[SIZE][SIZE] = {
		{' ', ' ', '1', '2','3', '4', '5', '6', '7', '8'},
		{' ', '_', '_', '_','_', '_', '_', '_', '_', '_'},
		{'1', '|', '?', '?','?', '?', '?', '?', '?', '?'},
		{'2', '|', '?', '?','?', '?', '?', '?', '?', '?'},
		{'3', '|', '?', '?','?', '?', '?', '?', '?', '?'},
		{'4', '|', '?', '?','?', '?', '?', '?', '?', '?'},
		{'5', '|', '?', '?','?', '?', '?', '?', '?', '?'},
		{'6', '|', '?', '?','?', '?', '?', '?', '?', '?'},
		{'7', '|', '?', '?','?', '?', '?', '?', '?', '?'},
		{'8', '|', '?', '?','?', '?', '?', '?', '?', '?'} };
	for (int x = 0; x < SIZE; x++) {
		for (int y = 0; y < SIZE; y++) {
			cout << hiddenArray[x][y]<< ' ';
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