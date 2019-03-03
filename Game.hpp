#ifndef GAME_HPP
#define GAME_HPP

#include<iostream>
#include<string>
#include<vector>

#include"Passage.hpp"
#include"Maze.hpp"
#include"Player.hpp"

class Game {
public:
	Game(Maze*, Player*);
	void DisplayItems();
	void DisplayPassages();
	std::string GetCurrentRoomName();
	void LootRoom();
	bool ValidDirection(std::string direction);
	void MoveDirection(std::string direction);
	bool ExitFound();

private:
	Maze* maze;
	Player* player;
	Room* currentRoom;
	std::vector<std::string> currentItems;

	std::string GetPassageDescription(Passage*);
};

#endif