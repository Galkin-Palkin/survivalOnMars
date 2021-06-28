#include "Game.h"
using namespace std;

Game::PlotItem::PlotItem(string Path) {
	try {
		ifstream fin(Path);
		if (!fin.is_open())
			throw "Файл с сюжетным предметом не существует!";
		cin >> ws;
		getline(cin, Name);
		int Size;
		fin >> Size;
		Info.resize(Size);

		for (int i = 0; i < Size; i++) {
			cin >> ws;
			getline(cin, Info[i]);
		}
	}
	catch (string Error) {
		Text::Tab(15, "Ошибка:\n" + Error);
	}
}