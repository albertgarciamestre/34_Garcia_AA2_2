#include "Map.h"
#include <sstream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <iostream>
#include <queue>
#include <time.h>


Map::Map() {
	// initialize attributes
	std::ifstream fileConfig("config.txt");

	if (fileConfig.is_open()) {

		std::string firstLine;
		fileConfig >> firstLine;
		size_t prev = 0, pos = 0;
		pos = firstLine.find(";", prev);
		numColumns = atoi((firstLine.substr(0, pos - prev)).c_str());
		prev = pos + 1;
		pos = firstLine.find(";", prev);
		numRows = atoi((firstLine.substr(prev, pos - prev)).c_str());

		//map
		std::string secondLine;
		std::string tablero;
		std::stringstream str;
		str << fileConfig.rdbuf();
		tablero = str.str();

		map = new char*[numRows + 1];
		for (int i = 0; i < numRows + 1; i++) {
			map[i] = new char[numColumns + 1];
		}

		int x{ 0 };
		int y{ 0 };

		for (auto& c : tablero)
		{
			map[x][y] = c;
			y++;
			if (y == numColumns) {
				y = 0;
				x++;
			}
		}
		fileConfig.close();

	}
	linePlayer = numRows-5;
	setPlayer();

}
void Map::InitializeMap()
{
	int i;


	player = Player(numColumns / 2);

	

	// Inicialitzem la cua de punts
	while (points.size() > 0) points.pop();		// Per a debuggar
	srand(time(NULL));
	for (int i = 0; i < numColumns; i++) {
		points.push((rand() % 5));
	}

	// Inicialitzem la puntuació a zero
	score = 0;
	setPlayer();

}



void Map::printMap() {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	// reposition the cursor at the start of the console to repaint without erasing (avoiding flickering or flashing)
	SetConsoleCursorPosition(console, { 0,0 });

	SetConsoleTextAttribute(console, 11);	
	std::cout << "Score--> " << score << "     " << std::endl;

	for (int i = 0; i < numRows+1 ; i++) {
		for (int j = 0; j < numColumns ; j++) {
					if (map[i][j] == 'X')
						SetConsoleTextAttribute(console, 16);
					else if (map[i][j] == '*')
						SetConsoleTextAttribute(console, 15);
					else if (map[i][j] == ' ')
						SetConsoleTextAttribute(console, 1);
					std::cout << map[i][j];
		}
		
	}
	std::cout << std::endl;
	
}
void Map::makeMove(int move) {
	// Esborrem "estela"
	/*if (move == Movement::RIGHT) {
		if (player.getPositionX() == 0) map[linePlayer][numColumns - 1] = ' ';
		else map[linePlayer][player.getPositionX() - 1] = ' ';
	}
	else if (move == Movement::LEFT) {
		if (player.getPositionX() == numColumns - 1) map[linePlayer][0] = ' ';
		else map[linePlayer][player.getPositionX() + 1] = ' ';
	}
	if (move == Movement::UP) {
		if (player.getPositionX() == 0) map[linePlayer][numColumns - 1] = ' ';
		else map[linePlayer][player.getPositionY()] = ' ';
	}
	else if (move == Movement::DOWN) {
		if (player.getPositionX() == numRows-1) map[linePlayer][0] = ' ';
		else map[linePlayer][player.getPositionY() + 1] = ' ';
	}*/
	if (move == Movement::RIGHT) {
		if (player.getPositionX() == 0) map[linePlayer][numColumns - 1] = ' ';
		else map[linePlayer][player.getPositionX() - 1] = ' ';
		
	}
	else if (move == Movement::LEFT) {
		if (player.getPositionX() == numColumns - 1) map[linePlayer][0] = ' ';
		else  map[linePlayer][player.getPositionX() + 1] = ' ';
	}
	/*if (move == Movement::UP) {
		map[linePlayer][player.getPositionY() - 1] = ' ';
	}
	else if (move == Movement::DOWN) {
	
	 map[linePlayer][player.getPositionY() + 1] = ' ';
	}*/
	player.setPosition(player.getPositionX() + move, player.getPositionY());


	//player.setPositionX((player.getPositionX() + move) % numColumns);
	setPlayer();
}
void Map::setPlayer() {
	

	map[linePlayer][player.getPositionX()] = '<';
}



int Map::getNumRows() {
	return numRows;
}

int Map::getNumColumns() {
	return numColumns;
}
/*int Map::getScore() {
	return score;
}*/

bool Map::youWin() {
	return (points.empty());
}
