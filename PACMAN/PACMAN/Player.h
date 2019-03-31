class Player
{
	int position_x;
	int position_y;

public:
	Player();
	Player(int start_pos);

	int getPositionX();
	int getPositionY();
	void setPosition(int _position_x, int _position_y);

};