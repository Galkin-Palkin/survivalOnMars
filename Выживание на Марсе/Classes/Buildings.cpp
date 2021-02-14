#include "Game.h"
#include <conio.h>
void Game::Buildings::RoomMap(int RoomType, int Variety, vector<string> &RoomVarietyVector, string Info, bool IsFirst) {
	system("cls");
	T.PRC(1, "План помещения:\n");
	// Отрисовка плана помещения
	switch (RoomType) { // Проверка на тип комнаты

		// Казармы
	case 1: {
		
		switch (Variety) {
		case 1: { // Первая разновидность казарм
			T.PRC(15, "");
			Room room = rooms[0];
			room.Print();
			/*
			cout << " ___________________________________ " << endl;
			cout << "|          |    |  |                |" << endl;
			cout << "|          |    |  |        2       |" << endl;
			cout << "|          |_  _|  |_______  _______|" << endl;
			cout << "|     1    |_  _    _______  _______|" << endl;
			cout << "|          |    |  |                |" << endl;
			cout << "|          |    |  |        3       |" << endl;
			cout << "|____  ____|____|  |________________|" << endl;
			cout << "|                               4   |" << endl;
			cout << "|________________   ________|_______|\n" << endl;
			*/
			if (IsFirst)
				room.AddRoomsTo(RoomVarietyVector);
			/*
			if (IsFirst) {
				RoomVarietyVector.push_back("Первый блок");
				RoomVarietyVector.push_back("Второй блок");
				RoomVarietyVector.push_back("Третий блок");
				RoomVarietyVector.push_back("Офис охраны");
			}
			*/
			break;
		}
		case 2: { // Вторая разновидность казарм
			T.PRC(15, "");
			Room room = rooms[0];
			room.Print();
			if (IsFirst)
				room.AddRoomsTo(RoomVarietyVector);
			//cout << " ___________________________________ " << endl;
			//cout << "|         |                         |" << endl;
			//cout << "|    1    |____  ____    _____  ____|" << endl;
			//cout << "|___   ___|          |  |           |" << endl;
			//cout << "|         |     2    |  |     3     |" << endl;
			//cout << "|         |          |  |           |" << endl;
			//cout << "|         |__________|  |___________|" << endl;
			//cout << "|                                   |" << endl;
			//cout << "|_________|__________________   ____|\n" << endl;
			//if (IsFirst) {
			//	RoomVarietyVector.push_back("Техническое помещение");
			//	RoomVarietyVector.push_back("Первый блок");
			//	RoomVarietyVector.push_back("Второй блок");
			//}
			break;
		}
		default: T.PRC(4, "Отсутствует разновидность данной комнаты с таким номером\n"); break; // При указании варианта комнаты, которого нет, нам выведет это сообщение
		}
		break;
	}
		  // Столовая
	case 2: {
		
		switch (Variety) {
		case 1: {
			T.PRC(15, "");
			Room room = rooms[0];
			room.Print();
			if (IsFirst)
				room.AddRoomsTo(RoomVarietyVector);
			//cout << " _______________________________ \n";
			//cout << "|      |                        |\n";
			//cout << "|      |                        |\n";
			//cout << "|   3  |                        |\n";
			//cout << "|      |                        |\n";
			//cout << "|__  __|           1             \n";
			//cout << "|      |                        |\n";
			//cout << "|   2  |                        |\n";
			//cout << "|                               |\n";
			//cout << "|______|________________________|\n\n";
			//if (IsFirst) {
			//	RoomVarietyVector.push_back("Основной зал");
			//	RoomVarietyVector.push_back("Подсобное помещение");
			//	RoomVarietyVector.push_back("Кухня");
			//}
			break;
		}
		case 2: {
			T.PRC(15, "");
			Room room = rooms[0];
			room.Print();
			if (IsFirst)
				room.AddRoomsTo(RoomVarietyVector);
			//cout << " ______________________________ " << endl;
			//cout << "|          |                   |" << endl;
			//cout << "|     1    |         2         |" << endl;
			//cout << "|          |                   |" << endl;
			//cout << "|_  _______|________  _________|" << endl;
			//cout << "|          |                   |" << endl;
			//cout << "|                               " << endl;
			//cout << "|____  ____|________  _________|" << endl;
			//cout << "|   |  |   |                   |" << endl;
			//cout << "|   |  |   |         3         |" << endl;
			//cout << "|          |                   |" << endl;
			//cout << "|___|__|___|___________________|\n" << endl;
			//if (IsFirst) {
			//	RoomVarietyVector.push_back("Кухня");
			//	RoomVarietyVector.push_back("Первый зал");
			//	RoomVarietyVector.push_back("Второй зал");
			//}
			break;
		}
		default: T.PRC(4, "Отсутствует разновидность данной комнаты с таким номером\n"); break;
		}
		break;
	}
		  // Склад
	case 3: {
		
		switch (Variety) {
		case 1: {
			T.PRC(15, "");
			Room room = rooms[0];
			room.Print();
			if (IsFirst)
				room.AddRoomsTo(RoomVarietyVector);
			/*
			T.PRC(15, "");
			cout << " ____________________________________ " << endl;
			cout << "|                     |              |" << endl;
			cout << "|          1                         |" << endl;
			cout << "|                     |       3      |" << endl;
			cout << "|_________  __________|              |" << endl;
			cout << "|                   |  |_  __________|" << endl;
			cout << "|                   |   _  __________ " << endl;
			cout << "|_________  ________|__|             |" << endl;
			cout << "|                     |              |" << endl;
			cout << "|          2          |       4      |" << endl;
			cout << "|                                    |" << endl;
			cout << "|_____________________|______________|\n" << endl;
			if (IsFirst) {
				RoomVarietyVector.push_back("Первый сектор");
				RoomVarietyVector.push_back("Второй сектор");
				RoomVarietyVector.push_back("Третий сектор");
				RoomVarietyVector.push_back("Четвёртый сектор");
			}
			*/
			break;
		}
		case 2: {
			T.PRC(15, "");
			Room room = rooms[0];
			room.Print();
			if(IsFirst)
				room.AddRoomsTo(RoomVarietyVector);
			/*
			cout << " _____________________ " << endl;
			cout << "|     |         |     |" << endl;
			cout << "|           1   |  2  |" << endl;
			cout << "|     |               |" << endl;
			cout << "|     |_________|_____|" << endl;
			cout << "|      _______________ " << endl;
			cout << "|     |               |" << endl;
			cout << "|     |       3       |" << endl;
			cout << "|                     |" << endl;
			cout << "|_____|_______________|\n" << endl;
			if (IsFirst) {
				RoomVarietyVector.push_back("Первый сектор");
				RoomVarietyVector.push_back("Второй сектор");
				RoomVarietyVector.push_back("Третий сектор");
			}
			*/
			break;
		}
		default: T.PRC(4, "Отсутствует разновидность данной комнаты с таким номером\n"); break;
		}
		break;
	}
		  // Медпункт
	case 4: {
		
		switch (Variety) {
		case 1: {
			break;
		}
		case 2: {
			break;
		}
		default: T.PRC(4, "Отсутствует разновидность данной комнаты с таким номером\n"); break;
		}
		break;
	}
		  // Лаборатория
	case 5: {
		
		switch (Variety) {
		case 1: {
			break;
		}
		case 2: {
			break;
		}
		default: T.PRC(4, "Отсутствует разновидность данной комнаты с таким номером\n"); break;
		}
		break;
	}
	default: T.PRC(4, "Отсутствует комната с таким номером\n"); break; // При отсутствии указанного типа комнаты выводит следующее
	}
}
void Game::Buildings::RoomVarietyPrint(vector<string> RoomVarietyVector) {
	T.PRC(1, "Выберите отдел помещения:\n");
	T.V(4, 45);
	int Size = RoomVarietyVector.size();
	for (int i = 0; i < Size; i++) {
		T.PRC(3, "(");
		cout << i + 1 << ") ";
		T.PRC(15, RoomVarietyVector[i]);
		cout << endl;
		if (Size - i - 1) T.V(4, 30);
	}
	T.V(4, 45);
	T.PRC(15, "");
}
int Game::Buildings::RoomChoose(vector<string> &RoomVarietyVector) {
	while (true) {
		int Click = _getch(); // Считываем аскии-код символа. У единицы он 49, у двойки - 50 и так далее
		switch (Click) {
		case 49:
			if (RoomVarietyVector.size() < 1) break;
			RoomVarietyVector.erase(RoomVarietyVector.begin());
			return 1;
		case 50:
			if (RoomVarietyVector.size() < 2) break;
			RoomVarietyVector.erase(RoomVarietyVector.begin() + 1);
			return 2;
		case 51:
			if (RoomVarietyVector.size() < 3) break; // Проверка на то, есть ли достаточное количество мест для поиска в комнате
			RoomVarietyVector.erase(RoomVarietyVector.begin() + 2);
			return 3;
		case 52:
			if (RoomVarietyVector.size() < 4) break;
			RoomVarietyVector.erase(RoomVarietyVector.begin() + 3);
			return 4;
		}
	}
}
void Game::Buildings::RoomSearching(string Info) {
	system("cls");
	T.PRC(3, Info);
}
#pragma region Enters
void Game::Buildings::EnterRoom(int RoomType)
{
	string RoomDenyType; // Говорит, доступ в какое помещение невозможен
	string Info; // Информация о комнате помещения
	vector<string> RoomVarietyVector; // Вектор названий комнат помещения
	switch (RoomType) {
		//Bedrooms
	case 1: RoomDenyType = "от казарм"; break;
		//Cantin
	case 2: RoomDenyType = "от столовой"; break;
		//Storage
	case 3: RoomDenyType = "от склада"; break;
		//Hospital
	case 4: RoomDenyType = "от медпункта"; break;
		//Laboratory
	case 5: RoomDenyType = "от лаборатории"; break;
	}
	bool Entering = true;
	if (rand() % 8 == 0) {
		int DenyType = 1 + rand() % 3;
		DenyToGoIn(DenyType, RoomDenyType, Entering);
	}
	if (Entering) {
		int RoomVariety = 1 + rand() % 2;
		RoomMap(RoomType, RoomVariety, RoomVarietyVector, Info, true); // Делает всю грязную работу)
		RoomVarietyPrint(RoomVarietyVector);
		int Choose = RoomChoose(RoomVarietyVector);
		while (RoomVarietyVector.size() > 0) {
			RoomMap(RoomType, RoomVariety, RoomVarietyVector, Info, false);
			RoomVarietyPrint(RoomVarietyVector);
			int Choose = RoomChoose(RoomVarietyVector);
			RoomSearching(Info);
		}
	}
}
#pragma endregion

