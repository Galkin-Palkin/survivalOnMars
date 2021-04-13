#include "Game.h"
#include <fstream>
int Game::Human::GetI(HumanInfo Type) {
	switch (Type)
	{
	case HumanInfo::HP: {
		return HP;
		break;
	}
	case HumanInfo::FP: {
		return FP;
		break;
	}
	case HumanInfo::EP: {
		return EP;
		break;
	}
	case HumanInfo::PHP: {
		return PHP;
		break;
	}
	case HumanInfo::Sol: {
		return Sol;
		break;
	}
	case HumanInfo::Hour: {
		return Hour;
		break;
	}
	case HumanInfo::HalChance: {
		return HalChance;
		break;
	}
	default: {
		return -100000;
		break;
	}
	}
}
double Game::Human::GetD(HumanInfo Type) {
	switch (Type) {
	case HumanInfo::DP:
		return DP; break;
	default:
		return -100000;
	}
}
int Game::Human::GetEffectsCount() {
	return EffectsVector.size();
}
void Game::Human::Set(HumanInfo Type, char Sign, int NumberI) {
	// Реализовано криво, потом переделаю. Нужно заменить 'N' на '=', убрать '0'. Перегрузить функцию для вещественных чисел
	switch (Type) {
	case HumanInfo::HP: {
		switch (Sign) {
		case '+': HP += NumberI; break;
		case '0': HP = 0; break;
		case '-': HP -= NumberI; break;
		case 'N': HP = NumberI; break;
		}
		break;
	}
	case HumanInfo::FP:
	{
		switch (Sign) {
		case '+': FP += NumberI; break;
		case '0': FP = 0; break;
		case '-': FP -= NumberI; break;
		case 'N': FP = NumberI; break;
		}
		break;
	}
	case HumanInfo::EP: {
		switch (Sign) {
		case '+': EP += NumberI; break;
		case '0': EP = 0; break;
		case '-': EP -= NumberI; break;
		case 'N': EP = NumberI; break;
		}
		break;
	}
	case HumanInfo::PHP: {
		switch (Sign) {
		case '+': PHP += NumberI; break;
		case '0': PHP = 0; break;
		case '-': PHP -= NumberI; break;
		case 'N': PHP = NumberI; break;
		}
		break;
	}
	case HumanInfo::Sol: {
		switch (Sign) {
		case '+': Sol += NumberI; break;
		case '0': Sol = 0; break;
		case '-': Sol -= NumberI; break;
		case 'N': Sol = NumberI; break;
		}
		break;
	}
	case HumanInfo::Hour: {
		switch (Sign) {
		case '+': Hour += NumberI; break;
		case '0': Hour = 0; break;
		case '-': Hour -= NumberI; break;
		case 'N': Hour = NumberI; break;
		}
		break;
	}
	case HumanInfo::HalChance: {
		switch (Sign) {
		case '+': HalChance += NumberI; break;
		case '0': HalChance = 0; break;
		case '-': HalChance -= NumberI; break;
		case 'N': HalChance = NumberI; break;
		}
		break;
	}
	}
}
void Game::Human::Set(HumanInfo Type, char Sign, double Number) {
	switch (Type) {
	case HumanInfo::DP:
		switch (Sign) {
		case '+': DP += Number; break;
		case '-': DP -= Number; break;
		case 'N': DP = Number; break;
		case '0': DP = 0; break;
		}
	}
}
void Game::Human::Null() {
	HP = 70 + (rand() % 5) * 5;
	FP = 30 + (rand() % 7) * 5;
	EP = 100;
	PHP = 30 + (rand() % 3) * 10;
	DP = rand() % 21;
	Sol = 0;
	Hour = 7;
	ConsumableVector.clear();
	BookVector.clear();
	for (auto it : ConsumableMap)
		it.second->SetCount(0);
	for (auto it : BookMap) {
		it.second->SetCount(0);
		it.second->SetPagesCount(it.second->GetTotalPagesCount());
	}
	ofstream fout("Data\\Notes.txt");
	fout << "";
	ConsumableCount = 0;
	NightmareNumber = 1;
	NightmareChance = 0;
}
void Game::Human::Changes(bool& Life, bool& Working) {
	FP -= 5;
	Validate();
	EffectsTick();
	if (FP >= 75) EP += 10;
	else if (FP >= 50) EP += 8;
	else if (FP >= 25) EP += 5;
	if (FP == 0) {
		HP--;
		EP -= 5;
		PHP -= 2;
		DP += 0.2;
		AddEffect(Effect("Data\\Effects\\Starvation.txt"));
	}
	if (HP > 75 && FP >= 30) {
		DP--;
		PHP += 2;
	}
	else if (HP > 50 && FP >= 30) {
		DP -= 0.5;
		PHP++;
	}
	if (HP >= 25 && HP < 50) {
		DP += 0.5;
		PHP -= 2;
	}
	else if (HP < 25 && HP > 0) {
		DP++;
		PHP -= 3;
	}
	else if (HP == 0) {
		DP += 2.0;
		PHP -= 5;
		if (DP >= 90.0) AddEffect(Effect("Data\\Effects\\Agony.txt"));
	}
	if (PHP >= 80)
		HalChance -= 3;
	else if (PHP >= 50)
		HalChance -= 2;
	else if (PHP <= 0)
		HalChance += 5;
	else if (PHP <= 30)
		HalChance++;
	Validate();
	if (DP >= 100.0) {
		Life = false;
		Hour = 23;
		S->SetNew(true);
		S->Download(*this);
		Game::Death(Working);
	}
}
void Game::Human::Validate() {
	if (HP > 100) HP = 100;
	else if (HP < 0) HP = 0;
	if (FP > 100) FP = 100;
	else if (FP < 0) FP = 0;
	if (EP > 100) EP = 100;
	else if (EP < 0) EP = 0;
	if (DP > 100) DP = 100.0;
	else if (DP < 0) DP = 0.0;
	if (PHP < 0) PHP = 0;
	else if (PHP > 100) PHP = 100;
	if (HalChance > 100) HalChance = 100;
	else if (HalChance < 0) HalChance = 0;
}
void Game::Human::SetPointer(Saves* P) {
	S = P;
}
void Game::Human::ClearEffects() {
	EffectsVector.clear();
}
void Game::Human::SaveEffects(ofstream& fout) {
	fout << EffectsVector.size() << endl;
	for (auto i : EffectsVector) {
		fout << i.GetType() << endl
		<< i.GetDuration() << endl;
	}
}
void Game::Human::AddEffect(Effect Ef) {
	EffectsVector.push_back(Ef);
	for (size_t i = 0; i < EffectsVector.size(); i++) {
		for (size_t j = 0; j < EffectsVector.size(); j++) {
			if (i == j) break;
			if (i != j && EffectsVector[i] == EffectsVector[j] && EffectsVector[i].GetDuration() > EffectsVector[j].GetDuration()) {
				EffectsVector.erase(EffectsVector.begin() + j--);
				break;
			}	
			else if (i != j && EffectsVector[i] == EffectsVector[j] && EffectsVector[i].GetDuration() < EffectsVector[j].GetDuration()) {
				EffectsVector.erase(EffectsVector.begin() + i--);
				break;
			}
		}
	}
}
void Game::Human::EffectsTick() {
	for (size_t i = 0; i < EffectsVector.size(); i++) {
		EffectsVector[i].Tick();
		EffectsAction();
		if (!EffectsVector[i].GetDuration())
			EffectsVector.erase(EffectsVector.begin() + i);
	}
}
void Game::Human::EffectsAction() {
	for (size_t i = 0; i < EffectsVector.size(); i++)
		EffectsVector[i].EffectAction();
}