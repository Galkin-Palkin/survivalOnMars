#include "Game.h"
#include <map>
#include <fstream>
void Game::Saves::Load(Human& H, bool& IsExit) {
	// Загрузка в файл
	ifstream fin("Data\\Parameters.txt");
	string String;
	int Number;
	double NumberDouble;
	fin >> NewGame;
	fin >> Number;
	H.Set(hi_HP, 'N', Number);
	fin >> Number;
	H.Set(hi_FP, 'N', Number);
	fin >> Number;
	H.Set(hi_EP, 'N', Number);
	fin >> Number;
	H.Set(hi_PHP, 'N', Number); 
	fin >> NumberDouble;
	H.Set(hi_DP, 'N', 0, NumberDouble);
	fin >> Number;
	H.Set(hi_Sol, 'N', Number);
	fin >> Number;
	H.Set(hi_Hour, 'N', Number);
	fin >> Number;
	ConsumableCount = Number;
	for (int i = 0; i < ConsumableCount; i++) {
		fin >> String >> Number;
		ConsumableVector.push_back(&Game::ConsumableMap[String]);
		ConsumableVector[i]->SetCount(Number);
	}
	fin >> IsExit;
}
void Game::Saves::Download(Human& H, bool IsExit) {
	// Загрузка из файла
	ofstream fout("Data\\Do not open this file.txt");
	fout << NewGame << endl;
	fout << H.GetI(hi_HP) << endl;
	fout << H.GetI(hi_FP) << endl;
	fout << H.GetI(hi_EP) << endl;
	fout << H.GetI(hi_PHP) << endl;
	fout << H.GetD(hi_DP) << endl;
	fout << H.GetI(hi_Sol) << endl;
	fout << H.GetI(hi_Hour) << endl;
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