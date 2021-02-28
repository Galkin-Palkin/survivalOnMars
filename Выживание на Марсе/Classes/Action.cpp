//
// Created by wildt on 14.02.2021.
//

#include "Game.h"
#include <fstream>
#include <string>

Game::Action::Action(ifstream &fin) {
	fin >> ws;
	getline(fin, Name);
	int size;
	string Temp;
	fin >> size;
	SearchingResult.resize(size);
	for (int i = 0; i < size; i++) {
		fin >> Temp;
		SearchingResult[i] = ConsumableMap[Temp];
	}
}
string Game::Action::GetName() {
	return Name;
}
void Game::Action::GenerateItems() {
	for (int i = 0; i < SearchingResult.size(); i++) {
		if (SearchingResult[i].GetChance() - rand() % 101 >= 0) SearchingResult[i].SetCount(1/* + (rand() % 10 == 0)*/);
	}
}
void Game::Action::FoundedItems() {
	system("cls");
	T.PRC(1, "Вы нашли:\n");
	T.V(4, 60);
	bool IsEmpty = true;
	for (int i = 0; i < SearchingResult.size(); i++) {
		if (SearchingResult[i].GetCount() > 0) {
			IsEmpty = false;
			T.PRC(3, " - ");
			T.PRC(15, SearchingResult[i].GetName() + " (" + char(48 + SearchingResult[i].GetCount()) + ")\n");
		}
	}
	if (IsEmpty) T.PRC(3, "Вы ничего не нашли\n");
	T.V(4, 60);
	T.PRC(15, "");
	system("pause");
}