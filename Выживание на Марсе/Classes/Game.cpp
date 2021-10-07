#include "Game.h"
#include <conio.h>
#include <fstream>
#include <string>
#define NightmareCount 9

void Game::Introduction() {
	SetConsoleTextAttribute(h, 15);
	system("cls");
	cout << "�� ������ �����. ������ 2 ������ �� ���� ������, �� ����� ����� �����" << endl;
	cout << "������������� � �������, �� ��������� �� ���� ����. �� ��� ���� ���-��, ����� ������� �� ����" << endl;
	cout << "��������� ���������� � �������� ������ - ��� � ��, ��� ���� ������� �� ���� �����������" << endl;
	cout << "����� ������� �� ������ �������� ��� ������ � ����� ��������, ������� ��������� �������� � �����" << endl;
	cout << "\"���������� ����������, ������ � ����� �� �����\", - ������� ��" << endl;
	cout << "�� ��� �� ������� ����� ������ � ����� �����" << endl;
	Text::V(4, 55);
	system("pause");
}

void Game::InfoShowing(int HP, int FP, int EP, int PHP, double DP, int Sol, int Hour) {
	// ���������� ���������
	bool Hallucination = H.GetI(HumanInfo::HalChance) - rand() % 101 >= 0 && H.GetI(HumanInfo::PHP) <= 20;
	if (Hallucination) {
		Text::PRC(3, "29.11.1979\n");
		Text::V(4, 15);
		Text::PRC(15, to_string(rand() % 24) + ':' + to_string(10 + rand() % 50) + '\n');
	}
	else {
		Text::PRC(3, "��� ");
		Text::PRC(15, to_string(H.GetI(HumanInfo::Sol)) + '\n');
		Text::V(4, 15);
		Text::PRC(15, to_string(Hour) + ":00\n");
	}
	Text::V(4, 45);

	Text::PRC(13, "��������� ��������: ");
	if (!Hallucination) {
		if (HP >= 90)
			Text::PRC(1, "���������\n");
		else if (HP >= 70)
			Text::PRC(3, "��������\n");
		else if (HP >= 50)
			Text::PRC(10, "�������\n");
		else if (HP >= 30)
			Text::PRC(6, "������\n");
		else if (HP >= 20)
			Text::PRC(4, "�������\n");
		else
			Text::PRC(4, "�����������\n");
	}
	else
		Text::PRC(4, "����\n");
	Text::V(4, 45);

	Text::PRC(13, "��������� ���������: ");
	if (!Hallucination) {
		if (DP >= 90.0)
			Text::PRC(4, "������������\n");
		else if (DP >= 75.0 && DP < 90)
			Text::PRC(4, "����� ���������\n");
		else if (DP >= 50.0 && DP < 75.0)
			Text::PRC(4, "���������\n");
		else if (DP >= 25.0 && DP < 50.0)
			Text::PRC(6, "�������\n");
		else if (DP > 0.0 && DP < 25.0)
			Text::PRC(10, "������\n");
		else
			Text::PRC(1, "�����������\n");
	}
	else
		Text::PRC(4, "����\n");
	Text::V(4, 45);

	Text::PRC(13, "��������� ������������ ��������: ");
	if (!Hallucination) {
		if (PHP >= 90)
			Text::PRC(1, "���������\n");
		else if (PHP >= 70)
			Text::PRC(3, "��������\n");
		else if (PHP >= 50)
			Text::PRC(10, "�������\n");
		else if (PHP >= 30)
			Text::PRC(6, "������\n");
		else if (PHP >= 20)
			Text::PRC(4, "�������\n");
		else
			Text::PRC(4, "�����������\n");
	}
	else
		Text::PRC(4, "����������\n");
	Text::V(4, 45);

	Text::PRC(13, "������� �������: ");
	if (FP >= 90)
		Text::PRC(1, "������\n");
	else if (FP >= 75)
		Text::PRC(3, "�������\n");
	else if (FP >= 50)
		Text::PRC(10, "�������\n");
	else if (FP >= 25)
		Text::PRC(6, "������������������\n");
	else if (FP < 25)
		Text::PRC(4, "�����\n");
	Text::V(4, 45);

	Text::PRC(13, "������� �������������: ");
	if (H.GetI(HumanInfo::WP) >= 90)
		Text::PRC(1, "�������\n");
	else if (H.GetI(HumanInfo::WP) >= 75)
		Text::PRC(3, "������ ������\n");
	else if (H.GetI(HumanInfo::WP) >= 50)
		Text::PRC(10, "������\n");
	else if (H.GetI(HumanInfo::WP) >= 25)
		Text::PRC(6, "�����\n");
	else if (H.GetI(HumanInfo::WP) < 25)
		Text::PRC(4, "�������������\n");
	Text::V(4, 45);

	Text::PRC(13, "������� ���������: ");
	if (EP >= 100)
		Text::PRC(1, "�������\n");
	else if (EP >= 80)
		Text::PRC(3, "������ �����\n");
	else if (EP >= 60)
		Text::PRC(10, "�����\n");
	else if (EP >= 40)
		Text::PRC(6, "�������\n");
	else if (EP >= 20)
		Text::PRC(4, "�������\n");
	else
		Text::PRC(4, "������\n");
	Text::V(4, 45);
}

