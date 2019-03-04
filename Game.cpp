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

	std::cout << "\nYou are in " << this->GetCurrentRoomName() << std::endl;

	std::string temp = this->currentRoom->AcquireNextItem();
	
	if (temp != "") {

		std::cout << "Item(s) Collected:";
		
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

	return this->currentRoom->GetName();
}

void Game::LootRoom() {

	int numItems = this->currentItems.size();
	
	for (int i = 0; i < numItems; ++i) {

		this->player->AddItem(this->currentItems.at(i));
	}
}

bool Game::ValidDirection(std::string direction) {

	bool check = false;
	
	if (direction == "N") {
		check = this->currentRoom->GetNorthPassage()->IsOpen();
		if (!check && this->player->HasItem(this->currentRoom->GetNorthPassage()->GetRequiredKey())) {
			this->currentRoom->GetNorthPassage()->Open();
			this->maze->GetRoom(this->player->GetRow() - 1, this->player->GetCol())->GetSouthPassage()->Open();
			this->player->UseItem(this->currentRoom->GetNorthPassage()->GetRequiredKey());
			check = true;
		}
	}

	else if (direction == "E") {
		check = this->currentRoom->GetEastPassage()->IsOpen();
		if (!check && this->player->HasItem(this->currentRoom->GetEastPassage()->GetRequiredKey())) {
			this->currentRoom->GetEastPassage()->Open();
			this->maze->GetRoom(this->player->GetRow(), this->player->GetCol() + 1)->GetWestPassage()->Open();
			this->player->UseItem(this->currentRoom->GetEastPassage()->GetRequiredKey());
			check = true;
		}
	}

	else if (direction == "S") {
		check = this->currentRoom->GetSouthPassage()->IsOpen();
		if (!check && this->player->HasItem(this->currentRoom->GetSouthPassage()->GetRequiredKey())) {
			this->currentRoom->GetSouthPassage()->Open();
			this->maze->GetRoom(this->player->GetRow() + 1, this->player->GetCol())->GetNorthPassage()->Open();
			this->player->UseItem(this->currentRoom->GetSouthPassage()->GetRequiredKey());
			check = true;
		}
	}

	else if (direction == "W") {
		check = this->currentRoom->GetWestPassage()->IsOpen();
		if (!check && this->player->HasItem(this->currentRoom->GetWestPassage()->GetRequiredKey())) {
			this->currentRoom->GetWestPassage()->Open();
			this->maze->GetRoom(this->player->GetRow(), this->player->GetCol() - 1)->GetEastPassage()->Open();
			this->player->UseItem(this->currentRoom->GetWestPassage()->GetRequiredKey());
			check = true;
		}
	}

	return check;
}

void Game::MoveDirection(std::string direction) {
	
	if (ValidDirection(direction)) {

		if (direction == "N") {
			this->player->SetPosition(this->player->GetRow() - 1, this->player->GetCol());
		}
		else if (direction == "E") {
			this->player->SetPosition(this->player->GetRow(), this->player->GetCol() + 1);
		}
		else if (direction == "S") {
			this->player->SetPosition(this->player->GetRow() + 1, this->player->GetCol());
		}
		else if (direction == "W") {
			this->player->SetPosition(this->player->GetRow(), this->player->GetCol() - 1);
		}
		
		this->player->IncrementMoves();
		
		this->currentRoom = this->maze->GetRoom(this->player->GetRow(), this->player->GetCol());
	}
}

bool Game::ExitFound() {

	if (this->GetCurrentRoomName().find("Exit") != -1) {
		std::cout << "You made it out in " << this->player->GetMoveCount() << " moves.";
		this->maze->~Maze();
		return true;
	}

	return false;
}