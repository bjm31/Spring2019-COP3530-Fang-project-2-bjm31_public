#include"Game.hpp"

std::string Game::GetPassageDescription(Passage* passage) {

	std::string description;

	description = "There is a(n) ";

	if (passage->IsOpen()) {
		description += "open door to the ";
	}

	else if (passage->RequiresKey()) {
		description += "doorway that requires a(n) " + passage->GetRequiredKey() + " to the ";
	}

	else {
		description += "solid wall to the ";
	}

	return description;
}

Game::Game(Maze* maze, Player* player) {
	this->maze = maze;
	this->player = player;
}

void Game::DisplayItems() {

	std::cout << "Room Items:";
	for (int i = 0; i < this->currentItems.size(); ++i) {
		std::cout << " " << currentItems.at(i);
	}
	std::cout << std::endl;
}

void Game::DisplayPassages() {

	Passage* tempPassage = this->maze->GetRoom(this->player->GetRow(), 
		this->player->GetCol())->GetNorthPassage();
}

std::string Game::GetCurrentRoomName() {

	return this->currentRoom->GetName();
}

void Game::LootRoom() {
	
}

bool Game::ValidDirection(std::string direction) {

	return false;
}

void Game::MoveDirection(std::string direction) {
	this->currentRoom = maze->GetRoom(player->GetRow(),
		player->GetCol());
}

bool Game::ExitFound() {

	return false;
}