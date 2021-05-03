#include "Classes/Game.h"
using namespace std;
int Game::ConsumableCount = 0;
int Game::NightmareNumber = 1;
int Game::NightmareChance = 0;
vector<Game::Consumable*> Game::ConsumableVector;
map<string, Game::Consumable*> Game::ConsumableMap;
map<string, Game::HumanInfo> Game::HIMap;
Game::Human* Game::Consumable::H = nullptr;
Game::Human* Game::Effect::H = nullptr;
Game::Human* Game::Action::H = nullptr;
Game::Human* Game::Room::H = nullptr;
Game::Human* Game::Enemy::H = nullptr;
Game::Saves* Game::Enemy::S = nullptr;
vector<string> Game::NotesVector;
vector<string> Game::DiaryVector;
vector<bool> Game::SeenEnemies;
vector<Game::Book*> Game::BookVector;
map<string, Game::Book*> Game::BookMap;
vector<pair<string, string>> Game::AchievementVector;
map<int, bool> Game::IsAchMap;
map<string, Game::Effect> Game::EffectMap;
map<string, vector<Game::Tool>> Game::Tools;
map<string, Game::Tool> Game::ToolMap;
Game::Room Game::Room1;
Game::Room Game::Room2;
Game::Room Game::Room3;
Game::Room Game::Room4;
Game::Room Game::Room5;
Game::Room Game::Room6;
Game::Room Game::Room7;
Game::Room Game::Room8;
Game::Room Game::Room9;
Game::Room Game::Room10;
Game::Inventory* Game::Tool::I = nullptr;
Game::Human* Game::Tool::H = nullptr;
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