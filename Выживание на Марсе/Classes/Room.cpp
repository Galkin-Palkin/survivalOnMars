#include "Game.h"
#include <fstream>
#include <string>
#include <conio.h>

Game::Room::Room(string filename) {
	ifstream fin(filename);
	int size;
	fin >> size;
	floorPlan.resize(size);
	for (int i = 0; i < size; ++i) {
		getline(fin, floorPlan[i]);
	}
	fin >> ws;
	getline(fin, Info);
	fin >> size;
	roomToName.resize(size);
	roomToActions.resize(size);
	for (int i = 0; i < size; ++i) {
		fin >> ws;
		getline(fin, roomToName[i]);
		int countOfActions;
		fin >> countOfActions;
		for (int j = 0; j < countOfActions; j++) {
			roomToActions[i].emplace_back(Action(fin));
		}
	}
}
void Game::Room::Print() {
	for (auto i : floorPlan)
		cout << i << "\n";
	cout << '\n';
}
void Game::Room::AddRoomsTo(vector<string>& arr) {
	for (auto i : roomToName)
		arr.push_back(i);
}
string Game::Room::GetInfo() {
	return Info;
}
string Game::Room::GetName(int Index) {
	if (Index >= roomToName.size()) return "Выбрана несуществующая комната";
	return roomToName[Index];
}
void Game::Room::PrintRooms() {
	for (size_t i = 0; i < roomToName.size(); i++) {
		T.HV(1, i + 1, 15, roomToName[i]);
		if (roomToName.size() != i + 1) T.V(4, 40);
	}
}
void Game::Room::ActionChoose(vector<Action>& RoomPlacesVector) {
	while (true) {
		int Click = _getch(); // Считываем аскии-код символа. У единицы он 49, у двойки - 50 и так далее
		switch (Click) {
		case 49:
			if (RoomPlacesVector.size() < 1) break;
			RoomPlacesVector[0].GenerateItems();
			RoomPlacesVector[0].FoundedItems();
			RoomPlacesVector.erase(RoomPlacesVector.begin());
			return;
		case 50:
			if (RoomPlacesVector.size() < 2) break;
			RoomPlacesVector[1].GenerateItems();
			RoomPlacesVector[1].FoundedItems();
			RoomPlacesVector.erase(RoomPlacesVector.begin() + 1);
			return;
		case 51:
			if (RoomPlacesVector.size() < 3) break; // Проверка на то, есть ли достаточное количество мест для поиска в комнате
			RoomPlacesVector[2].GenerateItems();
			RoomPlacesVector[2].FoundedItems();
			RoomPlacesVector.erase(RoomPlacesVector.begin() + 2);
			return;
		case 52:
			if (RoomPlacesVector.size() < 4) break;
			RoomPlacesVector[3].GenerateItems();
			RoomPlacesVector[3].FoundedItems();
			RoomPlacesVector.erase(RoomPlacesVector.begin() + 3);
			return;
		}
	}
}
void Game::Room::SetActionVector(vector<Action> ActionVector, int Index) {
	roomToActions[Index] = ActionVector;
}
void Game::Room::PlaceClear(int Index) {
	roomToActions.erase(roomToActions.begin() + Index);
}
void Game::Room::operator=(Room R) {
	this->Info = R.Info;
	this->floorPlan = R.floorPlan;
	this->roomToName = R.roomToName;
}
vector<vector<Game::Action>> Game::Room::GetVectorAction() {
	return roomToActions;
}
void Game::Room::SetVectorAction(vector<vector<Action>> Temp) {
	this->roomToActions = Temp;
}
vector<Game::Action> Game::Room::GetRoomPlaces(int Index) {
	return roomToActions[Index];
}
void Game::Room::PlacePrint(vector<Action> PlacesVector, string RoomName) {
	system("cls");
	T.PRC(1, "Ты находишься в локации \"" + RoomName + "\"\n");
	T.V(4, 60);
	T.PRC(1, "Места для поиска:\n");
	T.V(4, 45);
	for (size_t i = 0; i < PlacesVector.size(); i++) {
		T.HV(3, i + 1, 15, PlacesVector[i].GetName());
		if (i + (size_t)1 < PlacesVector.size()) T.V(4, 30);
	}
	T.V(4, 60);
}