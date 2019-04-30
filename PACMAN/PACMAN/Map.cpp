#include "Map.h"
#include <sstream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <iostream>
#include <queue>
#include <time.h>


Map::Map() {
	fileRead();
	player = Player(9,11);
	//  initialize the score to zero
	player.setScore(0);
	

}
void Map::playerInit() {
	
}

void Map::fileRead()
{
	std::ifstream inFile;

	char coma1;

	inFile.open("Config.txt");
	if (!inFile)
	{
		std::cout << "unable to open file C.txt for reading" << std::endl;    
	}

	inFile >> NumColumns >> coma1 >> NumRows >> coma1;                       
	map = new char*[NumColumns];
	for (int i = 0; i < NumColumns; i++)
	{
		map[i] = new char[NumRows];
	}

	std::string dump;
	std::getline(inFile, dump, '\n');
	for (int i = 0; i < NumColumns; ++i)
	{
		inFile.std::istream::getline(map[i], NumColumns, '\n');
	}
#pragma endregion

	inFile.close();
}
void Map::setPlayer() {
	//player = Player(playerInitY, playerInitX);

	player.setPositionX(player.getPositionX());
	player.setPositionY(player.getPositionY());

	map[player.getPositionY()][player.getPositionX()] = '>';

}
void Map::print()
{

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	// reposition the cursor at the start of the console to repaint without erasing (avoiding flickering or flashing)
	SetConsoleCursorPosition(console, { 0,0 });



	for (int i = 0; i < NumColumns; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < NumRows; j++)
		{
			switch (map[i][j])
			{
			case ' ':
				SetConsoleTextAttribute(console, 1);
				std::cout << ' ';
				break;
			case '&':
				SetConsoleTextAttribute(console, 3);
				std::cout << '&';
				break;
			case '#':
				SetConsoleTextAttribute(console, 5);
				std::cout << '#';
				break;
			case '$':
				SetConsoleTextAttribute(console, 8);
				std::cout << '$';
				break;
			case 'X':
				SetConsoleTextAttribute(console, 1);
				std::cout << char(219);
				break;
			case '*':
				dots++;
				SetConsoleTextAttribute(console, 15);
				std::cout << '*' ;
				break;
			case '>':
				SetConsoleTextAttribute(console, 10);
		
				std::cout << '>';
				break;
			default: SetConsoleTextAttribute(console, 1); break;
			}
		}
	}
	SetConsoleTextAttribute(console, 1);
	std::cout << std::endl;
	SetConsoleTextAttribute(console, 11);
	std::cout << "Score: " << player.getScore()<<std::endl; 
	std::cout << std::endl;
	player.getLives();
	
}

void Map::countDots()
{
	for (int i = 0; i < NumColumns; i++)
	{
		for (int j = 0; j < NumRows; j++)
		{
			if (map[i][j] == '*')
			{
				//player.setScore(score++);
			}
		}
	}
}

/*void Map::updatePlayerPos(int x, int y, Inputs mov)
{
	map[x][y] = '>';
	if (y <= 0)
	{
		map[x][NumRows - 1] = ' ';
	}
	if (y >= NumRows)
	{
		map[x][0] = ' ';
	}

	switch (mov)
	{
	case LEFT:
		map[x][y + 1] = ' ';
		break;
	case RIGHT:
		map[x][y - 1] = ' ';
		break;
	case UP:
		map[x + 1][y] = ' ';
		break;
	case DOWN:
		map[x - 1][y] = ' ';
		break;
	}
}*/
void Map::makeMove(int move) {
	// clean
	if (move == Inputs::RIGHT) {
		map[player.getPositionY()][player.getPositionX()] = ' ';
	}
	else if (move == Inputs::LEFT) {
		 map[player.getPositionY()][player.getPositionX()] = ' ';
	}
	else if (move == Inputs::UP) {
		map[player.getPositionY()][player.getPositionX()] = ' ';
	}
	else if (move == Inputs::DOWN) {
		map[player.getPositionY()][player.getPositionX()] = ' ';
	}

	// movement player
	if (move == Inputs::DOWN) {
		if (map[player.getPositionY() + 1][player.getPositionX()] == 'X')
		{
			player.setPositionY(player.getPositionY()); player.setPositionX(player.getPositionX()); 
			//std::cout << player.getPositionX();
		}
		else {
			if (map[player.getPositionY() + 1][player.getPositionX()] == '*') {
				player.scorePoints();
			}
			player.setPositionY(player.getPositionY() + 1); player.setPositionX(player.getPositionX()); 
			//std::cout << player.getPositionX() << " " << player.getPositionY();
		}
	} else if (move == Inputs::UP){
		if (map[player.getPositionY() - 1 ][player.getPositionX()] == 'X')
		{
			player.setPositionY(player.getPositionY()); player.setPositionX(player.getPositionX());
		}
		else {
			if (map[player.getPositionY() - 1][player.getPositionX()] == '*') {
				player.scorePoints();
			}
			player.setPositionY(player.getPositionY() - 1); player.setPositionX(player.getPositionX() ); 
			//std::cout << player.getPositionX() << " " << player.getPositionY();
		}
		
	} else if (move == Inputs::LEFT) {
		if (map[player.getPositionY()][player.getPositionX()-1 ] == 'X')
		{
			player.setPositionY(player.getPositionY()); player.setPositionX(player.getPositionX());
		}
		else {
			if (map[player.getPositionY()][player.getPositionX() - 1] == '*'){
				player.scorePoints();	
			}
			player.setPositionY(player.getPositionY()); player.setPositionX(player.getPositionX() - 1); 
			//std::cout << player.getPositionX() <<" "<<  player.getPositionY();
		}
		
	}
	else if (move == Inputs::RIGHT) {
		if (map[player.getPositionY()][player.getPositionX()+1] == 'X')
		{
			player.setPositionY(player.getPositionY()); player.setPositionX(player.getPositionX());
		}
		else {
			if (map[player.getPositionY()][player.getPositionX()+1] == '*'){
				player.scorePoints();
			}
			player.setPositionY(player.getPositionY()); player.setPositionX(player.getPositionX() + 1); 
			//std::cout << player.getPositionX() << " " << player.getPositionY();
		}
		
	}

	setPlayer();
	
}



int Map::getNumRows() {
	return NumRows;
}

int Map::getNumColumns() {
	return NumColumns;
}



