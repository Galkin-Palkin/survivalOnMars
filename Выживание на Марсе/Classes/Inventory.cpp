#include "Game.h"
Game::Inventory::Inventory() {
	// Обычные (рядовые) расходники имеют 1-2 типа. Редкие имеют 3 типа

	Knife.SetParameters("Knife", "Кухонный нож", 0.3, 11, 7);
	Hand.SetParameters("Hand", "Руки", 0.0, 5, 0, "Data\\Tools\\Hand.txt");
	Axe.SetParameters("Axe", "Пожарный топор", 3.0, 22, 3, "Data\\Tools\\Axe.txt");
	Hammer.SetParameters("Hammer", "Молоток", 1.2, 12, 5, "Data\\Tools\\Hammer.txt");
	Crowbar.SetParameters("Crowbar", "Монтировка", 2.1, 17, 3, "Data\\Tools\\Crowbar.txt");
	Screwdriver.SetParameters("Screwdriver", "Крестовая отвёртка", 0.15, 9, 6, "Data\\Tools\\Screwdriver.txt");
	Wrench.SetParameters("Wrench", "Гаечный ключ", 1.8, 15, 4, "Data\\Tools\\Wrench.txt");
	Chainsaw.SetParameters("Chainsaw", "Цепная бензопила", 4.5, 31, 1, "Data\\Tools\\Chainsaw.txt");
	Scalpel.SetParameters("Scalpel", "Скальпель", 0.1, 9, 8);

	Palont.Constructor("Palont", "Мазь \"Палонт\"", 0.1, 25, HumanInfo::DP, -2.0, HumanInfo::HP, 20);
	Aspirin.Constructor("Aspirin", "Гранула аспирина", 0.025, 20, HumanInfo::DP, -0.5, HumanInfo::HP, 10);
	Trivoclisine.Constructor("Trivoclisine", "Ампула с тривоклизином", 0.01, 10, HumanInfo::DP, -15.0, HumanInfo::EP, -70);
	Gericline.Constructor("Gericline", "Укол гериклина", 0.1, 10, HumanInfo::DP, 2.0, HumanInfo::EP, 75);
	Phenothan.Constructor("Phenothan", "Таблетки фенотана", 0.05, 15, HumanInfo::DP, -1.0, HumanInfo::HP, 20);
	Sedatives.Constructor("Sedatives", "Таблетки успокоительного", 0.05, 15, HumanInfo::HP, -2, HumanInfo::PHP, 50, HumanInfo::HalChance, -10);
	Syrup.Constructor("Syrup", "Сироп", 0.175, 15, HumanInfo::HP, 5, HumanInfo::EP, 10);

	CannedBeef.Constructor("CannedBeef", "Консервированная говядина", 0.25, 15, HumanInfo::FP, 30, HumanInfo::EP, 20);
	Hardtack.Constructor("Hardtack", "Пачка галет", 0.15, 20, HumanInfo::FP, 20);
	EnergyBar.Constructor("EnergyBar", "Энергетический батончик", 0.05, 15, HumanInfo::FP, 10, HumanInfo::EP, 30);
	MushroomSoup.Constructor("MushroomSoup", "Грибной суп в тюбиках", 0.3, 15, HumanInfo::FP, 40, HumanInfo::EP, 20);
	CannedApple.Constructor("CannedApple", "Законсервированное яблоко", 0.2, 10, HumanInfo::FP, 20, HumanInfo::EP, 20);
	RicePurge.Constructor("RicePurge", "Консервы с рисом", 0.3, 15, HumanInfo::FP, 30, HumanInfo::EP, 20);
	MeatBriquette.Constructor("MeatBriquette", "Мясной брикет", 0.3, 10, HumanInfo::FP, 25, HumanInfo::EP, 40);
	MeltedCheese.Constructor("MeltedCheese", "Упаковка плавленного сыра", 0.15, 20, HumanInfo::FP, 20);
	CannedFish.Constructor("CannedFish", "Консервированная горбуша", 0.25, 10, HumanInfo::FP, 30, HumanInfo::EP, 20);
	Noodle.Constructor("Noodle", "Макароны", 0.3, 15, HumanInfo::FP, 25, HumanInfo::EP, 10);
	VegetableStew.Constructor("VegetableStew", "Овощное рагу в консервах", 0.2, 15, HumanInfo::FP, 15, HumanInfo::EP, 25);
	DriedFruits.Constructor("DriedFruits", "Сухофрукты", 0.1, 15, HumanInfo::FP, 10, HumanInfo::EP, 10);

	ScienceFiction.SetParametrs("ScienceFiction", "Научная фантастика", 0.4, 8, 125, HumanInfo::PHP, 6);
	CriminalDrama.SetParametrs("CriminalDrama", "Криминальная драма", 0.5, 5, 150, HumanInfo::PHP, 8, HumanInfo::HalChance, 1);
	Comics.SetParametrs("Comics", "Комиксы", 0.3, 7, 50, HumanInfo::PHP, 15);
	Adventures.SetParametrs("Adventures", "Приключенческий роман", 0.7, 4, 250, HumanInfo::PHP, 6);
	Thriller.SetParametrs("Thriller", "Триллер", 0.6, 6, 175, HumanInfo::PHP, 5, HumanInfo::HalChance, 1);

	FishSoup.Constructor("FishSoup", "Похлёбка из трески", 0.4, 1, HumanInfo::DP, -5.0, HumanInfo::FP, 40, HumanInfo::EP, 55);
	DarkChocolateBar.Constructor("DarkChocolateBar", "Плитка горького шоколада", 0.1, 1, HumanInfo::FP, 25, HumanInfo::EP, 40, HumanInfo::PHP, 30);
	BartonsDrug.Constructor("BartonsDrug", "Сыворотка профессора Бартона", 0.4, 1, HumanInfo::DP, -10.0, HumanInfo::HP, 40, HumanInfo::EP, 20);

	MeatBriquette.AddEffect(Effect("Data\\Effects\\Satiety.txt"));
	CannedBeef.AddEffect(Effect("Data\\Effects\\Satiety.txt"));
	CannedFish.AddEffect(Effect("Data\\Effects\\Satiety.txt"));
	FishSoup.AddEffect(Effect("Data\\Effects\\Satiety.txt"));
	Trivoclisine.AddEffect(Effect("Data\\Effects\\Fatigue.txt"));
	Sedatives.AddEffect(Effect("Data\\Effects\\Calming.txt"));
	Gericline.AddEffect(Effect("Data\\Effects\\Adrenaline.txt"));
	BartonsDrug.AddEffect(Effect("Data\\Effects\\Recovery.txt"));

	ToolMap["Hand"] = Hand;
	ToolMap["Knife"] = Knife;
	ToolMap["Axe"] = Axe;
	ToolMap["Hammer"] = Hammer;
	ToolMap["Screwdriver"] = Screwdriver;
	ToolMap["Wrench"] = Wrench;
	ToolMap["Crowbar"] = Crowbar;
	ToolMap["Chainsaw"] = Chainsaw;
	ToolMap["Scalpel"] = Scalpel;
}