#include "Game.h"
void Game::Text::V(int Number, int count) {
	switch (Number) {
	case 1: cout << "�������� ���������� ��������:" << endl; break;
	case 2: {
		PRC(10, "(1) ");
		PRC(15, "��");
		PRC(4, " (2) ");
		PRC(15, "���\n");
		break;
	}
	case 3: cout << "��������� � ������� ����?" << endl; break;
	case 4: {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		// ������� ������� �����
		SetConsoleTextAttribute(h, 4);
		for (int i = 0; i < count; i++) {
			cout << "_";
		}
		cout << endl;
		SetConsoleTextAttribute(h, 15);
		break;
	}
	}
}

void Game::Text::HV(int Color1, int Number, int Color2, string String) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	// ��� ���������� ������ ������ ����. ����� ������� ������� ���� �����, ����� �����, � ����� ���� ������ � ��� �����
	SetConsoleTextAttribute(h, Color1);
	cout << "(" << Number << ") ";
	SetConsoleTextAttribute(h, Color2);
	cout << String << endl;
}

void Game::Text::PRC(int Colour, string String, int Background) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	// ��� ������ �������� ������
	SetConsoleTextAttribute(h, (WORD)((Background << 4) | Colour));
	cout << String;
}

void Game::Text::Tab(int Color, string Text) {
	system("cls");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	PRC(Color, Text + '\n');
	V(4, 60);
	system("pause");
}

void Game::Text::PRC(int Colour, char String, int Background) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	// ��� ������ �������� ������
	SetConsoleTextAttribute(h, (WORD)((Background << 4) | Colour));
	cout << String;
}

Game::Text::Text() {
	
}