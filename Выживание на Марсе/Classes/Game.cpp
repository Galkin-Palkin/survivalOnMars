#include "Game.h"
#include <conio.h>
void Game::Introduction() {
	SetConsoleTextAttribute(h, 15);
	system("cls");
	cout << "��������� ������������� �������������� ����, � ������ ������� ���������." << endl;
	cout << "�� ����������� � ����� ����������� ���������. �� ���� ����������� � ���� � ������ ���������� ����� � ����� �������" << endl;
	cout << "�� ����������. ����� ��������� � ������ ������. ��� ���?" << endl;
	cout << "�� ����� �� ���� � ������� � �����. �� �� �� ������ ���� ����� � ����������" << endl;
	cout << "��� ����������... ������ ������ � ��� ���� �����... �� �������� ���� ����! �� ����� ������������ � ���� �������� � ������" << endl;
	cout << "�� ��� �� ������� ����� ������ � ��������� �������� �������" << endl;
	cout << "����� �������� ������� ������� �������� � �� �� ������������ ��������..." << endl;
	T.V(4, 25);
	SetConsoleTextAttribute(h, 15);
	system("pause");
}
void Game::InfoShowing(int HP, int FP, int EP, int PHP, double DP, int Sol, int Hour) {
	// ���������� ���������
	SetConsoleTextAttribute(h, 3);
	cout << "��� ";
	SetConsoleTextAttribute(h, 15);
	cout << H.GetI(hi_Sol) << endl;
	T.V(4, 15);
	SetConsoleTextAttribute(h, 15);
	cout << Hour << ":00" << endl;
	T.V(4, 50);
	SetConsoleTextAttribute(h, 13);
	cout << "��������� ��������: ";
	SetConsoleTextAttribute(h, 15);
	if (HP >= 90) {
		SetConsoleTextAttribute(h, 1);
		cout << "���������\n";
	}
	else if (HP >= 70) {
		SetConsoleTextAttribute(h, 3);
		cout << "��������\n";
	}
	else if (HP >= 50) {
		SetConsoleTextAttribute(h, 10);
		cout << "�������\n";
	}
	else if (HP >= 30) {
		SetConsoleTextAttribute(h, 6);
		cout << "������\n";
	}
	else if (HP >= 20) {
		SetConsoleTextAttribute(h, 4);
		cout << "�������\n";
	}
	else {
		SetConsoleTextAttribute(h, 4);
		cout << "�����������\n";
	}
	T.V(4, 45);
	SetConsoleTextAttribute(h, 13);
	cout << "��������� ���������: ";
	SetConsoleTextAttribute(h, 15);
	if (DP < 100.0 && DP >= 90.0) {
		SetConsoleTextAttribute(h, 4);
		cout << "������������" << endl;
	}
	else if (DP >= 75.0 && DP < 90) {
		SetConsoleTextAttribute(h, 4);
		cout << "����� ���������" << endl;
	}
	else if (DP >= 50.0 && DP < 75.0) {
		SetConsoleTextAttribute(h, 4);
		cout << "���������" << endl;
	}
	else if (DP >= 25.0 && DP < 50.0) {
		SetConsoleTextAttribute(h, 6);
		cout << "�������" << endl;
	}
	else if (DP > 0.0 && DP < 25.0) {
		SetConsoleTextAttribute(h, 10);
		cout << "������" << endl;
	}
	else {
		SetConsoleTextAttribute(h, 1);
		cout << "�����������" << endl;
	}
	T.V(4, 45);
	SetConsoleTextAttribute(h, 13);
	cout << "��������� ������������ ��������: ";
	if (PHP >= 90) {
		SetConsoleTextAttribute(h, 1);
		cout << "���������\n";
	}
	else if (PHP >= 70) {
		SetConsoleTextAttribute(h, 3);
		cout << "��������\n";
	}
	else if (PHP >= 50) {
		SetConsoleTextAttribute(h, 10);
		cout << "�������\n";
	}
	else if (PHP >= 30) {
		SetConsoleTextAttribute(h, 6);
		cout << "������\n";
	}
	else if (PHP >= 20) {
		SetConsoleTextAttribute(h, 4);
		cout << "�������\n";
	}
	else {
		SetConsoleTextAttribute(h, 4);
		cout << "�����������\n";
	}
	T.V(4, 45);
	SetConsoleTextAttribute(h, 13);
	cout << "������� �������: ";
	if (FP >= 90) {
		SetConsoleTextAttribute(h, 1);
		cout << "������" << endl;
	}
	else if (FP >= 75) {
		SetConsoleTextAttribute(h, 3);
		cout << "�������" << endl;
	}
	else if (FP >= 50) {
		SetConsoleTextAttribute(h, 10);
		cout << "�������" << endl;
	}
	else if (FP >= 25) {
		SetConsoleTextAttribute(h, 6);
		cout << "������������������" << endl;
	}
	else if (FP < 25) {
		SetConsoleTextAttribute(h, 4);
		cout << "�����" << endl;
	}
	T.V(4, 45);
	SetConsoleTextAttribute(h, 13);
	cout << "������� ���������: ";
	if (EP == 100) {
		SetConsoleTextAttribute(h, 1);
		cout << "�������" << endl;
	}
	else if (EP >= 80) {
		SetConsoleTextAttribute(h, 3);
		cout << "������ �����" << endl;
	}
	else if (EP >= 60) {
		SetConsoleTextAttribute(h, 10);
		cout << "�����" << endl;
	}
	else if (EP >= 40) {
		SetConsoleTextAttribute(h, 6);
		cout << "�������" << endl;
	}
	else if (EP >= 20) {
		SetConsoleTextAttribute(h, 4);
		cout << "�������" << endl;
	}
	else {
		SetConsoleTextAttribute(h, 4);
		cout << "������" << endl;
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
	cout << "������ ����� ����" << endl;
	if (S.GetNew() != true) {
		SetConsoleTextAttribute(h, 4);
		T.V(4, 20);
		SetConsoleTextAttribute(h, 13);
		cout << "(2) ";
		SetConsoleTextAttribute(h, 15);
		cout << "���������� ����" << endl;
	}
	S.SetNew(false);
	while (true) {
		int Click = _getch();
		if (Click == 49) return 1;
		else if (S.GetNew() != true && Click == 50) return 2;
	}
}
void Game::Changes(bool& Life, int& Hour, bool& Working) {
	// ������� ��������� ���������, ������� ���������� ������ ������� ���
	H.Set(hi_FP, '-', 5);
	if (H.GetI(hi_HP) > 100) H.Set(hi_HP, 'N', 100);
	if (H.GetI(hi_FP) >= 75) H.Set(hi_EP, '+', 10);
	if (H.GetI(hi_EP) > 100) H.Set(hi_EP, 'N', 100);
	else if (H.GetI(hi_FP) >= 50) H.Set(hi_EP, '+', 8);
	else if (H.GetI(hi_FP) >= 25) H.Set(hi_EP, '+', 5);
	if (H.GetI(hi_FP) < 0) H.Set(hi_FP, '0', 1);
	if (H.GetI(hi_FP) == 0) {
		H.Set(hi_HP, '-', 1);
		H.Set(hi_EP, '-', 5);
		H.Set(hi_PHP, '-', 2);
		H.Set(hi_DP, '+', 0, 0.25);
	}
	if (H.GetI(hi_PHP) < 0) H.Set(hi_PHP, '0', 0);
	if (H.GetI(hi_PHP) > 100) H.Set(hi_PHP, 'N', 100);
	if (H.GetD(hi_DP) < 0.0) H.Set(hi_DP, '0', 0);
	if (H.GetI(hi_HP) > 75 && H.GetI(hi_FP) >= 30) {
		H.Set(hi_DP, '-', 0, 1.0);
		H.Set(hi_PHP, '+', 2);
	}
	else if (H.GetI(hi_HP) > 50 && H.GetI(hi_FP) >= 30) {
		H.Set(hi_DP, '-', 0, 0.5);
		H.Set(hi_PHP, '+', 1);
	}
	if (H.GetI(hi_EP) > 100) H.Set(hi_EP, 'N', 100);
	if (H.GetI(hi_EP) < 0) H.Set(hi_EP, '0', 0);
	if (H.GetI(hi_EP) > 100) H.Set(hi_EP, 'N', 100);
	if (H.GetI(hi_EP) < 0) H.Set(hi_EP, '0', 0);
	if (H.GetI(hi_HP) < 0) H.Set(hi_HP, '0', 0);
	if (H.GetI(hi_HP) >= 25 && H.GetI(hi_HP) < 50) {
		H.Set(hi_DP, '+', 0, 0.1);
		H.Set(hi_PHP, '-', 2);
	}
	else if (H.GetI(hi_HP) < 25 && H.GetI(hi_HP) > 0) {
		H.Set(hi_DP, '+', 0, 0.5);
		H.Set(hi_PHP, '-', 3);
	}
	else if (H.GetI(hi_HP) == 0) {
		H.Set(hi_DP, '+', 0, 1.0);
		H.Set(hi_PHP, '-', 5);
	}
	if (H.GetD(hi_DP) > 100.0) H.Set(hi_DP, 'N', 0, 100.0);
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
		T.HV(13, 1, 15, "��������� ���������");
	}
	else {
		T.HV(13, 1, 15, "������ ������ � �����");
		T.V(4, 15);
		T.HV(13, 2, 15, "������� ����");
		T.V(4, 15);
		T.HV(13, 3, 15, "����� �� ������� ����");
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
void Game::Eating(Inventory& I, bool& IsBack, int &Hour) {
	int CurrentPage = 0;
	int TotalPage = (ConsumableCount % 9 == 0) ? ConsumableCount / 9 : ConsumableCount / 9 + 1;
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
				(*ConsumableVector[0 + int(CurrentPage * 9)]).Taking(H);
				return;
			}
			break;
		}
		case 50: {
			if (Size >= 2) {
				(*ConsumableVector[1 + CurrentPage * 9]).Taking(H);
				return;
			}
			break;
		}
		case 51: {
			if (Size >= 3) {
				(*ConsumableVector[2 + int(CurrentPage * 9)]).Taking(H);
				return;
			}
			break;
		}
		case 52: {
			if (Size >= 4) {
				(*ConsumableVector[3 + int(CurrentPage * 9)]).Taking(H);
				return;
			}
			break;
		}
		case 53: {
			if (Size >= 5) {
				(*ConsumableVector[4 + int(CurrentPage * 9)]).Taking(H);
				return;
			}
			break;
		}
		case 54: {
			if (Size >= 6) {
				(*ConsumableVector[5 + int(CurrentPage * 9)]).Taking(H);
				return;
			}
			break;
		}
		case 55: {
			if (Size >= 7) {
				(*ConsumableVector[6 + int(CurrentPage * 9)]).Taking(H);
				return;
			}
			break;
		}
		case 56: {
			if (Size >= 8) {
				(*ConsumableVector[7 + int(CurrentPage * 9)]).Taking(H);
				return;
			}
			break;
		}
		case 57: {
			if (Size >= 9) {
				(*ConsumableVector[8 + int(CurrentPage * 9)]).Taking(H);
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
		cout << "�� �����..." << endl;
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
	T.PRC(1, "��������� � ������� ����?\n");
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
void Game::Back(int &Hour, bool& IsBack) {
	Hour--;
	IsBack = true;
}
void Game::Actions(int Choose, bool& Life, int& Hour, bool &IsBack) {
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
	cout << "�� ����� ��������� ���������. ��������� �������� ����, ������������ ����������� ��������� ������� �������, �� ������ ������ ��� ������ �� ����������� �����.\n� ���� ����� ���� � ������������ �������. ��� ���������� �������� � ������, � ����� ��������� ����������� ���������" << endl;
	T.V(4, 45);
	SetConsoleTextAttribute(h, 15);
	system("pause");
	I.Phenothan.SetNew(rand() % 2 + 1);
	I.Aspirin.SetNew(2 + rand() % 2);
	I.CannedBeef.SetNew(rand() % 3 + 1);
	I.EnergyBar.SetNew(1 + rand() % 2);
	I.Hardtack.SetNew(rand() % 3 + 2);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}
void Game::MenuReturning(bool& Working) {
	system("cls");
	SetConsoleTextAttribute(h, 4);
	cout << "�� ������" << endl;
	T.V(4, 35);
	SetConsoleTextAttribute(h, 13);
	T.V(1);
	T.PRC(10, "(1) ");
	T.PRC(15, "��������� � ������� ����");
	T.PRC(4, " (2) ");
	T.PRC(15, "����� �� ����\n");
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
	// ���������, ���������� ����� ������ ����
	H.Set(hi_Sol, '+', 1);
	if (H.GetI(hi_Sol) != 1 && !IsExit) {
		Sleeping();
		H.Set(hi_HP, '+', 5);
		H.Set(hi_DP, '-', 0, 1.0);
		H.Set(hi_EP, '+', 50);
		H.Set(hi_FP, '-', 15);
	}
	if (H.GetI(hi_HP) > 100) H.Set(hi_HP, 'N', 100);
	else if (H.GetI(hi_HP) < 0) H.Set(hi_HP, '0', 0);
	if (H.GetI(hi_FP) > 100) H.Set(hi_FP, 'N', 100);
	else if (H.GetI(hi_FP) < 0) H.Set(hi_FP, '0', 0);
	if (H.GetI(hi_EP) > 100) H.Set(hi_EP, 'N', 100);
	else if (H.GetI(hi_EP) < 0) H.Set(hi_EP, '0', 0);
	if (H.GetD(hi_DP) > 100) H.Set(hi_DP, 'N', 0, 100.0);
	else if (H.GetD(hi_DP) < 0) H.Set(hi_DP, '0', 0, 0.0);
}
Game::Game() {
	ConsumableMap["Aspirin"] = I.Aspirin;
	ConsumableMap["Aspirin"].SetName("������� ��������");
	ConsumableMap["BartonsDrug"] = I.BartonsDrug;
	ConsumableMap["BartonsDrug"].SetName("��������� ���������� �������");
	ConsumableMap["CannedApple"] = I.CannedApple;
	ConsumableMap["CannedApple"].SetName("������������������ ������");
	ConsumableMap["CannedBeef"] = I.CannedBeef;
	ConsumableMap["CannedBeef"].SetName("���������������� ��������");
	ConsumableMap["DarkChocolateBar"] = I.DarkChocolateBar;
	ConsumableMap["DarkChocolateBar"].SetName("������ �������� ��������");
	ConsumableMap["EnergyBar"] = I.EnergyBar;
	ConsumableMap["EnergyBar"].SetName("�������������� ��������");
	ConsumableMap["FishSoup"] = I.FishSoup;
	ConsumableMap["FishSoup"].SetName("������� �� ������");
	ConsumableMap["Gericline"] = I.Gericline;
	ConsumableMap["Gericline"].SetName("���� ���������");
	ConsumableMap["Hardtack"] = I.Hardtack;
	ConsumableMap["Hardtack"].SetName("����� �����");
	ConsumableMap["MeatBriquette"] = I.MeatBriquette;
	ConsumableMap["MeatBriquette"].SetName("������ ������");
	ConsumableMap["MeltedCheese"] = I.MeltedCheese;
	ConsumableMap["MeltedCheese"].SetName("�������� ����������� ����");
	ConsumableMap["MushroomSoup"] = I.MushroomSoup;
	ConsumableMap["MushroomSoup"].SetName("������� ��� � �������");
	ConsumableMap["Palont"] = I.Palont;
	ConsumableMap["Palont"].SetName("���� \"������\"");
	ConsumableMap["Phenothan"] = I.Phenothan;
	ConsumableMap["Phenothan"].SetName("�������� ��������");
	ConsumableMap["RicePurge"] = I.RicePurge;
	ConsumableMap["RicePurge"].SetName("�������� � �����");
	ConsumableMap["Trivoclisine"] = I.Trivoclisine;
	ConsumableMap["Trivoclisine"].SetName("������ � �������������");
}
int Game::Menu() {
	system("cls");
	SetConsoleTextAttribute(h, 13);
	cout << "��������� �� ����� 0.1" << endl;
	SetConsoleTextAttribute(h, 4);
	T.V(4, 25);
	SetConsoleTextAttribute(h, 13);
	cout << "(1) ";
	SetConsoleTextAttribute(h, 15);
	cout << "������ ����" << endl;
	SetConsoleTextAttribute(h, 4);
	T.V(4, 5);
	SetConsoleTextAttribute(h, 13);
	cout << "(2) ";
	SetConsoleTextAttribute(h, 15);
	cout << "������ � ����" << endl;
	SetConsoleTextAttribute(h, 4);
	T.V(4, 5);
	SetConsoleTextAttribute(h, 13);
	cout << "(3) ";
	SetConsoleTextAttribute(h, 15);
	cout << "������������" << endl;
	SetConsoleTextAttribute(h, 4);
	T.V(4, 5);
	SetConsoleTextAttribute(h, 13);
	cout << "(4) ";
	SetConsoleTextAttribute(h, 15);
	cout << "����� �� ����" << endl;
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
	// �������� �������, ������ � ��� �� � ����������
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
				continue;
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
	cout << "������ � ����" << endl;
	SetConsoleTextAttribute(h, 4);
	T.V(4, 35);
	SetConsoleTextAttribute(h, 15);
	cout << "��� ���" << endl;
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
	T.PRC(13, "������������\n");
	T.V(4, 45);
	T.PRC(13, "������������� �� ����������: ");
	T.PRC(15, "\n- Programming Harius\n");
	T.PRC(15, "- DobbikoV\n");
	T.PRC(15, "- GoogeTan\n");
	T.V(4, 25);
	T.PRC(13, "����������: ");
	T.PRC(15, "\n- Programming Harius\n");
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
	cout << "�� ����� ������ �����?" << endl;
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