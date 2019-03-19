#include "Map.h"
#include <stdio.h>
#include <time.h>
#include <conio.h>

void showCursor(const HANDLE &console, bool show) {
	// Amaguem el cursor de la consola
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = false;
	cursor.dwSize = 25;
	SetConsoleCursorInfo(console, &cursor);
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

	while (1)
	{

		Sleep(10);	// value in miliseconds for the movement
		board.printMap();


	}
	showCursor(console, true);

	system("CLS");
	std::cout << "ADEU, TORNA AVIAT!" << std::endl;
	system("pause");

	return 0;
}