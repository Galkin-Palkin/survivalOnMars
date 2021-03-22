#include "Game.h"
Game::Inventory::Inventory() {
	// Обычные (рядовые) расходники имеют 1-2 типа. Редкие имеют 3 типа
	Hammer.Constructor("Молоток", 1.5);
	Jigsaw.Constructor("Пила", 2.0);
	Axe.Constructor("Топор", 4.5);

	Palont.Constructor("Palont", "Мазь \"Палонт\"", 0.1, 25, hi_DP, -2.0, hi_HP, 20);
	Aspirin.Constructor("Aspirin", "Гранула аспирина", 0.025, 20, hi_DP, -0.5, hi_HP, 10);
	Trivoclisine.Constructor("Trivoclisine", "Ампула с тривоклизином", 0.01, 10, hi_DP, -15.0, hi_EP, -70);
	Gericline.Constructor("Gericline", "Укол гериклина", 0.1, 10, hi_DP, 2.0, hi_EP, 75);
	Phenothan.Constructor("Phenothan", "Таблетки фенотана", 0.05, 15, hi_DP, -1.0, hi_HP, 20);
	Sedatives.Constructor("Sedatives", "Таблетки успокоительного", 0.05, 15, hi_HP, -2, hi_PHP, 50);
	Syrup.Constructor("Syrup", "Сироп", 0.175, 15, hi_HP, 5, hi_EP, 10);

	CannedBeef.Constructor("CannedBeef", "Консервированная говядина", 0.25, 15, hi_FP, 30, hi_EP, 20);
	Hardtack.Constructor("Hardtack", "Пачка галет", 0.15, 20, hi_FP, 20);
	EnergyBar.Constructor("EnergyBar", "Энергетический батончик", 0.05, 15, hi_FP, 10, hi_EP, 30);
	MushroomSoup.Constructor("MushroomSoup", "Грибной суп в тюбиках", 0.3, 15, hi_FP, 40, hi_EP, 20);
	CannedApple.Constructor("CannedApple", "Законсервированное яблоко", 0.2, 10, hi_FP, 20, hi_EP, 20);
	RicePurge.Constructor("RicePurge", "Консервы с рисом", 0.3, 15, hi_FP, 30, hi_EP, 20);
	MeatBriquette.Constructor("MeatBriquette", "Мясной брикет", 0.3, 10, hi_FP, 25, hi_EP, 40);
	MeltedCheese.Constructor("MeltedCheese", "Упаковка плавленного сыра", 0.15, 20, hi_FP, 20);
	CannedFish.Constructor("CannedFish", "Консервированная горбуша", 0.25, 10, hi_FP, 30, hi_EP, 20);
	Noodle.Constructor("Noodle", "Макароны", 0.3, 15, hi_FP, 25, hi_EP, 10);
	VegetableStew.Constructor("VegetableStew", "Овощное рагу в консервах", 0.2, 15, hi_FP, 15, hi_EP, 25);
	DriedFruits.Constructor("DriedFruits", "Сухофрукты", 0.1, 15, hi_FP, 10, hi_EP, 10);

	FishSoup.Constructor("FishSoup", "Похлёбка из трески", 0.4, 1, hi_DP, -5.0, hi_FP, 40, hi_EP, 55);
	DarkChocolateBar.Constructor("DarkChocolateBar", "Плитка горького шоколада", 0.1, 1, hi_FP, 25, hi_EP, 40, hi_PHP, 30);
	BartonsDrug.Constructor("BartonsDrug", "Сыворотка профессора Бартона", 0.4, 1, hi_DP, -10.0, hi_HP, 40, hi_EP, 20);

	MeatBriquette.AddEffect(Effect("Data\\Effects\\Satiety.txt"));
	CannedBeef.AddEffect(Effect("Data\\Effects\\Satiety.txt"));
	CannedFish.AddEffect(Effect("Data\\Effects\\Satiety.txt"));
	FishSoup.AddEffect(Effect("Data\\Effects\\Satiety.txt"));
	Trivoclisine.AddEffect(Effect("Data\\Effects\\Fatigue.txt"));
	Sedatives.AddEffect(Effect("Data\\Effects\\Calming.txt"));
	Gericline.AddEffect(Effect("Data\\Effects\\Adrenaline.txt"));
	BartonsDrug.AddEffect(Effect("Data\\Effects\\Recovery.txt"));
}