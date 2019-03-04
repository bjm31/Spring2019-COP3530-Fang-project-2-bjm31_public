#include<iostream>
#include<string>
#include<fstream>

#include"Maze.hpp"
#include"Player.hpp"
#include"Game.hpp"

using namespace std;

int main() {

	string mazeFile;

	cout << "Welcome to The Maze\n";
	/*
	cout << "Please enter the filename of your maze: ";
	cin >> mazeFile;
	*/

	mazeFile = "maze.txt";
	Maze* maze = new Maze(mazeFile);
	Player* player = new Player();

	Game game = Game(maze, player);
	std::cout << game.GetCurrentRoomName();
	game.DisplayItems();
	game.DisplayPassages();

	return 0;
}

