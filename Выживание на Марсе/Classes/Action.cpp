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
		SearchingResult[i] = (*ConsumableMap[Temp]).Null();
	}
	fin >> size;
	FoundedBooks.resize(size);
	for (int i = 0; i < size; i++) {
		fin >> Temp;
		FoundedBooks[i] = BookMap[Temp]->Common();
	}
}
string Game::Action::GetName() {
	return Name;
}
void Game::Action::GenerateItems() {
	for (int i = 0; i < SearchingResult.size(); i++) {
		if (SearchingResult[i].GetChance() - rand() % 101 >= 0) SearchingResult[i].SetCount(1 + (rand() % 10 == 0));
	}
	for (size_t i = 0; i < FoundedBooks.size(); i++) {
		if (FoundedBooks[i].GetChance() - rand() % 101 >= 0) FoundedBooks[i].SetCount(1);
	}
}
void Game::Action::FoundedItems() {
	system("cls");
	T.PRC(1, "�� �����:\n");
	T.V(4, 60);
	bool IsEmpty = true;
	for (int i = 0; i < SearchingResult.size(); i++) {
		if (SearchingResult[i].GetCount() > 0) {
			IsEmpty = false;
			T.PRC(3, " - ");
			T.PRC(15, SearchingResult[i].GetName() + " (" + char(48 + SearchingResult[i].GetCount()) + ")\n");
			(*ConsumableMap[SearchingResult[i].GetType()]).SetNew(SearchingResult[i].GetCount());
			H->Set(HumanInfo::PHP, '+', 3 * SearchingResult[i].GetCount());
		}
	}
	for (size_t i = 0; i < FoundedBooks.size(); i++) {
		if (FoundedBooks[i].GetCount() > 0) {
			IsEmpty = false;
			T.PRC(3, " - ");
			T.PRC(15, FoundedBooks[i].GetName() + " (" + char(48 + FoundedBooks[i].GetCount()) + ")\n");
			(*BookMap[FoundedBooks[i].GetType()]).SetNew(FoundedBooks[i].GetCount());
			H->Set(HumanInfo::PHP, '+', 5);
		}
	}
	if (ConsumableMap["Aspirin"]->GetCount() >= 100 && !IsAchMap[Ach_Aspirin]) {
		ofstream fout("Data\\Achievements.txt", ofstream::app);
		fout << "������� - ������� �� ���� ��������!\n������� 100 ������ ��������\n";
		IsAchMap[Ach_Aspirin] = true;
	}
	if (ConsumableMap["DarkChocolateBar"]->GetCount() >= 4 && !IsAchMap[Ach_Chocolate]) {
		ofstream fout("Data\\Achievements.txt", ofstream::app);
		fout << "���������� ������� ����� �����\n������� 4 ������ ��������\n";
		IsAchMap[Ach_Chocolate] = true;
	}
	if (ConsumableMap["BartonsDrug"]->GetCount() >= 3 && !IsAchMap[Ach_Barton]) {
		ofstream fout("Data\\Achievements.txt", ofstream::app);
		fout << "��������� ������ ����� ��� ����\n������� 3 ���������\n";
		IsAchMap[Ach_Barton] = true;
	}
	if (ConsumableVector.size() >= 20 && !IsAchMap[Ach_Plushkin]) {
		ofstream fout("Data\\Achievements.txt", ofstream::app);
		fout << "�������\n������� 20 ��������� ����� ���� � ������������\n";
		IsAchMap[Ach_Plushkin] = true;
	}
	if (BookVector.size() >= 4 && !IsAchMap[Ach_BookWorm]) {
		ofstream fout("Data\\Achievements.txt", ofstream::app);
		fout << "������� �����\n������� �� ����� 4 ����� ����������\n";
		IsAchMap[Ach_BookWorm] = true;
	}
	if (IsEmpty) {
		T.PRC(3, "�� ������ �� �����\n");
		H->Set(HumanInfo::PHP, '-', 3);
	}
	T.V(4, 60);
	T.PRC(15, "");
	system("pause");
}
void Game::Action::SetPointer(Human* Temp) {
	H = Temp;
}
