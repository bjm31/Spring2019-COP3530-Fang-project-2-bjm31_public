#include "Passage.hpp"

Passage::Passage() {

	this->isOpen = false;
	this->key = "";
}

Passage::Passage(bool isOpen) {
	
	this->isOpen = isOpen;
	this->key = "";
}

Passage::Passage(bool isOpen, std::string key) {
	
	this->isOpen = isOpen;
	this->key = key;
}

bool Passage::IsOpen() {

	return this->isOpen;
}

bool Passage::RequiresKey() {
	
	if (this->key != "") {
		return true;
	}

	return false;
}

std::string Passage::GetRequiredKey() {

	return this->key;
}

void Passage::Open() {

	this->isOpen = true;
}