void Game::Buildings::DenyToGoIn(int Type, string RoomType, bool& Entering) {
	// Запрет на вход внутрь помещения
	system("cls");
	SetConsoleTextAttribute(h, 13);
	switch (Type) {
		//дверь заблокирована
	case 1: {
		cout << "Дверь " << RoomType << " заблокирована. В этот отдел через эту дверь войти больше нельзя" << endl;
		Entering = false;
		break;
	}
		  //все разрушено, но в одном из случаев находится чьята кисть
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
		  //иной случай
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
				case 1:
					T.PRC(1, "Ты подошёл к двери " + RoomType + ". На ней виднеются следы высохшей крови какого-то бедолаги... Похоже, какому-то сотрудинку несладко досталось...\n");
					break;
				case 2:
					T.PRC(1, "У шлюза из сплава титана есть сенсорный монитор. Там необходимо ввести ключ, либо же провести картой в терминале ниже. Судя по количеству попыток и слегка треснутому экрану можно полагать, что кто-то безуспешно пытался разблокировать эту дверь.\n");
					break;
				case 3:
					T.PRC(1, "У широкого входа есть компьютерный механизм. Он издаёт потрескивания. На пыльном, с паутиной мониторе требуют ввести код. Однако, твоё внимание привлекло другое: клавиатура была заляпана какой-то жёлтой вязкой\nжидкостью, из-за чего некоторые кнопки не работали. А ещё, похоже, кто-то пытался ввести код до тебя\n");
					break;
				case 4:
					T.PRC(1, "Стальная дверь, отделяющая тебя " + RoomType + ", вся в царапинах. В нижней левой части виднеется вмятина, диаметр которой, как ты примерно представил, около 20 сантиметров\nИз электронных петель двери сверкали искры и издавалось характерное потрескивание. На мониторе, находящимся\nна стене чуть левее двери, серыми, еле заметными буквами требовало: \"Введите код\"\n");
					break;
				}
			}
			else T.PRC(1, "Ты оказался перед дверью. Она была заперта, однако, экран, издававший звуки белого шума, просил ввести код\n");
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
				if (!Chance) {
					switch (Type) {
					case 1:
						T.PRC(1, "Похоже, дверь была механическая: были слышны характерные постукивания шестерней. Кровавое пятно на двери медленно поднималось вверх...\n");
						break;
					case 2:
						T.PRC(1, "Издался звенящий звук. Из ближайших двух труб вырвался клубень пара. Шлюз начал открываться\n");
						break;
					case 3:
						T.PRC(1, "Нажатия на противные липкие кнопки оказались не напрасны: издав режущий слух звук, дверь резко упала вниз, открыв проход\n");
						break;
					case 4:
						if (rand() % 4 != 0) T.PRC(1, "Раздался ужасающий скрежет, и мятая дверь начала открываться... Ты думал, что она вот-вот развалиться, но всё обошлось\n");
						else {
							T.PRC(1, "Дверь издала ужасный скрежет, похожий на чьи-то вопли... Тут же послышался треск тока порвавшихся проводов, и массивная стальная дверь грохнулась на пол, чуть не убив тебя\n");
							H.Set(hi_PHP, '-', 10);
						}
						break;
					}
				}
				else T.PRC(13, "Раздался грохот, и дверь медленно поднялась вверх. Путь был открыт\n");
				break;
				continue;
			}
			CountOfTry--;
			if (CountOfTry == 0 && !Entering) {
				system("cls");
				int DenyingType = 1 + rand() % 4;
				switch (DenyingType) {
				case 1:
					T.PRC(1, "\n");
					break;
				case 2:
					T.PRC(1, "\n");
					break;
				case 3:
					T.PRC(1, "\n");
					break;
				case 4:
					T.PRC(1, "\n");
					break;
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
				EnterRoom(RoomType);
				break;
			}
		}
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		CountOfRooms--;
	}
}

Game::Buildings::Buildings() {
	rooms.emplace_back(Room("Data\\Barracks\\First.txt"));
	rooms.emplace_back(Room("Data\\Barracks\\Second.txt"));
	rooms.emplace_back(Room("Data\\Canteen\\First.txt"));
	rooms.emplace_back(Room("Data\\Canteen\\Second.txt"));
	rooms.emplace_back(Room("Data\\Warehouse\\First.txt"));
	rooms.emplace_back(Room("Data\\Warehouse\\Second.txt"));
}