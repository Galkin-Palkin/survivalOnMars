//
// Created by wildt on 14.02.2021.
//

#include "Game.h"
#include <fstream>
#include <string>

Game::Action::Action(ifstream & fin) {
	int size;
	fin >> size;
	textToPrint.resize(size);
	for (int i = 0; i < size; ++i) {
		getline(fin, textToPrint[i]);
	}
}

void Game::Action::Print() {
	for (auto text : textToPrint) {
		cout << text << "\n";
	}
}
