#include"Maze.hpp"

void Maze::LoadMaze() {
	
	this->mazeFile >> this->rows;
	this->mazeFile >> this->cols;

	//multi-dimensional array builder - allocates space for Room pointers
	this->rooms = new Room*[this->rows];
	for (int i = 0; i < this->rows; ++i) {
		this->rooms[i] = new Room[this->cols];
	}

	std::string line;
	
	int rowCount = 0;
	int colCount = 0;

	std::string dump;
	std::getline(this->mazeFile, dump);

	do {
		
		std::getline(this->mazeFile, line);

		int pos = line.find(',');

		std::string name = line.substr(0, pos);

		std::string resizedLine = line.substr(pos + 1);

		pos = resizedLine.find(',');
		std::string northPassage = resizedLine.substr(0, pos);

		resizedLine = resizedLine.substr(pos + 1);

		pos = resizedLine.find(',');
		std::string eastPassage = resizedLine.substr(0, pos);

		resizedLine = resizedLine.substr(pos + 1);

		pos = resizedLine.find(',');
		std::string southPassage = resizedLine.substr(0, pos);

		resizedLine = resizedLine.substr(pos + 1);

		pos = resizedLine.find(',');
		std::string westPassage = resizedLine.substr(0, pos);

		resizedLine = resizedLine.substr(pos + 1);
		std::cout << "items: " << resizedLine << std::endl;

		this->rooms[rowCount][colCount] = Room(name, CreatePassage(northPassage), 
			CreatePassage(eastPassage),	CreatePassage(southPassage), 
			CreatePassage(westPassage));

		std::cout << "item line size: " << resizedLine.size() << std::endl;
		
		if (resizedLine.size() != 0) {

			pos = resizedLine.find(' ');

			if (pos != std::string::npos) {

				this->rooms[rowCount][colCount].AddItem(resizedLine.substr(0, pos));

				resizedLine = resizedLine.substr(pos + 1);

				do {

					resizedLine = resizedLine.substr(pos + 1);

					pos = resizedLine.find(' ');

					if (pos != std::string::npos) {

						this->rooms[rowCount][colCount].AddItem(resizedLine.substr(0, pos));

						resizedLine = resizedLine.substr(pos + 1);
					}

					else {
						
						this->rooms[rowCount][colCount].AddItem(resizedLine);
					}

				} while (pos != std::string::npos);
			}

			else {

				this->rooms[rowCount][colCount].AddItem(resizedLine);
			}
		}

		if (colCount == this->cols - 1) {
			colCount = 0;
			++rowCount;
		}
		else {
			++colCount;
		}
	} while ((rowCount != GetNumberRows()) && (colCount != GetNumberCols()));

	this->mazeFile.close();
}

Passage* Maze::CreatePassage(std::string type) {

	if (type.size() > 1) {

		//this value is a key needed to open passage
		return new Passage(false, type);

	}

	else {

		//makes a passage that is either a door or a wall
		if (type.compare("+")) {
			return new Passage(true);
		}

		else {
			return new Passage();
		}
	}
	
}

Maze::Maze(std::string mazeFile) {
	
	this->mazeFile.open((mazeFile).c_str());
	
	if (!this->mazeFile) {
		std::cout << "Could not open file " << mazeFile << std::endl;
	}
	else {
		LoadMaze();
	}
}

Room* Maze::GetRoom(int row, int col) {
	return &rooms[row][col];
}

int Maze::GetNumberRows() {

	return this->rows;
}

int Maze::GetNumberCols() {
	
	return this->cols;
}

Maze::~Maze() {

	for (int i = 0; i < this->cols; ++i) {
		delete[] this->rooms[i];
	}

	delete[] this;
}