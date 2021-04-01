#include "Game.h"
#include <map>
#include <fstream>
void Game::Saves::Load(Human& H, bool& IsExit) {
	// Загрузка в файл
	ifstream fin("Data\\Parameters.txt");
	string String;
	int Number, Temp;
	double NumberDouble;
	fin >> NewGame;
	fin >> Number;
	H.Set(HumanInfo::HP, 'N', Number);
	fin >> Number;
	H.Set(HumanInfo::FP, 'N', Number);
	fin >> Number;
	H.Set(HumanInfo::EP, 'N', Number);
	fin >> Number;
	H.Set(HumanInfo::PHP, 'N', Number);
	fin >> NumberDouble;
	H.Set(HumanInfo::DP, 'N', NumberDouble);
	fin >> Number;
	H.Set(HumanInfo::HalChance, 'N', Number);
	fin >> Number;
	H.Set(HumanInfo::Sol, 'N', Number);
	fin >> Number;
	H.Set(HumanInfo::Hour, 'N', Number);
	fin >> Number;
	ConsumableCount = Number;
	for (int i = 0; i < ConsumableCount; i++) {
		fin >> String >> Number;
		ConsumableVector.push_back(Game::ConsumableMap[String]);
		ConsumableVector[i]->SetCount(Number);
		ConsumableVector[i]->SetBeing();
		ConsumableVector[i]->SetID(i);
	}
	fin >> Number;
	BookVector.resize(Number);
	for (size_t i = 0; i < BookVector.size(); i++) {
		fin >> String >> Number >> Temp;
		BookVector[i] = BookMap[String];
		BookVector[i]->SetCount(Number);
		BookVector[i]->SetPagesCount(Temp);
		BookVector[i]->SetIsBeing(true);
	}
	fin >> Number;
	for (int i = 0; i < Number; i++) {
		fin >> Temp;
		IsAchMap[Temp] = true;
	}
	fin >> NightmareNumber;
	fin >> IsExit;
}
void Game::Saves::Download(Human& H, bool IsExit) {
	// Загрузка из файла
	ofstream fout("Data\\Parameters.txt");
	fout << NewGame << endl;
	fout << H.GetI(HumanInfo::HP) << endl;
	fout << H.GetI(HumanInfo::FP) << endl;
	fout << H.GetI(HumanInfo::EP) << endl;
	fout << H.GetI(HumanInfo::PHP) << endl;
	fout << H.GetD(HumanInfo::DP) << endl;
	fout << H.GetI(HumanInfo::HalChance) << endl;
	fout << H.GetI(HumanInfo::Sol) << endl;
	fout << H.GetI(HumanInfo::Hour) << endl;
	fout << ConsumableCount << endl;
	for (int i = 0; i < ConsumableCount; i++) {
		fout << ConsumableVector[i]->GetType() << endl;
		fout << ConsumableVector[i]->GetCount() << endl;
	}
	fout << BookVector.size() << endl;
	for (size_t i = 0; i < BookVector.size(); i++) {
		fout << BookVector[i]->GetType() << endl;
		fout << BookVector[i]->GetCount() << endl;
		fout << BookVector[i]->GetPagesCount() << endl;
	}
	fout << IsAchMap.size() << endl;
	for (auto i : IsAchMap)
		fout << i.first << endl;
	fout << NightmareNumber << endl;
	fout << IsExit << endl;
}
bool Game::Saves::GetNew() {
	return NewGame;
}
void Game::Saves::SetNew(bool Truelness) {
	NewGame = Truelness;
}