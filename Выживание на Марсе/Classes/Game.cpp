#include "Game.h"
#include <conio.h>
void Game::Introduction() {
	SetConsoleTextAttribute(h, 15);
	system("cls");
	cout << "Раздалось потрескивание электрического тока, и дверца капсулы открылась." << endl;
	cout << "Ты приподнялся и начал осматривать помещение. По мере пробуждения у тебя в голове появлялись новые и новые вопросы" << endl;
	cout << "Ты осмотрелся. Стены госпиталя и никого вокруг. Где все?" << endl;
	cout << "Ты встал на ноги и подошёл к столу. На нём ты увидел кипу бумаг и фотографию" << endl;
	cout << "Эта фотография... Доктор Парклз и его жена Сьюзи... Ты вспомнил свою Софи! От этого воспоминания у тебя кольнуло в сердце" << endl;
	cout << "Ты сел на стоящее рядом кресло и попытался включить монитор" << endl;
	cout << "После третьего нажатия монитор вспыхнул и на нём отобразилось следущее..." << endl;
	T.V(4, 25);
	SetConsoleTextAttribute(h, 15);
	system("pause");
}
void Game::InfoShowing(int HP, int FP, int EP, int PHP, double DP, int Sol, int Hour) {
	// Показывает состояние
	SetConsoleTextAttribute(h, 3);
	cout << "Сол ";
	SetConsoleTextAttribute(h, 15);
	cout << H.GetI(hi_Sol) << endl;
	T.V(4, 15);
	SetConsoleTextAttribute(h, 15);
	cout << Hour << ":00" << endl;
	T.V(4, 50);
	SetConsoleTextAttribute(h, 13);
	cout << "Состояние здоровья: ";
	SetConsoleTextAttribute(h, 15);
	if (HP >= 90) {
		SetConsoleTextAttribute(h, 1);
		cout << "Идеальное\n";
	}
	else if (HP >= 70) {
		SetConsoleTextAttribute(h, 3);
		cout << "Отличное\n";
	}
	else if (HP >= 50) {
		SetConsoleTextAttribute(h, 10);
		cout << "Хорошее\n";
	}
	else if (HP >= 30) {
		SetConsoleTextAttribute(h, 6);
		cout << "Плохое\n";
	}
	else if (HP >= 20) {
		SetConsoleTextAttribute(h, 4);
		cout << "Ужасное\n";
	}
	else {
		SetConsoleTextAttribute(h, 4);
		cout << "Критическое\n";
	}
	T.V(4, 45);
	SetConsoleTextAttribute(h, 13);
	cout << "Истощение организма: ";
	SetConsoleTextAttribute(h, 15);
	if (DP < 100.0 && DP >= 90.0) {
		SetConsoleTextAttribute(h, 4);
		cout << "Предсмертное" << endl;
	}
	else if (DP >= 75.0 && DP < 90) {
		SetConsoleTextAttribute(h, 4);
		cout << "Очень серьёзное" << endl;
	}
	else if (DP >= 50.0 && DP < 75.0) {
		SetConsoleTextAttribute(h, 4);
		cout << "Серьёзное" << endl;
	}
	else if (DP >= 25.0 && DP < 50.0) {
		SetConsoleTextAttribute(h, 6);
		cout << "Среднее" << endl;
	}
	else if (DP > 0.0 && DP < 25.0) {
		SetConsoleTextAttribute(h, 10);
		cout << "Слабое" << endl;
	}
	else {
		SetConsoleTextAttribute(h, 1);
		cout << "Отсутствует" << endl;
	}
	T.V(4, 45);
	SetConsoleTextAttribute(h, 13);
	cout << "Состояние психического здоровья: ";
	if (PHP >= 90) {
		SetConsoleTextAttribute(h, 1);
		cout << "Идеальное\n";
	}
	else if (PHP >= 70) {
		SetConsoleTextAttribute(h, 3);
		cout << "Отличное\n";
	}
	else if (PHP >= 50) {
		SetConsoleTextAttribute(h, 10);
		cout << "Хорошее\n";
	}
	else if (PHP >= 30) {
		SetConsoleTextAttribute(h, 6);
		cout << "Плохое\n";
	}
	else if (PHP >= 20) {
		SetConsoleTextAttribute(h, 4);
		cout << "Ужасное\n";
	}
	else {
		SetConsoleTextAttribute(h, 4);
		cout << "Критическое\n";
	}
	T.V(4, 45);
	SetConsoleTextAttribute(h, 13);
	cout << "Степень сытости: ";
	if (FP >= 90) {
		SetConsoleTextAttribute(h, 1);
		cout << "Полная" << endl;
	}
	else if (FP >= 75) {
		SetConsoleTextAttribute(h, 3);
		cout << "Хорошая" << endl;
	}
	else if (FP >= 50) {
		SetConsoleTextAttribute(h, 10);
		cout << "Средняя" << endl;
	}
	else if (FP >= 25) {
		SetConsoleTextAttribute(h, 6);
		cout << "Удовлетворительная" << endl;
	}
	else if (FP < 25) {
		SetConsoleTextAttribute(h, 4);
		cout << "Голод" << endl;
	}
	T.V(4, 45);
	SetConsoleTextAttribute(h, 13);
	cout << "Степень усталости: ";
	if (EP == 100) {
		SetConsoleTextAttribute(h, 1);
		cout << "Нулевая" << endl;
	}
	else if (EP >= 80) {
		SetConsoleTextAttribute(h, 3);
		cout << "Крайне малая" << endl;
	}
	else if (EP >= 60) {
		SetConsoleTextAttribute(h, 10);
		cout << "Малая" << endl;
	}
	else if (EP >= 40) {
		SetConsoleTextAttribute(h, 6);
		cout << "Средняя" << endl;
	}
	else if (EP >= 20) {
		SetConsoleTextAttribute(h, 4);
		cout << "Большая" << endl;
	}
	else {
		SetConsoleTextAttribute(h, 4);
		cout << "Полная" << endl;
	}
	T.V(4, 50);
	SetConsoleTextAttribute(h, 15);
}
int Game::NewGame() {
	system("cls");
	SetConsoleTextAttribute(h, 13);
	T.V(1);
	SetConsoleTextAttribute(h, 4);
	T.V(4, 30);
	SetConsoleTextAttribute(h, 13);
	cout << "(1) ";
	SetConsoleTextAttribute(h, 15);
	cout << "Начать новую игру" << endl;
	if (S.GetNew() != true) {
		SetConsoleTextAttribute(h, 4);
		T.V(4, 20);
		SetConsoleTextAttribute(h, 13);
		cout << "(2) ";
		SetConsoleTextAttribute(h, 15);
		cout << "Продолжить игру" << endl;
	}
	S.SetNew(false);
	while (true) {
		int Click = _getch();
		if (Click == 49) return 1;
		else if (S.GetNew() != true && Click == 50) return 2;
	}
}
void Game::Changes(bool& Life, int& Hour, bool& Working) {
	// Система организма персонажа, функция вызывается каждый игровой час
	H.Set(hi_FP, '-', 5);
	Validate();
	H.EffectsTick();
	if (H.GetI(hi_FP) >= 75) H.Set(hi_EP, '+', 10);
	else if (H.GetI(hi_FP) >= 50) H.Set(hi_EP, '+', 8);
	else if (H.GetI(hi_FP) >= 25) H.Set(hi_EP, '+', 5);
	if (H.GetI(hi_FP) == 0) {
		H.Set(hi_HP, '-', 1);
		H.Set(hi_EP, '-', 5);
		H.Set(hi_PHP, '-', 2);
		H.Set(hi_DP, '+', 0.25);
	}
	if (H.GetI(hi_HP) > 75 && H.GetI(hi_FP) >= 30) {
		H.Set(hi_DP, '-', 1.0);
		H.Set(hi_PHP, '+', 2);
	}
	else if (H.GetI(hi_HP) > 50 && H.GetI(hi_FP) >= 30) {
		H.Set(hi_DP, '-', 0.5);
		H.Set(hi_PHP, '+', 1);
	}
	if (H.GetI(hi_HP) >= 25 && H.GetI(hi_HP) < 50) {
		H.Set(hi_DP, '+', 0.25);
		H.Set(hi_PHP, '-', 2);
	}
	else if (H.GetI(hi_HP) < 25 && H.GetI(hi_HP) > 0) {
		H.Set(hi_DP, '+', 1.0);
		H.Set(hi_PHP, '-', 3);
	}
	else if (H.GetI(hi_HP) == 0) {
		H.Set(hi_DP, '+', 2.0);
		H.Set(hi_PHP, '-', 5);
	}
	Validate();
	if (H.GetD(hi_DP) >= 100.0) {
		Life = false;
		Hour = 23;
		S.SetNew(true);
		S.Download(H);
		MenuReturning(Working);
	}
}
int Game::ActionsChoose(int Sol, int Hour) {
	SetConsoleTextAttribute(h, 10);
	T.V(1);
	T.V(4, 30);
	bool FirstAction = false;
	if (Sol == 1 && Hour == 7) {
		FirstAction = true;
		T.HV(13, 1, 15, "Осмотреть помещение");
	}
	else {
		T.HV(13, 1, 15, "Надеть костюм и выйти");
		T.V(4, 15);
		T.HV(13, 2, 15, "Принять пищу");
		T.V(4, 15);
		T.HV(13, 3, 15, "Сесть за рабочий стол");
	}
	while (true) {
		int Click = _getch();
		if (Click == 49 && FirstAction) return 0;
		else {
			if (Click == 49 && !FirstAction) return 1;
			else if (Click == 50 && !FirstAction) return 2;
			else if (Click == 51 && !FirstAction) return 3;
			else if (Click == 52 && !FirstAction) return 4;
			else if (Click == 27) return 5;
		}
	}
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}
void Game::Eating(Inventory& I, bool& IsBack, int& Hour) {
	size_t CurrentPage = 0;
	size_t TotalPage = (ConsumableCount % 9 == 0) ? ConsumableCount / 9 : ConsumableCount / 9 + 1;
	while (true) {
		int Size = (ConsumableCount - CurrentPage * 9 > 8) ? 9 : ConsumableCount - CurrentPage * 9;
		if (ConsumableCount < 9) Size = ConsumableCount;
		Consumable::Show(T, CurrentPage);
		int Click = _getch();
		if (!ConsumableCount) {
			Back(Hour, IsBack);
			return;
		}
		switch (Click) {
		case 27: {
			Back(Hour, IsBack);
			return;
		}
		case 49: {
			if (Size >= 1) {
				(*ConsumableVector[(size_t)0 + CurrentPage * (size_t)9]).Taking();
				return;
			}
			break;
		}
		case 50: {
			if (Size >= 2) {
				(*ConsumableVector[(size_t)1 + CurrentPage * (size_t)9]).Taking();
				return;
			}
			break;
		}
		case 51: {
			if (Size >= 3) {
				(*ConsumableVector[(size_t)2 + (size_t)CurrentPage * 9]).Taking();
				return;
			}
			break;
		}
		case 52: {
			if (Size >= 4) {
				(*ConsumableVector[(size_t)3 + (size_t)CurrentPage * 9]).Taking();
				return;
			}
			break;
		}
		case 53: {
			if (Size >= 5) {
				(*ConsumableVector[4 + (size_t)CurrentPage * 9]).Taking();
				return;
			}
			break;
		}
		case 54: {
			if (Size >= 6) {
				(*ConsumableVector[5 + (size_t)CurrentPage * 9]).Taking();
				return;
			}
			break;
		}
		case 55: {
			if (Size >= 7) {
				(*ConsumableVector[6 + (size_t)CurrentPage * 9]).Taking();
				return;
			}
			break;
		}
		case 56: {
			if (Size >= 8) {
				(*ConsumableVector[7 + (size_t)CurrentPage * 9]).Taking();
				return;
			}
			break;
		}
		case 57: {
			if (Size >= 9) {
				(*ConsumableVector[8 + (size_t)CurrentPage * 9]).Taking();
				return;
			}
			break;
		}
		case 65: {
			if (CurrentPage) CurrentPage--;
			break;
		}
		case 68: {
			if (CurrentPage < TotalPage - 1) CurrentPage++;
			break;
		}
		case 97: {
			if (CurrentPage) CurrentPage--;
			break;
		}
		case 100: {
			if (CurrentPage < TotalPage - 1) CurrentPage++;
			break;
		}
		case 194: {
			if (CurrentPage < TotalPage - 1) CurrentPage++;
			break;
		}
		case 212: {
			if (CurrentPage) CurrentPage--;
			break;
		}
		case 226: {
			if (CurrentPage < TotalPage - 1) CurrentPage++;
			break;
		}
		case 244: {
			if (CurrentPage) CurrentPage--;
			break;
		}
		}
	}
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}
void Game::Outing() {
	B.LocationGeneration();
}
void Game::Sleeping() {
	int Counter = 0;
	int HoursN = 23;
	while (Counter != 8) {
		system("cls");
		SetConsoleTextAttribute(h, 13);
		cout << "Ты спишь..." << endl;
		T.V(4, 30);
		SetConsoleTextAttribute(h, 3);
		cout << HoursN << ":00" << endl;
		HoursN++;
		if (HoursN == 24) HoursN = 0;
		Counter++;
		Sleep(970);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	}

}
void Game::Escape(bool& Life, int& Hour) {
	system("cls");
	T.PRC(1, "Вернуться в главное меню?\n");
	T.V(2);
	while (true) {
		int Click = _getch();
		if (Click == 49) {
			Life = false;
			H.Set(hi_Sol, '-', 1);
			S.Download(H, true);
			break;
		}
		else if (Click == 50) {
			Hour--;
			break;
		}
	}
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}
void Game::Back(int& Hour, bool& IsBack) {
	Hour--;
	IsBack = true;
}
void Game::Actions(int Choose, bool& Life, int& Hour, bool& IsBack) {
	switch (Choose) {
	case 0: RoomLooking(I); break;
	case 1: Outing(); break;
	case 2: Eating(I, IsBack, Hour); break;
	case 3: break;
	case 4: {
		break;
	}
	case 5: Escape(Life, Hour); break;
	}
}
void Game::RoomLooking(Inventory& I) {
	system("cls");
	SetConsoleTextAttribute(h, 15);
	cout << "Ты решил осмотреть помещение. Приоткрыв цинковый шкаф, обработанный специальным раствором нитрата серебра, ты увидел костюм для выхода на поверхность Марса.\nВ углу стоял ящик с гуманитарной помощью. Там находились консервы и галеты, а также некоторые медицинские препараты" << endl;
	T.V(4, 45);
	SetConsoleTextAttribute(h, 15);
	system("pause");
	I.Aspirin.SetNew(2 + rand() % 1);
	I.Hardtack.SetNew(rand() % 2 + 1);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}
