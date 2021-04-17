#include "Game.h"
#include <conio.h>
#include <string>
#include <fstream>
void Game::Buildings::RoomMap(int RoomType, int Variety, vector<string>& RoomVarietyVector, Room& room, bool IsFirst) {
	int RoomNumber = 0;
	switch (RoomType) { // Проверка на тип комнаты
	// Казармы
	case 1: {
		switch (Variety) {
		case 1: { // Первая разновидность казарм
			room = rooms[0];
			RoomNumber = 0;
			break;
		}
		case 2: { // Вторая разновидность казарм
			room = rooms[1];
			RoomNumber = 1;
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
			room = rooms[2];
			RoomNumber = 2;
			break;
		}
		case 2: {
			room = rooms[3];
			RoomNumber = 3;
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
			room = rooms[4];
			RoomNumber = 4;
			break;
		}
		case 2: {
			room = rooms[5];
			RoomNumber = 5;
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
			room = rooms[6];
			RoomNumber = 6;
			break;
		}
		case 2: {
			room = rooms[7];
			RoomNumber = 7;
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
			room = rooms[8];
			RoomNumber = 8;
			break;
		}
		case 2: {
			room = rooms[9];
			RoomNumber = 9;
			break;
		}
		default: T.PRC(4, "Отсутствует разновидность данной комнаты с таким номером\n"); break;
		}
		break;
	}
	default: T.PRC(4, "Отсутствует комната с таким номером\n"); break; // При отсутствии указанного типа комнаты выводит следующее
	}
	system("cls");
	T.PRC(1, "План помещения:\n");
	// Отрисовка плана помещения
	T.PRC(15, "");
	room.Print();
	T.PRC(3, room.GetInfo() + '\n');
	T.V(4, 90);
	if (IsFirst) {
		room.AddRoomsTo(RoomVarietyVector);
		room.SetVectorAction(rooms[RoomNumber].GetVectorAction());
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
int Game::Buildings::RoomChoose(vector<string>& RoomVarietyVector, string& Temp) {
	while (true) {
		int Click = _getch(); // Считываем аскии-код символа. У единицы он 49, у двойки - 50 и так далее
		switch (Click) {
		case 49:
			if (RoomVarietyVector.size() < 1) break;
			Temp = RoomVarietyVector[0];
			RoomVarietyVector.erase(RoomVarietyVector.begin());
			return 1;
		case 50:
			if (RoomVarietyVector.size() < 2) break;
			Temp = RoomVarietyVector[1];
			RoomVarietyVector.erase(RoomVarietyVector.begin() + 1);
			return 2;
		case 51:
			if (RoomVarietyVector.size() < 3) break; // Проверка на то, есть ли достаточное количество мест для поиска в комнате
			Temp = RoomVarietyVector[2];
			RoomVarietyVector.erase(RoomVarietyVector.begin() + 2);
			return 3;
		case 52:
			if (RoomVarietyVector.size() < 4) break;
			Temp = RoomVarietyVector[3];
			RoomVarietyVector.erase(RoomVarietyVector.begin() + 3);
			return 4;
		}
	}
}
void Game::Buildings::RoomSearching(Room& Room, string RoomName, int RoomVarType) {
	system("cls");
	vector<Action> RoomPlacesVector = Room.GetRoomPlaces(RoomVarType - 1);
	while (RoomPlacesVector.size() > 0) {
		Room.PlacePrint(RoomPlacesVector, RoomName);
		Room.ActionChoose(RoomPlacesVector);
	}
	Room.PlaceClear(RoomVarType - 1);
}
void Game::Buildings::EnterRoom(bool& Life, bool& Working, int RoomType, int& Hour) {
	string RoomDenyType; // Говорит, доступ в какое помещение невозможен
	vector<string> RoomVarietyVector; // Вектор названий комнат помещения
	string Temp;
	Room Room = rooms[0];
	switch (RoomType) {
		//Bedrooms
	case 1: RoomDenyType = "от казарм"; break;
		//Canteen
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
	else if (rand() % 10 == 0)
		Battle(Working, Life);
	if (Entering && Life) {
		int RoomVariety = 1 + rand() % 2;
		RoomMap(RoomType, RoomVariety, RoomVarietyVector, Room, true);
		RoomVarietyPrint(RoomVarietyVector);
		int Choose = RoomChoose(RoomVarietyVector, Temp);
		RoomSearching(Room, Temp, Choose);
		while (RoomVarietyVector.size() > 0) {
			RoomMap(RoomType, RoomVariety, RoomVarietyVector, Room, false);
			RoomVarietyPrint(RoomVarietyVector);
			Choose = RoomChoose(RoomVarietyVector, Temp);
			RoomSearching(Room, Temp, Choose);
			Hour++;
			H->Set(HumanInfo::EP, '-', 10);
			H->Changes(Life, Working);
		}
	}
}

void Game::Buildings::DenyToGoIn(int Type, string RoomType, bool& Entering) {
	// Запрет на вход внутрь помещения
	system("cls");
	T.PRC(13);
	switch (Type) {
		//дверь заблокирована
	case 1: {
		cout << "Дверь " + RoomType + " заблокирована. В этот отдел через эту дверь войти больше нельзя" << endl;
		Entering = false;
		break;
	}
		  //все разрушено, но в одном из случаев находится чья-то кисть
	case 2: {
		cout << "Открыв дверь " << RoomType << ", ты увидел лишь руины: всё было завалено грудами пористого бетона" << endl;
		if (rand() % 5 == 0) {
			cout << "Под одним из обломков ты увидел чью-то расплющенную кисть... Тебе стало дурно от этого и ты поспешил закрыть дверь" << endl;
			(*H).Set(HumanInfo::PHP, '-', 40);
			H->Set(HumanInfo::HalChance, '+', 5);
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
			system("cls");
			if (UsedDoor && Chance == 0) {
				switch (Type) {
				case 1:
					T.PRC(1, "Ты подошёл к двери " + RoomType + ". На ней виднеются следы высохшей крови какого-то бедолаги... Похоже, какому-то сотруднику несладко досталось...\n");
					break;
				case 2:
					T.PRC(1, "У шлюза из сплава титана есть сенсорный монитор. Там необходимо ввести ключ, либо же провести картой в терминале ниже. Судя по количеству попыток и слегка треснутому экрану можно полагать, что кто-то безуспешно пытался разблокировать эту дверь.\n");
					break;
				case 3:
					T.PRC(1, "У широкого входа есть компьютерный механизм. Он издаёт потрескивания. На пыльном, с паутиной мониторе требуют ввести код. Однако, твоё внимание привлекло другое: клавиатура была заляпана какой-то жёлтой вязкой\nжидкостью, из-за чего некоторые кнопки не работали. А ещё, похоже, кто-то пытался ввести код до тебя\n");
					break;
				case 4:
					T.PRC(1, "Стальная дверь, отделяющая тебя " + RoomType + ", вся в царапинах. В нижней левой части виднеется вмятина, диаметр которой, как ты примерно представил, около 20 сантиметров\nИз электронных петель двери сверкали искры и издавалось характерное потрескивание.\nНа мониторе, находящeмся на стене чуть левее двери, серыми, еле заметными буквами требовало: \"Введите код\"\n");
					break;
				}
			}
			else T.PRC(1, "Ты оказался перед дверью. Она была заперта, однако, экран, издававший звуки белого шума, просил ввести код\n");
			T.PRC(13, "Чтобы войти внутрь, нужно ввести пин-код - четырёхзначное число\n");
			T.V(4, 50);
			T.PRC(13, "Осталось попыток: ");
			T.PRC(15, to_string(CountOfTry) + '\n');
			T.V(4, 25);
			if (CountOfTry != 10) {
				T.PRC(4, "В доступе отказано!\n");
				T.PRC(13, "Пин-код: ");
				if (Code / 1000 % 10 == Thousands) T.PRC(10, "*");
				else T.PRC(4, "*");
				if (Code / 100 % 10 == Hundreds) T.PRC(10, "*");
				else T.PRC(4, "*");
				if (Code / 10 % 10 == Decs) T.PRC(10, "*");
				else T.PRC(4, "*");
				if (Code % 10 == Ones) T.PRC(10, "*\n");
				else T.PRC(4, "*\n");
				T.V(4, 40);
			}
			T.PRC(13, "Введите код: ");
			T.PRC(15);
			cin >> Code;
			CountOfTry--;
			if (Code < 1000 || Code > 9999) Code = 0;
			if (Code == Thousands * 1000 + Hundreds * 100 + Decs * 10 + Ones) {
				system("cls");
				if (!IsAchMap[Ach_Hacker]) {
					ofstream fout("Data\\Achievements.txt", ofstream::app);
					fout << "Видел, как в кино это делается\nПодобрать код к замку и открыть дверь\n";
					IsAchMap[Ach_Hacker] = true;
				}
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
						if (rand() % 4 != 0) T.PRC(1, "Раздался ужасающий скрежет, и мятая дверь начала открываться... Ты думал, что она вот-вот развалится, но всё обошлось\n");
						else {
							T.PRC(1, "Дверь издала ужасный скрежет, похожий на чьи-то вопли... Тут же послышался треск тока порвавшихся проводов, и массивная стальная дверь грохнулась на пол, чуть не убив тебя\n");
							(*H).Set(HumanInfo::PHP, '-', 10);
						}
						break;
					}
				}
				else T.PRC(13, "Раздался грохот, и дверь медленно поднялась вверх. Путь был открыт\n");
				break;
			}
			else if (CountOfTry == 0) {
				system("cls");
				Entering = false;
				int DenyingType = 1 + rand() % 4;
				switch (DenyingType) {
				case 1:
					T.PRC(1, "После последней попытки терминал выключился, и твой путь в комнату стал заказан\n");
					break;
				case 2:
					T.PRC(1, "Раздался оглушающий писк, и на терминале высветилось:\n\n");
					T.PRC(10, "\"ТЕРМИНАЛ ЗАБЛОКИРОВАН. ОБРАТИТЕСЬ К УПРАВЛЯЮЩЕМУ СЕКТОРA\"\n");
					break;
				case 3:
					T.PRC(1, "После последнего нажатия кнопки прозвучала кратковременная сирена, и терминал был закрыт\n");
					break;
				case 4:
					T.PRC(1, "Экран терминала стал красным, и на нём белыми буквами высветилось:\n\n");
					T.PRC(15, "SERVER CONNECTING ERROR\n");
					T.PRC(15, "SYSTEM ERROR: 0xF10A819C34\n");
					T.PRC(15, "SYSTEM ERROR: 0x92D703\n");
					T.PRC(15, "STREAM 0x14D15 WAS ABORTED\n");
					T.PRC(15, "STREAM 0x913F WAS ABORTED\n");
					T.PRC(15, "REBOOTING ERROR: 0xD13280FC\n");
					T.PRC(15, "STREAM 0x13F WAS ABORTED\n");
					T.PRC(15, "TRANSPLANTATION ERROR: 0x91DF\n");
					T.PRC(15, "STREAM 0x3CA97 WAS ABORTED\n");
					T.PRC(15, "SYSTEM TERMINATED\n");
					break;
				}
				break;
			}
		}
		break;
	}
	}
	T.V(4, 40);
	T.PRC(15);
	system("pause");
}


void Game::Buildings::GetPath() {
	rooms.emplace_back(Room("Data\\Buildings\\Barracks\\First.txt"));
	rooms.emplace_back(Room("Data\\Buildings\\Barracks\\Second.txt"));
	rooms.emplace_back(Room("Data\\Buildings\\Canteen\\First.txt"));
	rooms.emplace_back(Room("Data\\Buildings\\Canteen\\Second.txt"));
	rooms.emplace_back(Room("Data\\Buildings\\Warehouse\\First.txt"));
	rooms.emplace_back(Room("Data\\Buildings\\Warehouse\\Second.txt"));
	rooms.emplace_back(Room("Data\\Buildings\\Medical Centre\\First.txt"));
	rooms.emplace_back(Room("Data\\Buildings\\Medical Centre\\Second.txt"));
	rooms.emplace_back(Room("Data\\Buildings\\Laboratory\\First.txt"));
	rooms.emplace_back(Room("Data\\Buildings\\Laboratory\\Second.txt"));
}

void Game::Buildings::LocationGeneration(bool& Life, bool& Working, int& Hour) {
	// "Генерирует" помещения
	GetPath();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	T.PRC(3, "Ты зашёл в здание\n");
	T.V(4, 40);
	T.PRC(15);
	system("pause");
	int CountOfRooms = 1 + rand() % 3;
	vector<pair<int, string>> RoomVector(CountOfRooms);
	for (size_t i = 0; i < RoomVector.size(); i++) {
		if (rand() % 20 == 0)
			RoomVector[i].first = 5;
		else if (rand() % 15 == 0)
			RoomVector[i].first = 4;
		else if (rand() % 10 == 0)
			RoomVector[i].first = 3;
		else if (rand() % 6 == 0)
			RoomVector[i].first = 2;
		else
			RoomVector[i].first = 1;
		switch (RoomVector[i].first) {
		case 1: RoomVector[i].second = "Пойти в казармы"; break;
		case 2: RoomVector[i].second = "Пойти в столовую"; break;
		case 3: RoomVector[i].second = "Пойти на склад"; break;
		case 4: RoomVector[i].second = "Пойти в медпункт"; break;
		case 5: RoomVector[i].second = "Пойти в лабораторию"; break;
		}
	}
	while (CountOfRooms != 0 && Life) {
		system("cls");
		T.PRC(3, "Ты находишься в помещении\n");
		T.PRC(3, "Осталось неосмотренных отделов: ");
		T.PRC(15, to_string(CountOfRooms) + '\n');
		T.V(4, 40);
		if (Hour >= 21 || H->GetI(HumanInfo::EP) < 10 || H->GetI(HumanInfo::PHP) <= 30)
			RoomVector.clear();
		for (size_t i = 0; i < RoomVector.size(); i++) {
			T.HV(13, i + 1, 15, RoomVector[i].second);
			T.V(4, 15);
		}
		T.HV(13, RoomVector.size() + 1, 15, "Вернуться домой");
		if (!RoomVector.size()) {
			while (true) {
				int Click = _getch();
				if (Click == 49) return;
			}
		}
		else {
			bool Clicking = true;
			while (Clicking) {
				int Click = _getch();
				switch (Click) {
				case 49: {
					EnterRoom(Life, Working, RoomVector[(size_t)Click - 49].first, Hour);
					Clicking = false;
					RoomVector.erase(RoomVector.begin() + ((size_t)Click - 49));
					break;
				}
				case 50: {
					if (RoomVector.size() > 1) {
						EnterRoom(Life, Working, RoomVector[(size_t)Click - 49].first, Hour);
						Clicking = false;
						RoomVector.erase(RoomVector.begin() + ((size_t)Click - 49));
					}
					else if (RoomVector.size() == 1)
						return;
					break;
				}
				case 51: {
					if (RoomVector.size() > 2) {
						EnterRoom(Life, Working, RoomVector[(size_t)Click - 49].first, Hour);
						Clicking = false;
						RoomVector.erase(RoomVector.begin() + ((size_t)Click - 49));
					}
					else if (RoomVector.size() == 2)
						return;
					break;
				}
				case 52: {
					if (RoomVector.size() >= 3)
						return;
					break;
				}
				}
			}
		}
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		CountOfRooms--;
	}
}
void Game::Buildings::SetPointer(Human* Temp, Saves* S) {
	H = Temp;
	this->S = S;
}

void Game::Buildings::Battle(bool &Working, bool &Life) {
	string Path = "Data\\Enemies\\" + to_string(1 + rand() % 3) + ".txt";
	Enemy En(Path);
	int Choice = 0;
	while (!En.IsDead() && Life) {
		En.Show();
		Text::HV(13, 1, 15, "Нанести удар");
		Text::V(4);
		Text::HV(13, 2, 15, "Принять лекарства");
		Text::V(4);
		Text::HV(13, 3, 15, "Предпринять попытку убежать");
		Text::V(4, 55);
		while (true) {
			int Click = _getch();
			switch (Click) {
			case 49: {
				Choice = 1;
				goto Choose;
			}
			case 50: {
				Choice = 2;
				goto Choose;
			}
			case 51: {
				Choice = 3;
				goto Choose;
			}
			}
		}
	Choose:
		switch (Choice) {
		case 1: {
			En.Damaged(20);
			En.Attack(Working, Life);
			break;
		}
		case 2: break;
		case 3: {
			if (En.GetChanceToLeave() - rand() % 101 >= 0)
				return;
			else
				En.Attack(Working, Life);
			break;
		}
		}
	}
}