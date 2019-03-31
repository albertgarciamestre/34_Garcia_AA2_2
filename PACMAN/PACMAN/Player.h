#include <queue>
class Player
{
	int position_x;
	int position_y;
	int score;
	std::queue<int> queuePoints;

public:
	Player();
	Player(int start_posX, int start_posY);

	int getPositionX();
	int getPositionY();
	void setPositionX(int _position_X);
	void setPositionY(int _position_y);
	int getScore();
	void setScore(int _scores);
	void scorePoints();
	bool youWin();
		

};