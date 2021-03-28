#include "Game.h"
#include <conio.h>
#include <string>
void Game::Buildings::RoomMap(int RoomType, int Variety, vector<string>& RoomVarietyVector, Room& room, bool IsFirst) {
	int RoomNumber = 0;
	switch (RoomType) { // �������� �� ��� �������
	// �������
	case 1: {
		switch (Variety) {
		case 1: { // ������ ������������� ������
			room = rooms[0];
			RoomNumber = 0;
			break;
		}
		case 2: { // ������ ������������� ������
			room = rooms[1];
			RoomNumber = 1;
			break;
		}
		default: T.PRC(4, "����������� ������������� ������ ������� � ����� �������\n"); break; // ��� �������� �������� �������, �������� ���, ��� ������� ��� ���������
		}
		break;
	}
		  // ��������
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
		default: T.PRC(4, "����������� ������������� ������ ������� � ����� �������\n"); break;
		}
		break;
	}
		  // �����
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
		default: T.PRC(4, "����������� ������������� ������ ������� � ����� �������\n"); break;
		}
		break;
	}
		  // ��������
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
		default: T.PRC(4, "����������� ������������� ������ ������� � ����� �������\n"); break;
		}
		break;
	}
		  // �����������
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
		default: T.PRC(4, "����������� ������������� ������ ������� � ����� �������\n"); break;
		}
		break;
	}
	default: T.PRC(4, "����������� ������� � ����� �������\n"); break; // ��� ���������� ���������� ���� ������� ������� ���������
	}
	system("cls");
	T.PRC(1, "���� ���������:\n");
	// ��������� ����� ���������
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
	T.PRC(1, "�������� ����� ���������:\n");
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
		int Click = _getch(); // ��������� �����-��� �������. � ������� �� 49, � ������ - 50 � ��� �����
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
			if (RoomVarietyVector.size() < 3) break; // �������� �� ��, ���� �� ����������� ���������� ���� ��� ������ � �������
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
#pragma region Enters
void Game::Buildings::EnterRoom(int RoomType, int& Hour)
{
	string RoomDenyType; // �������, ������ � ����� ��������� ����������
	vector<string> RoomVarietyVector; // ������ �������� ������ ���������
	string Temp;
	Room Room = rooms[0];
	switch (RoomType) {
		//Bedrooms
	case 1: RoomDenyType = "�� ������"; break;
		//Canteen
	case 2: RoomDenyType = "�� ��������"; break;
		//Storage
	case 3: RoomDenyType = "�� ������"; break;
		//Hospital
	case 4: RoomDenyType = "�� ���������"; break;
		//Laboratory
	case 5: RoomDenyType = "�� �����������"; break;
	}
	bool Entering = true;
	if (rand() % 8 == 0) {
		int DenyType = 1 + rand() % 3;
		DenyToGoIn(DenyType, RoomDenyType, Entering);
	}
	if (Entering) {
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
		}
	}
}
#pragma endregion

