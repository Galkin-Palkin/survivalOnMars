#include "Game.h"
#include <string>

Game::Obstacle::Obstacle(string Path) {
	ifstream fin(Path);
	if (!fin.is_open())
		throw "Error: file isn't open!";
	fin >> MaxDurPoints;
	DurPoints = MaxDurPoints - rand() % (MaxDurPoints / 2 + 1);
	fin >> ws;
	getline(fin, Name);
	fin >> Type;
	int Size;
	fin >> Size;
	Text.resize(Size);
	for (int i = 0; i < Size; i++) {
		fin >> ws;
		getline(fin, Text[i]);
	}
}

void Game::Obstacle::SetPointer(Human* HP) {
	H = HP;
}

bool Game::Obstacle::Creating() {
	while (DurPoints > 0) {
		system("cls");
		Text::PRC(1, "Препятствие: ");
		Text::PRC(15, Name + '\n');
		Text::V(4, 60);
		for (auto& i : Text)
			Text::PRC(15, i + '\n');
		Text::V(4, 60);
		Text::PRC(3, "Инструмент: ");
		Text::PRC(15, H->GetCurrentTool()->GetName() + '\n');
		Text::V(4, 55);
		Text::PRC(3, "Прочность препятствия: ");
		if (DurPoints >= MaxDurPoints / 4 * 3)
			Text::PRC(1, "Абсолютно целое\n");
		else if (DurPoints >= MaxDurPoints / 2)
			Text::PRC(10, "Целое\n");
		else if (DurPoints >= MaxDurPoints / 4)
			Text::PRC(6, "Поломанное\n");
		else
			Text::PRC(4, "Разбитое\n");
		Text::V(4, 55);
		bool Condition = false;
		bool IsHand = false;
		int Damage = 0;
		for (int i = 0; i < ToolMap["Hand"].Size() && !Condition; i++)
			if (Type == ToolMap["Hand"][i].first) {
				Condition = true;
				IsHand = true;
				Damage = ToolMap["Hand"][i].second;
			}
		for (int i = 0; i < H->GetCurrentTool()->Size() && !Condition; i++)
			if (Type == H->GetCurrentTool()->operator[](i).first) {
				Condition = true;
				if (!IsHand)
					Damage = H->GetCurrentTool()->operator[](i).second;
			}
		if (!Condition) {
			Text::HV(13, 1, 15, "Оставить препятствие и уйти");
			while (true) {
				int Click = _getch();
				switch (Click) {
				case 49: return false;
				}
			}
		}
		else {
			Text::HV(13, 1, 15, "Начать ломать препятствие");
			Text::HV(13, 2, 15, "Оставить препятствие и уйти");
			bool Work = true;
			while (Work) {
				int Click = _getch();
				switch (Click) {
				case 49: {
					if (!IsHand)
						H->GetCurrentTool()->Attack();
					DurPoints -= Damage;
					Work = false;
					break;
				}
				case 50: return false;
				}
			}
		}
	}
	return true;
}

Game::Obstacle Game::Obstacle::Clone() {
	DurPoints = MaxDurPoints - rand() % (MaxDurPoints / 2 + 1);
	return *this;
}
