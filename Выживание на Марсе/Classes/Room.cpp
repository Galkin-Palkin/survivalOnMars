//
// Created by wildt on 14.02.2021.
//

#include "Game.h"


void Game::Room::Room(string filename) {
	ifstream fin(filename);
	int size;
	cin >> size;
	floorPlan.resize(size);
	for (int i = 0; i < size; ++i) {
		fin >> floorPlan[i];
	}
	fin >> size;
	roomToActions.resize(size);
	roomToName.resize(size);
	for (int i = 0; i < size; ++i) {
		fin >> roomToName[i];
		int countOfActions;
		fin >> countOfActions;
		for (int j = 0; j < size; ++j) {
			roomToActions[j].push_back(Action(fin));
		}
	}
}
void Game::Room::Print() {
	for (auto i : floorPlan)
		cout << i << "\n";
}

void Game::Room::PrintActions() {
	for (int i = 0; i < selectedRoom; ++i) {
		roomToActions[selectedRoom][i].Print();
	}
}