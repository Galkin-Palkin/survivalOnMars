#include "Game.h"
#include <map>
#include <fstream>
#define EnemiesCount 5

void Game::Saves::Load(Human& H, bool& IsExit) {
	// �������� � ����
	ifstream fin("Data\\Parameters.txt");
	string String;
	int Number, Temp;
	double NumberDouble;
	fin >> NewGame;
	fin >> NightmareChance;
	fin >> Number;
	H.Set(HumanInfo::HP, '=', Number);
	fin >> Number;
	H.Set(HumanInfo::FP, '=', Number);
	fin >> Number;
	H.Set(HumanInfo::WP, '=', Number);
	fin >> Number;
	H.Set(HumanInfo::EP, '=', Number);
	fin >> Number;
	H.Set(HumanInfo::PHP, '=', Number);
	fin >> NumberDouble;
	H.Set(HumanInfo::DP, '=', NumberDouble);
	fin >> Number;
	H.Set(HumanInfo::HalChance, '=', Number);
	fin >> Number;
	H.Set(HumanInfo::Sol, '=', Number);
	fin >> Number;
	H.Set(HumanInfo::Hour, '=', Number);
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
	H.ClearEffects();
	fin >> Number;
	for (int i = 0; i < Number; i++) {
		fin >> String >> Temp;
		H.AddEffect(EffectMap[String].SetDuration(Temp));
	}
	fin >> NightmareNumber;
	for (int i = 0; i < EnemiesCount; i++) {
		fin >> Temp;
		SeenEnemies[i] = Temp;
	}
	fin >> Number;
	for (int i = 0; i < Number; i++) {
		fin >> String >> Temp;
		Tools[String].resize(Temp);
		for (int j = 0; j < Temp; j++) {
			Tools[String][j] = ToolMap[String];
			fin >> Tools[String][j];
		}
	}
	fin >> IsExit;
}

void Game::Saves::Download(Human& H, bool IsExit) {
	// �������� �� �����
	ofstream fout("Data\\Parameters.txt");
	fout << NewGame << endl;
	fout << NightmareChance << endl;
	fout << H.GetI(HumanInfo::HP) << endl;
	fout << H.GetI(HumanInfo::FP) << endl;
	fout << H.GetI(HumanInfo::WP) << endl;
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
	H.SaveEffects(fout);
	fout << NightmareNumber << endl;
	for (int i = 0; i < EnemiesCount; i++)
		fout << SeenEnemies[i] << endl;
	fout << Tools.size() << endl;
	for (auto& i : Tools) {
		fout << i.first << endl;
		fout << i.second.size() << endl;
		for (size_t j = 0; j < i.second.size(); j++)
			fout << i.second[j] << endl;
	}
	fout << IsExit << endl;
}

bool Game::Saves::GetNew() {
	return NewGame;
}

void Game::Saves::SetNew(bool Truelness) {
	NewGame = Truelness;
}