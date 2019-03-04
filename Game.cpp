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
}

void Game::DisplayItems() {

	std::cout << "You are in " << GetCurrentRoomName() << std::endl;

	std::string temp = this->currentRoom->AcquireNextItem();
	
	if (temp != "") {

		std::cout << "Current Room Items Collected:";
		
		do {

			this->currentItems.push_back(temp);

			std::cout << " " << temp;
			
			temp = this->currentRoom->AcquireNextItem();

		} while (temp != "");

		std::cout << std::endl;

		LootRoom();
	}
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

	int numItems = this->currentItems.size();
	
	for (int i = 0; i < numItems; ++i) {

		this->player->AddItem(this->currentItems.at(i));
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