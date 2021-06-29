#include "Game.h"
using namespace std;

Game::Diary::Diary(string Path) {
	ifstream fin(Path);

	try {
		if (!fin.is_open())
			throw 54;
		fin >> ws;
		getline(fin, Title);
		int Size, Size2;
		fin >> Size;
		
		DiaryPages.resize(Size);
		for (int i = 0; i < Size; i++) {
			fin >> Size2;
			DiaryPages[i].resize(Size2);
			for (int j = 0; j < Size2; j++) {
				fin >> ws;
				getline(fin, DiaryPages[i][j]);
			}
		}
	}
	catch (int Error) {
		Text::Tab(15, "������:\n���� � ��������� �����������!\n");
	}
}

void Game::Diary::Read() {
	int CurrentPage = 0;
Start:
	system("cls");
	Text::PRC(15, Title + '\n');
	Text::V(4, 50);

	for (size_t i = 0; i < DiaryPages[CurrentPage].size(); i++) {
		for (size_t j = 0; j < DiaryPages[CurrentPage][i].size(); j++) {
			switch (DiaryPages[CurrentPage][i][j]) {
			case '#':
				Text::PRC(0, ' ', 4);
				break;
			default:
				Text::PRC(0, DiaryPages[CurrentPage][i][j], 15);
				break;
			}
		}
		Text::PRC(15, "\n");
	}

	Text::V(4, 50);

	while (true) {
		switch (_getch()) {
		case 75:
			if (CurrentPage > 0)
				CurrentPage--;
			goto Start;
		case 77:
			if (CurrentPage < DiaryPages.size() - 1)
				CurrentPage++;
			goto Start;
		case 27:
			return;
		}
	}
}