#include "Game.h"
void Game::Book::SetParametrs(string Type, string Name, double Weight, int Chance, int PagesCount, HumanInfo FirstType, int FirstNumber, HumanInfo SecondType, int SecondNumber, HumanInfo ThirdType, int ThirdNumber) {
	this->Constructor(Type, Name, Weight, Chance, FirstType, FirstNumber, SecondType, SecondNumber, ThirdType, ThirdNumber);
	this->PagesCount = PagesCount;
	TotalPagesCount = PagesCount;
}
bool Game::Book::Taking() {
	if (!PagesCount) Count--;
	if (this->Count > 0 && PagesCount > 0) {
		(*H).Set(this->FirstType, '+', this->FirstNumber);
		if (this->SecondType != HumanInfo::Null) (*H).Set(this->SecondType, '+', this->SecondNumber);
		if (this->ThirdType != HumanInfo::Null) (*H).Set(this->ThirdType, '+', this->ThirdNumber);
		this->PagesCount -= 25;
		if (PagesCount <= 0) this->Count--;
		EffectsToHuman();
	}
	else return false;
	if (this->Count <= 0 && this->IsBeing) this->Clear();
	return true;
}
void Game::Book::Clear() {
	for (size_t i = 0; i < BookVector.size(); i++) {
		if ((*BookVector[i]).GetID() > this->ID) (*BookVector[i]).GetIDP()--;
	}
	BookVector.erase(BookVector.begin() + this->ID);
	this->Count = 0;
	this->IsBeing = false;
}
void Game::Book::SetNew(int Count) {
	if (!this->Count) {
		BookVector.push_back(this);
		this->ID = BookVector.size() - 1;
	}
	this->IsBeing = true;
	this->Count += Count;
}
Game::Book Game::Book::Common() {
	Book Temp = *this;
	Temp.Count = 0;
	Temp.PagesCount = Temp.TotalPagesCount;
	return Temp;
}
int Game::Book::GetPagesCount() {
	return PagesCount;
}
Game::Book& Game::Book::SetPagesCount(int Value) {
	PagesCount = Value;
	return *this;
}
int Game::Book::GetTotalPagesCount() {
	return TotalPagesCount;
}
void Game::Book::SetIsBeing(bool Temp) {
	IsBeing = Temp;
}