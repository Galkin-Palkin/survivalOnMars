#include "Game.h"
#include <conio.h>
#include <string>
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
	T.PRC(3, "��� ");
	T.PRC(15, to_string(H.GetI(HumanInfo::Sol)) + '\n');
	T.V(4, 15);
	T.PRC(15, to_string(Hour) + ":00\n");
	T.V(4, 50);
    
	T.PRC(13, "��������� ��������: ");
	if (HP >= 90)
		T.PRC(1, "���������\n");
	else if (HP >= 70)
		T.PRC(3, "��������\n");
	else if (HP >= 50)
		T.PRC(10, "�������\n");
	else if (HP >= 30)
		T.PRC(6, "������\n");
	else if (HP >= 20)
		T.PRC(4, "�������\n");
	else
		T.PRC(4, "�����������\n");
	T.V(4, 45);

	T.PRC(13, "��������� ���������: ");
	if (DP >= 90.0)
		T.PRC(4, "������������\n");
	else if (DP >= 75.0 && DP < 90)
		T.PRC(4, "����� ���������\n");
	else if (DP >= 50.0 && DP < 75.0)
		T.PRC(4, "���������\n");
	else if (DP >= 25.0 && DP < 50.0)
		T.PRC(6, "�������\n");
	else if (DP > 0.0 && DP < 25.0)
		T.PRC(10, "������\n");
	else
		T.PRC(1, "�����������\n");
	T.V(4, 45);

	T.PRC(13, "��������� ������������ ��������: ");
	if (PHP >= 90)
		T.PRC(1, "���������\n");
	else if (PHP >= 70)
		T.PRC(3, "��������\n");
	else if (PHP >= 50)
		T.PRC(10, "�������\n");
	else if (PHP >= 30)
		T.PRC(6, "������\n");
	else if (PHP >= 20)
		T.PRC(4, "�������\n");
	else
		T.PRC(4, "�����������\n");
	T.V(4, 45);

	T.PRC(13, "������� �������: ");
	if (FP >= 90)
		T.PRC(1, "������\n");
	else if (FP >= 75)
		T.PRC(3, "�������\n");
	else if (FP >= 50)
		T.PRC(10, "�������\n");
	else if (FP >= 25)
		T.PRC(6, "������������������\n");
	else if (FP < 25)
		T.PRC(4, "�����\n");
	T.V(4, 45);

	T.PRC(13, "������� ���������: ");
	if (EP >= 100)
		T.PRC(1, "�������\n");
	else if (EP >= 80)
		T.PRC(3, "������ �����\n");
	else if (EP >= 60)
		T.PRC(10, "�����\n");
	else if (EP >= 40)
		T.PRC(6, "�������\n");
	else if (EP >= 20)
		T.PRC(4, "�������\n");
	else
		T.PRC(4, "������\n");
	T.V(4, 50);
}
int Game::NewGame() {
	system("cls");
	T.PRC(13);
	T.V(1);
	T.V(4, 30);
	T.HV(13, 1, 15, "������ ����� ����");
	if (S.GetNew() != true) {
		T.V(4, 20);
		T.HV(13, 1, 15, "���������� ����");
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
	H.Set(HumanInfo::FP, '-', 5);
	Validate();
	H.EffectsTick();
	if (H.GetI(HumanInfo::FP) >= 75) H.Set(HumanInfo::EP, '+', 10);
	else if (H.GetI(HumanInfo::FP) >= 50) H.Set(HumanInfo::EP, '+', 8);
	else if (H.GetI(HumanInfo::FP) >= 25) H.Set(HumanInfo::EP, '+', 5);
	if (H.GetI(HumanInfo::FP) == 0) {
		H.Set(HumanInfo::HP, '-', 1);
		H.Set(HumanInfo::EP, '-', 5);
		H.Set(HumanInfo::PHP, '-', 2);
		H.Set(HumanInfo::DP, '+', 0.25);
		H.AddEffect(Effect("Data\\Effects\\Starvation.txt"));
	}
	if (H.GetI(HumanInfo::HP) > 75 && H.GetI(HumanInfo::FP) >= 30) {
		H.Set(HumanInfo::DP, '-', 1.0);
		H.Set(HumanInfo::PHP, '+', 2);
	}
	else if (H.GetI(HumanInfo::HP) > 50 && H.GetI(HumanInfo::FP) >= 30) {
		H.Set(HumanInfo::DP, '-', 0.5);
		H.Set(HumanInfo::PHP, '+', 1);
	}
	if (H.GetI(HumanInfo::HP) >= 25 && H.GetI(HumanInfo::HP) < 50) {
		H.Set(HumanInfo::DP, '+', 0.25);
		H.Set(HumanInfo::PHP, '-', 2);
	}
	else if (H.GetI(HumanInfo::HP) < 25 && H.GetI(HumanInfo::HP) > 0) {
		H.Set(HumanInfo::DP, '+', 1.0);
		H.Set(HumanInfo::PHP, '-', 3);
	}
	else if (H.GetI(HumanInfo::HP) == 0) {
		H.Set(HumanInfo::DP, '+', 2.0);
		H.Set(HumanInfo::PHP, '-', 5);
		if (H.GetD(HumanInfo::DP) >= 90.0) H.AddEffect(Effect("Data\\Effects\\Agony.txt"));
	}
	Validate();
	if (H.GetD(HumanInfo::DP) >= 100.0) {
		Life = false;
		Hour = 23;
		S.SetNew(true);
		S.Download(H);
		Death(Working);
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
void Game::Outing(int &Hour, bool &IsBack) {
	system("cls");
	bool Condition = Hour <= 18 && H.GetI(HumanInfo::EP) >= 60 && H.GetI(HumanInfo::PHP) >= 50;
	if (Condition) B.LocationGeneration(++Hour);
	else if (Hour > 18 && H.GetI(HumanInfo::EP) >= 60 && H.GetI(HumanInfo::PHP) >= 50)
		T.PRC(3, "\"� ����� ����� �� ������, �� ��� ������\", - ������������ ����� � ����� ������, � �� ������ �� �����\n");
	else if (Hour <= 18 && H.GetI(HumanInfo::EP) < 60 && H.GetI(HumanInfo::PHP) >= 50)
		T.PRC(3, "\"���� ��� ���� �����, �� � ������� ������ - ��� ���... �� ����... \", - ������ �� ���� � � ���������� ������\n");
	else if (Hour > 18 && H.GetI(HumanInfo::EP) < 60 && H.GetI(HumanInfo::PHP) >= 50)
		T.PRC(3, "\"� ����� �� �������, �� ��� ���� ������ �����. �� � ���� ��� �������\", - ������� ��, ��������� �� ������\n");
	else if (Hour > 18 && H.GetI(HumanInfo::EP) < 60 && H.GetI(HumanInfo::PHP) < 50)
		T.PRC(3, "\"� ������ �� �����! � ���� ����� ����, �������� ������� ���, ��� ��� � ����� ��������!\", - ������ ������� ��, ������� �� �������� �����\n");
	else if (Hour > 18 && H.GetI(HumanInfo::EP) >= 60 && H.GetI(HumanInfo::PHP) < 50)
		T.PRC(3, "\"� ���� ���� ����, �� ��� ������� � �������\", - �� ������� ������� ��\n");
	else if (Hour <= 18 && H.GetI(HumanInfo::EP) < 60 && H.GetI(HumanInfo::PHP) < 50)
		T.PRC(3, "\"����� ��� ����, �� ��������� � ��������� ������� ����� �� ���� - � ������ �� �����\", - �� ������� ������ ��\n");
	else if (Hour <= 18 && H.GetI(HumanInfo::EP) >= 60 && H.GetI(HumanInfo::PHP) < 50)
		T.PRC(3, "\"��� ������� ����-���� ����\", - ����������� ��\n");
	if (!Condition) {
		T.V(4, 40);
		Back(Hour, IsBack);
		T.PRC(15);
		system("pause");
	}
}
void Game::Sleeping() {
	int Counter = 0;
	int HoursN = 23;
	while (Counter != 8) {
		system("cls");
		T.PRC(13, "�� �����...\n");
		T.V(4, 30);
		T.PRC(3, to_string(HoursN++) + ":00\n");
		if (HoursN == 24) HoursN = 0;
		Counter++;
		H.EffectsTick();
		Sleep(970);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	}

}
void Game::Escape(bool& Life, int& Hour, bool &IsBack) {
	system("cls");
	T.PRC(1, "��������� � ������� ����?\n");
	T.V(2);
	while (true) {
		int Click = _getch();
		if (Click == 49) {
			Life = false;
			H.Set(HumanInfo::Sol, '-', 1);
			S.Download(H, true);
			break;
		}
		else if (Click == 50) {
			Back(Hour, IsBack);
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
	case 1: Outing(Hour, IsBack); break;
	case 2: Eating(I, IsBack, Hour); break;
	case 3: break;
	case 4: {
		break;
	}
	case 5: Escape(Life, Hour, IsBack); break;
	}
}
void Game::RoomLooking(Inventory& I) {
	system("cls");
	T.PRC(15, "���������� �������� ������ �����\n");
	T.V(4, 45);
	T.PRC(15);
	system("pause");
	I.Aspirin.SetNew(2 + rand() % 1);
	I.Hardtack.SetNew(rand() % 2 + 1);
	I.DriedFruits.SetNew(rand() % 2 + 1);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}
void Game::Death(bool& Working) {
	system("cls");
	T.PRC(4, "�� ������\n");
	T.V(4, 35);
	T.PRC(13);
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
	H.Set(HumanInfo::Sol, '+', 1);
	if (H.GetI(HumanInfo::Sol) != 1 && !IsExit) {
		Sleeping();
		H.Set(HumanInfo::HP, '+', 5);
		H.Set(HumanInfo::DP, '-', 1.0);
		H.Set(HumanInfo::EP, '+', 50);
		H.Set(HumanInfo::FP, '-', 15);
		H.Set(HumanInfo::FP, '+', 20);
		Validate();
	}
}

Game::Game() {
	B.SetPointer(&H);
	Consumable::SetPointer(&H);
	Effect::SetPointer(&H);
	Action::SetPointer(&H);
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
	T.PRC(13, "��������� �� ����� v 0.1\n");
	T.V(4, 25);
	T.HV(13, 1, 15, "������ ����");
	T.V(4, 5);
	T.HV(13, 2, 15, "������ � ����");
	T.V(4, 5);
	T.HV(13, 3, 15, "������������");
	T.V(4, 5);
	T.HV(13, 4, 15, "����� �� ����");
	T.V(4, 25);
	T.PRC(15);
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
		if (H.GetI(HumanInfo::Hour) >= 23) H.Set(HumanInfo::Hour, 'N', 7);
		for (; H.GetI(HumanInfo::Hour) <= 22; H.Set(HumanInfo::Hour, '+', 1)) {
			if (!Life) {
				H.Set(HumanInfo::Hour, '-', 1);
				break;
			}
			system("cls");
			InfoShowing(H.GetI(HumanInfo::HP), H.GetI(HumanInfo::FP), H.GetI(HumanInfo::EP), H.GetI(HumanInfo::PHP), H.GetD(HumanInfo::DP), H.GetI(HumanInfo::Sol), H.GetI(HumanInfo::Hour));
			int Choose = ActionsChoose(H.GetI(HumanInfo::Sol), H.GetI(HumanInfo::Hour));
			int Hour = H.GetI(HumanInfo::Hour);
			bool IsBack = false;
			Actions(Choose, Life, Hour, IsBack);
			H.Set(HumanInfo::Hour, 'N', Hour);
			if (!(H.GetI(HumanInfo::Sol) == 1 && Hour == 7) && !IsBack) Changes(Life, Hour, Working);
		}
	}
}
void Game::Menu_2(bool& Working) {
	system("cls");
	T.PRC(13, "������ � ����\n");
	T.V(4, 35);
	T.PRC(15, "������� ����� ������� � ������ �������\n");
	T.V(4, 35);
	T.PRC(15);
	T.V(3);
	T.V(2);
	T.V(4, 25);
	T.PRC(15);
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
	T.PRC(13, "������������� �� ����������:\n");
	T.PRC(15, "- Programming Harius\n");
	T.PRC(15, "- DobbikoV\n");
	T.PRC(15, "- GoogeTan\n");
	T.V(4, 25);
	T.PRC(13, "����������:\n");
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
	T.PRC(13, "�� ����� ������ �����?\n");
	T.V(2);
	T.V(4, 25);
	T.PRC(15);
	int Variety = _getch();
	switch (Variety) {
	case 49: Variety = 1; break;
	case 50: Variety = 2; break;
	}
	if (Variety == 1) Working = false;
}
void Game::Validate() {
	if (H.GetI(HumanInfo::HP) > 100) H.Set(HumanInfo::HP, 'N', 100);
	else if (H.GetI(HumanInfo::HP) < 0) H.Set(HumanInfo::HP, '0', 0);
	if (H.GetI(HumanInfo::FP) > 100) H.Set(HumanInfo::FP, 'N', 100);
	else if (H.GetI(HumanInfo::FP) < 0) H.Set(HumanInfo::FP, '0', 0);
	if (H.GetI(HumanInfo::EP) > 100) H.Set(HumanInfo::EP, 'N', 100);
	else if (H.GetI(HumanInfo::EP) < 0) H.Set(HumanInfo::EP, '0', 0);
	if (H.GetD(HumanInfo::DP) > 100) H.Set(HumanInfo::DP, 'N', 100.0);
	else if (H.GetD(HumanInfo::DP) < 0) H.Set(HumanInfo::DP, '0', 0.0);
	if (H.GetI(HumanInfo::PHP) < 0) H.Set(HumanInfo::PHP, '0', 0);
	else if (H.GetI(HumanInfo::PHP) > 100) H.Set(HumanInfo::PHP, 'N', 100);
}