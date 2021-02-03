#include "Game.h"
#include <conio.h>
void Game::Buildings::EnterStorage() {
	bool Entering = true;
	if (rand() % 8 == 0) {
		int DenyType = 1 + rand() % 3;
		DenyToGoIn(H, T, DenyType, "от склада", Entering);
	}
}
void Game::Buildings::EnterLaboratory() {
	bool Entering = true;
	if (rand() % 8 == 0) {
		int DenyType = 1 + rand() % 3;
		DenyToGoIn(H, T, DenyType, "от лаборатории", Entering);
	}
}
void Game::Buildings::EnterBedrooms() {
	bool Entering = true;
	if (rand() % 8 == 0) {
		int DenyType = 1 + rand() % 3;
		DenyToGoIn(H, T, DenyType, "от казарм", Entering);
	}
}
void Game::Buildings::EnterCantin(Inventory& I) {
	bool Entering = true;
	if (rand() % 8 == 0) {
		int DenyType = 1 + rand() % 3;
		DenyToGoIn(H, T, DenyType, "от столовой", Entering);
	}
	I.DarkChocolateBar.SetNew();
}
void Game::Buildings::EnterHospital() {
	bool Entering = true;
	if (rand() % 8 == 0) {
		int DenyType = 1 + rand() % 3;
		DenyToGoIn(H, T, DenyType, "от медпункта", Entering);
	}
}
void Game::Buildings::DenyToGoIn(Human& H, Text& T, int Type, string RoomType, bool& Entering) {
	// Запрет на вход внутрь помещения
	system("cls");
	SetConsoleTextAttribute(h, 13);
	switch (Type) {
	case 1: {
		cout << "Дверь " << RoomType << " заблокирована. В этот отдел через эту дверь войти больше нельзя" << endl;
		Entering = false;
		break;
	}
	case 2: {
		cout << "Открыв дверь " << RoomType << ", ты увидел лишь руины: всё было завалено грудами пористого бетона" << endl;
		if (rand() % 5 == 0) {
			cout << "Под одним из обломков ты увидел чью-то расплющенную кисть... Тебе стало дурно от этого и ты поспешил закрыть дверь" << endl;
			H.Set(hi_PHP, '-', 40);
		}
		else cout << "Искать тебе здесь явно нечего, и ты закрыл дверь" << endl;
		Entering = false;
		break;
	}
	case 3: {
		int CountOfTry = 3 + rand() % 8;
		bool UsedDoor = CountOfTry < 10;
		int Thousands = 1 + rand() % 9;
		int Type = 1 + rand() % 4;
		int Chance = rand() % 5;
		int Hundreds = rand() % 10;
		int Decs = rand() % 10;
		int Ones = rand() % 10;
		int Code = (1 + rand() % 9) * 1000 + rand() % 10 * 100 + rand() % 10 * 10 + rand() % 10;
		while (CountOfTry != 0) {
			SetConsoleTextAttribute(h, 13);
			system("cls");
			if (UsedDoor && Chance == 0) {
				switch (Type) {
				case 1: {
					T.PRC(1, "Ты подошёл к двери " + RoomType + ". На ней виднеются следы высохшей крови какого-то бедолаги... Похоже, какому-то сотрудинку несладко досталось...\n");
					break;
				}
				case 2: {
					T.PRC(1, "У шлюза из сплава титана есть сенсорный монитор. Там необходимо ввести ключ, либо же провести картой в терминале ниже. Судя по количеству попыток и слегка треснутому экрану можно полагать, что кто-то безуспешно пытался разблокировать эту дверь.\n");
					break;
				}
				case 3: {
					T.PRC(1, "У широкого входа есть компьютерный механизм. Он издаёт потрескивания. На пыльном, с паутиной мониторе требуют ввести код. Однако, твоё внимание привлекло другое: клавиатура была заляпана какой-то жёлтой вязкой\nжидкостью, из-за чего некоторые кнопки не работали. А ещё, похоже, кто-то пытался ввести код до тебя\n");
					break;
				}
				case 4: {
					T.PRC(1, "Стальная дверь, отделяющая тебя " + RoomType + ", вся в царапинах. В нижней левой части виднеется вмятина, диаметр которой, как ты примерно представил, около 20 сантиметров\nИз электронных петель двери сверкали искры и издавалось характерное потрескивание. На мониторе, находящимся\nна стене чуть левее двери, серыми, еле заметными буквами требовало: \"Введите код\"\n");
					break;
				}
				}
			}
			cout << "Чтобы войти внутрь, нужно ввести пин-код - четырёхзначное число" << endl;
			T.V(4, 50);
			SetConsoleTextAttribute(h, 13);
			cout << "Осталось попыток: ";
			SetConsoleTextAttribute(h, 15);
			cout << CountOfTry << endl;
			T.V(4, 25);
			if (CountOfTry != 10) {
				cout << "В доступе отказано!" << endl;
				SetConsoleTextAttribute(h, 13);
				cout << "Пин-код: ";
				if (Code / 1000 % 10 == Thousands) SetConsoleTextAttribute(h, 10);
				else SetConsoleTextAttribute(h, 4);
				cout << "*";
				if (Code / 100 % 10 == Hundreds) SetConsoleTextAttribute(h, 10);
				else SetConsoleTextAttribute(h, 4);
				cout << "*";
				if (Code / 10 % 10 == Decs) SetConsoleTextAttribute(h, 10);
				else SetConsoleTextAttribute(h, 4);
				cout << "*";
				if (Code % 10 == Ones) SetConsoleTextAttribute(h, 10);
				else SetConsoleTextAttribute(h, 4);
				cout << "*" << endl;
				T.V(4, 40);
			}
			SetConsoleTextAttribute(h, 13);
			cout << "Введите код: ";
			SetConsoleTextAttribute(h, 15);
			cin >> Code;
			if (Code < 1000 || Code > 9999) Code = 0;
			if (Code == Thousands * 1000 + Hundreds * 100 + Decs * 10 + Ones) {
				Entering = true;
				system("cls");
				SetConsoleTextAttribute(h, 13);
				cout << "Тебе удалось подобрать пин-код и войти" << endl;
				break;
			}
			CountOfTry--;
			if (CountOfTry == 0) {
				system("cls");
				int DenyingType = 1 + rand() % 4;
				switch (DenyingType) {
				case 1: {
					T.PRC(1, "");
					break;
				}
				case 2: {
					break;
				}
				case 3: {
					break;
				}
				case 4: {
					break;
				}
				}
				break;
			}
		}
		break;
	}
	}
	T.V(4, 40);
	SetConsoleTextAttribute(h, 15);
	system("pause");
}


