#include "Classes/Game.h"
using namespace std;
int Game::ConsumableCount = 0;
int Game::NightmareNumber = 1;
vector<Game::Consumable*> Game::ConsumableVector;
map<string, Game::Consumable*> Game::ConsumableMap;
map<string, Game::HumanInfo> Game::HIMap;
Game::Human* Game::Consumable::H = nullptr;
Game::Human* Game::Effect::H = nullptr;
Game::Human* Game::Action::H = nullptr;
vector<string> Game::NotesVector;
vector<string> Game::DiaryVector;
vector<Game::Book*> Game::BookVector;
map<string, Game::Book*> Game::BookMap;
vector<pair<string, string>> Game::AchievementVector;
map<int, bool> Game::IsAchMap;
map<string, Game::Effect> Game::EffectMap;
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Game G;
	bool Working = true;
	while (Working) {
		int Menu = G.Menu();
		switch (Menu) {
		case 1: G.GamingProcess(Working); break;
		case 2: G.Menu_2(Working); break;
		case 3: G.Menu_3(Working); break;
		case 4: G.Menu_4(Working); break;
		case 5: G.Menu_5(Working); break;
		}
	}
}