#include "Game.h"
#include <fstream>

void Game::Effect::EffectAction() {
	for (size_t i = 0; i < ParametrsNames.size(); i++) {
		if (Duration) {
			if (ParametrsNames[i] == HumanInfo::DP) (*H).Set(ParametrsNames[i], '+', ParametrsValues[i]);
			else {
				int Value = ParametrsValues[i];
				(*H).Set(ParametrsNames[i], '+', Value);
			}
		}
	}
}

int Game::Effect::GetDuration() {
	return Duration;
}

void Game::Effect::Tick() {
	Duration = (Duration > 0) ? Duration - 1 : 0;
}

void Game::Effect::SetPointer(Human* Temp) {
	H = Temp;
}

Game::Effect::Effect() {

}

Game::Effect::Effect(string Path) {
	HIMap["HP"] = HumanInfo::HP;
	HIMap["FP"] = HumanInfo::FP;
	HIMap["EP"] = HumanInfo::EP;
	HIMap["PHP"] = HumanInfo::PHP;
	HIMap["DP"] = HumanInfo::DP;
	HIMap["HC"] = HumanInfo::HalChance;
	ifstream fin(Path);
	string Type;
	fin >> this->Type;
	double Value;
	int Size;
	fin >> Duration;
	fin >> Size;
	for (int i = 0; i < Size; i++) {
		fin >> Type >> Value;
		ParametrsNames.push_back(HIMap[Type]);
		ParametrsValues.push_back(Value);
	}
}

bool Game::Effect::operator==(Effect &Temp) {
	for (size_t i = 0; i < ParametrsNames.size(); i++)
		if (ParametrsNames[i] != Temp.ParametrsNames[i] || ParametrsValues[i] != Temp.ParametrsValues[i])
			return false;
	return true;
}

Game::Effect& Game::Effect::SetDuration(int Value) {
	Duration = Value;
	return *this;
}

string Game::Effect::GetType() {
	return Type;
}