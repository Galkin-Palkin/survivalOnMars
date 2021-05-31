//
// Created by wildt on 14.02.2021.
//

#include "Game.h"
#include <fstream>
#include <string>

Game::Action::Action(ifstream& fin) {
	fin >> ws;
	getline(fin, Name);
	fin >> IsObstacle;
	if (IsObstacle) {
		fin >> ws;
		getline(fin, ObstacleType);
	}
	int size;
	string Temp;
	fin >> size;
	SearchingResult.resize(size);
	for (int i = 0; i < size; i++) {
		fin >> Temp >> SearchingResult[i].second;
		SearchingResult[i].first = (*ConsumableMap[Temp]).Null();
	}
	fin >> size;
	FoundedBooks.resize(size);
	for (int i = 0; i < size; i++) {
		fin >> Temp;
		FoundedBooks[i] = BookMap[Temp]->Common();
	}
	fin >> size;
	IsFound.resize(size, false);
	for (int i = 0; i < size; i++) {
		fin >> Temp;
		FoundedTools.push_back(ToolMap[Temp]);
	}
}

string Game::Action::GetName() {
	return Name;
}

void Game::Action::GenerateItems() {
	for (size_t i = 0; i < SearchingResult.size(); i++) {
		int Count = SearchingResult[i].second + 1 + (rand() % 10 == 0);
		for (int j = 0; j < Count; j++)
			if (SearchingResult[i].first.GetChance() - rand() % 101 >= 0)
				SearchingResult[i].first.SetCount(SearchingResult[i].first.GetCount() + 1);
	}

	for (size_t i = 0; i < FoundedBooks.size(); i++)
		if (FoundedBooks[i].GetChance() - rand() % 101 >= 0)
			FoundedBooks[i].SetCount(1);

	for (size_t i = 0; i < FoundedTools.size(); i++)
		if (FoundedTools[i].GetChance() - rand() % 101 >= 0)
			IsFound[i] = true;
}

void Game::Action::FoundedItems() {
	system("cls");
	T.PRC(1, "Вы нашли:\n");
	T.V(4, 60);
	bool IsEmpty = true;
	for (int i = 0; i < SearchingResult.size(); i++) {
		if (SearchingResult[i].first.GetCount() > 0) {
			IsEmpty = false;
			T.PRC(3, " - ");
			T.PRC(15, SearchingResult[i].first.GetName() + " (" + char(48 + SearchingResult[i].first.GetCount()) + ")\n");
			(*ConsumableMap[SearchingResult[i].first.GetType()]).SetNew(SearchingResult[i].first.GetCount());
			H->Set(HumanInfo::PHP, '+', 3 * SearchingResult[i].first.GetCount());
		}
	}
	for (size_t i = 0; i < FoundedBooks.size(); i++) {
		if (FoundedBooks[i].GetCount() > 0) {
			IsEmpty = false;
			T.PRC(3, " - ");
			T.PRC(15, FoundedBooks[i].GetName() + '\n');
			(*BookMap[FoundedBooks[i].GetType()]).SetNew(FoundedBooks[i].GetCount());
			H->Set(HumanInfo::PHP, '+', 5);
		}
	}
	for (size_t i = 0; i < FoundedTools.size(); i++) {
		if (IsFound[i]) {
			IsEmpty = false;
			T.PRC(3, " - ");
			T.PRC(15, FoundedTools[i].GetName() + '\n');
			string Temp = H->GetCurrentTool()->GetType();
			Tools[FoundedTools[i].GetType()].push_back(ToolMap[FoundedTools[i].GetType()]);
			Tools[FoundedTools[i].GetType()][Tools[FoundedTools[i].GetType()].size() - 1].SetNew();
			if (Temp == FoundedTools[i].GetType())
				H->SetTool(&Tools[FoundedTools[i].GetType()][Tools[FoundedTools[i].GetType()].size() - 2]);
			H->Set(HumanInfo::PHP, '+', 10);
		}
	}
	if (ConsumableMap["Aspirin"]->GetCount() >= 100 && !IsAchMap[Ach_Aspirin]) {
		ofstream fout("Data\\Achievements.txt", ofstream::app);
		fout << "Аспирин - панацея от всех болезней!\nСобрать 100 гранул аспирина\n";
		IsAchMap[Ach_Aspirin] = true;
	}
	if (ConsumableMap["DarkChocolateBar"]->GetCount() >= 4 && !IsAchMap[Ach_Chocolate]) {
		ofstream fout("Data\\Achievements.txt", ofstream::app);
		fout << "Шоколадная фабрика Вилли Вонки\nСобрать 4 плитки шоколада\n";
		IsAchMap[Ach_Chocolate] = true;
	}
	if (ConsumableMap["BartonsDrug"]->GetCount() >= 3 && !IsAchMap[Ach_Barton]) {
		ofstream fout("Data\\Achievements.txt", ofstream::app);
		fout << "Профессор Бартон знает своё дело\nСобрать 3 сыворотки\n";
		IsAchMap[Ach_Barton] = true;
	}
	if (ConsumableVector.size() >= 20 && !IsAchMap[Ach_Plushkin]) {
		ofstream fout("Data\\Achievements.txt", ofstream::app);
		fout << "Плюшкин\nСобрать 20 различных видов пищи и медикаментов\n";
		IsAchMap[Ach_Plushkin] = true;
	}
	if (BookVector.size() >= 4 && !IsAchMap[Ach_BookWorm]) {
		ofstream fout("Data\\Achievements.txt", ofstream::app);
		fout << "Книжный червь\nСобрать не менее 4 видов литературы\n";
		IsAchMap[Ach_BookWorm] = true;
	}
	if (IsEmpty) {
		T.PRC(3, "Вы ничего не нашли\n");
		H->Set(HumanInfo::PHP, '-', 3);
	}
	T.V(4, 60);
	T.PRC(15, "");
	system("pause");
}

string Game::Action::GetObstacleType() {
	return ObstacleType;
}

void Game::Action::SetPointer(Human* Temp) {
	H = Temp;
}

bool Game::Action::GetIsObstacle() {
	return IsObstacle;
}