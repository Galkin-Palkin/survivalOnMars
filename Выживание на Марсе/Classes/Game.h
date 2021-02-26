#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <ctime>
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
		// ��������� ����� ��� ����� �������� ���������� � �������
	public:
		/// <summary>
		/// ������� ��� ������ ������ ����.
		/// </summary>
		/// <param name="Number">��� ����� �������.</param>
		/// <param name="count">���������� ������ �������������.</param>
		void V(int Number, int count = 20);
		/// <summary>
		/// ������� ������ ��������� � ������.
		/// </summary>
		/// <param name="Color1">���� ������.</param>
		/// <param name="Number">�����.</param>
		/// <param name="Color2">���� ������.</param>
		/// <param name="String">����� ���������.</param>
		void HV(int Color1, int Number, int Color2, string String);
		/// <summary>
		/// ������� ������ �������� ������ ��� �������.
		/// </summary>
		/// <param name="Colour">����.</param>
		/// <param name="String">�����.</param>
		void PRC(int Colour, string String);
		Text();
	};
	class Human {
		int HP = 70 + (rand() % 5) * 5; // ���� ��������
		int FP = 30 + (rand() % 7) * 5; // ���� �������
		int EP = 100; // ���� �������
		int PHP = 30 + (rand() % 3) * 10; // ���� ���������������� ��������� (��� ���� � ���� ������� ���������, ���� ��������������� ��������� �������� �����, �� ���� ������ �������� ��������)
		double DP = (rand() % 21) / 1.0; // ���� ���������
		int Sol = 0; // ��� - ����� �� �����
		int Hour = 7;
	public:
		int GetI(HumanInfo Type);
		double GetD(HumanInfo Type);
		void Set(HumanInfo Type, char Sign, int NumberI, double NumberD = 0.0);
		void Null(); // ��������� ������
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
		double Durability = 100.0; // ���������
		double BreakQualityPerUse = 0.1; // ����� ��������� �� 1 �������������
		double Damage = 0.0; // ����
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
		HumanInfo FirstType; // ����� � ����� - ����, ������� ������ ������ ������
		HumanInfo SecondType;
		HumanInfo ThirdType;
		string Type;
		int Chance = 1;
		int FirstNumber = 0; // ����� � ����� - ��������, �� ������� �������� ������ � ��� ����� ��� ������ ������
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
		string GetType();
		int GetCount();
		void SetCount(int Value);
		void Constructor(string Type, string Name, double Weight, int Chance, HumanInfo FirstType, double FirstNumber, HumanInfo SecondType = hi_NULL, int SecondNumber = -10000, HumanInfo ThirdType = hi_NULL, int ThirdNumber = -10000);
		void Constructor(string Type, string Name, double Weight, int Chance, HumanInfo FirstType, int FirstNumber, HumanInfo SecondType = hi_NULL, int SecondNumber = -10000, HumanInfo ThirdType = hi_NULL, int ThirdNumber = -10000);
		int GetChance();
		void SetChance(int);
		string GetName();
		void SetName(string);
	};
	class Inventory {
	public:
		// ����������, ���������
		Instrument Hammer;
		Instrument Jigsaw;
		Instrument Axe;
		// �����������
		Consumable Palont;
		Consumable Aspirin;
		Consumable Trivoclisine;
		Consumable Gericline;
		Consumable Phenothan;
		// ����
		Consumable CannedBeef;
		Consumable Hardtack;
		Consumable EnergyBar;
		Consumable CannedApple;
		Consumable RicePurge;
		Consumable MeatBriquette;
		Consumable MeltedCheese;
		Consumable MushroomSoup;
		// ������
		Consumable DarkChocolateBar;
		Consumable BartonsDrug;
		Consumable FishSoup;
		Inventory();
	};
	class Action {
	private:
		Text T;
		string Name;
		vector<Consumable> SearchingResult;
	public:
		Action(ifstream &);
		Action() = default;
		string GetName();
		void GenerateItems();
		void FoundedItems();
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
	static map<string, Consumable> ConsumableMap;
	class Buildings {	
	private:
		// ������
		Inventory I;
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		Human H;
		Text T;
		vector<Room> rooms;
		/// <summary>
		/// �������, ������� ������� ���� �������.
		/// </summary>
		/// <param name="RoomType">��� �������: �������, ��������, �������� � ��� �����.</param>
		/// <param name="Variety">������������� ����� �������.</param>
		void RoomMap(int, int, vector<string>&, Room&, bool);
		void RoomVarietyPrint(vector<string>);
		int RoomChoose(vector<string>&, string &);
		void RoomSearching(Room &, string, int);
		void EnterRoom(int RoomType);
		void DenyToGoIn(int Type, string RoomType, bool& Entering);
	public:
		void GetPath();
		void LocationGeneration();
		Buildings();
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
	void Eating(Inventory& I, bool& IsBack, int& Hour);
	void Outing();
	void Sleeping();
	void Escape(bool& Life, int& Hour);
	void Actions(int Choose, bool& Life, int& Hour, bool& IsBack);
	void RoomLooking(Inventory& I);
	void MenuReturning(bool& Working);
	void ChangesDay(bool IsExit);
	void Back(int& Hour, bool& IsBack);
public:
	Game();
	int Menu();
	void GamingProcess(bool& Working);
	void Menu_2(bool& Working);
	void Menu_3(bool& Working);
	void Menu_4(bool& Working);
};