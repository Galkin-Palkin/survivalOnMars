#include "Game.h"

void Game::Weapon::SetParameters(string Type, string Name, double Weight, int Damage, int Chance) {
	this->Type = Type;
	this->Name = Name;
	this->Weight = Weight;
	this->Damage = Damage;
	this->ChanceToFind = Chance;
}

int Game::Weapon::Attack() {
	Durability -= BreakPerUse;
	if (Durability <= 0.0)
		Weapons[Type].erase(Weapons[Type].begin() + Weapons[Type].size() - 1);
	return Damage;
}

void Game::Weapon::SetNew(int Count) {
	Durability = 10.0 + (double)(rand() % 910) / 10.0;
	BreakPerUse = 1.0 + (double)(rand() % 61) / 10.0;
}
string Game::Weapon::GetType() {
	return Type;
}

int Game::Weapon::GetChance() {
	return ChanceToFind;
}
string Game::Weapon::GetName() {
	return Name;
}