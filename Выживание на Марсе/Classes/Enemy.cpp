#include "Game.h"
#include <fstream>
#include <string>

void Game::Enemy::Damaged(int Value) {
	if (H->GetI(HumanInfo::PHP) >= 80)
		HP = (HP - Value > 0) ? HP - Value : 0;
	else if (H->GetI(HumanInfo::PHP) >= 50 && rand() % 2 == 0)
		HP = (HP - Value > 0) ? HP - Value : 0;
	else if (H->GetI(HumanInfo::PHP) >= 30 && rand() % 4 == 0)
		HP = (HP - Value > 0) ? HP - Value : 0;
	else if (H->GetI(HumanInfo::PHP) < 30 && rand() % 8 == 0)
		HP = (HP - Value > 0) ? HP - Value : 0;
	else {
		system("cls");
		int Variable = rand() % 4;
		switch (Variable) {
		case 0: Text::PRC(3, "Твоя рука задрожала, и ты не смог нанести удар\n"); break;
		case 1: Text::PRC(3, "Тварь оказалась достаточно вёрткой, и ты промахнулся\n"); break;
		case 2: Text::PRC(3, "У тебя не хватило духа ударить, поэтому ты отступил\n"); break;
		case 3: Text::PRC(3, "Твари удалось заблокировать твой удар\n"); break;
		}
		Text::V(4, 50);
		system("pause");
	}
}
Game::Enemy::Enemy(string Path) {
	HIMap["HP"] = HumanInfo::HP;
	HIMap["FP"] = HumanInfo::FP;
	HIMap["EP"] = HumanInfo::EP;
	HIMap["PHP"] = HumanInfo::PHP;
	HIMap["DP"] = HumanInfo::DP;
	HIMap["HC"] = HumanInfo::HalChance;
	ifstream fin(Path);
	fin >> HP >> ChanceToHit >> ChanceToLeave;
	fin >> ws;
	getline(fin, Name);
	int Size;
	fin >> Size;
	DamageType.resize(Size);
	DamageValue.resize(Size);
	for (int i = 0; i < Size; i++) {
		string Temp;
		fin >> Temp >> DamageValue[i];
		DamageType[i] = HIMap[Temp];
	}
	fin >> Size;
	Info.resize(Size);
	for (int i = 0; i < Size; i++) {
		fin >> ws;
		getline(fin, Info[i]);
	}
	fin >> Size;
	NotesToDiary.resize(Size);
	for (int i = 0; i < Size; i++) {
		fin >> ws;
		getline(fin, NotesToDiary[i]);
	}
}
bool Game::Enemy::IsDead() {
	return HP <= 0;
}
void Game::Enemy::Show(int Number, bool IsFirst) {
	system("cls");
	Text::PRC(15, "Противник: ");
	if (!SeenEnemies[(size_t)Number - 1]) {
		Text::PRC(13, "???\n");
		if (IsFirst) 
			for (auto i : NotesToDiary)
				DiaryVector.push_back(i);
	}
	else
		Text::PRC(3, Name + '\n');
	Text::V(4, 60);
	for (auto i : Info)
		Text::PRC(15, i + '\n');
	Text::V(4, 60);
	Text::PRC(1, "Состояние здоровья противника: ");
	int Variety = rand() % 4;
	switch (Variety) {
	case 0: Text::PRC(4, "Ранен\n"); break;
	case 1: Text::PRC(4, "Истекает кровью\n"); break;
	case 2: Text::PRC(4, "Не имеет повреждений\n"); break;
	case 3: Text::PRC(4, "При смерти\n"); break;
	}

	Text::V(4, 55);
	Text::PRC(13, "Состояние здоровья: ");
	if (H->GetI(HumanInfo::HP) >= 90)
		Text::PRC(1, "Идеальное\n");
	else if (H->GetI(HumanInfo::HP) >= 70)
		Text::PRC(3, "Отличное\n");
	else if (H->GetI(HumanInfo::HP) >= 50)
		Text::PRC(10, "Хорошее\n");
	else if (H->GetI(HumanInfo::HP) >= 30)
		Text::PRC(6, "Плохое\n");
	else if (H->GetI(HumanInfo::HP) >= 20)
		Text::PRC(4, "Ужасное\n");
	else
		Text::PRC(4, "Критическое\n");
	Text::V(4, 55);

	Text::PRC(13, "Истощение организма: ");
	if (H->GetD(HumanInfo::DP) >= 90.0)
		Text::PRC(4, "Предсмертное\n");
	else if (H->GetD(HumanInfo::DP) >= 75.0 && H->GetD(HumanInfo::DP) < 90)
		Text::PRC(4, "Очень серьёзное\n");
	else if (H->GetD(HumanInfo::DP) >= 50.0 && H->GetD(HumanInfo::DP) < 75.0)
		Text::PRC(4, "Серьёзное\n");
	else if (H->GetD(HumanInfo::DP) >= 25.0 && H->GetD(HumanInfo::DP) < 50.0)
		Text::PRC(6, "Среднее\n");
	else if (H->GetD(HumanInfo::DP) > 0.0 && H->GetD(HumanInfo::DP) < 25.0)
		Text::PRC(10, "Слабое\n");
	else
		Text::PRC(1, "Отсутствует\n");
	Text::V(4, 55);

	Text::PRC(13, "Состояние психического здоровья: ");
	if (H->GetI(HumanInfo::PHP) >= 90)
		Text::PRC(1, "Идеальное\n");
	else if (H->GetI(HumanInfo::PHP) >= 70)
		Text::PRC(3, "Отличное\n");
	else if (H->GetI(HumanInfo::PHP) >= 50)
		Text::PRC(10, "Хорошее\n");
	else if (H->GetI(HumanInfo::PHP) >= 30)
		Text::PRC(6, "Плохое\n");
	else if (H->GetI(HumanInfo::PHP) >= 20)
		Text::PRC(4, "Ужасное\n");
	else
		Text::PRC(4, "Критическое\n");
	Text::V(4, 55);
	Text::PRC(13, "Оружие: ");
	Text::PRC(15, H->GetCurrentTool()->GetName() + '\n');
	Text::V(4, 55);
}
void Game::Enemy::SetPointer(Human* T, Saves *T2) {
	H = T;
	S = T2;
}
void Game::Enemy::Attack(bool &Working, bool &Life) {
	if (ChanceToHit - rand() % 101 >= 0) {
		for (size_t i = 0; i < DamageValue.size(); i++) {
			if (DamageType[i] == HumanInfo::DP)
				H->Set(DamageType[i], '+', DamageValue[i]);
			else {
				int Value = DamageValue[i];
				H->Set(DamageType[i], '-', Value);
			}
		}
	}
	if (H->GetD(HumanInfo::DP) >= 100.0) {
		S->SetNew(true);
		S->Download(*H);
		Game::Death(Working, Life);
	}
}
int Game::Enemy::GetChanceToLeave() {
	return ChanceToLeave;
}