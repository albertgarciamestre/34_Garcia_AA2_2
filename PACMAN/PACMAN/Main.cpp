#include "Map.h"
#include "Types.h"
#include <stdio.h>
#include <time.h>
#include <conio.h>

bool Keyboard[8]{ 0 };

char showMessage(const HANDLE &console, const int &width, const int &height, const std::string &message, int color, bool askForConfirmation = true) {
	SetConsoleCursorPosition(console, { (short)(width / 2 - message.length() / 2 + 1), (short)(height / 2 + 1) });
	SetConsoleTextAttribute(console, color);
	std::cout << message;
	char confirm = ' ';
	while (askForConfirmation && (confirm != 's') && (confirm != 'n')) {
		confirm = _getch();
	}
	return confirm;
}
void showCursor(const HANDLE &console, bool show) {
	// Amaguem el cursor de la consola
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = false;
	cursor.dwSize = 25;
	SetConsoleCursorInfo(console, &cursor);
}
void getInput() {
	Keyboard[(int)InputKey::ESC] = GetAsyncKeyState(VK_ESCAPE);
	Keyboard[(int)InputKey::UP] = GetAsyncKeyState(VK_UP);
	Keyboard[(int)InputKey::DOWN] = GetAsyncKeyState(VK_DOWN);
	Keyboard[(int)InputKey::RIGHT] = GetAsyncKeyState(VK_RIGHT);
	Keyboard[(int)InputKey::LEFT] = GetAsyncKeyState(VK_LEFT);
	Keyboard[(int)InputKey::SPACE] = GetAsyncKeyState(VK_SPACE);
	Keyboard[(int)InputKey::PAUSE] = GetAsyncKeyState('p');
}

int main(int, char *[])
{
	
	bool start = false;
	bool pause = false;

	Map board = Map();
	int numRows = board.getNumRows();
	int numColumns = board.getNumColumns();

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	showCursor(console, false);

	std::cout << "*-*-*Init*-*-*"<<std::endl;
	std::cout << "Press space to start the game." << std::endl;

	
	while (1)
	{
		
		//INPUT
		getInput();
		if (Keyboard[(int)InputKey::LEFT])
			board.makeMove(Inputs::LEFT);
		else if (Keyboard[(int)InputKey::RIGHT])
			board.makeMove(Inputs::RIGHT);
		else if (Keyboard[(int)InputKey::DOWN])
			board.makeMove(Inputs::DOWN);
		else if (Keyboard[(int)InputKey::UP])
			board.makeMove(Inputs::UP);
		else if (Keyboard[(int)InputKey::SPACE])
			start = true;
		else if (Keyboard[(int)InputKey::PAUSE])
			pause = true;
		else if (Keyboard[(int)InputKey::ESC])
			break;
		
		//UPDATE
		if (start) {
			
			
			if (pause) {
				board.print();
				Sleep(300);
				std::cout<<"P A U S E";
				Sleep(300);
				
			}
			//DRAW
			board.print();

			//FPS
			Sleep(10);	// value in miliseconds for the movement
		}

		
	}
	
	showCursor(console, true);

	system("CLS");
	std::cout << "ADEU, TORNA AVIAT!" << std::endl;
	system("pause");

	return 0;
}