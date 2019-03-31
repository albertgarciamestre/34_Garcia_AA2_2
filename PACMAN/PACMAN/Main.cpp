#include "Map.h"
#include <stdio.h>
#include <time.h>
#include <conio.h>
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

int main(int, char *[])
{
	bool start = true;
	bool pause = false;

	Map board = Map();
	int numRows = board.getNumRows();
	int numColumns = board.getNumColumns();

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	showCursor(console, false);

	while (1)
	{

		Sleep(10);	// value in miliseconds for the movement
		board.printMap();

		/*if (board.youWin()) {
			showMessage(console, numColumns, numRows, "*-*-*-->YOU WIN!!!<--*-*-*", 14);
			//showMessage(console, numColumns, numRows + 2, "Score: " + std::to_string(map.getScore()), 9);
			if ((showMessage(console, numColumns, numRows + 4, "Vols tornar a jugar? (s/n)", 15, false) == 's')) {
				start = true;
				board.InitializeMap();
				continue;
			}
			else
				break;
		}
			
		}*/
		if (GetAsyncKeyState('P') && start) {
			pause = !pause;
		}
		if (pause) {
			board.printMap();
			Sleep(300);
			showMessage(console, numColumns, numRows, "P A U S E", 15);
			Sleep(300);
			continue;
		}

		if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
			board.makeMove(MovementX::LEFT);
		else if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
			board.makeMove(MovementX::RIGHT);
		else if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
			board.makeMove(MovementY::UP);
		else if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
			board.makeMove(MovementY::DOWN);
		else  if (GetAsyncKeyState(VK_SPACE))
			start = true;
		else  if (GetAsyncKeyState(VK_ESCAPE))
			if (showMessage(console, numColumns, numRows, "Segur que vols sortir? (s/n)", 15, true) == 's') break;
	}
	
	showCursor(console, true);

	system("CLS");
	std::cout << "ADEU, TORNA AVIAT!" << std::endl;
	system("pause");

	return 0;
}