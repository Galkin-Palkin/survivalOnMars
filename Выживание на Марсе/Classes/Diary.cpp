#include "Game.h"
using namespace std;

Game::Diary::Diary(string Path) {
	ifstream fin(Path);

	try {
		if (!fin.is_open())
			throw "Файл с дневником отсутствует!";
		fin >> ws;
		getline(fin, Title);
		int Size, Size2;
		fin >> Size;
		
		for (int i = 0; i < Size; i++) {
			fin >> Size2;
			for (int j = 0; j < Size2; j++) {
				fin >> ws;
				getline(fin, DiaryPages[i][j]);
			}
		}
	}
	catch (string Error) {
		Text::Tab(15, "Ошибка:\n" + Error);
	}
}

void Game::Diary::Read() {
Start:
	system("cls");
	Text::PRC(15, Title + '\n');
	Text::V(4, 50);

	int CurrentPage = 0;

	for (size_t j = 0; j < DiaryPages[CurrentPage].size(); j++)
		Text::PRC(0, DiaryPages[CurrentPage][j], 15);

	Text::V(4, 50);

	while (true) {
		switch (_getch()) {
		case 75:
			if (CurrentPage > 0)
				CurrentPage--;
			goto Start;
		case 77:
			if (CurrentPage < DiaryPages.size())
				CurrentPage++;
			goto Start;
		case 27:
			return;
		}
	}
}