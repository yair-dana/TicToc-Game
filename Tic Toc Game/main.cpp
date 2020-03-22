//PROJECT 1 - X/O Game
//Introduction to Computer Science
//26/12/18

#include <iostream>
using namespace std;


int main()
{
	//declaration of variables
	int win = 0; // who won
	char res[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' }; // The values ​​of the board
	bool flag = false;//input test
	char mark = ' ';// X/O, for placing the values in the board

	cout << "Welcome to TIC TAC TOE" << endl;
	PrintBoard(res);
	GameRotation(win, flag, mark, res);

	if (win == 1 && mark == 'X') //
		cout << "Player number 1 is W-O-N!!!\n";
	else if (win == 1 && mark == 'O')
		cout << "Player number 2 is W-O-N!!!\n";
	else if (win == -1)
		cout << "TIE in the Game\n";
}
