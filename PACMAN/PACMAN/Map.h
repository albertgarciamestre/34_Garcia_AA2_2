#include "Player.h"
#include <fstream>
#include <string>
#include <Windows.h>
#include <iostream>
#include <time.h>

const int NUM_ROWS{ 20 };
const int NUM_COLUMNS{ 20 };


enum Movement { LEFT = -1, RIGHT = 1,UP= -1,DOWN=-1 };


class Map {

	char **map;
	int numRows;
	int numColumns;
	//std::queue<int> Points;
	int score;



public:

	Map();
	
	void InitializeMap();

	void printMap();

	int getNumColumns();

	int getNumRows();

	

private:
	
};