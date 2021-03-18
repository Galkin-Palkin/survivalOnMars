#include "Game.h"
#include <fstream>
void Game::Effect::EffectAction() {
	for (size_t i = 0; i < ParametrsNames.size(); i++) {
		if (Duration) {
			if (ParametrsNames[i] == hi_DP) (*H).Set(ParametrsNames[i], '+', ParametrsValues[i]);
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
	HIMap["HP"] = hi_HP;
	HIMap["FP"] = hi_FP;
	HIMap["EP"] = hi_EP;
	HIMap["PHP"] = hi_PHP;
	HIMap["DP"] = hi_DP;
	ifstream fin(Path);
	string Type;
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
