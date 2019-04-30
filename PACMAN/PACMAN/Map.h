#include "Player.h"
#include <fstream>
#include <string>
#include <Windows.h>
#include <iostream>
#include <time.h>
#include <queue>

const int NUM_ROWS{ 20 };
const int NUM_COLUMNS{ 20 };


enum Inputs { LEFT , RIGHT, UP , DOWN  };


class Map {

	char **map;
	int NumRows;
	int NumColumns;
	int linePlayer;	// line where the player goes
	Player player;
	int playerInitX;
	int playerInitY;
	int score;
	int dots;
	bool clean;
	
	

public:

	Map();

	void fileRead();
	void print();

	int getNumColumns();

	int getNumRows();

	void makeMove(int move);
	void countDots();
	void playerInit();
	void updatePlayerPos(int x, int y, Inputs mov);

	bool youWin();

	void setPlayer();
	


};