#include "Game.h"
Game::Inventory::Inventory() {
	// ������� (�������) ���������� ����� 1-2 ����. ������ ����� 3 ����

	Knife.SetParameters("Knife", "�������� ���", 0.3, 11, 7);
	Hand.SetParameters("Hand", "����", 0.0, 5, 0, "Data\\Tools\\Hand.txt");
	Axe.SetParameters("Axe", "�������� �����", 3.0, 22, 3, "Data\\Tools\\Axe.txt");
	Hammer.SetParameters("Hammer", "�������", 1.2, 12, 5, "Data\\Tools\\Hammer.txt");
	Crowbar.SetParameters("Crowbar", "����������", 2.1, 17, 3, "Data\\Tools\\Crowbar.txt");
	Screwdriver.SetParameters("Screwdriver", "��������� �������", 0.15, 9, 6, "Data\\Tools\\Screwdriver.txt");
	Wrench.SetParameters("Wrench", "������� ����", 1.8, 15, 4, "Data\\Tools\\Wrench.txt");
	Chainsaw.SetParameters("Chainsaw", "������ ���������", 4.5, 31, 1, "Data\\Tools\\Chainsaw.txt");
	Scalpel.SetParameters("Scalpel", "���������", 0.1, 9, 8);

	Palont.Constructor("Palont", "���� \"������\"", 0.1, 25, HumanInfo::DP, -2.0, HumanInfo::HP, 20);
	Aspirin.Constructor("Aspirin", "������� ��������", 0.025, 20, HumanInfo::DP, -0.5, HumanInfo::HP, 10);
	Trivoclisine.Constructor("Trivoclisine", "������ � �������������", 0.01, 10, HumanInfo::DP, -15.0, HumanInfo::EP, -70);
	Gericline.Constructor("Gericline", "���� ���������", 0.1, 10, HumanInfo::DP, 2.0, HumanInfo::EP, 75);
	Phenothan.Constructor("Phenothan", "�������� ��������", 0.05, 15, HumanInfo::DP, -1.0, HumanInfo::HP, 20);
	Sedatives.Constructor("Sedatives", "�������� ���������������", 0.05, 15, HumanInfo::HP, -2, HumanInfo::PHP, 50, HumanInfo::HalChance, -10);
	Syrup.Constructor("Syrup", "�����", 0.175, 15, HumanInfo::HP, 5, HumanInfo::EP, 10);

	CannedBeef.Constructor("CannedBeef", "���������������� ��������", 0.25, 15, HumanInfo::FP, 30, HumanInfo::EP, 20);
	Hardtack.Constructor("Hardtack", "����� �����", 0.15, 20, HumanInfo::FP, 20);
	EnergyBar.Constructor("EnergyBar", "�������������� ��������", 0.05, 15, HumanInfo::FP, 10, HumanInfo::EP, 30);
	MushroomSoup.Constructor("MushroomSoup", "������� ��� � �������", 0.3, 15, HumanInfo::FP, 40, HumanInfo::EP, 20);
	CannedApple.Constructor("CannedApple", "������������������ ������", 0.2, 10, HumanInfo::FP, 20, HumanInfo::EP, 20);
	RicePurge.Constructor("RicePurge", "�������� � �����", 0.3, 15, HumanInfo::FP, 30, HumanInfo::EP, 20);
	MeatBriquette.Constructor("MeatBriquette", "������ ������", 0.3, 10, HumanInfo::FP, 25, HumanInfo::EP, 40);
	MeltedCheese.Constructor("MeltedCheese", "�������� ����������� ����", 0.15, 20, HumanInfo::FP, 20);
	CannedFish.Constructor("CannedFish", "���������������� �������", 0.25, 10, HumanInfo::FP, 30, HumanInfo::EP, 20);
	Noodle.Constructor("Noodle", "��������", 0.3, 15, HumanInfo::FP, 25, HumanInfo::EP, 10);
	VegetableStew.Constructor("VegetableStew", "������� ���� � ���������", 0.2, 15, HumanInfo::FP, 15, HumanInfo::EP, 25);
	DriedFruits.Constructor("DriedFruits", "����������", 0.1, 15, HumanInfo::FP, 10, HumanInfo::EP, 10);

	ScienceFiction.SetParametrs("ScienceFiction", "������� ����������", 0.4, 8, 125, HumanInfo::PHP, 6);
	CriminalDrama.SetParametrs("CriminalDrama", "������������ �����", 0.5, 5, 150, HumanInfo::PHP, 8, HumanInfo::HalChance, 1);
	Comics.SetParametrs("Comics", "�������", 0.3, 7, 50, HumanInfo::PHP, 15);
	Adventures.SetParametrs("Adventures", "��������������� �����", 0.7, 4, 250, HumanInfo::PHP, 6);
	Thriller.SetParametrs("Thriller", "�������", 0.6, 6, 175, HumanInfo::PHP, 5, HumanInfo::HalChance, 1);

	FishSoup.Constructor("FishSoup", "������� �� ������", 0.4, 1, HumanInfo::DP, -5.0, HumanInfo::FP, 40, HumanInfo::EP, 55);
	DarkChocolateBar.Constructor("DarkChocolateBar", "������ �������� ��������", 0.1, 1, HumanInfo::FP, 25, HumanInfo::EP, 40, HumanInfo::PHP, 30);
	BartonsDrug.Constructor("BartonsDrug", "��������� ���������� �������", 0.4, 1, HumanInfo::DP, -10.0, HumanInfo::HP, 40, HumanInfo::EP, 20);

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