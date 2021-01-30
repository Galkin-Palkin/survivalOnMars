#include "Game.h"
#include <fstream>
void Game::Saves::Load(Human& H, bool& IsExit) {
	// �������� � ����
	ifstream fin("Do not open this file.txt");
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
	fin >> IsExit;
}
void Game::Saves::Download(Human& H, bool IsExit) {
	// �������� �� �����
	ofstream fout("Do not open this file.txt");
	fout << NewGame << endl;
	fout << H.GetI(hi_HP) << endl;
	fout << H.GetI(hi_FP) << endl;
	fout << H.GetI(hi_EP) << endl;
	fout << H.GetI(hi_PHP) << endl;
	fout << H.GetD(hi_DP) << endl;
	fout << H.GetI(hi_Sol) << endl;
	fout << H.GetI(hi_Hour) << endl;
	fout << IsExit << endl;
}
bool Game::Saves::GetNew() {
	return NewGame;
}
void Game::Saves::SetNew(bool Truelness) {
	NewGame = Truelness;
}