int Game::NewGame() {
	system("cls");
	Text::PRC(13);
	Text::V(1);
	Text::V(4, 30);
	Text::HV(13, 1, 15, "������ ����� ����");
	if (!S.GetNew()) {
		Text::V(4, 20);
		Text::HV(13, 2, 15, "���������� ����");
	}
	while (true) {
		int Click = _getch();
		if (Click == 49)
			return 1;
		else if (!S.GetNew() && Click == 50)
			return 2;
	}
}

int Game::ActionsChoose(int Sol, int Hour) {
	SetConsoleTextAttribute(h, 10);
	Text::V(1);
	Text::V(4, 30);
	bool FirstAction = false;
	if (Sol == 1 && Hour == 7) {
		FirstAction = true;
		Text::HV(13, 1, 15, "��������� ���������");
	}
	else {
		Text::HV(13, 1, 15, "����� ������");
		Text::V(4, 15);
		Text::HV(13, 2, 15, "������� ����");
		Text::V(4, 15);
		Text::HV(13, 3, 15, "����� �� ������� ����");
		Text::V(4, 15);
		Text::HV(13, 4, 15, "������ �� ������");
	}
	while (true) {
		int Click = _getch();
		if (Click == 49 && FirstAction)
			return 0;
		else {
			if (Click == 49 && !FirstAction)
				return 1;
			else if (Click == 50 && !FirstAction)
				return 2;
			else if (Click == 51 && !FirstAction)
				return 3;
			else if (Click == 52 && !FirstAction)
				return 4;
			else if (Click == 27)
				return 5;
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
		case 27:
			Back(Hour, IsBack);
			return;
		case 49:
			if (Size >= 1) {
				(*ConsumableVector[(size_t)0 + CurrentPage * (size_t)9]).Taking();
				return;
			}
			break;
		case 50:
			if (Size >= 2) {
				(*ConsumableVector[(size_t)1 + CurrentPage * (size_t)9]).Taking();
				return;
			}
			break;
		case 51:
			if (Size >= 3) {
				(*ConsumableVector[(size_t)2 + (size_t)CurrentPage * 9]).Taking();
				return;
			}
			break;
		case 52:
			if (Size >= 4) {
				(*ConsumableVector[(size_t)3 + (size_t)CurrentPage * 9]).Taking();
				return;
			}
			break;
		case 53:
			if (Size >= 5) {
				(*ConsumableVector[4 + (size_t)CurrentPage * 9]).Taking();
				return;
			}
			break;
		case 54:
			if (Size >= 6) {
				(*ConsumableVector[5 + (size_t)CurrentPage * 9]).Taking();
				return;
			}
			break;
		case 55:
			if (Size >= 7) {
				(*ConsumableVector[6 + (size_t)CurrentPage * 9]).Taking();
				return;
			}
			break;
		case 56:
			if (Size >= 8) {
				(*ConsumableVector[7 + (size_t)CurrentPage * 9]).Taking();
				return;
			}
			break;
		case 57:
			if (Size >= 9) {
				(*ConsumableVector[8 + (size_t)CurrentPage * 9]).Taking();
				return;
			}
			break;
		case 65:
			if (CurrentPage)
				CurrentPage--;
		    break;
		case 68:
			if (CurrentPage < TotalPage - 1)
				CurrentPage++;
			break;
		case 97:
			if (CurrentPage)
				CurrentPage--;
			break;
		case 100:
			if (CurrentPage < TotalPage - 1)
				CurrentPage++;
			break;
		case 194:
			if (CurrentPage < TotalPage - 1)
				CurrentPage++;
			break;
		case 212:
			if (CurrentPage)
				CurrentPage--;
			break;
		case 226: 
			if (CurrentPage < TotalPage - 1)
				CurrentPage++;
			break;
		case 244:
			if (CurrentPage)
				CurrentPage--;
			break;
		}
	}
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}

