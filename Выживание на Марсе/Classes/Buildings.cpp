#include "Game.h"
#include <conio.h>
void Game::Buildings::RoomMap(int RoomType, int Variety) {
	system("cls");
	T.PRC(1, "���� ���������:\n");
	// ��������� ����� ���������
	switch (RoomType) { // �������� �� ��� �������

		// �������
	case 1: {
		
		switch (Variety) {
		case 1: { // ������ ������������� ������
			cout << " ___________________________________ " << endl;
			cout << "|          |    |  |                |" << endl;
			cout << "|          |    |  |        2       |" << endl;
			cout << "|          |_  _|  |_______  _______|" << endl;
			cout << "|     1    |_  _    _______  _______|" << endl;
			cout << "|          |    |  |                |" << endl;
			cout << "|          |    |  |        3       |" << endl;
			cout << "|____  ____|____|  |________________|" << endl;
			cout << "|                               4   |" << endl;
			cout << "|________________   ________|_______|" << endl;
			break;
		}
		case 2: { // ������ ������������� ������
			cout << " ___________________________________ " << endl;
			cout << "|         |                         |" << endl;
			cout << "|    1    |____  ____    _____  ____|" << endl;
			cout << "|___   ___|          |  |           |" << endl;
			cout << "|         |     2    |  |     3     |" << endl;
			cout << "|         |          |  |           |" << endl;
			cout << "|         |__________|  |___________|" << endl;
			cout << "|                                   |" << endl;
			cout << "|_________|__________________   ____|" << endl;
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
			T.PRC(15, "");
			cout << " _______________________________ \n";
			cout << "|      |                        |\n";
			cout << "|      |                        |\n";
			cout << "|   3  |                        |\n";
			cout << "|      |                        |\n";
			cout << "|__  __|           1             \n";
			cout << "|      |                        |\n";
			cout << "|   2  |                        |\n";
			cout << "|                               |\n";
			cout << "|______|________________________|\n";
			break;
		}
		case 2: {
			T.PRC(15, "");
			cout << " ______________________________" << endl;
			cout << "|          |                   |" << endl;
			cout << "|     1    |         2         |" << endl;
			cout << "|          |                   |" << endl;
			cout << "|_  _______|________  _________|" << endl;
			cout << "|          |                   |" << endl;
			cout << "|                               " << endl;
			cout << "|____  ____|________  _________|" << endl;
			cout << "|   |  |   |                   |" << endl;
			cout << "|   |  |   |         3         |" << endl;
			cout << "|          |                   |" << endl;
			cout << "|___|__|___|___________________|" << endl;
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
			break;
		}
		case 2: {
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
			break;
		}
		case 2: {
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
			break;
		}
		case 2: {
			break;
		}
		default: T.PRC(4, "����������� ������������� ������ ������� � ����� �������\n"); break;
		}
		break;
	}
	default: T.PRC(4, "����������� ������� � ����� �������\n"); break; // ��� ���������� ���������� ���� ������� ������� ���������
	}
}

#pragma region Enters
void Game::Buildings::EnterRoom(int RoomType, Inventory* I = new Inventory())
{
	switch (RoomType) {
		//BedRooms
	case 1: {
		bool Entering = true;
		if (rand() % 8 == 0) {
			int DenyType = 1 + rand() % 3;
			DenyToGoIn(H, T, DenyType, "�� ������", Entering);
		}
		break;
	}
		  //Cantin
	case 2: {
		bool Entering = true;
		if (rand() % 8 == 0) {
			int DenyType = 1 + rand() % 3;
			DenyToGoIn(H, T, DenyType, "�� ��������", Entering);
		}
		if (Entering) {
			int RoomType = 1 + rand() % 2;
			switch (RoomType) {
			case 1: {
				RoomMap(2, 1);
				system("pause");
			}
			case 2: {
				RoomMap(2, 2);
				system("pause");
			}
			}
		}
	}
		  //Storage
	case 3: {
		bool Entering = true;
		if (rand() % 8 == 0) {
			int DenyType = 1 + rand() % 3;
			DenyToGoIn(H, T, DenyType, "�� ������", Entering);
		}
		break;
	}
		  //Hospital
	case 4: {
		bool Entering = true;
		if (rand() % 8 == 0) {
			int DenyType = 1 + rand() % 3;
			DenyToGoIn(H, T, DenyType, "�� ���������", Entering);
		}
		break;
	}
		  //Laboratory
	case 5: {
		bool Entering = true;
		if (rand() % 8 == 0) {
			int DenyType = 1 + rand() % 3;
			DenyToGoIn(H, T, DenyType, "�� �����������", Entering);
		}
		break;
	}
	}
}
#pragma endregion