void Game::Buildings::DenyToGoIn(int Type, string RoomType, bool& Entering) {
	// ������ �� ���� ������ ���������
	system("cls");
	T.PRC(13);
	switch (Type) {
		//����� �������������
	case 1: {
		cout << "����� " + RoomType + " �������������. � ���� ����� ����� ��� ����� ����� ������ ������" << endl;
		Entering = false;
		break;
	}
		  //��� ���������, �� � ����� �� ������� ��������� ���-�� �����
	case 2: {
		cout << "������ ����� " << RoomType << ", �� ������ ���� �����: �� ���� �������� ������� ��������� ������" << endl;
		if (rand() % 5 == 0) {
			cout << "��� ����� �� �������� �� ������ ���-�� ������������ �����... ���� ����� ����� �� ����� � �� �������� ������� �����" << endl;
			(*H).Set(HumanInfo::PHP, '-', 40);
		}
		else cout << "������ ���� ����� ���� ������, � �� ������ �����" << endl;
		Entering = false;
		break;
	}
		  //���� ������
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
					T.PRC(1, "�� ������� � ����� " + RoomType + ". �� ��� ��������� ����� �������� ����� ������-�� ��������... ������, ������-�� ���������� �������� ���������...\n");
					break;
				case 2:
					T.PRC(1, "� ����� �� ������ ������ ���� ��������� �������. ��� ���������� ������ ����, ���� �� �������� ������ � ��������� ����. ���� �� ���������� ������� � ������ ���������� ������ ����� ��������, ��� ���-�� ���������� ������� �������������� ��� �����.\n");
					break;
				case 3:
					T.PRC(1, "� �������� ����� ���� ������������ ��������. �� ����� �������������. �� �������, � �������� �������� ������� ������ ���. ������, ��� �������� ��������� ������: ���������� ���� �������� �����-�� ����� ������\n���������, ��-�� ���� ��������� ������ �� ��������. � ���, ������, ���-�� ������� ������ ��� �� ����\n");
					break;
				case 4:
					T.PRC(1, "�������� �����, ���������� ���� " + RoomType + ", ��� � ���������. � ������ ����� ����� ��������� �������, ������� �������, ��� �� �������� ����������, ����� 20 �����������\n�� ����������� ������ ����� �������� ����� � ���������� ����������� �������������. �� ��������, �����������\n�� ����� ���� ����� �����, ������, ��� ��������� ������� ���������: \"������� ���\"\n");
					break;
				}
			}
			else T.PRC(1, "�� �������� ����� ������. ��� ���� �������, ������, �����, ���������� ����� ������ ����, ������ ������ ���\n");
			T.PRC(13, "����� ����� ������, ����� ������ ���-��� - ������������� �����\n");
			T.V(4, 50);
			T.PRC(13, "�������� �������: ");
			T.PRC(15, to_string(CountOfTry) + '\n');
			T.V(4, 25);
			if (CountOfTry != 10) {
				T.PRC(4, "� ������� ��������!\n");
				T.PRC(13, "���-���: ");
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
			T.PRC(13, "������� ���: ");
			T.PRC(15);
			cin >> Code;
			CountOfTry--;
			if (Code < 1000 || Code > 9999) Code = 0;
			if (Code == Thousands * 1000 + Hundreds * 100 + Decs * 10 + Ones) {
				system("cls");
				if (!Chance) {
					switch (Type) {
					case 1:
						T.PRC(1, "������, ����� ���� ������������: ���� ������ ����������� ������������ ���������. �������� ����� �� ����� �������� ����������� �����...\n");
						break;
					case 2:
						T.PRC(1, "������� �������� ����. �� ��������� ���� ���� �������� ������� ����. ���� ����� �����������\n");
						break;
					case 3:
						T.PRC(1, "������� �� ��������� ������ ������ ��������� �� ��������: ����� ������� ���� ����, ����� ����� ����� ����, ������ ������\n");
						break;
					case 4:
						if (rand() % 4 != 0) T.PRC(1, "�������� ��������� �������, � ����� ����� ������ �����������... �� �����, ��� ��� ���-��� ����������, �� �� ��������\n");
						else {
							T.PRC(1, "����� ������ ������� �������, ������� �� ���-�� �����... ��� �� ���������� ����� ���� ����������� ��������, � ��������� �������� ����� ���������� �� ���, ���� �� ���� ����\n");
							(*H).Set(HumanInfo::PHP, '-', 10);
						}
						break;
					}
				}
				else T.PRC(13, "�������� ������, � ����� �������� ��������� �����. ���� ��� ������\n");
				break;
			}
			else if (CountOfTry == 0) {
				system("cls");
				Entering = false;
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

void Game::Buildings::LocationGeneration(int& Hour) {
	// "����������" ���������
	GetPath();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	T.PRC(3, "�� ����� � ������\n");
	T.V(4, 40);
	T.PRC(15);
	system("pause");
	int CountOfRooms = 1 + rand() % 3;
	while (CountOfRooms != 0) {
		system("cls");
		T.PRC(3, "�� ���������� � ���������\n");
		T.PRC(3, "�������� ������������� �������: ");
		T.PRC(15, to_string(CountOfRooms) + '\n');
		T.V(4, 40);
		int RoomType = 1;
		string Variety;
		if (rand() % 20 == 0) RoomType = 5;
		else if (rand() % 15 == 0) RoomType = 4;
		else if (rand() % 10 == 0) RoomType = 3;
		else if (rand() % 6 == 0) RoomType = 2;
		switch (RoomType) {
		case 1: Variety = "����� � �������"; break;
		case 2: Variety = "����� � ��������"; break;
		case 3: Variety = "����� �� �����"; break;
		case 4: Variety = "����� � ��������"; break;
		case 5: Variety = "����� � �����������"; break;
		}
		T.HV(13, 1, 15, Variety);
		while (true) {
			int Click = _getch();
			if (Click == 49) {
				EnterRoom(RoomType, Hour);
				break;
			}
		}
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		CountOfRooms--;
	}
}
void Game::Buildings::SetPointer(Human* Temp) {
	H = Temp;
}