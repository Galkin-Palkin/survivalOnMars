#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;
class Game {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	enum HumanInfo {
		hi_NULL,
		hi_HP,
		hi_FP,
		hi_EP,
		hi_PHP,
		hi_Sol,
		hi_Hour,
		hi_DP
	};
	class Text {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		// Служебный класс для более удобного оформления в консоли
	public:
		/// <summary>
		/// Функция для вывода текста меню.
		/// </summary>
		/// <param name="Number">Что нужно вывести.</param>
		/// <param name="count">Количеств нижних подчеркиваний.</param>
		void V(int Number, int count = 20);
		/// <summary>
		/// Функция вывода сообщения с цыфрой.
		/// </summary>
		/// <param name="Color1">Цвет номера.</param>
		/// <param name="Number">Номер.</param>
		/// <param name="Color2">Цвет текста.</param>
		/// <param name="String">Текст сообщения.</param>
		void HV(int Color1, int Number, int Color2, string String);
		/// <summary>
		/// Функция вывода цветного текста без номеров.
		/// </summary>
		/// <param name="Colour">Цвет.</param>
		/// <param name="String">Текст.</param>
		void PRC(int Colour, string String);
	};
	class Human {
		int HP = 70 + (rand() % 5) * 5; // Очки здоровья
		int FP = 30 + (rand() % 7) * 5; // Очки сытости
		int EP = 100; // Очки энергии
		int PHP = 30 + (rand() % 3) * 10; // Очки психологического состояния (тут имею в виду настрой персонажа, само психологическое состояние реализую позже, от него должна зависеть концовка)
		double DP = (rand() % 21) / 1.0; // Очки истощения
		int Sol = 0; // Сол - сутки на Марсе
		int Hour = 7;
	public:
		int GetI(HumanInfo Type);
		double GetD(HumanInfo Type);
		void Set(HumanInfo Type, char Sign, int NumberI, double NumberD = 0.0);
		void Null(); // Обнуление данных
	};
	class Item {
	protected:
		string Name = "";
		int Count = 0;
		double Weight = 0.0;
	public:
		virtual void SetNew(int count = 1) {

		}
	};
	class Instrument : public Item {
	protected:
		double Durability = 100.0; // Прочность
		double BreakQualityPerUse = 0.1; // Трата прочности за 1 использование
		double Damage = 0.0; // Урон
	public:
		vector<Instrument> InstrumentsVector;
		void Correcting();
		void Breaking();
		void PartBreaking(double Damage);
		void Repairing(double Heal);
		void OnceUsing();
		void SetNewInstrument(double Durability, double BreakQualityPerUse, double Damage);
		virtual void Attack();
		virtual void Clear();
		void Constructor(string Name, double Weight);
		Instrument();
	};
	class Weapon : public Instrument {
		unsigned int Ammo = 0;
		vector<Weapon> WeaponVector;
	public:
		Weapon();
		void Attack() override;
		void SetNew(int count = 1) override;
		void Clear() override;
		Weapon(string Name, double Weight);
	};
	class Gun : public Weapon {

	};
	class ColdWeapon : public Weapon {

	};
	class Explodives : public Weapon {

	};
	class Consumable;
	static vector<Consumable*> ConsumableVector;
	static int ConsumableCount;
	class Consumable : public Item {
		HumanInfo FirstType; // Здесь и далее - типы, которые меняет объект класса
		HumanInfo SecondType;
		HumanInfo ThirdType;
		int FirstNumber = 0; // Здесь и далее - значение, на которое изменяет первый и так далее тип объект класса
		double DFirstNumber = 0.0;
		int SecondNumber = 0;
		int ThirdNumber = 0;
		int ID = 0;
		bool IsBeing = false;
	public:
		bool Taking(Human& H);
		void SetNew(int Count = 1) override;
		void Clear();
		static void Show(Text& T, int Page);
		void Constructor(string Name, double Weight, HumanInfo FirstType, double FirstNumber, HumanInfo SecondType = hi_NULL, int SecondNumber = -10000, HumanInfo ThirdType = hi_NULL, int ThirdNumber = -10000);
		void Constructor(string Name, double Weight, HumanInfo FirstType, int FirstNumber, HumanInfo SecondType = hi_NULL, int SecondNumber = -10000, HumanInfo ThirdType = hi_NULL, int ThirdNumber = -10000);
	};
	class Inventory {
	public:
		// Собственно, инвентарь
		Instrument Hammer;
		Instrument Jigsaw;
		Instrument Axe;
		// Медикаменты
		Consumable Palont;
		Consumable Aspirin;
		Consumable Trivoclisine;
		Consumable Gericline;
		Consumable Phenothan;
		// Пища
		Consumable CannedBeef;
		Consumable Hardtack;
		Consumable EnergyBar;
		Consumable CannedApple;
		Consumable RicePurge;
		Consumable MeatBriquette;
		Consumable MeltedCheese;
		Consumable MushroomSoup;
		// Редкие
		Consumable DarkChocolateBar;
		Consumable BartonsDrug;
		Consumable FishSoup;
		Inventory();
	};
	class Buildings {
		// Здания
		Inventory I;
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		Human H;
		Text T;
		/// <summary>
		/// Функция, которая выводит план комнаты.
		/// </summary>
		/// <param name="RoomType">Тип комнаты: Казарма, Больница, Столовая и так далее.</param>
		/// <param name="Variety">Разновидность плана комнаты.</param>
		void RoomMap(int, int);
		void EnterRoom(int RoomType, Inventory* I);
		void DenyToGoIn(Human& H, Text& T, int Type, string RoomType, bool& Entering);
	public:
		void LocationGeneration();
	};
	Buildings B;
	Human H;
	Text T;
	Inventory I;
	vector<vector<Item>> InventoryVector;
	class Saves {
	public:
		void Load(Human& H, bool& IsExit);
		void Download(Human& H, bool IsExit = false);
		bool GetNew();
		void SetNew(bool Truelness);
	protected:
		bool NewGame = true;
	};
	Saves S;
	void Introduction();
	void InfoShowing(int HP, int FP, int EP, int PHP, double DP, int Sol, int Hour);
	int NewGame();
	void Changes(bool& Life, int& Hour, bool& Working);
	int ActionsChoose(int Sol, int Hour);
	/*void Eating(Inventory& I, bool& IsBack, int& Hour);*/
	void Eating(Inventory& I, bool &IsBack, int &Hour);
	void Outing();
	void Sleeping();
	void Escape(bool& Life, int& Hour);
	void Actions(int Choose, bool& Life, int& Hour, bool& IsBack);
	void RoomLooking(Inventory& I);
	void MenuReturning(bool& Working);
	void ChangesDay(bool IsExit);
	void Back(int &Hour, bool& IsBack);
public:
	Game();
	int Menu();
	void GamingProcess(bool& Working);
	void Menu_2(bool& Working);
	void Menu_3(bool& Working);
	void Menu_4(bool& Working);
};