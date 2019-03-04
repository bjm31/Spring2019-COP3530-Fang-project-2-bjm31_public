#include"Player.hpp"

Player::Player() {
	this->row = 0;
	this->col = 0;
	this->moves = 0;
}

int Player::GetRow() {

	return this->row;
}

int Player::GetCol() {

	return this->col;
}

void Player::SetPosition(int row, int col) {
	
	this->row = row;
	
	this->col = col;
}

void Player::AddItem(std::string item) {
	
	this->items.push_back(item);
}

bool Player::Hasitem(std::string item) {

	for (int i = 0; i < this->items.size(); ++i) {
		if (this->items.at(i) == item) {
			return true;
		}
	}

	std::cout << "Have not obtained the " << item << " yet!\n";
	return false;
}

void Player::UseItem(std::string item) {

	for (int i = 0; i < this->items.size(); ++i) {
		if (this->items.at(i) == item) {
			this->items.erase(items.begin() + i);
		}
	}
}

int Player::GetMoveCount() {

	return this->moves;
}

void Player::incrementMoves() {

	++this->moves;
}