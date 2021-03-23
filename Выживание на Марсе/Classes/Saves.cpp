#include "Game.h"
#include <map>
#include <fstream>
void Game::Saves::Load(Human& H, bool& IsExit) {
	// �������� � ����
	ifstream fin("Data\\Parameters.txt");
	string String;
	int Number;
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
	H.Set(HumanInfo::Sol, 'N', Number);
	fin >> Number;
	H.Set(HumanInfo::Hour, 'N', Number);
	fin >> Number;
	ConsumableCount = Number;
	for (int i = 0; i < ConsumableCount; i++) {
		fin >> String >> Number;
		ConsumableVector.push_back(Game::ConsumableMap[String]);
		ConsumableVector[i]->SetCount(Number);
	}
	fin >> IsExit;
}
void Game::Saves::Download(Human& H, bool IsExit) {
	// �������� �� �����
	ofstream fout("Data\\Parameters.txt");
	fout << NewGame << endl;
	fout << H.GetI(HumanInfo::HP) << endl;
	fout << H.GetI(HumanInfo::FP) << endl;
	fout << H.GetI(HumanInfo::EP) << endl;
	fout << H.GetI(HumanInfo::PHP) << endl;
	fout << H.GetD(HumanInfo::DP) << endl;
	fout << H.GetI(HumanInfo::Sol) << endl;
	fout << H.GetI(HumanInfo::Hour) << endl;
	fout << ConsumableCount << endl;
	for (int i = 0; i < ConsumableCount; i++) {
		fout << ConsumableVector[i]->GetType() << endl;
		fout << ConsumableVector[i]->GetCount() << endl;
	}
	fout << IsExit << endl;
}
bool Game::Saves::GetNew() {
	return NewGame;
}
void Game::Saves::SetNew(bool Truelness) {
	NewGame = Truelness;
}