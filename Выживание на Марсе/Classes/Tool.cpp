#include "Game.h"
#include <fstream>

void Game::Tool::SetParameters(string Type, string Name, double Weight, int Damage, int Chance, string Path) {
	this->Type = Type;
	this->Name = Name;
	this->Weight = Weight;
	this->Damage = Damage;
	this->ChanceToFind = Chance;
	if (Path != "") {
		ifstream fin(Path);
		int Size;
		fin >> Size;
		Specialisation.resize(Size);
		for (int i = 0; i < Size; i++)
			cin >> Specialisation[i].first >> Specialisation[i].second;
	}
}

int Game::Tool::Attack() {
	Durability -= BreakPerUse;
	if (Durability <= 0.0)
		Tools[Type].erase(Tools[Type].begin() + Tools[Type].size() - 1);
	if (!Tools[Type].size())
		Tools.erase(Type);
	return Damage;
}

void Game::Tool::SetNew(int Count) {
	Durability = 10.0 + (double)(rand() % 910) / 10.0;
	BreakPerUse = 1.0 + (double)(rand() % 61) / 10.0;
}
string Game::Tool::GetType() {
	return Type;
}

int Game::Tool::GetChance() {
	return ChanceToFind;
}
string Game::Tool::GetName() {
	return Name;
}