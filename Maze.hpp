#ifndef MAZE_HPP
#define MAZE_HPP

#include<iostream>
#include<string>
#include<fstream>

#include"Room.hpp"
#include"Passage.hpp"

class Maze {
public:
	Maze(std::string mazeFile);
	Room* GetRoom(int row, int col);
	int GetNumberRows();
	int GetNumberCols();

	~Maze();

private:
	Room** rooms;
	int rows;
	int cols;

	std::ifstream mazeFile;

	void LoadMaze();
	Passage* CreatePassage(std::string type);
};

#endif