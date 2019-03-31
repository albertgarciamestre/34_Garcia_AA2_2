#include "Player.h"
#include "Constants.h"
Player::Player() {};

Player::Player(int start_posX, int start_posY) : position_x(start_posX), position_y(start_posY), score{ 0 } {
	// initialize the point queue
	while (queuePoints.size() > 0) queuePoints.pop();

	for (int i = 0; i < NUM_ROWS*NUM_COLUMNS; i++) {
		queuePoints.push(1);
	}
};

int Player::getPositionX() {
	return position_x;
}
int Player::getPositionY() {
	return position_y;
}

void Player::setPositionX(int _position_x) {
	position_x = _position_x;

}
void Player::setPositionY(int _position_y) {
	position_y = _position_y;

}

void Player::scorePoints() {
	score += queuePoints.front();
	queuePoints.pop();
}
int Player::getScore() {
	return score;
}
void Player::setScore(int _scores) {
	score = _scores;
}
bool Player::youWin() {
	return (queuePoints.empty());
}