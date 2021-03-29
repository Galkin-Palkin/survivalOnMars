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
		static void PRC(int Colour, string String = "");
		Text();
	};
	class Human;
	class Effect {
		int Duration = 0;
		static Human* H;
		vector<HumanInfo> ParametrsNames;
		vector<double> ParametrsValues;
	public:
		void EffectAction();
		int GetDuration();
		void Tick();
		static void SetPointer(Human*);
		Effect();
		Effect(string);
		bool operator==(Effect&);
	};
	class Saves;
	class Human {
		int HP = 70 + (rand() % 5) * 5; // ���� ��������
		int FP = 30 + (rand() % 7) * 5; // ���� �������
		int EP = 100; // ���� �������
		int PHP = 30 + (rand() % 3) * 10; // ���� ���������������� ��������� (��� ���� � ���� ������� ���������, ���� ��������������� ��������� �������� �����, �� ���� ������ �������� ��������)
		double DP = (rand() % 21) / 1.0; // ���� ���������
		int Sol = 0; // ��� - ����� �� �����
		int Hour = 7;
		int HalChance = rand() % 11; // ���� ������� ������������ � %
		Saves *S;
		vector<Effect> EffectsVector;
		void EffectsAction();
	public:
		int GetI(HumanInfo);
		double GetD(HumanInfo);
		void Set(HumanInfo, char, int);
		void Set(HumanInfo, char, double);
		void AddEffect(Effect);
		void EffectsTick();
		void Null(); // ��������� ������
		void Changes(bool&, bool&);
		void Validate();
		void SetPointer(Saves*);
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
	static vector<Book*> BookVector;
	static map<string, Book*> BookMap;
	class Inventory {
	public:
		// ����������, ���������

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
		vector<vector<Action>> roomToActions; // ������ ����� ��� ������
		vector<string> roomToName; // �������� ������
		vector<string> floorPlan; // ����� ���������
		string Info;
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
	};
	static map<string, Consumable*> ConsumableMap;
	class Buildings {
	private:
		// ������
		Inventory I;
		Human* H = nullptr;
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
	public:
		void GetPath();
		void LocationGeneration(bool&, bool&, int&);
		void SetPointer(Human*);
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
	Saves S;
	static vector<string> DiaryVector;
	static vector<string> NotesVector;
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
	void Sleeping();
	void Escape(bool& Life, int& Hour, bool&);
	void Actions(int Choose, bool& Life, int& Hour, bool& IsBack, bool&);
	void RoomLooking(Inventory& I);
	static void Death(bool& Working);
	void ChangesDay(bool IsExit);
	void Back(int& Hour, bool& IsBack);
	bool Statement(string, string);
	void Validate();
public:
	Game();
	int Menu();
	void GamingProcess(bool& Working);
	void Menu_2(bool& Working);
	void Menu_3(bool& Working);
	void Menu_4(bool& Working);
};