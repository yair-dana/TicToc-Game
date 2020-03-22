#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <iostream>
using namespace std;

void PrintBoard(char res[]); //Game Board
bool CheckInput(char res[], char ch, char ch2); //Input test
void PutResInBoard(char res[], char ch, char ch2, char mark); //Placing values ​​in the board
int whowon(char res[], char mark); //Check status of the game
void GameRotation(int &win, bool &flag, char& mark, char* res);

#endif // _FUNCTIONS_H_