void Game::Outing(bool& Life, bool& Working, int& Hour, bool& IsBack) {
	system("cls");
	bool Condition = Hour <= 18 && H.GetI(HumanInfo::EP) >= 60 && H.GetI(HumanInfo::PHP) >= 30;
	if (Condition)
		B.LocationGeneration(Life, Working, ++Hour);
	else if (Hour > 18 && H.GetI(HumanInfo::EP) >= 60 && H.GetI(HumanInfo::PHP) >= 30)
		Text::PRC(3, "\"� ����� ����� �� ������, �� ��� ������\", - ������������ ����� � ����� ������, � �� ������ �� �����\n");
	else if (Hour <= 18 && H.GetI(HumanInfo::EP) < 60 && H.GetI(HumanInfo::PHP) >= 30)
		Text::PRC(3, "\"���� ��� ���� �����, �� � ������� ������ - ��� ���... �� ����... \", - ������ �� ���� � � ���������� ������\n");
	else if (Hour > 18 && H.GetI(HumanInfo::EP) < 60 && H.GetI(HumanInfo::PHP) >= 30)
		Text::PRC(3, "\"� ����� �� �������, �� ��� ���� ������ �����. �� � ���� ��� �������\", - ������� ��, ��������� �� ������\n");
	else if (Hour > 18 && H.GetI(HumanInfo::EP) < 60 && H.GetI(HumanInfo::PHP) < 30)
		Text::PRC(3, "\"� ������ �� �����! � ���� ����� ����, �������� ������� ���, ��� ��� � ����� ��������!\", - ������ ������� ��, ������� �� �������� �����\n");
	else if (Hour > 18 && H.GetI(HumanInfo::EP) >= 60 && H.GetI(HumanInfo::PHP) < 30)
		Text::PRC(3, "\"� ���� ���� ����, �� ��� ������� � �������\", - �� ������� ������� ��\n");
	else if (Hour <= 18 && H.GetI(HumanInfo::EP) < 60 && H.GetI(HumanInfo::PHP) < 30)
		Text::PRC(3, "\"����� ��� ����, �� ��������� � ��������� ������� ����� �� ���� - � ������ �� �����\", - �� ������� ������ ��\n");
	else if (Hour <= 18 && H.GetI(HumanInfo::EP) >= 60 && H.GetI(HumanInfo::PHP) < 30)
		Text::PRC(3, "\"��� ������� ����-���� ����\", - ����������� ��\n");
	if (!Condition) {
		Text::V(4, 40);
		Back(Hour, IsBack);
		Text::PRC(15);
		system("pause");
	}
}

void Game::Workplace(int& Hour, bool& IsBack) {
	system("cls");
	Text::PRC(1, "�������� ��������:\n");
	Text::V(4, 40);
	Text::HV(13, 1, 15, "�������� �����");
	Text::V(4, 10);
	Text::HV(13, 2, 15, "����������� �������");
	Text::V(4, 10);
	Text::HV(13, 3, 15, "����������� �������");
	Text::V(4, 10);
	Text::HV(13, 4, 15, "�������� �������");
	if (Diaries.size() > 0) {
		Text::V(4, 10);
		Text::HV(13, 5, 15, "�������� �������� �����������");
	}

	Text::V(4, 40);
	int Click;
	while (true) {
		Click = _getch();
		switch (Click) {
		case 49:
			Click = 1;
			goto End;
		case 50:
			Click = 2;
			goto End;
		case 51:
			Click = 3;
			goto End;
		case 52:
			Click = 4;
			goto End;
		case 53:
			if (Diaries.size() > 0) {
				Click = 5;
				goto End;
			}
			break;
		case 27:
			Back(Hour, IsBack);
			goto End;
		}
	}
End:
	switch (Click) {
	case 1:
		BookReading(Hour, IsBack);
		break;
	case 2:
		DiaryReading(Hour, IsBack);
		break;
	case 3:
		ReadNotes(Hour, IsBack);
		break;
	case 4:
		NotesWriting();
		break;
	case 5:
		OthersDiaryReading();
		break;
	}
}

