#include"Game.hpp"

std::string Game::GetPassageDescription(Passage* passage) {

	std::string description;

	description = "There is a(n) ";

	if (passage->IsOpen()) {
		description += "open door to the ";
	}

	else if (passage->RequiresKey()) {
		description += "door that requires a(n) " + passage->GetRequiredKey() + " to the ";
	}

	else {
		description += "solid wall to the ";
	}

	return description;
}

Game::Game(Maze* maze, Player* player) {
	this->maze = maze;
	this->player = player;
	this->currentRoom = maze->GetRoom(0, 0);

	LootRoom();
}

void Game::DisplayItems() {

	std::cout << "You picked up the following room items:";
	int itemNum = this->currentItems.size();
	for (int i = 0; i < itemNum; ++i) {
		std::cout << " " << this->currentItems.at(i);
		this->player->AddItem(this->currentItems.at(i));
	}
	std::cout << std::endl;
}

void Game::DisplayPassages() {

	std::cout << GetPassageDescription(this->currentRoom->GetNorthPassage()) << "North\n";
	std::cout << GetPassageDescription(this->currentRoom->GetEastPassage()) << "East\n";
	std::cout << GetPassageDescription(this->currentRoom->GetSouthPassage()) << "South\n";
	std::cout << GetPassageDescription(this->currentRoom->GetWestPassage()) << "West\n";

}

std::string Game::GetCurrentRoomName() {

	return "You are in " + this->currentRoom->GetName() + "!\n";
}

void Game::LootRoom() {

	std::string temp = this->currentRoom->AcquireNextItem();

	while (temp != "") {
		std::cout << temp << std::endl;
		this->currentItems.push_back(temp);
		temp = this->currentRoom->AcquireNextItem();
		this->player->AddItem(temp);
	}
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