void Game::Buildings::LocationGeneration() {
	// "Генерирует" помещения
	int CountOfRooms = 2 + rand() % 4;


	system("cls");
	
	
	SetConsoleTextAttribute(h, 3);
	cout << "Ты зашёл в здание" << endl;
	SetConsoleTextAttribute(h, 4);
	cout << "________________________________________" << endl;
	SetConsoleTextAttribute(h, 15);


	system("pause");


	while (CountOfRooms != 0) {
		SetConsoleTextAttribute(h, 3);
		system("cls");
		cout << "Ты находишься в помещении" << endl;
		cout << "Осталось неосмотренных отделов: ";
		SetConsoleTextAttribute(h, 15);
		cout << CountOfRooms << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "________________________________________" << endl;
		SetConsoleTextAttribute(h, 13);
		cout << "(1) ";
		SetConsoleTextAttribute(h, 15);
		int RoomType = 1;
		if (rand() % 2 == 0) RoomType++;
		if (rand() % 3 == 0) RoomType++;
		if (rand() % 4 == 0) RoomType++;
		if (rand() % 5 == 0) RoomType++;
		switch (RoomType) {
		case 1: cout << "Пойти в казармы" << endl; break;
		case 2: cout << "Пойти в столовую" << endl; break;
		case 3: cout << "Пойти на склад" << endl; break;
		case 4: cout << "Пойти в медпункт" << endl; break;
		case 5: cout << "Пойти в лабораторию" << endl; break;
		}


		while (true) {
			int Click = _getch();
			if (Click == 49) {
				switch (RoomType) {
				case 1: EnterBedrooms(); break;
				case 2: EnterCantin(I); break;
				case 3: EnterStorage(); break;
				case 4: EnterHospital(); break;
				case 5: EnterLaboratory(); break;
				}
				break;
			}
		}
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		CountOfRooms--;
	}
}