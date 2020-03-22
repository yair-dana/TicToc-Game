#include "Functions.h"


//Function that prints the game board
void PrintBoard(char res[])
{
	cout << endl;
	cout << "     " << 1 << "      " << 2 << "      " << 3 << endl;
	cout << 'A' << "    " << res[0] << "      " << res[1] << "      " << res[2] << endl;
	cout << 'B' << "    " << res[3] << "      " << res[4] << "      " << res[5] << endl;
	cout << 'C' << "    " << res[6] << "      " << res[7] << "      " << res[8] << endl;

}

//Function that checks the propriety of the input from the user
//The function return:
//False for invalid input
//True for proper input
bool CheckInput(char res[], char ch, char ch2)
{
	if (ch != 'A' && ch != 'B' && ch != 'C')
	{
		cout << "The row you enter is not A / B / C\n";
		cout << "please enter your cell again\n";
		cout << endl;
		return (false);
	}
	else
	{
		if (ch2 != '1' && ch2 != '2' && ch2 != '3')
		{
			cout << "The col you entered is not 1 /2 / 3\n";
			cout << "please enter your cell again\n";
			cout << endl;
			return (false);
		}
		else
		{
			if ((ch == 'A') && (ch2 == '1') && (res[0] != ' '))
			{
				cout << "The cell you chose is taken\n";
				cout << endl;
				return (false);
			}
			else if ((ch == 'A') && (ch2 == '2') && (res[1] != ' '))
			{
				cout << "The cell you chose is taken\n";
				cout << endl;
				return (false);
			}
			else if ((ch == 'A') && (ch2 == '3') && (res[2] != ' '))
			{
				cout << "The cell you chose is taken\n";
				cout << endl;
				return (false);
			}
			else if ((ch == 'B') && (ch2 == '1') && (res[3] != ' '))
			{
				cout << "The cell you chose is taken\n";
				cout << endl;
				return (false);
			}
			else if ((ch == 'B') && (ch2 == '2') && (res[4] != ' '))
			{
				cout << "The cell you chose is taken\n";
				cout << endl;
				return (false);
			}
			else if ((ch == 'B') && (ch2 == '3') && (res[5] != ' '))
			{
				cout << "The cell you chose is taken\n";
				cout << endl;
				return (false);
			}
			else if ((ch == 'C') && (ch2 == '1') && (res[6] != ' '))
			{
				cout << "The cell you chose is taken\n";
				cout << endl;
				return (false);
			}
			else if ((ch == 'C') && (ch2 == '2') && (res[7] != ' '))
			{
				cout << "The cell you chose is taken\n";
				cout << endl;
				return (false);
			}
			else if ((ch == 'C') && (ch2 == '3') && (res[8] != ' '))
			{
				cout << "The cell you chose is taken\n";
				cout << endl;
				return (false);
			}
			else
			{
				return (true);
			}
		}
	}
}


//Function for placing the values into the board variables
void PutResInBoard(char res[], char ch, char ch2, char mark)
{
	switch (ch)
	{
	case 'A':
	{
		if (ch2 == '1')
		{
			res[0] = mark;
			break;
		}
		else if (ch2 == '2')
		{
			res[1] = mark;
			break;
		}
		else if (ch2 == '3')
		{
			res[2] = mark;
			break;
		}
	}
	case 'B':
	{
		if (ch2 == '1')
		{
			res[3] = mark;
			break;
		}

		else if (ch2 == '2')
		{
			res[4] = mark;
			break;
		}
		else if (ch2 == '3')
		{
			res[5] = mark;
			break;
		}

	}
	case 'C':
	{
		if (ch2 == '1')
		{
			res[6] = mark;
			break;
		}
		else if (ch2 == '2')
		{
			res[7] = mark;
			break;
		}
		else if (ch2 == '3')
		{
			res[8] = mark;
			break;
		}
	}
	}
}


//FUNCTION TO RETURN GAME STATUS
//1 FOR GAME IS OVER WITH RESULT
//0 FOR GAME IS IN PROGRESS
//-1 GAME IS OVER AND NO RESULT
int whowon(char res[], char mark) // function that return the result - (1- win, 0-countine -1 game over)
{
	if (res[0] == res[1] && res[1] == res[2] && res[2] == mark)
		return (1);
	else if (res[3] == res[4] && res[4] == res[5] && res[5] == mark)
		return (1);
	else if (res[6] == res[7] && res[7] == res[8] && res[8] == mark)
		return (1);
	else if (res[0] == res[4] && res[4] == res[8] && res[8] == mark)
		return (1);
	else if (res[2] == res[4] && res[4] == res[6] && res[6] == mark)
		return (1);
	else if (res[0] == res[3] && res[3] == res[6] && res[6] == mark)
		return (1);
	else if (res[1] == res[4] && res[4] == res[7] && res[7] == mark)
		return (1);
	else if (res[2] == res[5] && res[5] == res[8] && res[8] == mark)
		return (1);
	else if (res[0] != ' ' && res[1] != ' ' && res[2] != ' ' && res[3] != ' ' && res[4] != ' ' && res[5] != ' ' && res[6] != ' ' && res[7] != ' ' && res[8] != ' ')
		return (-1); //Tie in the game
	else // No winner yet
		return (0);
}


void GameRotation(int &win, bool &flag, char& mark, char* res)
{
	char ch = ' '; //input by user (A/B/C)
	char ch2 = ' '; //input by user (1/2/3)

	while (win == 0)
	{
		while (flag == false) //Player 1 (X)
		{
			cout << "Player Number 1 (X)\n";
			cout << "Please enter cell input (for expample C3)\n";
			cin >> ch >> ch2;
			flag = CheckInput(res, ch, ch2);
		}
		flag = false;
		mark = 'X';
		PutResInBoard(res, ch, ch2, mark);
		PrintBoard(res);
		win = whowon(res, mark);
		if (win == 0) //Player 2 (O)
		{
			while (flag == false)
			{
				cout << "Player Number 2 (O)\n";
				cout << "Please enter cell input (for expample C3)\n";
				cin >> ch >> ch2;
				flag = CheckInput(res, ch, ch2);
			}
			flag = false;
			mark = 'O';
			PutResInBoard(res, ch, ch2, mark);
			PrintBoard(res);
			win = whowon(res, mark);
		}
	}
}