void Game::BookReading(int& Hour, bool& IsBack) {
	system("cls");
	Text::PRC(1, "����������\n");
	Text::V(4, 70);
	for (size_t i = 0; i < BookVector.size(); i++)
		Text::HV(13, i + 1, 15, BookVector[i]->GetName());
	if (!BookVector.size()) {
		Text::PRC(3, "���������� �����������\n");
		Text::V(4, 70);
		Text::PRC(15);
		Back(Hour, IsBack);
		system("pause");
	}
	else {
		int Click;
		Text::V(4, 70);
		while (true) {
			Click = _getch();
			switch (Click) {
			case 49: {
				Click = 0;
				goto Br;
			}
			case 50: {
				if (BookVector.size() >= 2) {
					Click = 1;
					goto Br;
				}
			}
			case 51: {
				if (BookVector.size() >= 3) {
					Click = 2;
					goto Br;
				}
			}
			case 52: {
				if (BookVector.size() >= 4) {
					Click = 3;
					goto Br;
				}
			}
			case 53: {
				if (BookVector.size() >= 5) {
					Click = 4;
					goto Br;
				}
			}
			case 54: {
				if (BookVector.size() >= 6) {
					Click = 5;
					goto Br;
				}
			}
			case 55: {
				if (BookVector.size() >= 7) {
					Click = 6;
					goto Br;
				}
			}
			case 56: {
				if (BookVector.size() >= 8) {
					Click = 7;
					goto Br;
				}
			}
			case 57: {
				if (BookVector.size() >= 9) {
					Click = 8;
					goto Br;
				}
			}
			case 27: {
				Back(Hour, IsBack);
				return;
			}
			}
		}
	Br:
		BookVector[Click]->Taking();
	}
}

void Game::DiaryReading(int& Hour, bool& IsBack) {
	system("cls");
	Text::PRC(13, "��� ");
	Text::PRC(15, to_string(H.GetI(HumanInfo::Sol)) + '\n');
	Text::V(4, 60);
	for (size_t i = 0; i < DiaryVector.size(); i++) {
		Text::PRC(1, " - ");
		Text::PRC(15, DiaryVector[i] + "\n\n");
		if (i + 1 == DiaryVector.size()) Text::V(4, 60);
	}
	if (!DiaryVector.size()) {
		Text::PRC(15, "����������� ������ �� ����������� ����\n");
		Text::V(4, 60);
		Back(Hour, IsBack);
	}
	Text::PRC(15);
	system("pause");
}

void Game::ReadNotes(int& Hour, bool& IsBack) {
	ifstream fin("Data\\Notes.txt");
	string Temp;
	NotesVector.clear();
	while (!fin.eof()) {
		getline(fin, Temp);
		if (Temp.size() > 1)
			NotesVector.push_back(Temp);
	}
	system("cls");
	Text::PRC(1, "�������\n");
	Text::V(4, 60);
	if (!NotesVector.size()) {
		Text::PRC(3, "������� ������������\n");
		Back(Hour, IsBack);
	}
	for (size_t i = 0; i < NotesVector.size(); i++)
		Text::PRC(15, NotesVector[i] + '\n');
	Text::V(4, 60);
	Text::PRC(15);
	system("pause");
}

void Game::NotesWriting() {
	ofstream fout1("Data\\Notes.txt", ofstream::app);
	system("cls");
	Text::PRC(3, "�������� �������: ");
	string Temp;
	Text::PRC(15);
	cin >> ws;
	getline(cin, Temp);
	if (Temp == "nofap") {
		Temp = "����������� �������-���������!";
		if (!IsAchMap[Ach_Nofap]) {
			ofstream fout("Data\\Achievements.txt", ofstream::app);
			fout << "����-�������\n���� ������ ���������� Nofap � ������� ������� � ����-�����\n";
			IsAchMap[Ach_Nofap] = true;
			fout.close();
		}
	}
	fout1 << "��� " + to_string(H.GetI(HumanInfo::Sol)) + ", " + to_string(H.GetI(HumanInfo::Hour)) + ":00  " + Temp << endl;
}

bool Game::Statement(string Header, string Text) {
	system("cls");
	Text::PRC(1, Header + '\n');
	Text::V(4, 60);
	Text::PRC(15, Text);
	Text::V(4, 60);
	Text::HV(13, 1, 15, "��������� �����");
	Text::HV(13, 2, 15, "��������� � ������� ����");
	while (true) {
		int Click = _getch();
		switch (Click) {
		case 49:
			return false;
		case 50:
			return true;
		}
	}
}

