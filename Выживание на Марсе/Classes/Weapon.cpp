#include "Game.h"

void Game::Weapon::SetParameters(string Type, string Name, double Weight, int Damage, double Durability, double BreakPerUse) {
	this->Type = Type;
	this->Name = Name;
	this->Weight = Weight;
	this->Damage = Damage;
	this->Durability = Durability;
	this->BreakPerUse = BreakPerUse;
}

void Game::Weapon::Attack() {

	Durability -= BreakPerUse;
	if (Durability <= 0.0) {

	}
}
