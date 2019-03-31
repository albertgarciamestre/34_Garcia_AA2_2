#include "Player.h"
#include <fstream>
#include <string>
#include <Windows.h>
#include <iostream>
#include <time.h>
#include <queue>

const int NUM_ROWS{ 20 };
const int NUM_COLUMNS{ 20 };


enum MovementX { LEFT , RIGHT  };
enum MovementY { UP=2 , DOWN  };


class Map {

	char **map;
	int numRows;
	int numColumns;
	int linePlayer;	// line where the player goes
	Player player;
	

public:

	Map();


	void printMap();

	int getNumColumns();

	int getNumRows();

	void makeMove(int move);


	bool youWin();

	void setPlayer();
	


};