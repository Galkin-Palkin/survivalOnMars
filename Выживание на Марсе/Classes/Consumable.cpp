#include "Game.h"
bool Game::Consumable::Taking(Human& H) {
	// Употребление
	if (this->Count > 0) {
		if (this->FirstType != hi_DP) H.Set(this->FirstType, '+', this->FirstNumber);
		else H.Set(hi_DP, '+', 0, this->DFirstNumber);
		if (this->SecondType != hi_NULL) H.Set(this->SecondType, '+', this->SecondNumber);
		if (this->ThirdType != hi_NULL) H.Set(this->ThirdType, '+', this->ThirdNumber);
		this->Count--;
	}
	else return false;
	if (this->Count <= 0 && this->IsBeing) this->Clear();
	return true;
}
void Game::Consumable::SetNew(int Count) {
	// Добавление нового объекта
	if (!this->Count) {
		ConsumableVector.push_back(this);
		this->ID = ConsumableCount++;
		this->IsBeing = true;
	}
	this->Count += Count;
}
void Game::Consumable::Clear() {
	for (int i = 0; i < ConsumableCount; i++) {
		if ((*ConsumableVector[i]).ID > this->ID) (*ConsumableVector[i]).ID--;
	}
	ConsumableVector.erase(ConsumableVector.begin() + this->ID);
	ConsumableCount--;
	this->Count = 0;
	this->IsBeing = false;
}
void Game::Consumable::Show(Text& T) {
	// Показ списка
	system("cls");
	T.PRC(13, "Пища и медикаменты\n");
	T.V(4, 60);
	for (int i = 0; i < ConsumableCount; i++) {
		T.PRC(10, "[");
		T.PRC(15, "");
		cout << i + 1;
		T.PRC(10, "] ");
		T.PRC(1, (*ConsumableVector[i]).Name);
		T.PRC(6, " x");
		T.PRC(15, "");
		cout << (*ConsumableVector[i]).Count << "    ";
		cout << (*ConsumableVector[i]).Weight * (*ConsumableVector[i]).Count;
		T.PRC(8, " кг\n");
		if (i != ConsumableCount - 1) T.V(4, 50);
	}
	T.V(4, 60);
}
void Game::Consumable::Constructor(string Name, double Weight, HumanInfo FirstType, double FirstNumber, HumanInfo SecondType, int SecondNumber, HumanInfo ThirdType, int ThirdNumber) {
	// Обычный конструктор нельзя вызвать в классе вне функции, поэтому, такой аналог
	ConsumableCount = 0;
	this->FirstType = FirstType;
	this->DFirstNumber = FirstNumber;
	this->Name = Name;
	this->Weight = Weight;
	if (SecondType != hi_NULL && SecondNumber != -10000) {
		this->SecondType = SecondType;
		this->SecondNumber = SecondNumber;
	}
	if (ThirdType != hi_NULL && ThirdNumber != -10000) {
		this->ThirdType = ThirdType;
		this->ThirdNumber = ThirdNumber;
	}
}
void Game::Consumable::Constructor(string Name, double Weight, HumanInfo FirstType, int FirstNumber, HumanInfo SecondType, int SecondNumber, HumanInfo ThirdType, int ThirdNumber) {
	ConsumableCount = 0;
	this->FirstType = FirstType;
	this->FirstNumber = FirstNumber;
	this->Name = Name;
	this->Weight = Weight;
	if (SecondType != hi_NULL && SecondNumber != -10000) {
		this->SecondType = SecondType;
		this->SecondNumber = SecondNumber;
	}
	if (ThirdType != hi_NULL && ThirdNumber != -10000) {
		this->ThirdType = ThirdType;
		this->ThirdNumber = ThirdNumber;
	}
}