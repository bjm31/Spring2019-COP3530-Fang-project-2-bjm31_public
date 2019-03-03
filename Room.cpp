#include"Room.hpp"

Room::Room() {

	this->name = "";
	/*
	this->northPassage = NULL;
	this->eastPassage = NULL;
	this->southPassage = NULL;
	this->westPassage = NULL;
	*/
}

Room::Room(std::string name, Passage* northPassage, Passage* eastPassage,
	Passage* southPassage, Passage* westPassage) {

	this->name = name;
	this->northPassage = northPassage;
	this->eastPassage = eastPassage;
	this->southPassage = southPassage;
	this->westPassage = westPassage;
}

std::string Room::GetName() {

	return this->name;
}

Passage* Room::GetNorthPassage() {

	return this->northPassage;
}

Passage* Room::GetEastPassage() {

	return this->eastPassage;
}

Passage* Room::GetSouthPassage() {

	return this->southPassage;
}

Passage* Room::GetWestPassage() {

	return this->westPassage;
}

void Room::AddItem(std::string item) {

	this->items.push_back(name);
}

std::string Room::AcquireNextItem() {

	std::string temp = "";
	
	if (this->items.size() != 0) {
		
		std::string temp = this->items.at(items.size() - 1);
		items.erase(items.begin());
	}

	return temp;
}