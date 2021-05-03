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
			fin >> Specialisation[i].first >> Specialisation[i].second;
	}
}

int Game::Tool::Attack() {
	Durability -= BreakPerUse;
	int Last = (Type == "Hand") ? 1 : (int)Tools[Type].size() - 1;
	string Temp = Type;
	if (Durability <= 0.0) {
		auto Iterator = Tools[Type].begin();
		Tools[Temp].erase(Iterator + Last);
		H->SetTool(&ToolMap["Hand"]);
	}
	if (!(Last + 1))
		Tools.erase(Temp);
	return Damage;
}

void Game::Tool::SetNew(int Count) {
	Durability = 10.0 + (double)(rand() % 901) / 10.0;
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

double Game::Tool::GetDurability() {
	return Durability;
}

double Game::Tool::GetBreakPerUse() {
	return BreakPerUse;
}

void Game::Tool::SetDurability(double Value) {
	Durability = Value;
}

void Game::Tool::SetBreakPerUse(double Value) {
	BreakPerUse = Value;
}

void Game::Tool::SetPointer(Human* HT, Inventory* IT) {
	H = HT;
	I = IT;
}
