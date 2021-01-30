#include "Game.h"
void Game::Instrument::Correcting() {
	if (this->Durability < 0.0) this->Durability = 0.0;
	if (this->Durability > 100.0) this->Durability = 100.0;
	if (this->Durability == 0.0 && this->Count > 0) {
		this->Count--;
		InstrumentsVector.pop_back();
	}
}
void Game::Instrument::Breaking() {
	this->Durability = 0.0;
	Correcting();
}
void Game::Instrument::PartBreaking(double Damage) {
	this->Durability -= Damage;
	Correcting();
}
void Game::Instrument::Repairing(double Heal) {
	this->Durability += Heal;
	Correcting();
}
void Game::Instrument::OnceUsing() {
	this->Durability -= BreakQualityPerUse;
	Correcting();
}
void Game::Instrument::SetNewInstrument(double Durability, double BreakQualityPerUse, double Damage) {
	// Добавление нового объекта в вектор для данного класса
	InstrumentsVector.resize(++Count);
	InstrumentsVector[Count - 1].Durability = Durability;
	InstrumentsVector[Count - 1].BreakQualityPerUse = BreakQualityPerUse;
	InstrumentsVector[Count - 1].Damage = Damage;
}
void Game::Instrument::Attack() {

}
void Game::Instrument::Clear() {
	InstrumentsVector.clear();
}
void Game::Instrument::Constructor(string Name, double Weight) {
	this->Name = Name;
	this->Weight = Weight;
}
Game::Instrument::Instrument() {

}