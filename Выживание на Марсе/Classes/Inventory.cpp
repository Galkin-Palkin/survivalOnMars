#include "Game.h"
Game::Inventory::Inventory() {
	// ������� (�������) ���������� ����� 1-2 ����. ������ ����� 3 ����
	Hammer.Constructor("�������", 1.5);
	Jigsaw.Constructor("����", 2.0);
	Axe.Constructor("�����", 4.5);

	Palont.Constructor("Palont", "���� \"������\"", 0.1, 25, hi_DP, -2.0, hi_HP, 20);
	Aspirin.Constructor("Aspirin", "������� ��������", 0.025, 30, hi_DP, -0.5, hi_HP, 15);
	Trivoclisine.Constructor("Trivoclisine", "������ � �������������", 0.01, 10, hi_DP, -15.0, hi_EP, -70);
	Gericline.Constructor("Gericline", "���� ���������", 0.1, 10, hi_DP, 2.0, hi_EP, 75);
	Phenothan.Constructor("Phenotan", "�������� ��������", 0.05, 20, hi_DP, -1.0, hi_HP, 30);

	CannedBeef.Constructor("CannedBeef", "���������������� ��������", 0.25, 25, hi_FP, 30, hi_EP, 25);
	Hardtack.Constructor("Hardtack", "����� �����", 0.15, 35, hi_FP, 20);
	EnergyBar.Constructor("EnergyBar", "�������������� ��������", 0.05, 20, hi_FP, 10, hi_EP, 30);
	MushroomSoup.Constructor("MushroomSoup", "������� ��� � �������", 0.3, 15, hi_FP, 40, hi_EP, 20);
	CannedApple.Constructor("CannedApple", "������������������ ������", 0.2, 10, hi_FP, 20, hi_EP, 20);
	RicePurge.Constructor("RicePurge", "�������� � �����", 0.3, 20, hi_FP, 30, hi_EP, 20);
	MeatBriquette.Constructor("MeatBriquette", "������ ������", 0.3, 10, hi_FP, 25, hi_EP, 50);
	MeltedCheese.Constructor("MeltedCheese", "�������� ����������� ����", 0.15, 30, hi_FP, 20);

	FishSoup.Constructor("FishSoup", "������� �� ������", 0.4, 3, hi_DP, -5.0, hi_FP, 40, hi_EP, 55);
	DarkChocolateBar.Constructor("DarkChocolateBar", "������ �������� ��������", 0.1, 5, hi_FP, 25, hi_EP, 40, hi_PHP, 30);
	BartonsDrug.Constructor("BartonsDrug", "��������� ���������� �������", 0.4, 2, hi_DP, -10.0, hi_HP, 40, hi_EP, 20);
}