void Game::Buildings::DenyToGoIn(Human& H, Text& T, int Type, string RoomType, bool& Entering) {
	// ������ �� ���� ������ ���������
	system("cls");
	SetConsoleTextAttribute(h, 13);
	switch (Type) {
		//����� �������������
	case 1: {
		cout << "����� " << RoomType << " �������������. � ���� ����� ����� ��� ����� ����� ������ ������" << endl;
		Entering = false;
		break;
	}
		  //��� ���������, �� � ����� �� ������� ��������� ����� �����
	case 2: {
		cout << "������ ����� " << RoomType << ", �� ������ ���� �����: �� ���� �������� ������� ��������� ������" << endl;
		if (rand() % 5 == 0) {
			cout << "��� ����� �� �������� �� ������ ���-�� ������������ �����... ���� ����� ����� �� ����� � �� �������� ������� �����" << endl;
			H.Set(hi_PHP, '-', 40);
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
			SetConsoleTextAttribute(h, 13);
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
			cout << "����� ����� ������, ����� ������ ���-��� - ������������� �����" << endl;
			T.V(4, 50);
			SetConsoleTextAttribute(h, 13);
			cout << "�������� �������: ";
			SetConsoleTextAttribute(h, 15);
			cout << CountOfTry << endl;
			T.V(4, 25);
			if (CountOfTry != 10) {
				cout << "� ������� ��������!" << endl;
				SetConsoleTextAttribute(h, 13);
				cout << "���-���: ";
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
			cout << "������� ���: ";
			SetConsoleTextAttribute(h, 15);
			cin >> Code;
			if (Code < 1000 || Code > 9999) Code = 0;
			if (Code == Thousands * 1000 + Hundreds * 100 + Decs * 10 + Ones) {
				Entering = true;
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
						if (rand() % 4 != 0) T.PRC(1, "�������� ��������� �������, � ����� ����� ������ �����������... �� �����, ��� ��� ���-��� �����������, �� �� ��������\n");
						else {
							T.PRC(1, "����� ������ ������� �������, ������� �� ���-�� �����... ��� �� ���������� ����� ���� ����������� ��������, � ��������� �������� ����� ���������� �� ���, ���� �� ���� ����\n");
							H.Set(hi_PHP, '-', 10);
						}
						break;
					}
				}
				else T.PRC(13, "�������� ������, � ����� �������� ��������� �����. ���� ��� ������\n");
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
	// "����������" ���������
	int CountOfRooms = 2 + rand() % 4;


	system("cls");


	SetConsoleTextAttribute(h, 3);
	cout << "�� ����� � ������" << endl;
	SetConsoleTextAttribute(h, 4);
	cout << "________________________________________" << endl;
	SetConsoleTextAttribute(h, 15);


	system("pause");


	while (CountOfRooms != 0) {
		SetConsoleTextAttribute(h, 3);
		system("cls");
		cout << "�� ���������� � ���������" << endl;
		cout << "�������� ������������� �������: ";
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
		case 1: cout << "����� � �������" << endl; break;
		case 2: cout << "����� � ��������" << endl; break;
		case 3: cout << "����� �� �����" << endl; break;
		case 4: cout << "����� � ��������" << endl; break;
		case 5: cout << "����� � �����������" << endl; break;
		}


		while (true) {
			int Click = _getch();
			if (Click == 49) {
				EnterRoom(RoomType, &I);
				break;
			}
		}
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		CountOfRooms--;
	}
}