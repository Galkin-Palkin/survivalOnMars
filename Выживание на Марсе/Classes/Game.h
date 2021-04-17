#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <Windows.h>
using namespace std;
class Game {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	enum class HumanInfo {
		Null,
		HP,
		FP,
		EP,
		PHP,
		Sol,
		Hour,
		DP,
		HalChance
	};
	static map<string, HumanInfo> HIMap;
	class Text {
		// Служебный класс для более удобного оформления в консоли
	public:
		/// <summary>
		/// Функция для вывода текста меню.
		/// </summary>
		/// <param name="Number">Что нужно вывести.</param>
		/// <param name="count">Количество нижних подчеркиваний.</param>
		static void V(int Number, int count = 20);
		/// <summary>
		/// Функция вывода сообщения с цифрой.
		/// </summary>
		/// <param name="Color1">Цвет номера.</param>
		/// <param name="Number">Номер.</param>
		/// <param name="Color2">Цвет текста.</param>
		/// <param name="String">Текст сообщения.</param>
		static void HV(int Color1, int Number, int Color2, string String);
		/// <summary>
		/// Функция вывода цветного текста без номеров.
		/// </summary>
		/// <param name="Colour">Цвет.</param>
		/// <param name="String">Текст.</param>
		static void PRC(int Colour, string String = "");
		Text();
	};
	class Human;
	class Effect {
		int Duration = 0;
		string Type;
		static Human* H;
		vector<HumanInfo> ParametrsNames;
		vector<double> ParametrsValues;
	public:
		void EffectAction();
		int GetDuration();
		Effect& SetDuration(int);
		void Tick();
		static void SetPointer(Human*);
		Effect();
		Effect(string);
		bool operator==(Effect&);
		string GetType();
	};
	class Saves;
	class Human {
		int HP = 70 + (rand() % 5) * 5; // Очки здоровья
		int FP = 30 + (rand() % 7) * 5; // Очки сытости
		int EP = 100; // Очки энергии
		int PHP = 30 + (rand() % 3) * 10; // Очки психологического состояния (тут имею в виду настрой персонажа, само психологическое состояние реализую позже, от него должна зависеть концовка)
		double DP = (rand() % 21) / 1.0; // Очки истощения
		int Sol = 0; // Сол - сутки на Марсе
		int Hour = 7;
		int HalChance = rand() % 11; // Шанс словить галлюцинацию в %
		Saves* S = nullptr;
		vector<Effect> EffectsVector;
		void EffectsAction();
	public:
		int GetI(HumanInfo);
		double GetD(HumanInfo);
		int GetEffectsCount();
		void Set(HumanInfo, char, int);
		void Set(HumanInfo, char, double);
		void AddEffect(Effect);
		void EffectsTick();
		void Null(); // Обнуление данных
		void Changes(bool&, bool&);
		void Validate();
		void SetPointer(Saves*);
		void ClearEffects();
		void SaveEffects(ofstream&);
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
	class Consumable;
	static vector<Consumable*> ConsumableVector;
	static int ConsumableCount;
	class Consumable : public Item {
	protected:
		vector<Effect> GiveEffect;
		HumanInfo FirstType = HumanInfo::Null; // Здесь и далее - типы, которые меняет объект класса
		HumanInfo SecondType = HumanInfo::Null;
		HumanInfo ThirdType = HumanInfo::Null;
		string Type;
		static Human* H;
		int Chance = 1;
		int FirstNumber = 0; // Здесь и далее - значение, на которое изменяет первый и так далее тип объект класса
		double DFirstNumber = 0.0;
		int SecondNumber = 0;
		int ThirdNumber = 0;
		int ID = 0;
		bool IsBeing = false;
		void EffectsToHuman();
	public:
		virtual bool Taking();
		virtual void SetNew(int Count = 1) override;
		virtual void Clear();
		static void Show(Text& T, size_t Page);
		string GetType();
		int GetCount();
		void SetCount(int Value);
		void Constructor(string Type, string Name, double Weight, int Chance, HumanInfo FirstType, double FirstNumber, HumanInfo SecondType = HumanInfo::Null, int SecondNumber = -10000, HumanInfo ThirdType = HumanInfo::Null, int ThirdNumber = -10000);
		void Constructor(string Type, string Name, double Weight, int Chance, HumanInfo FirstType, int FirstNumber, HumanInfo SecondType = HumanInfo::Null, int SecondNumber = -10000, HumanInfo ThirdType = HumanInfo::Null, int ThirdNumber = -10000);
		int GetChance();
		void SetChance(int);
		string GetName();
		void SetName(string);
		int GetID();
		int& GetIDP();
		double GetWeight();
		static void SetPointer(Human*);
		Consumable Null();
		void AddEffect(Effect);
		void SetBeing(bool Value = true);
		void SetID(int);
	};
	class Book : public Consumable {
		int PagesCount = 0;
		int TotalPagesCount = 0;
	public:
		void SetParametrs(string Type, string Name, double Weight, int Chance, int PagesCount, HumanInfo FirstType, int FirstNumber, HumanInfo SecondType = HumanInfo::Null, int SecondNumber = -10000, HumanInfo ThirdType = HumanInfo::Null, int ThirdNumber = -10000);
		bool Taking() override;
		void SetNew(int Count = 1) override;
		void Clear() override;
		Book Common();
		int GetPagesCount();
		Book& SetPagesCount(int);
		int GetTotalPagesCount();
		void SetIsBeing(bool);
	};
	class Obstacle {
		vector<string> Text;
		vector<string> Specialisation;
		int DurPoints = 100;
	public:
		Obstacle() = default;
	};
	class Weapon : public Item {
	protected:
		int Damage = 0;
		double Durability = 100.0;
		double BreakPerUse = 2.0;
		string Type;
	public:
		void SetParameters(string, string, double, int, double, double);
		void Attack();
	};
	class Tool : public Weapon {
		vector<string> Specialisation;
		int DamageToObstacles = 0;
	public:

	};
	class Enemy {
		static Human* H;
		static Saves* S;
		string Name;
		int HP = 100;
		vector<HumanInfo> DamageType;
		vector<double> DamageValue;
		vector<string> Info;
		vector<string> NotesToDiary;
		int ChanceToHit = 50;
		int ChanceToLeave = 10;
	public:
		Enemy() = default;
		Enemy(string);
		bool IsDead();
		void Show(int, bool);
		int GetChanceToLeave();
		void Damaged(int);
		void Attack(bool&, bool&);
		static void SetPointer(Human*, Saves*);
	};
	static vector<Book*> BookVector;
	static map<string, Book*> BookMap;
	class Inventory {
	public:
		// Собственно, инвентарь

