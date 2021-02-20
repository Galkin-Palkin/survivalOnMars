#include "Game.h"
#include <fstream>
#include <string>

Game::Room::Room(string filename) {
	ifstream fin(filename);
	int size;
	fin >> size;
	floorPlan.resize(size);
	for (int i = 0; i < size; ++i) {
		getline(fin, floorPlan[i]);
	}
	fin >> size;
	roomToActions.resize(size);
	roomToName.resize(size);
	for (int i = 0; i < size; ++i) {
		fin >> roomToName[i];
		int countOfActions;
		fin >> countOfActions;
		for (int j = 0; j < countOfActions; ++j) {
			roomToActions[j].emplace_back(Action(fin));
		}
	}
}
void Game::Room::Print() {
	for (auto i : floorPlan)
		cout << i << "\n";
	//PrintActions();
}

void Game::Room::PrintActions() {
	for (int i = 0; i < selectedRoom; ++i) {
		roomToActions[selectedRoom][i].Print();
	}
}

void Game::Room::PrintRooms(){
	for (auto i : roomToName)
		cout << i << "\n";
	cout << "\n";
}

void Game::Room::SelectRoom(int index) {
	selectedRoom = index;
}

void Game::Room::AddRoomsTo(vector<string>& arr) {
	for (auto i : roomToName)
		arr.push_back(i);
}