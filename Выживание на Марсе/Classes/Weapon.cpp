#include "Game.h"

void Game::Weapon::SetParameters(string Type, string Name, double Weight, int Damage) {
	this->Type = Type;
	this->Name = Name;
	this->Weight = Weight;
	this->Damage = Damage;
}

int Game::Weapon::Attack() {

	Durability -= BreakPerUse;
	if (Durability <= 0.0) {

	}
	return Damage;
}

void Game::Weapon::SetNew(int Count) {

}
