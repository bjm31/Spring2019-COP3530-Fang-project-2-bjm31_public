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

	return "\nYou are in " + this->currentRoom->GetName() + "!\n";
}

void Game::LootRoom() {

	int numItems = this->currentItems.size();
	
	for (int i = 0; i < numItems; ++i) {

		this->player->AddItem(this->currentItems.at(i));
	}
}

bool Game::ValidDirection(std::string direction) {

	bool check = false;
	
	if (direction == "n") {
		check = this->currentRoom->GetNorthPassage()->IsOpen();
		if (!check && this->player->Hasitem(this->currentRoom->GetNorthPassage()->GetRequiredKey())) {
			this->currentRoom->GetNorthPassage()->Open();
			check = true;
		}
	}

	else if (direction == "e") {
		check = this->currentRoom->GetEastPassage()->IsOpen();
		if (!check && this->player->Hasitem(this->currentRoom->GetEastPassage()->GetRequiredKey())) {
			this->currentRoom->GetEastPassage()->Open();
			check = true;
		}
	}

	else if (direction == "s") {
		check = this->currentRoom->GetSouthPassage()->IsOpen();
		if (!check && this->player->Hasitem(this->currentRoom->GetSouthPassage()->GetRequiredKey())) {
			this->currentRoom->GetSouthPassage()->Open();
			check = true;
		}
	}

	else if (direction == "w") {
		check = this->currentRoom->GetWestPassage()->IsOpen();
		if (!check && this->player->Hasitem(this->currentRoom->GetWestPassage()->GetRequiredKey())) {
			this->currentRoom->GetWestPassage()->Open();
			check = true;
		}
	}

	return check;
}

void Game::MoveDirection(std::string direction) {
	
	if (ValidDirection(direction)) {

		if (direction == "n") {
			this->player->SetPosition(this->player->GetRow() - 1, this->player->GetCol());
		}
		else if (direction == "e") {
			this->player->SetPosition(this->player->GetRow(), this->player->GetCol() + 1);
		}
		else if (direction == "s") {
			this->player->SetPosition(this->player->GetRow() + 1, this->player->GetCol());
		}
		else if (direction == "w") {
			this->player->SetPosition(this->player->GetRow(), this->player->GetCol() - 1);
		}
		
		this->player->IncrementMoves();
		
		this->currentRoom = this->maze->GetRoom(this->player->GetRow(), this->player->GetCol());
	}

}

bool Game::ExitFound() {

	if (this->GetCurrentRoomName().find("Exit") != -1) {
		std::cout << "You made it out in " << this->player->GetMoveCount() << " moves.";
		return true;
	}

	return false;
}