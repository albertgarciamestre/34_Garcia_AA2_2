#include "Player.h"

Player::Player() {};

Player::Player(int start_pos) : position_x(start_pos) {};

int Player::getPositionX() {
	return position_x;
}
int Player::getPositionY() {
	return position_y;
}

void Player::setPositionX(int _position_x, int _position_y) {
	position_x = _position_x;
	position_y = _position_y;
}