void Game::MenuReturning(bool& Working) {
	system("cls");
	SetConsoleTextAttribute(h, 4);
	cout << "Вы умерли" << endl;
	T.V(4, 35);
	SetConsoleTextAttribute(h, 13);
	T.V(1);
	T.PRC(10, "(1) ");
	T.PRC(15, "Вернуться в главное меню");
	T.PRC(4, " (2) ");
	T.PRC(15, "Выйти из игры\n");
	int Click;
	while (true) {
		Click = _getch();
		if (Click == 49) {
			Click = 1;
			break;
		}
		else if (Click == 50) {
			Click = 2;
			break;
		}
	}
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	if (Click == 2) Working = false;
}
void Game::ChangesDay(bool IsExit) {
	// Изменения, проходящие после каждой ночи
	H.Set(hi_Sol, '+', 1);
	if (H.GetI(hi_Sol) != 1 && !IsExit) {
		Sleeping();
		H.Set(hi_HP, '+', 5);
		H.Set(hi_DP, '-', 1.0);
		H.Set(hi_EP, '+', 50);
		H.Set(hi_FP, '-', 15);
		Validate();
	}
}

Game::Game() {
	B.SetPointer(&H);
	Consumable::SetPointer(&H);
	Effect::SetPointer(&H);
	ConsumableMap["Aspirin"] = &I.Aspirin;
	ConsumableMap["BartonsDrug"] = &I.BartonsDrug;
	ConsumableMap["CannedApple"] = &I.CannedApple;
	ConsumableMap["CannedBeef"] = &I.CannedBeef;
	ConsumableMap["DarkChocolateBar"] = &I.DarkChocolateBar;
	ConsumableMap["EnergyBar"] = &I.EnergyBar;
	ConsumableMap["FishSoup"] = &I.FishSoup;
	ConsumableMap["Gericline"] = &I.Gericline;
	ConsumableMap["Hardtack"] = &I.Hardtack;
	ConsumableMap["MeatBriquette"] = &I.MeatBriquette;
	ConsumableMap["MeltedCheese"] = &I.MeltedCheese;
	ConsumableMap["MushroomSoup"] = &I.MushroomSoup;
	ConsumableMap["Palont"] = &I.Palont;
	ConsumableMap["Phenothan"] = &I.Phenothan;
	ConsumableMap["RicePurge"] = &I.RicePurge;
	ConsumableMap["Trivoclisine"] = &I.Trivoclisine;
	ConsumableMap["CannedFish"] = &I.CannedFish;
	ConsumableMap["DriedFruits"] = &I.DriedFruits;
	ConsumableMap["Noodle"] = &I.Noodle;
	ConsumableMap["Sedatives"] = &I.Sedatives;
	ConsumableMap["Syrup"] = &I.Syrup;
	ConsumableMap["VegetableStew"] = &I.VegetableStew;
}
int Game::Menu() {
	system("cls");
	SetConsoleTextAttribute(h, 13);
	cout << "Выживание на Марсе 0.1" << endl;
	SetConsoleTextAttribute(h, 4);
	T.V(4, 25);
	SetConsoleTextAttribute(h, 13);
	cout << "(1) ";
	SetConsoleTextAttribute(h, 15);
	cout << "Начать игру" << endl;
	SetConsoleTextAttribute(h, 4);
	T.V(4, 5);
	SetConsoleTextAttribute(h, 13);
	cout << "(2) ";
	SetConsoleTextAttribute(h, 15);
	cout << "Помощь к игре" << endl;
	SetConsoleTextAttribute(h, 4);
	T.V(4, 5);
	SetConsoleTextAttribute(h, 13);
	cout << "(3) ";
	SetConsoleTextAttribute(h, 15);
	cout << "Разработчики" << endl;
	SetConsoleTextAttribute(h, 4);
	T.V(4, 5);
	SetConsoleTextAttribute(h, 13);
	cout << "(4) ";
	SetConsoleTextAttribute(h, 15);
	cout << "Выход из игры" << endl;
	SetConsoleTextAttribute(h, 4);
	T.V(4, 25);
	SetConsoleTextAttribute(h, 15);
	int Variety = _getch();
	switch (Variety) {
	case 49: Variety = 1; break;
	case 50: Variety = 2; break;
	case 51: Variety = 3; break;
	case 52: Variety = 4; break;
	}
	return Variety;
}
void Game::GamingProcess(bool& Working) {
	// Основная функция, именно в ней всё и происходит
	bool isExit = false;
	S.Load(H, isExit);
	bool Life = true;
	int GameType = NewGame();
	if (GameType == 1) {
		H.Null();
		Introduction();
	}
	while (Life) {
		S.Download(H, isExit);
		ChangesDay(isExit);
		isExit = false;
		if (H.GetI(hi_Hour) >= 23) H.Set(hi_Hour, 'N', 7);
		for (; H.GetI(hi_Hour) <= 22; H.Set(hi_Hour, '+', 1)) {
			if (!Life) {
				H.Set(hi_Hour, '-', 1);
				break;
			}
			system("cls");
			InfoShowing(H.GetI(hi_HP), H.GetI(hi_FP), H.GetI(hi_EP), H.GetI(hi_PHP), H.GetD(hi_DP), H.GetI(hi_Sol), H.GetI(hi_Hour));
			int Choose = ActionsChoose(H.GetI(hi_Sol), H.GetI(hi_Hour));
			int Hour = H.GetI(hi_Hour);
			bool IsBack = false;
			Actions(Choose, Life, Hour, IsBack);
			H.Set(hi_Hour, 'N', Hour);
			if (!(H.GetI(hi_Sol) == 1 && Hour == 7) && Choose != 5) Changes(Life, Hour, Working);
		}
	}
}
void Game::Menu_2(bool& Working) {
	system("cls");
	SetConsoleTextAttribute(h, 13);
	cout << "Помощь к игре" << endl;
	SetConsoleTextAttribute(h, 4);
	T.V(4, 35);
	SetConsoleTextAttribute(h, 15);
	cout << "Бла бла" << endl;
	SetConsoleTextAttribute(h, 4);
	T.V(4, 35);
	SetConsoleTextAttribute(h, 15);
	T.V(3);
	T.V(2);
	SetConsoleTextAttribute(h, 4);
	T.V(4, 25);
	SetConsoleTextAttribute(h, 15);
	int Variety = _getch();
	switch (Variety) {
	case 49: Variety = 1; break;
	case 50: Variety = 2; break;
	}
	if (Variety != 1) Working = false;
}
void Game::Menu_3(bool& Working) {
	system("cls");
	T.PRC(13, "Разработчики\n");
	T.V(4, 45);
	T.PRC(13, "Ответственные за разработку:\n");
	T.PRC(15, "- Programming Harius\n");
	T.PRC(15, "- DobbikoV\n");
	T.PRC(15, "- GoogeTan\n");
	T.V(4, 25);
	T.PRC(13, "Тестировка:\n");
	T.PRC(15, "- Programming Harius\n");
	T.V(4, 45);
	T.PRC(15, "");
	T.V(3);
	T.V(2);
	T.V(4, 25);
	T.PRC(15, "");
	int Variety = _getch();
	switch (Variety) {
	case 49: Variety = 1; break;
	case 50: Variety = 2; break;
	}
	if (Variety != 1) Working = false;
}
void Game::Menu_4(bool& Working) {
	system("cls");
	SetConsoleTextAttribute(h, 13);
	cout << "Вы точно хотите выйти?" << endl;
	T.V(2);
	T.V(4, 25);
	SetConsoleTextAttribute(h, 15);
	int Variety = _getch();
	switch (Variety) {
	case 49: Variety = 1; break;
	case 50: Variety = 2; break;
	}
	if (Variety == 1) Working = false;
}
void Game::Validate() {
	if (H.GetI(hi_HP) > 100) H.Set(hi_HP, 'N', 100);
	else if (H.GetI(hi_HP) < 0) H.Set(hi_HP, '0', 0);
	if (H.GetI(hi_FP) > 100) H.Set(hi_FP, 'N', 100);
	else if (H.GetI(hi_FP) < 0) H.Set(hi_FP, '0', 0);
	if (H.GetI(hi_EP) > 100) H.Set(hi_EP, 'N', 100);
	else if (H.GetI(hi_EP) < 0) H.Set(hi_EP, '0', 0);
	if (H.GetD(hi_DP) > 100) H.Set(hi_DP, 'N', 100.0);
	else if (H.GetD(hi_DP) < 0) H.Set(hi_DP, '0', 0.0);
	if (H.GetI(hi_PHP) < 0) H.Set(hi_PHP, '0', 0);
	else if (H.GetI(hi_PHP) > 100) H.Set(hi_PHP, 'N', 100);
}