void Game::Nightmare(string Path) {
	ifstream fin(Path);
	int Size;
	string Temp;
	fin >> Size;
	vector<vector<pair<int, string>>> Text(Size);
	for (size_t i = 0; i < Text.size(); i++) {
		fin >> Size;
		Text[i].resize(Size);
		for (int j = 0; j < Size; j++) {
			fin >> ws;
			getline(fin, Text[i][j].second);
			fin >> Text[i][j].first;
		}
	}
	fin >> Size;
	H.Set(HumanInfo::PHP, '+', Size);
	fin >> Size;
	for (int i = 0; i < Size; i++) {
		fin >> ws;
		getline(fin, Temp);
		DiaryVector.push_back(Temp);
	}
	for (size_t i = 0; i < Text.size(); i++) {
		system("cls");
		for (size_t j = 0; j < Text[i].size(); j++)
			Text::PRC(Text[i][j].first, Text[i][j].second + '\n');
		Text::V(4, 70);
		Text::PRC(15);
		system("pause");
	}
}

bool Game::Sleeping() {
	int Counter = 0;
	int HoursN = 23;
	while (Counter != 8) {
		system("cls");
		Text::PRC(13, "�� �����...\n");
		Text::V(4, 30);
		Text::PRC(3, to_string(HoursN++) + ":00\n");
		if (HoursN == 24) HoursN = 0;
		Counter++;
		H.EffectsTick();
		Sleep(970);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		if (rand() % (50 - NightmareChance) == 0 && NightmareNumber <= NightmareCount) {
			Nightmare("Data\\Nightmares\\" + to_string(NightmareNumber++) + ".txt");
			NightmareChance = 0;
			return true;
		}
	}
	if (NightmareChance < 45)
		NightmareChance += 9;
	return false;
}

