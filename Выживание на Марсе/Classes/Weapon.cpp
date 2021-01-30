#include "Game.h"
Game::Weapon::Weapon() {

}
void Game::Weapon::Attack() {

}
void Game::Weapon::SetNew(int count) {

}
void Game::Weapon::Clear()  {
	WeaponVector.clear();
}
Game::Weapon::Weapon(string Name, double Weight) {
	this->Name = Name;
	this->Weight = Weight;
}