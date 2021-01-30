#include "Game.h"
Game::Inventory::Inventory() {
	// Обычные (рядовые) расходники имеют 1-2 типа. Редкие имеют 3 типа
	Hammer.Constructor("Молоток", 1.5);
	Jigsaw.Constructor("Пила", 2.0);
	Axe.Constructor("Топор", 4.5);

	Palont.Constructor("Мазь \"Палонт\"", 0.1, hi_DP, -2.0, hi_HP, 20);
	Aspirin.Constructor("Гранула аспирина", 0.025, hi_DP, -0.5, hi_HP, 15);
	Trivoclisine.Constructor("Ампула с тривоклизином", 0.01, hi_DP, -15.0, hi_EP, -70);
	Gericline.Constructor("Укол гериклина", 0.1, hi_DP, 2.0, hi_EP, 75);
	Phenothan.Constructor("Таблетки фенотана", 0.05, hi_DP, -1.0, hi_HP, 30);

	CannedBeef.Constructor("Консервированная говядина", 0.25, hi_FP, 30, hi_EP, 25);
	Hardtack.Constructor("Пачка галет", 0.15, hi_FP, 20);
	EnergyBar.Constructor("Энергетический батончик", 0.05, hi_FP, 10, hi_EP, 30);
	MushroomSoup.Constructor("Грибной суп в тюбиках", 0.3, hi_FP, 40, hi_EP, 20);
	CannedApple.Constructor("Законсервированное яблоко", 0.2, hi_FP, 20, hi_EP, 20);
	RicePurge.Constructor("Консервы с рисом", 0.3, hi_FP, 30, hi_EP, 20);
	MeatBriquette.Constructor("Мясной брикет", 0.3, hi_FP, 25, hi_EP, 50);
	MeltedCheese.Constructor("Упаковка плавленного сыра", 0.15, hi_FP, 20);

	FishSoup.Constructor("Похлёбка из трески", 0.4, hi_DP, -5.0, hi_FP, 40, hi_EP, 55);
	DarkChocolateBar.Constructor("Плитка горького шоколада", 0.1, hi_FP, 25, hi_EP, 40, hi_PHP, 30);
	BartonsDrug.Constructor("Сыворотка профессора Бартона", 0.4, hi_DP, -10.0, hi_HP, 40, hi_EP, 20);
}