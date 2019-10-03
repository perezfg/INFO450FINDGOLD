#include <iostream>
#include <time.h>
using namespace std;
const int SIZE = 10;//can be changed to display any amount of arrays needed for bigger or smaller boards
void hiddenGameBoard();
void ruleBoard();
void gameBoard(char array[SIZE][SIZE]);//function to pass realGamboard array to follow non-functional requirements
int main() {
	int bomb = 0;
	char choice;
	int x, y;
	int points = 0;
	do {
		char realGameBoard[SIZE][SIZE] = {' '}; // space resets the gameboard
		int guess = 5;
		hiddenGameBoard();//call to function to display the a demo gameboard
		ruleBoard();//displays the rules of the game
		srand(time(NULL));
		int goldCount = 0;
		int bombCount = 0;
		while (goldCount < 5) { //to get gold onto the gameboard
			int gold1 = (rand() % (SIZE-2))+2;
			int gold2 = (rand() % (SIZE-2))+2;
			realGameBoard[gold1][gold2] = 'G';
			goldCount++;
		}
		cout << endl;
		while (bombCount < 1) { // to get bomb to display onto gameboard
			int bomb1 = (rand() % (SIZE-2))+2;
			int bomb2 = (rand() % (SIZE-2))+2;
			realGameBoard[bomb1][bomb2] = 'B';
			bombCount++;
		}
		do {
			cout << "Enter x coordinate: " << endl;// user input
			cin >> x;
			cout << "Enter y coordinates: " << endl;// user input
			cin >> y;
			x++;
			y++;
			if (realGameBoard[x][y] == 'G') { //finding gold
				cout << "You found GOLD!! Only " << ++guess << " guesses to go! You have " << ++points << " points!" << endl << endl;
				realGameBoard[x][y] = 'F';
			}
			else if (realGameBoard[x][y] == 'B') {//finding bomb

				cout << "BOMB! Game Over!" << endl << endl;
				bomb++;
			}
			else {// when you miss gold or bomb or even guess the same space
				cout << "Too bad... you have " << --guess << " guesses to go!" << endl << endl;
			}
		} while (bomb == 0 && guess != 0);
		cout << "You earned " << points << " points" << endl;//displays points from this and previous games
		cout << "Better Luck Next Time" << endl;
		cout << "Here's your board" << endl;
		gameBoard(realGameBoard);//function call to get gameboard and the results

		cout << "Play again? Enter 'Y'" << endl;
		cin >> choice;//user input to play again

		//start--;
	} while ((choice == 'y' || choice == 'Y'));//loop to keep going if y or Y

	system("pause");
	return 0;
}

void hiddenGameBoard() {
	int countX = 1;//these are used to make sure they reset at end of each iteration of the game
	int countY = 1;
	char hiddenArray[SIZE][SIZE] = { };//creating game board
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
void gameBoard(char array[SIZE][SIZE]) {
	int countX = 1;//these are used to make sure they reset at end of each iteration of the game
	int countY = 1;
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {//statements to find out what value is in a certain array index
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
			else if (array[x][y] == 'F') {
				cout << "F";
			}
			else if (array[x][y] == 'G') {
				cout << "G";
			}
			else if (array[x][y] == 'B') {
				cout << "B";
			}
			else {
				cout << " ";
			}
			cout << " ";
		}
		cout << endl;
	}
}
void ruleBoard() { // rules for the game
	cout << "   __________________" << endl;
	cout << "** ****************** **" << endl;
	cout << "**     Find Gold!     **" << endl;
	cout << "** You have 5 guesses,**" << endl;
	cout << "**  5 pieces of gold  **" << endl;
	cout << "**     and 1 bomb     **" << endl;
	cout << "**     Good Luck!     **" << endl;
}