void Game::Escape(bool& Life, int& Hour, bool& IsBack) {
	system("cls");
	Text::PRC(1, "��������� � ������� ����?\n");
	Text::V(2);
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

void Game::Actions(int Choose, bool& Life, int& Hour, bool& IsBack, bool& Working) {
	switch (Choose) {
	case 0:
		RoomLooking(I);
		break;
	case 1:
		Outing(Life, Working, Hour, IsBack);
		break;
	case 2:
		Eating(I, IsBack, Hour);
		break;
	case 3:
		Workplace(Hour, IsBack);
		break;
	case 4:
		H.Set(HumanInfo::PHP, '-', 5);
		break;
	case 5:
		Escape(Life, Hour, IsBack);
		break;
	}
}

void Game::RoomLooking(Inventory& I) {
	system("cls");
	Text::PRC(15, "�� �������� �������. ��� - ��� �� ����� - ���������� ������. � ����� ������ ������ � ����������. ��� ������� �������� �������� �������� �� �������.\n��������� ����� ��������, �� ������� ������� ������, ������������ �� �������, ������, ������ �������� ����� �� ������������. �� �� �������� �����-�� ����� � ��� ������� ����\n�� �������� ���� �������� ��������� ������������� �����. \"�����, ����� ��������� ������\", - ������ ��\n");
	Text::V(4, 45);
	Text::PRC(15);
	system("pause");
	I.Aspirin.SetNew(2);
	I.BottledWater.SetNew(2);
	I.Hardtack.SetNew(rand() % 2 + 1);
	I.DriedFruits.SetNew(rand() % 2 + 1);
	I.ScienceFiction.SetNew();
	DiaryVector.push_back("������� �����, ������� ����� �� �����, �������� ��� �������. ��� ������������ - 2061. ���������, ����� ������ ���?");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}

void Game::Death(bool& Working, bool& Life) {
	system("cls");
	Text::PRC(4, "�� ������\n");
	Text::V(4, 35);
	Text::PRC(13);
	Text::V(1);
	Text::PRC(10, "(1) ");
	Text::PRC(15, "��������� � ������� ����");
	Text::PRC(4, " (2) ");
	Text::PRC(15, "����� �� ����\n");
	int Click;
	Life = false;
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
	
	Working = Click != 2;
}

void Game::ChangesDay(bool IsExit) {
	// ���������, ���������� ����� ������ ����
	H.Set(HumanInfo::Sol, '+', 1);
	DiaryVector.clear();
	if (H.GetI(HumanInfo::Sol) != 1 && !IsExit) {
		if (!Sleeping())
			H.Set(HumanInfo::PHP, '+', 20);
		H.Set(HumanInfo::HP, '+', 5);
		H.Set(HumanInfo::DP, '-', 1.0);
		H.Set(HumanInfo::EP, '+', 50);
		H.Set(HumanInfo::FP, '-', 15);
		H.Set(HumanInfo::WP, '-', 20);
		Validate();
	}
}

Game::Game() {
	Room::SetPointer(&H);
	Consumable::SetPointer(&H);
	Effect::SetPointer(&H);
	Action::SetPointer(&H);
	Enemy::SetPointer(&H, &S);
	Tool::SetPointer(&H, &I);
	Obstacle::SetPointer(&H);
	H.SetPointer(&S, &I.Hand, &I);
	B.SetPointer(&H, &S);
	SeenEnemies.resize(5, false);
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
	ConsumableMap["BottledWater"] = &I.BottledWater;
	ConsumableMap["EnergyDrink"] = &I.EnergyDrink;
	ConsumableMap["OrangeJuice"] = &I.OrangeJuice;
	
	BookMap["Comics"] = &I.Comics;
	BookMap["Adventures"] = &I.Adventures;
	BookMap["CriminalDrama"] = &I.CriminalDrama;
	BookMap["ScienceFiction"] = &I.ScienceFiction;
	BookMap["Thriller"] = &I.Thriller;
	EffectMap["Adrenaline"] = Effect("Data\\Effects\\Adrenaline.txt");
	EffectMap["Agony"] = Effect("Data\\Effects\\Agony.txt");
	EffectMap["Calming"] = Effect("Data\\Effects\\Calming.txt");
	EffectMap["Fatigue"] = Effect("Data\\Effects\\Fatigue.txt");
	EffectMap["Recovery"] = Effect("Data\\Effects\\Recovery.txt");
	EffectMap["Satiety"] = Effect("Data\\Effects\\Satiety.txt");
	EffectMap["Starvation"] = Effect("Data\\Effects\\Starvation.txt");
	Room1.Set("Data\\Buildings\\Barracks\\First.txt");
	Room2.Set("Data\\Buildings\\Barracks\\Second.txt");
	Room3.Set("Data\\Buildings\\Canteen\\First.txt");
	Room4.Set("Data\\Buildings\\Canteen\\Second.txt");
	Room5.Set("Data\\Buildings\\Warehouse\\First.txt");
	Room6.Set("Data\\Buildings\\Warehouse\\Second.txt");
	Room7.Set("Data\\Buildings\\Medical Centre\\First.txt");
	Room8.Set("Data\\Buildings\\Medical Centre\\Second.txt");
	Room9.Set("Data\\Buildings\\Laboratory\\First.txt");
	Room10.Set("Data\\Buildings\\Laboratory\\Second.txt");
	B.GetPath();
	Obstacles["Planks"] = Obstacle("Data\\Obstacles\\Planks.txt");
	Obstacles["Boxes"] = Obstacle("Data\\Obstacles\\Boxes.txt");
	Obstacles["Bolts"] = Obstacle("Data\\Obstacles\\Bolts.txt");
	Obstacles["Screws"] = Obstacle("Data\\Obstacles\\Screws.txt");
	Obstacles["Window"] = Obstacle("Data\\Obstacles\\Window.txt");
	Obstacles["Wooden door"] = Obstacle("Data\\Obstacles\\Wooden door.txt");

	ActionObstacles["Wending machine"] = Obstacle("Data\\ActionObstacles\\Wending Machine.txt");
}

int Game::Menu() {
	system("cls");
	Text::PRC(13, "��������� �� �����\n");
	Text::V(4, 30);
	Text::HV(13, 1, 15, "������ ����");
	Text::V(4, 5);
	Text::HV(13, 2, 15, "������ � ����");
	Text::V(4, 5);
	Text::HV(13, 3, 15, "����������");
	Text::V(4, 5);
	Text::HV(13, 4, 15, "������������");
	Text::V(4, 5);
	Text::HV(13, 5, 15, "����� �� ����");
	Text::V(4, 30);
	Text::PRC(15, "v 0.4 beta-test\n");
	int Variety = _getch();
	switch (Variety) {
	case 49:
		return 1;
	case 50:
		return 2;
	case 51:
		return 3;
	case 52:
		return 4;
	case 53:
		return 5;
	case 27:
		return 5;
	}
	return -1;
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
		if (H.GetI(HumanInfo::Hour) >= 23) H.Set(HumanInfo::Hour, '=', 7);
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
			Actions(Choose, Life, Hour, IsBack, Working);
			H.Set(HumanInfo::Hour, '=', Hour);
			if (!(H.GetI(HumanInfo::Sol) == 1 && Hour == 7) && !IsBack)
				H.Changes(Life, Working);
		}
	}
}

