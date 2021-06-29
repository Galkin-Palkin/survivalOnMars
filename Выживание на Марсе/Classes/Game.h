#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctime>
#include <Windows.h>
#include <fstream>
#include <conio.h>

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

	class Text {
		// ��������� ����� ��� ����� �������� ���������� � �������
	public:
		/// <summary>
		/// ������� ��� ������ ������ ����.
		/// </summary>
		/// <param name="Number">��� ����� �������.</param>
		/// <param name="count">���������� ������ �������������.</param>
		static void V(int Number, int count = 20);
		/// <summary>
		/// ������� ������ ��������� � ������.
		/// </summary>
		/// <param name="Color1">���� ������.</param>
		/// <param name="Number">�����.</param>
		/// <param name="Color2">���� ������.</param>
		/// <param name="String">����� ���������.</param>
		static void HV(int Color1, int Number, int Color2, string String);
		/// <summary>
		/// ������� ������ �������� ������ ��� �������.
		/// </summary>
		/// <param name="Colour">����.</param>
		/// <param name="String">�����.</param>
		static void PRC(int Colour, string String = "", int Background = 0);
		static void Tab(int, string);
		static void PRC(int Colour, char String, int Background);
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

	class Tool;

	class Inventory;

	class Human {
		int HP = 70 + (rand() % 5) * 5; // ���� ��������
		int FP = 30 + (rand() % 7) * 5; // ���� �������
		int EP = 100; // ���� �������
		int PHP = 30 + (rand() % 3) * 10; // ���� ���������������� ��������� (��� ���� � ���� ������� ���������, ���� ��������������� ��������� �������� �����, �� ���� ������ �������� ��������)
		double DP = (rand() % 21) / 1.0; // ���� ���������
		int Sol = 0; // ��� - ����� �� �����
		int Hour = 7;
		int HalChance = rand() % 11; // ���� ������� ������������ � %
		Saves* S = nullptr;
		vector<Effect> EffectsVector;
		Tool* CurrentTool = nullptr;
		Inventory *I = nullptr;
		void EffectsAction();
	public:
		int GetI(HumanInfo);

		double GetD(HumanInfo);

		int GetEffectsCount();

		void Set(HumanInfo, char, int);

		void Set(HumanInfo, char, double);

		void AddEffect(Effect);

		void EffectsTick();

		void Null(); // ��������� ������

		void Changes(bool&, bool&);

		void Validate();

		void SetPointer(Saves*, Tool*, Inventory*);

		void ClearEffects();

		void SaveEffects(ofstream&);

		Tool* GetCurrentTool();

		void SetTool();

		void SetTool(Tool*);

	};
	class Item {
	protected:
		string Name = "";
		int Count = 0;
		double Weight = 0.0;
	public:
		virtual void SetNew(int Count = 1) = 0;
	};

	class PlotItem {
		string Name;
		vector<string> Info;

	public:
		PlotItem(string Path);
	};

	class Diary {
		string Title;
		vector<vector<string>> DiaryPages;
	public:
		Diary(string Path);

		void Read();
	};

	static vector<PlotItem> PlotItems;
	static vector<Diary> OtherDiary;

	class Consumable;
	static vector<Consumable*> ConsumableVector;
	static int ConsumableCount;
	class Consumable : public Item {
	protected:
		vector<Effect> GiveEffect;
		HumanInfo FirstType = HumanInfo::Null; // ����� � ����� - ����, ������� ������ ������ ������
		HumanInfo SecondType = HumanInfo::Null;
		HumanInfo ThirdType = HumanInfo::Null;
		string Type;
		static Human* H;
		int Chance = 1;
		int FirstNumber = 0; // ����� � ����� - ��������, �� ������� �������� ������ � ��� ����� ��� ������ ������
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
		string Type;
		string Name;
		int DurPoints = 100;
		int MaxDurPoints = 100;
		static Human* H;
	public:
		Obstacle() = default;
		
		Obstacle(string);
		
		static void SetPointer(Human*);
		
		bool Creating();
		
		Obstacle Clone();
	};
	class Tool : public Item {
		int Damage = 0;
		double Durability = 100.0;
		double BreakPerUse = 0.0;
		int ChanceToFind = 5;
		string Type;
		static Human* H;
		static Inventory* I;
		vector<pair<string, int>> Specialisation;
	public:
		void SetParameters(string, string, double, int, int, string Path = "");
		
		int Attack();
		
		void SetNew(int Count = 1) override;
		
		int GetChance();
		
		string GetType();
		
		string GetName();
		
		double GetDurability();
		
		double GetBreakPerUse();
		
		void SetDurability(double);
		
		void SetBreakPerUse(double);
		
		static void SetPointer(Human*, Inventory*);
		
		int Size();
		
		pair<string, int> operator[](unsigned int);
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
		// ����������, ���������

		// ������ � �����������
		Tool Hand;
		Tool Knife;
		Tool Axe;
		Tool Hammer;
		Tool Crowbar;
		Tool Screwdriver; // �������
		Tool Wrench; // ������� ����
		Tool Chainsaw; // ���������
		Tool Scalpel;

		// �����������
		Consumable Palont;
		Consumable Aspirin;
		Consumable Trivoclisine;
		Consumable Gericline;
		Consumable Phenothan;
		Consumable Sedatives;
		Consumable Syrup;
		// ����
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
		// ����������
		Book ScienceFiction;
		Book CriminalDrama;
		Book Comics;
		Book Adventures;
		Book Thriller;
		// ������
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
		bool IsObstacle = false;
		string ObstacleType;
		vector<pair<Consumable, int>> SearchingResult;
		vector<Book> FoundedBooks;
		vector<Tool> FoundedTools;
		vector<bool> IsFound;
	public:
		Action(ifstream&);
		
		Action() = default;
		
		string GetName();
		
		void GenerateItems();
		
		void FoundedItems();
		
		string GetObstacleType();
		
		bool GetIsObstacle();
		
		static void SetPointer(Human*);
	};

	class Room {
	private:
		Text T;
		static Human* H;
		vector<vector<Action>> roomToActions; // ������ ����� ��� ������
		vector<string> roomToName; // �������� ������
		vector<string> floorPlan; // ����� ���������
		string Info;
		string Name;
		bool IsScare = false;
	public:
		Room(string);
		
		Room() = default;
		
		void Print();
		
		void PrintRooms();
		
		void PlacePrint(vector<Action>, string);
		
		void AddRoomsTo(vector<string>& arr);
		
		string GetInfo();
		
		vector<Action> GetRoomPlaces(int);
		
		string GetName(int);
		
		string GetBuildingName();
		
		void ActionChoose(vector<Action>&);
		
		void SetActionVector(vector<Action>, int);
		
		void PlaceClear(int);
		
		void operator= (Room);
		
		vector<vector<Action>> GetVectorAction();
		
		void SetVectorAction(vector<vector<Action>>);
		
		static void SetPointer(Human*);
		
		void Set(string);
	};
	static map<string, Consumable*> ConsumableMap;
	class Buildings {
	private:
		// ������
		Inventory I;
		Human* H = nullptr;
		Saves* S = nullptr;
		Text T;
		vector<Room> rooms;
		/// <summary>
		/// �������, ������� ������� ���� �������.
		/// </summary>
		/// <param name="RoomType">��� �������: �������, ��������, �������� � ��� �����.</param>
		/// <param name="Variety">������������� ����� �������.</param>
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
		Ach_BookWorm,
		Ach_Nofap
	};
	Saves S;
	static map<string, HumanInfo> HIMap;
	static vector<string> DiaryVector;
	static vector<string> NotesVector;
	static vector<pair<string, string>> AchievementVector;
	static map<int, bool> IsAchMap;
	static int NightmareNumber;
	static map<string, Effect> EffectMap;
	static int NightmareChance;
	static vector<bool> SeenEnemies;
	static map<string, vector<Tool>> Tools;
	static map<string, Tool> ToolMap;
	static Room Room1;
	static Room Room2;
	static Room Room3;
	static Room Room4;
	static Room Room5;
	static Room Room6;
	static Room Room7;
	static Room Room8;
	static Room Room9;
	static Room Room10;
	static map<string, Obstacle> Obstacles;
	static map<string, Obstacle> ActionObstacles;
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
	friend ofstream& operator<<(ofstream&, Tool);
	friend ifstream& operator>>(ifstream&, Tool&);
};