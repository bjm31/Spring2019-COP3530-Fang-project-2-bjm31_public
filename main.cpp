#include<iostream>
#include<string>
#include<fstream>

#include"Maze.hpp"
#include"Player.hpp"
#include"Game.hpp"

using namespace std;

int main() {

	string mazeFile;
	string direction;

	cout << "Welcome to The Maze\n";

	cout << "Please enter the filename of your maze: ";

	cin >> mazeFile;

	Game game = Game(new Maze(mazeFile), new Player());

	do {
		game.DisplayItems();
		game.DisplayPassages();

		cout << "Which way would you like to move? ";
		cin >> direction;

		game.MoveDirection(direction);

	} while (!game.ExitFound());

	return 0;
}

