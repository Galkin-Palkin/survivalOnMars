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
			if (IsFirst)
				room.AddRoomsTo(RoomVarietyVector);
			room.Print();
			break;
		}
		case 2: { // Âòîðàÿ ðàçíîâèäíîñòü êàçàðì
			T.PRC(15, "");
			Room room = rooms[1];
			if (IsFirst)
				room.AddRoomsTo(RoomVarietyVector);
			room.Print();
			break;
		}
		default: T.PRC(4, "Отсутствует разновидность данной комнаты с таким номером\n"); break; // При указании варианта комнаты, которого нет, нам выведет это сообщение
		}
		break;
	}
		  // Ñòîëîâàÿ
	case 2: {
		
		switch (Variety) {
		case 1: {
			T.PRC(15, "");
			Room room = rooms[2];
			if (IsFirst)
				room.AddRoomsTo(RoomVarietyVector);
			room.Print();
			break;
		}
		case 2: {
			T.PRC(15, "");
			Room room = rooms[3];
			if (IsFirst)
				room.AddRoomsTo(RoomVarietyVector);
			room.Print();
			break;
		}
		default: T.PRC(4, "Отсутствует разновидность данной комнаты с таким номером\n"); break;
		}
		break;
	}
		  // Ñêëàä
	case 3: {
		
		switch (Variety) {
		case 1: {
			T.PRC(15, "");
			Room room = rooms[4];
			if (IsFirst)
				room.AddRoomsTo(RoomVarietyVector);
			room.Print();
			break;
		}
		case 2: {
			T.PRC(15, "");
			Room room = rooms[5];
			if (IsFirst)
				room.AddRoomsTo(RoomVarietyVector);
			room.Print();
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
			T.PRC(15, "");
			cout << " _________________________________ " << endl;
			cout << "|                |    |       |   |" << endl;
			cout << "|______   _______|    |           |" << endl;
			cout << "|______ 1 _______      _______|   |" << endl;
			cout << "|                |    |     2     |" << endl;
			cout << "|________________|_  _|___________|" << endl;
			cout << "                 |    |________  _|" << endl;
			cout << "                 |          3     |" << endl;
			cout << "                 |    |___________|" << endl;
			cout << "                 \\_______  _______/\n" << endl;
			if (IsFirst) {
				RoomVarietyVector.push_back("Áëîê ñ ïàëàòàìè");
				RoomVarietyVector.push_back("Ñêëàä è òåõíè÷åñêîå ïîìåùåíèå");
				RoomVarietyVector.push_back("Ðåãèñòðàòóðà");
			}
			break;
		}
		case 2: {
			T.PRC(15, "");
			cout << " __________________________________ " << endl;
			cout << "|      |      |      |      |      |" << endl;
			cout << "|      |      |   1  |      |      |" << endl;
			cout << "|__  __|__  __|__  __|__  __|__  __|" << endl;
			cout << "|_______________    _______________|" << endl;
			cout << "       |    2   |  |                " << endl;
			cout << "   ____|_____  _|  |_____________   " << endl;
			cout << "  |             |  |_  __    __  |  " << endl;
			cout << "  |______  _____|  |_____|  |____|  " << endl;
			cout << "  |                              |  " << endl;
			cout << "  |      3      |  |       4     |  " << endl;
			cout << "  |_____________|  |_____________|  \n" << endl;
			if (IsFirst) {
				RoomVarietyVector.push_back("Ñåêòîð ñ ïàëàòàìè");
				RoomVarietyVector.push_back("Ñêëàä ìåäèêàìåíòîâ");
				RoomVarietyVector.push_back("Ëåâûé áëîê");
				RoomVarietyVector.push_back("Ñòîëîâàÿ");
			}
			break;
		}
		default: T.PRC(4, "Отсутствует разновидность данной комнаты с таким номером\n"); break;
		}
		break;
	}
		  // Ëàáîðàòîðèÿ
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
		int Click = _getch(); // Ñ÷èòûâàåì àñêèè-êîä ñèìâîëà. Ó åäèíèöû îí 49, ó äâîéêè - 50 è òàê äàëåå
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
			if (RoomVarietyVector.size() < 3) break; // Ïðîâåðêà íà òî, åñòü ëè äîñòàòî÷íîå êîëè÷åñòâî ìåñò äëÿ ïîèñêà â êîìíàòå
			RoomVarietyVector.erase(RoomVarietyVector.begin() + 2);
			return 3;
		case 52:
			if (RoomVarietyVector.size() < 4) break;
			RoomVarietyVector.erase(RoomVarietyVector.begin() + 3);
			return 4;
		}
	}
}
void Game::Buildings::RoomSearching(vector<string> &RoomPlacesVector, string Info) {
	system("cls");
	T.PRC(3, Info);
	T.V(4, 50);
	int Choose = RoomChoose(RoomPlacesVector);
	T.V(4, 50);
}
#pragma region Enters
void Game::Buildings::EnterRoom(int RoomType)
{
	string RoomDenyType; // Ãîâîðèò, äîñòóï â êàêîå ïîìåùåíèå íåâîçìîæåí
	string Info; // Èíôîðìàöèÿ î êîìíàòå ïîìåùåíèÿ
	vector<string> RoomVarietyVector; // Âåêòîð íàçâàíèé êîìíàò ïîìåùåíèÿ
	vector<string> RoomPlacesVector; // Âåêòîð ñ íàçâàíèÿìè ìåñò äëÿ ïîèñêà â êîìíàòå
	map<string, vector<Game::Consumable>> Map; // Ñëîâàðü, õðàíÿùèé ïî íàçâàíèþ ìåñòà âåêòîð Consumable`îâ, êîòîðûå ìîæíî íàéòè â ýòîì ìåñòå
	switch (RoomType) {
		//Bedrooms
	case 1: RoomDenyType = "îò êàçàðì"; break;
		//Cantin
	case 2: RoomDenyType = "îò ñòîëîâîé"; break;
		//Storage
	case 3: RoomDenyType = "îò ñêëàäà"; break;
		//Hospital
	case 4: RoomDenyType = "îò ìåäïóíêòà"; break;
		//Laboratory
	case 5: RoomDenyType = "îò ëàáîðàòîðèè"; break;
	}
	bool Entering = true;
	if (rand() % 8 == 0) {
		int DenyType = 1 + rand() % 3;
		DenyToGoIn(DenyType, RoomDenyType, Entering);
	}
	if (Entering) {
		int RoomVariety = 1 + rand() % 2;
		RoomMap(RoomType, RoomVariety, RoomVarietyVector, Info, true); // Äåëàåò âñþ ãðÿçíóþ ðàáîòó)
		RoomVarietyPrint(RoomVarietyVector);
		int Choose = RoomChoose(RoomVarietyVector);
		RoomSearching(RoomPlacesVector, Info);
		while (RoomVarietyVector.size() > 0) {
			RoomMap(RoomType, RoomVariety, RoomVarietyVector, Info, false);
			RoomVarietyPrint(RoomVarietyVector);
			int Choose = RoomChoose(RoomVarietyVector);
			RoomSearching(RoomPlacesVector, Info);
		}
	}
}
#pragma endregion