		// Медикаменты
		Consumable Palont;
		Consumable Aspirin;
		Consumable Trivoclisine;
		Consumable Gericline;
		Consumable Phenothan;
		Consumable Sedatives;
		Consumable Syrup;
		// Пища
		Consumable CannedBeef;
		Consumable Hardtack;
		Consumable EnergyBar;
		Consumable CannedApple;
		Consumable RicePurge;
		Consumable MeatBriquette;
		Consumable MeltedCheese;
		Consumable MushroomSoup;
		Consumable CannedFish;
		Consumable Noodle;
		Consumable VegetableStew;
		Consumable DriedFruits;
		// Литература
		Book ScienceFiction;
		Book CriminalDrama;
		Book Comics;
		Book Adventures;
		Book Thriller;
		// Редкие
		Consumable DarkChocolateBar;
		Consumable BartonsDrug;
		Consumable FishSoup;
		Inventory();
	};
	class Action {
	private:
		Text T;
		static Human* H;
		string Name;
		vector<Consumable> SearchingResult;
		vector<Book> FoundedBooks;
	public:
		Action(ifstream&);
		Action() = default;
		string GetName();
		void GenerateItems();
		void FoundedItems();
		static void SetPointer(Human*);
	};
	class Room {
	private:
		Text T;
		static Human* H;
		vector<vector<Action>> roomToActions; // Хранит места для поиска
		vector<string> roomToName; // Названия комнат
		vector<string> floorPlan; // Карта помещения
		string Info;
		bool IsScare = false;
	public:
		Room(string);
		void Print();
		void PrintRooms();
		void PlacePrint(vector<Action>, string);
		void AddRoomsTo(vector<string>& arr);
		string GetInfo();
		vector<Action> GetRoomPlaces(int);
		string GetName(int);
		void ActionChoose(vector<Action>&);
		void SetActionVector(vector<Action>, int);
		void PlaceClear(int);
		void operator= (Room);
		vector<vector<Action>> GetVectorAction();
		void SetVectorAction(vector<vector<Action>>);
		static void SetPointer(Human*);
	};
	static map<string, Consumable*> ConsumableMap;
	class Buildings {
	private:
		// Здания
		Inventory I;
		Human* H = nullptr;
		Saves* S = nullptr;
		Text T;
		vector<Room> rooms;
		/// <summary>
		/// Функция, которая выводит план комнаты.
		/// </summary>
		/// <param name="RoomType">Тип комнаты: Казарма, Больница, Столовая и так далее.</param>
		/// <param name="Variety">Разновидность плана комнаты.</param>
		void RoomMap(int, int, vector<string>&, Room&, bool);
		void RoomVarietyPrint(vector<string>);
		int RoomChoose(vector<string>&, string&);
		void RoomSearching(Room&, string, int);
		void EnterRoom(bool&, bool&, int RoomType, int&);
		void DenyToGoIn(int Type, string RoomType, bool& Entering);
		void Battle(bool&, bool&);
	public:
		void GetPath();
		void LocationGeneration(bool&, bool&, int&);
		void SetPointer(Human*, Saves*);
	};
	Human H;
	Buildings B;
	Text T;
	Inventory I;
	class Saves {
	public:
		void Load(Human& H, bool& IsExit);
		void Download(Human& H, bool IsExit = false);
		bool GetNew();
		void SetNew(bool Truelness);
	protected:
		bool NewGame = true;
	};
	enum Achievement {
		Ach_Aspirin,
		Ach_Barton,
		Ach_Plushkin,
		Ach_Hacker,
		Ach_Chocolate,
		Ach_BookWorm
	};
	Saves S;
	static vector<string> DiaryVector;
	static vector<string> NotesVector;
	static vector<pair<string, string>> AchievementVector;
	static map<int, bool> IsAchMap;
	static int NightmareNumber;
	static map<string, Effect> EffectMap;
	static int NightmareChance;
	static vector<bool> SeenEnemies;
	void Introduction();
	void InfoShowing(int HP, int FP, int EP, int PHP, double DP, int Sol, int Hour);
	int NewGame();
	int ActionsChoose(int Sol, int Hour);
	void Eating(Inventory& I, bool& IsBack, int& Hour);
	void Outing(bool&, bool&, int&, bool&);
	void Workplace(int&, bool&);
	void BookReading(int&, bool&);
	void DiaryReading(int&, bool&);
	void ReadNotes(int&, bool&);
	void NotesWriting();
	bool Sleeping();
	void Escape(bool& Life, int& Hour, bool&);
	void Actions(int Choose, bool& Life, int& Hour, bool& IsBack, bool&);
	void RoomLooking(Inventory& I);
	static void Death(bool& Working, bool&);
	void ChangesDay(bool IsExit);
	void Back(int& Hour, bool& IsBack);
	bool Statement(string, string);
	void Nightmare(string);
	void Validate();
public:
	Game();
	int Menu();
	void GamingProcess(bool& Working);
	void Menu_2(bool& Working);
	void Menu_3(bool& Working);
	void Menu_4(bool& Working);
	void Menu_5(bool& Working);
};