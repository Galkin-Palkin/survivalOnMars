#include "Game.h"
Game::Inventory::Inventory() {
	// ������� (�������) ���������� ����� 1-2 ����. ������ ����� 3 ����
	Hammer.Constructor("�������", 1.5);
	Jigsaw.Constructor("����", 2.0);
	Axe.Constructor("�����", 4.5);

	Palont.Constructor("Palont", "���� \"������\"", 0.1, 25, hi_DP, -2.0, hi_HP, 20);
	Aspirin.Constructor("Aspirin", "������� ��������", 0.025, 20, hi_DP, -0.5, hi_HP, 10);
	Trivoclisine.Constructor("Trivoclisine", "������ � �������������", 0.01, 10, hi_DP, -15.0, hi_EP, -70);
	Gericline.Constructor("Gericline", "���� ���������", 0.1, 10, hi_DP, 2.0, hi_EP, 75);
	Phenothan.Constructor("Phenothan", "�������� ��������", 0.05, 15, hi_DP, -1.0, hi_HP, 20);
	Sedatives.Constructor("Sedatives", "�������� ���������������", 0.05, 15, hi_HP, -2, hi_PHP, 50);
	Syrup.Constructor("Syrup", "�����", 0.175, 15, hi_HP, 5, hi_EP, 10);

	CannedBeef.Constructor("CannedBeef", "���������������� ��������", 0.25, 15, hi_FP, 30, hi_EP, 20);
	Hardtack.Constructor("Hardtack", "����� �����", 0.15, 20, hi_FP, 20);
	EnergyBar.Constructor("EnergyBar", "�������������� ��������", 0.05, 15, hi_FP, 10, hi_EP, 30);
	MushroomSoup.Constructor("MushroomSoup", "������� ��� � �������", 0.3, 15, hi_FP, 40, hi_EP, 20);
	CannedApple.Constructor("CannedApple", "������������������ ������", 0.2, 10, hi_FP, 20, hi_EP, 20);
	RicePurge.Constructor("RicePurge", "�������� � �����", 0.3, 15, hi_FP, 30, hi_EP, 20);
	MeatBriquette.Constructor("MeatBriquette", "������ ������", 0.3, 10, hi_FP, 25, hi_EP, 40);
	MeltedCheese.Constructor("MeltedCheese", "�������� ����������� ����", 0.15, 20, hi_FP, 20);
	CannedFish.Constructor("CannedFish", "���������������� �������", 0.25, 10, hi_FP, 30, hi_EP, 20);
	Noodle.Constructor("Noodle", "��������", 0.3, 15, hi_FP, 25, hi_EP, 10);
	VegetableStew.Constructor("VegetableStew", "������� ���� � ���������", 0.2, 15, hi_FP, 15, hi_EP, 25);
	DriedFruits.Constructor("DriedFruits", "����������", 0.1, 15, hi_FP, 10, hi_EP, 10);

	FishSoup.Constructor("FishSoup", "������� �� ������", 0.4, 1, hi_DP, -5.0, hi_FP, 40, hi_EP, 55);
	DarkChocolateBar.Constructor("DarkChocolateBar", "������ �������� ��������", 0.1, 1, hi_FP, 25, hi_EP, 40, hi_PHP, 30);
	BartonsDrug.Constructor("BartonsDrug", "��������� ���������� �������", 0.4, 1, hi_DP, -10.0, hi_HP, 40, hi_EP, 20);

	MeatBriquette.AddEffect(Effect("Data\\Effects\\Satiety.txt"));
	CannedBeef.AddEffect(Effect("Data\\Effects\\Satiety.txt"));
	CannedFish.AddEffect(Effect("Data\\Effects\\Satiety.txt"));
	FishSoup.AddEffect(Effect("Data\\Effects\\Satiety.txt"));
	Trivoclisine.AddEffect(Effect("Data\\Effects\\Fatigue.txt"));
	Sedatives.AddEffect(Effect("Data\\Effects\\Calming.txt"));
	Gericline.AddEffect(Effect("Data\\Effects\\Adrenaline.txt"));
	BartonsDrug.AddEffect(Effect("Data\\Effects\\Recovery.txt"));
}