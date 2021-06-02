#include "Game.h"

bool Game::Consumable::Taking() {
	// Употребление
	if (this->Count > 0) {
		if (this->FirstType != HumanInfo::DP)
			(*H).Set(this->FirstType, '+', this->FirstNumber);
		else
			(*H).Set(HumanInfo::DP, '+', this->DFirstNumber);
		if (this->SecondType != HumanInfo::Null)
			(*H).Set(this->SecondType, '+', this->SecondNumber);
		if (this->ThirdType != HumanInfo::Null)
			(*H).Set(this->ThirdType, '+', this->ThirdNumber);
		this->Count--;
		EffectsToHuman();
	}
	else
		return false;
	if (this->Count <= 0 && this->IsBeing)
		Clear();
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
	for (int i = 0; i < ConsumableCount; i++)
		if ((*ConsumableVector[i]).GetID() > this->ID)
			(*ConsumableVector[i]).GetIDP()--;
	ConsumableVector.erase(ConsumableVector.begin() + this->ID);
	ConsumableCount--;
	this->Count = 0;
	this->IsBeing = false;
}

void Game::Consumable::Show(Text& T, size_t Page) {
	// Показ списка
	system("cls");
	T.PRC(13, "Пища и медикаменты\n");
	T.V(4, 60);
	int Size = (ConsumableCount - Page * 9 > 8) ? 9 : ConsumableCount - Page * 9;
	if (ConsumableCount < 9)
		Size = ConsumableCount;
	size_t TotalPage = (ConsumableCount % 9 == 0) ? ConsumableCount / 9 : ConsumableCount / 9 + 1;
	for (size_t i = 0; i < Size; i++) {
		T.PRC(10, "[");
		T.PRC(15);
		cout << i + 1;
		T.PRC(10, "] ");
		T.PRC(1, (*ConsumableVector[i + Page * (size_t)9]).GetName());
		T.PRC(6, " x");
		T.PRC(15);
		cout << (*ConsumableVector[i + Page * (size_t)9]).GetCount() << "    ";
		cout << (*ConsumableVector[i + Page * (size_t)9]).GetWeight() * (*ConsumableVector[i + Page * (size_t)9]).GetCount();
		T.PRC(8, " кг\n");
		if (i != (size_t)Size - 1)
			T.V(4, 50);
	}
	if (!Size)
		T.PRC(3, "Пища и медикаменты отсутствуют\n");
	T.V(4, 60);
	if (!Page && TotalPage > 1)
		T.PRC(15, "  ------------------->  \n");
	else if (Page == TotalPage - 1 && TotalPage > 1)
		T.PRC(15, "  <-------------------  \n");
	else if (Page > 0 && Page < TotalPage - 1)
		T.PRC(15, "  <-------------------                ------------------->  \n");
}

string Game::Consumable::GetType() {
	return this->Type;
}

int Game::Consumable::GetCount() {
	return this->Count;
}

void Game::Consumable::SetCount(int Value) {
	this->Count = Value;
}

void Game::Consumable::Constructor(string Type, string Name, double Weight, int Chance, Game::HumanInfo FirstType, double FirstNumber, HumanInfo SecondType, int SecondNumber, HumanInfo ThirdType, int ThirdNumber) {
	// Обычный конструктор нельзя вызвать в классе вне функции, поэтому есть такой аналог
	ConsumableCount = 0;
	this->Type = Type;
	this->FirstType = FirstType;
	this->DFirstNumber = FirstNumber;
	this->Name = Name;
	this->Weight = Weight;
	this->Chance = Chance;
	if (SecondType != HumanInfo::Null && SecondNumber != -10000) {
		this->SecondType = SecondType;
		this->SecondNumber = SecondNumber;
	}
	if (ThirdType != HumanInfo::Null && ThirdNumber != -10000) {
		this->ThirdType = ThirdType;
		this->ThirdNumber = ThirdNumber;
	}
}

void Game::Consumable::Constructor(string Type, string Name, double Weight, int Chance, HumanInfo FirstType, int FirstNumber, HumanInfo SecondType, int SecondNumber, HumanInfo ThirdType, int ThirdNumber) {
	ConsumableCount = 0;
	this->Type = Type;
	this->FirstType = FirstType;
	this->FirstNumber = FirstNumber;
	this->Name = Name;
	this->Weight = Weight;
	this->Chance = Chance;
	if (SecondType != HumanInfo::Null && SecondNumber != -10000) {
		this->SecondType = SecondType;
		this->SecondNumber = SecondNumber;
	}
	if (ThirdType != HumanInfo::Null && ThirdNumber != -10000) {
		this->ThirdType = ThirdType;
		this->ThirdNumber = ThirdNumber;
	}
}
void Game::Consumable::SetChance(int Value) {
	Chance = Value;
}
int Game::Consumable::GetChance() {
	return Chance;
}
string Game::Consumable::GetName() {
	return Name;
}
void Game::Consumable::SetName(string Name) {
	this->Name = Name;
}

Game::Consumable Game::Consumable::Null() {
	Consumable Temp = *this;
	Temp.Count = 0;
	return Temp;
}
void Game::Consumable::SetPointer(Game::Human* Temp) {
	H = Temp;
}
void Game::Consumable::AddEffect(Effect Ef) {
	GiveEffect.push_back(Ef);
}
int Game::Consumable::GetID() {
	return ID;
}
double Game::Consumable::GetWeight() {
	return Weight;
}
int& Game::Consumable::GetIDP() {
	return ID;
}
void Game::Consumable::EffectsToHuman() {
	for (size_t i = 0; i < GiveEffect.size(); i++)
		(*H).AddEffect(GiveEffect[i]);
}
void Game::Consumable::SetBeing(bool Value) {
	IsBeing = Value;
}
void Game::Consumable::SetID(int Value) {
	ID = Value;
}