void Game::Menu_2(bool& Working) {
	bool Menu = true;
	while (Menu) {
	Start:
		system("cls");
		Text::PRC(13, "������ � ����\n");
		Text::V(4, 35);
		Text::HV(13, 1, 15, "�������� � ������ �������������� ���������");
		Text::V(4, 15);
		Text::HV(13, 2, 15, "����� � ������������");
		Text::V(4, 15);
		Text::HV(13, 3, 15, "������, ������� � �������");
		Text::V(4, 15);
		Text::HV(13, 4, 15, "����� � �� ����������� �� ������");
		Text::V(4, 15);
		Text::HV(13, 5, 15, "��������� � ������� ����");
		Text::V(4, 35);
		while (true) {
			int Variety = _getch();
			switch (Variety) {
			case 49: {
				if (Statement("�������� � ������ �������������� ���������", "� �������� ��������� 5 �������������:\n - ��������\n - ���������\n - ��������������� ���������\n - �������\n - �������\n�� ������ �� ���� ����������� ����� ������� � ������� �� ����������� ������\n")) return;
				goto Start;
			}
			case 50: {
				if (Statement("����� � ������������", "� �������� ����� ���� ����������� ����� �� ������ ���� � ������������ � ������������� ���������� �� ������ ���������\n��� ���������� �������� � ����������� �����, ����� ����� ���������� ���, ������� ���� ����������� ��������������\n������ ������ ����� ����������� �����������, ������� ������� ������� � ������� ������������\n������������ ����� ���������� � ����� �������������� ����������� ������� ���������� ������ 'A' � 'D' ��� �������� ����� � ������ ��������������\n")) return;
				goto Start;
			}
			case 51: {
				if (Statement("������, ������� � �������", "������� �������� ����� ����������� ������, ������������� ���� �������, � ����� ��������� �������\n����� ����� ����� ��� ����������� ��������� � ������� ��� ������ ����\n� ������� �������� ���������� ���� ����� � ��������\n")) return;
				goto Start;
			}
			case 52: {
				if (Statement("����� � �� ����������� �� ������", "������ �������� ��������� ���� ����� ����������� �����. ��� ����� ������ ��������� � ���������.\n����� ����� ���������, ������� �������� ��� ����������� ��������� ������\n����� ����� ���� ������� �������� ��� �������������\n")) return;
				goto Start;
			}
			case 53:
				return;
			case 27:
				return;
			}
		}
	}
}

void Game::Menu_3(bool& Working) {
	ifstream fin("Data\\Achievements.txt");
	string Temp1, Temp2;
	AchievementVector.clear();
	while (!fin.eof()) {
		Temp1 = "";
		Temp2 = "";
		fin >> ws;
		getline(fin, Temp1);
		fin >> ws;
		getline(fin, Temp2);
		if (Temp1.size() > 1 && Temp2.size() > 1) AchievementVector.push_back(make_pair(Temp1, Temp2));
	}
Menu:
	system("cls");
	Text::PRC(13, "����������\n");
	Text::V(4, 60);
	for (size_t i = 0; i < AchievementVector.size(); i++) {
		Text::HV(1, i + 1, 15, AchievementVector[i].first);
		Text::PRC(3, '[' + AchievementVector[i].second + "]\n");
		if (AchievementVector.size() - i - 1) Text::V(4, 35);
	}
	if (!AchievementVector.size())
		Text::PRC(3, "���������� �����������\n");
	Text::V(4, 60);
	Text::HV(13, 1, 15, "�������� ����������");
	Text::HV(13, 2, 15, "��������� � ������� ����");
	while (true) {
		int Variety = _getch();
		switch (Variety) {
		case 49: {
			system("cls");
			Text::PRC(13, "�� ����� ������ �������� ����������?\n");
			Text::V(2);
			while (true) {
				int Click = _getch();
				switch (Click) {
				case 49: {
					ofstream fout("Data\\Achievements.txt");
					IsAchMap.clear();
					return;
				}
				case 50:
					goto Menu;
				}
			}
		}
		case 50:
			return;
		case 27:
			return;
		}
	}
}

void Game::Menu_4(bool& Working) {
	system("cls");
	Text::PRC(13, "������������\n");
	Text::V(4, 45);
	Text::PRC(13, "������������� �� ����������:\n");
	Text::PRC(15, "- Programming Harius\n");
	Text::PRC(15, "- DobbikoV\n");
	Text::PRC(15, "- GoogeTan\n");
	Text::V(4, 25);
	Text::PRC(13, "����������:\n");
	Text::PRC(15, "- Programming Harius\n");
	Text::V(4, 45);
	Text::PRC(15);
	Text::V(3);
	Text::V(2);
	Text::V(4, 25);
	Text::PRC(15);
	while (true) {
		int Variety = _getch();
		switch (Variety) {
		case 49:
			return;
		case 50:
			Working = false;
			return;
		case 27:
			return;
		}
	}
}

