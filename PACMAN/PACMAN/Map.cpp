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
	linePlayer = 16;
	player = Player(16,14);
	

	//  initialize the score to zero
	player.setScore(0);
	setPlayer();

}

void Map::printMap() {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	// reposition the cursor at the start of the console to repaint without erasing (avoiding flickering or flashing)
	SetConsoleCursorPosition(console, { 0,0 });

	SetConsoleTextAttribute(console, 11);	
	std::cout << "Score--> " << player.getScore() << "     " << std::endl;

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
	// clean
	if (move == MovementX::RIGHT) {
		map[player.getPositionY()][player.getPositionX()] = ' ';
	}
	else if (move == MovementX::LEFT) {
		 map[player.getPositionY()][player.getPositionX()] = ' ';
	}
	else if (move == MovementY::UP) {
		map[player.getPositionY()][player.getPositionX()] = ' ';
	}
	else if (move == MovementY::DOWN) {
		map[player.getPositionY()][player.getPositionX()] = ' ';
	}

	// movement player
	if (move == MovementY::DOWN) {
		if (map[player.getPositionY() + 1][player.getPositionX() - 1] == 'X')
		{
			player.setPositionY(player.getPositionY()); player.setPositionX(player.getPositionX()); 
		}
		else {
			if (map[player.getPositionY()+1][player.getPositionX() - 1] == '*') {
				player.scorePoints();
			}
			player.setPositionY(player.getPositionY() + 1); player.setPositionX(player.getPositionX() - 1); 
		}
	} else if (move == MovementY::UP){
		if (map[player.getPositionY() - 1][player.getPositionX() + 1] == 'X')
		{
			player.setPositionY(player.getPositionY()); player.setPositionX(player.getPositionX());
		}
		else {
			if (map[player.getPositionY()-1][player.getPositionX() + 1] == '*') {
				player.scorePoints();
			}
			player.setPositionY(player.getPositionY() - 1); player.setPositionX(player.getPositionX() + 1); 
		}
		
	} else if (move == MovementX::LEFT) {
		if (map[player.getPositionY()][player.getPositionX() - 1] == 'X')
		{
			player.setPositionY(player.getPositionY()); player.setPositionX(player.getPositionX());
		}
		else {
			if (map[player.getPositionY()][player.getPositionX() - 1] == '*'){
				player.scorePoints();	
			}
			player.setPositionY(player.getPositionY()); player.setPositionX(player.getPositionX() - 1); 
		}
		
	}
	else if (move == MovementX::RIGHT) {
		if (map[player.getPositionY()][player.getPositionX() + 1] == 'X')
		{
			player.setPositionY(player.getPositionY()); player.setPositionX(player.getPositionX());
		}
		else {
			if (map[player.getPositionY()][player.getPositionX() + 1] == '*'){
				player.scorePoints();
			}
			player.setPositionY(player.getPositionY()); player.setPositionX(player.getPositionX() + 1); 
		}
		
	}

	setPlayer();
	
}

void Map::setPlayer() {
	
	player.setPositionX(player.getPositionX());
	player.setPositionY(player.getPositionY());


	map[player.getPositionY()][player.getPositionX()] = '<';
	

}


int Map::getNumRows() {
	return numRows;
}

int Map::getNumColumns() {
	return numColumns;
}



