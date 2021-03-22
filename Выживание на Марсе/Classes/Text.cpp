#include "Game.h"
void Game::Text::V(int Number, int count) {
	switch (Number) {
	case 1: cout << "Выберите дальнейшее действие:" << endl; break;
	case 2: {
		PRC(10, "(1) ");
		PRC(15, "Да");
		PRC(4, " (2) ");
		PRC(15, "Нет\n");
		break;
	}
	case 3: cout << "Вернуться в главное меню?" << endl; break;
	case 4: {
		// Выводит красную линию
		SetConsoleTextAttribute(h, 4);
		for (int i = 0; i < count; i++) {
			cout << "_";
		}
		cout << endl;
		break;
	}
	}
}
void Game::Text::HV(int Color1, int Number, int Color2, string String) {
	// Для оформления одного пункта меню. Нужно указать сначала цвет цифры, затем цифру, а потом цвет текста и сам текст
	SetConsoleTextAttribute(h, Color1);
	cout << "(" << Number << ") ";
	SetConsoleTextAttribute(h, Color2);
	cout << String << endl;
}
void Game::Text::PRC(int Colour, string String) {
	// Для вывода цветного текста
	SetConsoleTextAttribute(h, Colour);
	cout << String;
}
Game::Text::Text() {
	
}