void Game::Menu_5(bool& Working) {
	system("cls");
	Text::PRC(13, "�� ����� ������ �����?\n");
	Text::V(2);
	Text::V(4, 25);
	Text::PRC(15);
	while (true) {
		int Variety = _getch();
		switch (Variety) {
		case 49:
			Working = false;
			return;
		case 50:
			return;
		case 27:
			return;
		}
	}
}

void Game::Validate() {
	if (H.GetI(HumanInfo::HP) > 100)
		H.Set(HumanInfo::HP, '=', 100);
	else if (H.GetI(HumanInfo::HP) < 0)
		H.Set(HumanInfo::HP, '=', 0);
	if (H.GetI(HumanInfo::FP) > 100)
		H.Set(HumanInfo::FP, '=', 100);
	else if (H.GetI(HumanInfo::FP) < 0)
		H.Set(HumanInfo::FP, '=', 0);
	if (H.GetI(HumanInfo::WP) > 100)
		H.Set(HumanInfo::WP, '=', 100);
	else if (H.GetI(HumanInfo::WP) < 0)
		H.Set(HumanInfo::WP, '=', 0);
	if (H.GetI(HumanInfo::EP) > 100)
		H.Set(HumanInfo::EP, '=', 100);
	else if (H.GetI(HumanInfo::EP) < 0)
		H.Set(HumanInfo::EP, '=', 0);
	if (H.GetD(HumanInfo::DP) > 100)
		H.Set(HumanInfo::DP, '=', 100.0);
	else if (H.GetD(HumanInfo::DP) < 0)
		H.Set(HumanInfo::DP, '=', 0.0);
	if (H.GetI(HumanInfo::PHP) < 0)
		H.Set(HumanInfo::PHP, '=', 0);
	else if (H.GetI(HumanInfo::PHP) > 100)
		H.Set(HumanInfo::PHP, '=', 100);
	if (H.GetI(HumanInfo::HalChance) > 100)
		H.Set(HumanInfo::HalChance, '=', 100);
	else if (H.GetI(HumanInfo::HalChance) < 0)
		H.Set(HumanInfo::HalChance, '=', 0);
}

ofstream& operator<<(ofstream& fout, Game::Tool T) {
	fout << T.GetDurability() << endl;
	fout << T.GetBreakPerUse();
	return fout;
}

ifstream& operator>>(ifstream& fin, Game::Tool& T) {
	double Temp;
	fin >> Temp;
	T.SetDurability(Temp);
	fin >> Temp;
	T.SetBreakPerUse(Temp);
	return fin;
}

void Game::OthersDiaryReading() {
	size_t CurrentPage = 0;
	size_t TotalPages = Diaries.size() / 9 + Diaries.size() % 9 != 0;

_Start:
	size_t Size = (Diaries.size() - CurrentPage * 9 > 8) ? 9 : Diaries.size() - CurrentPage * 9;

	system("cls");
	Text::PRC(13, "��������� ��������\n");
	Text::V(4, 50);
	
	for (size_t i = 0; i < Size; i++) {
		Text::HV(3, i + 1, 15, Diaries[CurrentPage * 9 + i].GetTitle());
		if (Size - i - 1)
			Text::V(4);
	}

	while (true) {
		int Click = _getch();
		
		if (isdigit(Click) && (CurrentPage * 9 + Click - 49) < Diaries.size()) {
			Diaries[CurrentPage * 9 + Click - 49].Read();
			goto _Start;
		}

		switch (Click) {
		case 27:
			return;
		case 75:
			if (CurrentPage > 0)
				CurrentPage--;
		case 77:
			if (CurrentPage < TotalPages - 1)
				CurrentPage++;
		}
	}

	Text::V(4, 50);

	if (!CurrentPage && TotalPages > 1)
		Text::PRC(15, "  ------------------->  \n");
	else if (CurrentPage == TotalPages - 1 && TotalPages > 1)
		Text::PRC(15, "  <-------------------  \n");
	else if (CurrentPage > 0 && CurrentPage < TotalPages - 1)
		Text::PRC(15, "  <-------------------                ------------------->  \n");
}