void Game::Buildings::DenyToGoIn(int Type, string RoomType, bool& Entering) {
	// Çàïðåò íà âõîä âíóòðü ïîìåùåíèÿ
	system("cls");
	SetConsoleTextAttribute(h, 13);
	switch (Type) {
		//äâåðü çàáëîêèðîâàíà
	case 1: {
		cout << "Äâåðü " << RoomType << " çàáëîêèðîâàíà. Â ýòîò îòäåë ÷åðåç ýòó äâåðü âîéòè áîëüøå íåëüçÿ" << endl;
		Entering = false;
		break;
	}
		  //âñå ðàçðóøåíî, íî â îäíîì èç ñëó÷àåâ íàõîäèòñÿ ÷üÿòà êèñòü
	case 2: {
		cout << "Îòêðûâ äâåðü " << RoomType << ", òû óâèäåë ëèøü ðóèíû: âñ¸ áûëî çàâàëåíî ãðóäàìè ïîðèñòîãî áåòîíà" << endl;
		if (rand() % 5 == 0) {
			cout << "Ïîä îäíèì èç îáëîìêîâ òû óâèäåë ÷üþ-òî ðàñïëþùåííóþ êèñòü... Òåáå ñòàëî äóðíî îò ýòîãî è òû ïîñïåøèë çàêðûòü äâåðü" << endl;
			H.Set(hi_PHP, '-', 40);
		}
		else cout << "Èñêàòü òåáå çäåñü ÿâíî íå÷åãî, è òû çàêðûë äâåðü" << endl;
		Entering = false;
		break;
	}
		  //èíîé ñëó÷àé
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
					T.PRC(1, "Òû ïîäîø¸ë ê äâåðè " + RoomType + ". Íà íåé âèäíåþòñÿ ñëåäû âûñîõøåé êðîâè êàêîãî-òî áåäîëàãè... Ïîõîæå, êàêîìó-òî ñîòðóäèíêó íåñëàäêî äîñòàëîñü...\n");
					break;
				case 2:
					T.PRC(1, "Ó øëþçà èç ñïëàâà òèòàíà åñòü ñåíñîðíûé ìîíèòîð. Òàì íåîáõîäèìî ââåñòè êëþ÷, ëèáî æå ïðîâåñòè êàðòîé â òåðìèíàëå íèæå. Ñóäÿ ïî êîëè÷åñòâó ïîïûòîê è ñëåãêà òðåñíóòîìó ýêðàíó ìîæíî ïîëàãàòü, ÷òî êòî-òî áåçóñïåøíî ïûòàëñÿ ðàçáëîêèðîâàòü ýòó äâåðü.\n");
					break;
				case 3:
					T.PRC(1, "Ó øèðîêîãî âõîäà åñòü êîìïüþòåðíûé ìåõàíèçì. Îí èçäà¸ò ïîòðåñêèâàíèÿ. Íà ïûëüíîì, ñ ïàóòèíîé ìîíèòîðå òðåáóþò ââåñòè êîä. Îäíàêî, òâî¸ âíèìàíèå ïðèâëåêëî äðóãîå: êëàâèàòóðà áûëà çàëÿïàíà êàêîé-òî æ¸ëòîé âÿçêîé\næèäêîñòüþ, èç-çà ÷åãî íåêîòîðûå êíîïêè íå ðàáîòàëè. À åù¸, ïîõîæå, êòî-òî ïûòàëñÿ ââåñòè êîä äî òåáÿ\n");
					break;
				case 4:
					T.PRC(1, "Ñòàëüíàÿ äâåðü, îòäåëÿþùàÿ òåáÿ " + RoomType + ", âñÿ â öàðàïèíàõ. Â íèæíåé ëåâîé ÷àñòè âèäíååòñÿ âìÿòèíà, äèàìåòð êîòîðîé, êàê òû ïðèìåðíî ïðåäñòàâèë, îêîëî 20 ñàíòèìåòðîâ\nÈç ýëåêòðîííûõ ïåòåëü äâåðè ñâåðêàëè èñêðû è èçäàâàëîñü õàðàêòåðíîå ïîòðåñêèâàíèå. Íà ìîíèòîðå, íàõîäÿùèìñÿ\níà ñòåíå ÷óòü ëåâåå äâåðè, ñåðûìè, åëå çàìåòíûìè áóêâàìè òðåáîâàëî: \"Ââåäèòå êîä\"\n");
					break;
				}
			}
			else T.PRC(1, "Òû îêàçàëñÿ ïåðåä äâåðüþ. Îíà áûëà çàïåðòà, îäíàêî, ýêðàí, èçäàâàâøèé çâóêè áåëîãî øóìà, ïðîñèë ââåñòè êîä\n");
			cout << "×òîáû âîéòè âíóòðü, íóæíî ââåñòè ïèí-êîä - ÷åòûð¸õçíà÷íîå ÷èñëî" << endl;
			T.V(4, 50);
			SetConsoleTextAttribute(h, 13);
			cout << "Îñòàëîñü ïîïûòîê: ";
			SetConsoleTextAttribute(h, 15);
			cout << CountOfTry << endl;
			T.V(4, 25);
			if (CountOfTry != 10) {
				cout << "Â äîñòóïå îòêàçàíî!" << endl;
				SetConsoleTextAttribute(h, 13);
				cout << "Ïèí-êîä: ";
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
			cout << "Ââåäèòå êîä: ";
			SetConsoleTextAttribute(h, 15);
			cin >> Code;
			if (Code < 1000 || Code > 9999) Code = 0;
			if (Code == Thousands * 1000 + Hundreds * 100 + Decs * 10 + Ones) {
				Entering = true;
				system("cls");
				if (!Chance) {
					switch (Type) {
					case 1:
						T.PRC(1, "Ïîõîæå, äâåðü áûëà ìåõàíè÷åñêàÿ: áûëè ñëûøíû õàðàêòåðíûå ïîñòóêèâàíèÿ øåñòåðíåé. Êðîâàâîå ïÿòíî íà äâåðè ìåäëåííî ïîäíèìàëîñü ââåðõ...\n");
						break;
					case 2:
						T.PRC(1, "Èçäàëñÿ çâåíÿùèé çâóê. Èç áëèæàéøèõ äâóõ òðóá âûðâàëñÿ êëóáåíü ïàðà. Øëþç íà÷àë îòêðûâàòüñÿ\n");
						break;
					case 3:
						T.PRC(1, "Íàæàòèÿ íà ïðîòèâíûå ëèïêèå êíîïêè îêàçàëèñü íå íàïðàñíû: èçäàâ ðåæóùèé ñëóõ çâóê, äâåðü ðåçêî óïàëà âíèç, îòêðûâ ïðîõîä\n");
						break;
					case 4:
						if (rand() % 4 != 0) T.PRC(1, "Ðàçäàëñÿ óæàñàþùèé ñêðåæåò, è ìÿòàÿ äâåðü íà÷àëà îòêðûâàòüñÿ... Òû äóìàë, ÷òî îíà âîò-âîò ðàçâàëèòüñÿ, íî âñ¸ îáîøëîñü\n");
						else {
							T.PRC(1, "Äâåðü èçäàëà óæàñíûé ñêðåæåò, ïîõîæèé íà ÷üè-òî âîïëè... Òóò æå ïîñëûøàëñÿ òðåñê òîêà ïîðâàâøèõñÿ ïðîâîäîâ, è ìàññèâíàÿ ñòàëüíàÿ äâåðü ãðîõíóëàñü íà ïîë, ÷óòü íå óáèâ òåáÿ\n");
							H.Set(hi_PHP, '-', 10);
						}
						break;
					}
				}
				else T.PRC(13, "Ðàçäàëñÿ ãðîõîò, è äâåðü ìåäëåííî ïîäíÿëàñü ââåðõ. Ïóòü áûë îòêðûò\n");
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
	// "Ãåíåðèðóåò" ïîìåùåíèÿ
	system("cls");
	T.PRC(3, "Òû çàø¸ë â çäàíèå\n");
	T.V(4, 40);
	T.PRC(15, "");
	system("pause");
	int CountOfRooms = 2 + rand() % 4;
	while (CountOfRooms != 0) {
		system("cls");
		T.PRC(3, "Òû íàõîäèøüñÿ â ïîìåùåíèè\n");
		T.PRC(3, "Îñòàëîñü íåîñìîòðåííûõ îòäåëîâ: ");
		T.PRC(15, "");
		cout << CountOfRooms << endl;
		T.V(4, 40);
		int RoomType = 1;
		string Variety;
		if (rand() % 20 == 0) RoomType = 5;
		else if (rand() % 15 == 0) RoomType = 4;
		else if (rand() % 10 == 0) RoomType = 3;
		else if (rand() % 6 == 0) RoomType = 2;
		switch (RoomType) {
		case 1: Variety = "Ïîéòè â êàçàðìû"; break;
		case 2: Variety = "Ïîéòè â ñòîëîâóþ"; break;
		case 3: Variety = "Ïîéòè íà ñêëàä"; break;
		case 4: Variety = "Ïîéòè â ìåäïóíêò"; break;
		case 5: Variety = "Ïîéòè â ëàáîðàòîðèþ"; break;
		}
		T.HV(13, 1, 15, Variety);
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
	rooms.emplace_back(Room("Data\\Medical Centre\\First.txt"));
	rooms.emplace_back(Room("Data\\Medical Centre\\Second.txt"));
	rooms.emplace_back(Room("Data\\Laboratory\\First.txt"));
	rooms.emplace_back(Room("Data\\Laboratory\\Second.txt"));
}