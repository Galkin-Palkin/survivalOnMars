#include "Classes/Game.h"

void Game::Effect::EffectAction(Human* H) {
	for (size_t i = 0; i < ParametrsNames.size(); i++) {
		if (Duration) (*H).Set(ParametrsNames[i], '+', ParametrsValues[i]);
	}
}
int Game::Effect::GetDuration() {
	return Duration;
}
void Game::Effect::Tick() {
	Duration = (Duration > 0)? Duration - 1 : 0;
}
Game::Effect::Effect() {

}
