#include <iostream>
#include <Windows.h>
#include <ctime>
#include <conio.h>
#include <vector>
#include <fstream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////

enum HumanInfo{
	hi_HP,
	hi_FP,
	hi_EP,
	hi_PHP,
	hi_Sol,
	hi_Hour
};

class Game {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	class Text {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		// Служебный класс для более удобного оформления в консоли
	public:
		void V(int Number, int count = 20) {
			switch (Number) {
			case 1: cout << "Выберите дальнейшее действие:" << endl; break;
			case 2: {
				PRC(10, "(1) ");
				PRC(15, "Да");
				PRC(4, " (2) ");
				PRC(15, "Нет\n");
				break;
			}
			case 3: cout << "Вернуться в главное меню?" << endl; break;
			case 4: {
				// Выводит красную линию
				SetConsoleTextAttribute(h, 4);
				for (int i = 0; i < count; i++) {
					cout << "_";
				}
				cout << endl;
				break;
			}
			}
		}
		void HV(int Color1, int Number, int Color2, string String) {
			// Для оформления одного пункта меню. Нужно указать сначала цвет цифры, затем цифру, а потом цвет текста и сам текст
			SetConsoleTextAttribute(h, Color1);
			cout << "(" << Number << ") ";
			SetConsoleTextAttribute(h, Color2);
			cout << String << endl;
		}
		void PRC(int Colour, string String) {
			// Для вывода цветного текста
			SetConsoleTextAttribute(h, Colour);
			cout << String;
		}
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
		int GetI(HumanInfo Type) {
			switch (Type)
			{
				case hi_HP: {
					return HP;
					break;
				}case hi_FP: {
					return HP;
					break;
				}case hi_EP: {
					return HP;
					break;
				}case hi_PHP: {
					return HP;
					break;
				}case hi_Sol: {
					return HP;
					break;
				}case hi_Hour: {
					return HP;
					break;
				}
				default: {
					return -100000;
					break;
				}
			}
		}
		double GetD(string Type) {
			if (Type == "DP") return DP;
			else return -100000;
		}
		void Set(string Type, char Sign, int NumberI, double NumberD = 0.0) {
			// Реализовано криво, потом переделаю. Нужно заменить 'N' на '=', убрать '0'. Перегрузить функцию для вещественных чисел
			if (Type == "HP") {
				switch (Sign) {
				case '+': HP += NumberI; break;
				case '0': HP = 0; break;
				case '-': HP -= NumberI; break;
				case 'N': HP = NumberI; break;
				}
			}
			else if (Type == "FP") {
				switch (Sign) {
				case '+': FP += NumberI; break;
				case '0': FP = 0; break;
				case '-': FP -= NumberI; break;
				case 'N': FP = NumberI; break;
				}
			}
			else if (Type == "EP") {
				switch (Sign) {
				case '+': EP += NumberI; break;
				case '0': EP = 0; break;
				case '-': EP -= NumberI; break;
				case 'N': EP = NumberI; break;
				}
			}
			else if (Type == "PHP") {
				switch (Sign) {
				case '+': PHP += NumberI; break;
				case '0': PHP = 0; break;
				case '-': PHP -= NumberI; break;
				case 'N': PHP = NumberI; break;
				}
			}
			else if (Type == "DP") {
				switch (Sign) {
				case '+': DP += NumberD; break;
				case '0': DP = 0.0; break;
				case '-': DP -= NumberD; break;
				case 'N': DP = NumberD; break;
				}
			}
			else if (Type == "Sol") {
				switch (Sign) {
				case '+': Sol += NumberI; break;
				case '0': Sol = 0; break;
				case '-': Sol -= NumberI; break;
				case 'N': Sol = NumberI; break;
				}
			}
			else if (Type == "Hour") {
				switch (Sign) {
				case '+': Hour += NumberI; break;
				case '0': Hour = 0; break;
				case '-': Hour -= NumberI; break;
				case 'N': Hour = NumberI; break;
				}
			}
		}
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
		double BreakQualityPerUse = 0.1; // Трата прочностиза 1 использование
		double Damage = 0.0; // Урон
	public:
		vector<Instrument> InstrumentsVector;
		void Correcting() {
			if (this->Durability < 0.0) this->Durability = 0.0;
			if (this->Durability > 100.0) this->Durability = 100.0;
			if (this->Durability == 0.0 && this->Count > 0) {
				this->Count--;
				InstrumentsVector.pop_back();
			}
		}
		void Breaking() {
			this->Durability = 0.0;
			Correcting();
		}
		void PartBreaking(double Damage) {
			this->Durability -= Damage;
			Correcting();
		}
		void Repairing(double Heal) {
			this->Durability += Heal;
			Correcting();
		}
		void OnceUsing() {
			this->Durability -= BreakQualityPerUse;
			Correcting();
		}
		void SetNewInstrument(double Durability, double BreakQualityPerUse, double Damage) {
			// Добавление нового объекта в вектор для данного класса
			InstrumentsVector.resize(++Count);
			InstrumentsVector[Count - 1].Durability = Durability;
			InstrumentsVector[Count - 1].BreakQualityPerUse = BreakQualityPerUse;
			InstrumentsVector[Count - 1].Damage = Damage;
		}
		virtual void Attack() {

		}
		void Clear() {
			InstrumentsVector.clear();
		}
		void Constructor(string Name, double Weight) {
			this->Name = Name;
			this->Weight = Weight;
		}
		Instrument() {

		}
	};
	class Weapon : public Instrument {
		unsigned int Ammo = 0;
		vector<Weapon> WeaponVector;
	public:
		Weapon() {

		}
		virtual void Attack() {

		}
		void SetNew(int count = 1) override {

		}
		void Clear() {
			WeaponVector.clear();
		}
		Weapon(string Name, double Weight) {
			this->Name = Name;
			this->Weight = Weight;
		}
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
		string FirstType = ""; // Здесь и далее - типы, которые меняет объект класса
		string SecondType = "";
		string ThirdType = "";
		int FirstNumber = 0; // Здесь и далее - значение, на которое изменяет первый и так далее тип объект класса
		double DFirstNumber = 0.0;
		int SecondNumber = 0;
		int ThirdNumber = 0;
		int ID = 0;
		bool IsBeing = false;
	public:
		Consumable() {

		}
		Consumable(string Name, double Weight, string FirstType, int FirstNumber, string SecondType = "Nan", int SecondNumber = -10000, string ThirdType = "Nan", int ThirdNumber = -10000) {
			this->FirstType = FirstType;
			this->FirstNumber = FirstNumber;
			this->Name = Name;
			this->Weight = Weight;
			if (SecondType != "Nan" && SecondNumber != -10000) {
				this->SecondType = SecondType;
				this->SecondNumber = SecondNumber;
			}
			if (ThirdType != "Nan" && ThirdNumber != -10000) {
				this->ThirdType = ThirdType;
				this->ThirdNumber = ThirdNumber;
			}
		}
		Consumable(string Name, double Weight, string FirstType, double FirstNumber, string SecondType = "Nan", int SecondNumber = -10000, string ThirdType = "Nan", int ThirdNumber = -10000) {
			this->FirstType = FirstType;
			this->DFirstNumber = FirstNumber;
			this->Name = Name;
			this->Weight = Weight;
			if (SecondType != "Nan" && SecondNumber != -10000) {
				this->SecondType = SecondType;
				this->SecondNumber = SecondNumber;
			}
			if (ThirdType != "Nan" && ThirdNumber != -10000) {
				this->ThirdType = ThirdType;
				this->ThirdNumber = ThirdNumber;
			}
		}
		bool Taking(Human& H) {
			// Употребление
			if (this->Count > 0) {
				if (this->FirstType != "DP") H.Set(this->FirstType, '+', this->FirstNumber);
				else H.Set("DP", '+', 0, this->DFirstNumber);
				if (this->SecondType != "") H.Set(this->SecondType, '+', this->SecondNumber);
				if (this->ThirdType != "") H.Set(this->ThirdType, '+', this->ThirdNumber);
				this->Count--;
			}
			else return false;
			if (this->Count <= 0 && this->IsBeing) this->Clear();
			return true;
		}
		void SetNew(int Count = 1) override {
			// Добавление нового объекта
			if (!this->Count) {
				ConsumableVector.push_back(this);
				this->ID = ConsumableCount++;
				this->IsBeing = true;
			}
			this->Count += Count;
		}
		void Clear() {
			for (int i = 0; i < ConsumableCount; i++) {
				if ((*ConsumableVector[i]).ID > this->ID) (*ConsumableVector[i]).ID--;
			}
			ConsumableVector.erase(ConsumableVector.begin() + this->ID);
			ConsumableCount--;
			this->Count = 0;
			this->IsBeing = false;
		}
		static void Show(Text &T) {
			// Показ списка
			system("cls");
			T.PRC(13, "Пища и медикаменты\n");
			T.V(4, 60);
			for (int i = 0; i < ConsumableCount; i++) {
				T.PRC(10, "[");
				T.PRC(15, "");
				cout << i + 1;
				T.PRC(10, "] ");
				T.PRC(1, (*ConsumableVector[i]).Name);
				T.PRC(6, " x");
				T.PRC(15, "");
				cout << (*ConsumableVector[i]).Count << "    ";
				cout << (*ConsumableVector[i]).Weight * (*ConsumableVector[i]).Count;
				T.PRC(8, " кг\n");
				if (i != ConsumableCount - 1) T.V(4, 50);
			}
			T.V(4, 60);
		}
		void Constructor(string Name, double Weight, string FirstType, double FirstNumber, string SecondType = "Nan", int SecondNumber = -10000, string ThirdType = "Nan", int ThirdNumber = -10000) {
			// Обычный конструктор нельзя вызвать в классе вне функции, поэтому, такой аналог
			ConsumableCount = 0;
			this->FirstType = FirstType;
			this->DFirstNumber = FirstNumber;
			this->Name = Name;
			this->Weight = Weight;
			if (SecondType != "Nan" && SecondNumber != -10000) {
				this->SecondType = SecondType;
				this->SecondNumber = SecondNumber;
			}
			if (ThirdType != "Nan" && ThirdNumber != -10000) {
				this->ThirdType = ThirdType;
				this->ThirdNumber = ThirdNumber;
			}
		}
		void Constructor(string Name, double Weight, string FirstType, int FirstNumber, string SecondType = "Nan", int SecondNumber = -10000, string ThirdType = "Nan", int ThirdNumber = -10000) {
			ConsumableCount = 0;
			this->FirstType = FirstType;
			this->FirstNumber = FirstNumber;
			this->Name = Name;
			this->Weight = Weight;
			if (SecondType != "Nan" && SecondNumber != -10000) {
				this->SecondType = SecondType;
				this->SecondNumber = SecondNumber;
			}
			if (ThirdType != "Nan" && ThirdNumber != -10000) {
				this->ThirdType = ThirdType;
				this->ThirdNumber = ThirdNumber;
			}
		}
	};
	class Inventory {
	public:
		// Собственно, инвентарь
		Instrument Hammer;
		Instrument Jigsaw;
		Instrument Axe;
		Consumable Palont;
		Consumable Aspirin;
		Consumable Trivoclisine;
		Consumable CannedBeef;
		Consumable Hardtack;
		Consumable EnergyBar;
		Consumable MushroomSoup;
		Consumable DarkChocolateBar;
		Consumable BartonsDrug;
		Inventory() {
			// Обычные (рядовые) расходники имеют 1-2 типа. Редкие имеют 3 типа
			Hammer.Constructor("Молоток", 1.5);
			Jigsaw.Constructor("Пила", 2.0);
			Axe.Constructor("Топор", 4.5);

			Palont.Constructor("Мазь \"Палонт\"", 0.1, "DP", -2.0, "HP", 20);
			Aspirin.Constructor("Гранула аспирина", 0.025, "DP", -0.5, "HP", 15);
			Trivoclisine.Constructor("Ампула с тривоклизином", 0.01, "DP", -15.0, "EP", -70);
			CannedBeef.Constructor("Консервированная говядина", 0.25, "FP", 30, "EP", 25);
			Hardtack.Constructor("Пачка галет", 0.15, "FP", 20);
			EnergyBar.Constructor("Энергетический батончик", 0.05, "FP", 10, "EP", 30);
			MushroomSoup.Constructor("Грибной суп в тюбиках", 0.3, "FP", 40, "EP", 20);
			DarkChocolateBar.Constructor("Плитка горького шоколада", 0.1, "FP", 25, "EP", 40, "PHP", 30);
			BartonsDrug.Constructor("Сыворотка профессора Бартона", 0.4, "DP", -10.0, "HP", 40, "EP", 20);
		}
	};
	class Buildings {
		// Здания
		Inventory I;
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		Human H;
		Text T;
		void Storage() {
			bool Entering = true;
			if (rand() % 8 == 0) {
				int DenyType = 1 + rand() % 3;
				DenyToGoIn(H, T, DenyType, "от склада", Entering);
			}
		}
		void Laboratory() {
			bool Entering = true;
			if (rand() % 8 == 0) {
				int DenyType = 1 + rand() % 3;
				DenyToGoIn(H, T, DenyType, "от лаборатории", Entering);
			}
		}
		void Bedrooms() {
			bool Entering = true;
			if (rand() % 8 == 0) {
				int DenyType = 1 + rand() % 3;
				DenyToGoIn(H, T, DenyType, "от казарм", Entering);
			}
		}
		void Cantin(Inventory &I) {
			bool Entering = true;
			if (rand() % 8 == 0) {
				int DenyType = 1 + rand() % 3;
				DenyToGoIn(H, T, DenyType, "от столовой", Entering);
			}
			I.DarkChocolateBar.SetNew();
		}
		void Hospital() {
			bool Entering = true;
			if (rand() % 8 == 0) {
				int DenyType = 1 + rand() % 3;
				DenyToGoIn(H, T, DenyType, "от медпункта", Entering);
			}
		}
		void DenyToGoIn(Human& H, Text& T, int Type, string RoomType, bool& Entering) {
			// Запрет на вход внутрь помещения
			system("cls");
			SetConsoleTextAttribute(h, 13);
			switch (Type) {
			case 1: {
				cout << "Дверь " << RoomType << " заблокирована. В этот отдел через эту дверь войти больше нельзя" << endl;
				Entering = false;
				break;
			}
			case 2: {
				cout << "Открыв дверь " << RoomType << ", ты увидел лишь руины: всё было завалено грудами пористого бетона" << endl;
				if (rand() % 5 == 0) {
					cout << "Под одним из обломков ты увидел чью-то расплющенную кисть... Тебе стало дурно от этого и ты поспешил закрыть дверь" << endl;
					H.Set("PHP", '-', 40);
				}
				else cout << "Искать тебе здесь явно нечего, и ты закрыл дверь" << endl;
				Entering = false;
				break;
			}
			case 3: {
				int CountOfTry = 3 + rand() % 8;
				bool UsedDoor = CountOfTry < 10;
				int Thousands = 1 + rand() % 9;
				int Type = 1 + rand() % 4;
				int Chance = rand() % 5;
				int Hundreds = rand() % 10;
				int Decs = rand() % 10;
				int Ones = rand() % 10;
				int Code = (1 + rand() % 9) * 1000 + rand() % 10 * 100 + rand() % 10 * 10 + rand() % 10;
				while (CountOfTry != 0) {
					SetConsoleTextAttribute(h, 13);
					system("cls");
					if (UsedDoor && Chance == 0) {
						switch (Type) {
						case 1: {
							T.PRC(1, "Ты подошёл к двери " + RoomType + ". На ней виднеются следы высохшей крови какого-то бедолаги... Похоже, какому-то сотрудинку несладко досталось...\n");
							break;
						}
						case 2: {
							T.PRC(1, "У шлюза из сплава титана есть сенсорный монитор. Там необходимо ввести ключ, либо же провести картой в терминале ниже. Судя по количеству попыток и слегка треснутому экрану можно полагать, что кто-то безуспешно пытался разблокировать эту дверь.\n");
							break;
						}
						case 3: {
							T.PRC(1, "У широкого входа есть компьютерный механизм. Он издаёт потрескивания. На пыльном, с паутиной мониторе требуют ввести код. Однако, твоё внимание привлекло другое: клавиатура была заляпана какой-то жёлтой вязкой\nжидкостью, из-за чего некоторые кнопки не работали. А ещё, похоже, кто-то пытался ввести код до тебя\n");
							break;
						}
						case 4: {
							T.PRC(1, "Стальная дверь, отделяющая тебя " + RoomType + ", вся в царапинах. В нижней левой части виднеется вмятина, диаметр которой, как ты примерно представил, около 20 сантиметров\nИз электронных петель двери сверкали искры и издавалось характерное потрескивание. На мониторе, находящимся\nна стене чуть левее двери, серыми, еле заметными буквами требовало: \"Введите код\"\n");
							break;
						}
						}
					}
					cout << "Чтобы войти внутрь, нужно ввести пин-код - четырёхзначное число" << endl;
					T.V(4, 50);
					SetConsoleTextAttribute(h, 13);
					cout << "Осталось попыток: ";
					SetConsoleTextAttribute(h, 15);
					cout << CountOfTry << endl;
					T.V(4, 25);
					if (CountOfTry != 10) {
						cout << "В доступе отказано!" << endl;
						SetConsoleTextAttribute(h, 13);
						cout << "Пин-код: ";
						if (Code / 1000 % 10 == Thousands) SetConsoleTextAttribute(h, 10);
						else SetConsoleTextAttribute(h, 4);
						cout << "*";
						if (Code / 100 % 10 == Hundreds) SetConsoleTextAttribute(h, 10);
						else SetConsoleTextAttribute(h, 4);
						cout << "*";
						if (Code / 10 % 10 == Decs) SetConsoleTextAttribute(h, 10);
						else SetConsoleTextAttribute(h, 4);
						cout << "*";
						if (Code % 10 == Ones) SetConsoleTextAttribute(h, 10);
						else SetConsoleTextAttribute(h, 4);
						cout << "*" << endl;
						T.V(4, 40);
					}
					SetConsoleTextAttribute(h, 13);
					cout << "Введите код: ";
					SetConsoleTextAttribute(h, 15);
					cin >> Code;
					if (Code < 1000 || Code > 9999) Code = 0;
					if (Code == Thousands * 1000 + Hundreds * 100 + Decs * 10 + Ones) {
						Entering = true;
						system("cls");
						SetConsoleTextAttribute(h, 13);
						cout << "Тебе удалось подобрать пин-код и войти" << endl;
						break;
					}
					CountOfTry--;
					if (CountOfTry == 0) {
						system("cls");
						int DenyingType = 1 + rand() % 4;
						switch (DenyingType) {
						case 1: {
							T.PRC(1, "");
							break;
						}
						case 2: {
							break;
						}
						case 3: {
							break;
						}
						case 4: {
							break;
						}
						}
						break;
					}
				}
				break;
			}
			}
			T.V(4, 40);
			SetConsoleTextAttribute(h, 15);
			system("pause");
		}
	public:
		void LocationGeneration() {
			// "Генерирует" помещения
			int CountOfRooms = 2 + rand() % 4;
			system("cls");
			SetConsoleTextAttribute(h, 3);
			cout << "Ты зашёл в здание" << endl;
			SetConsoleTextAttribute(h, 4);
			cout << "________________________________________" << endl;
			SetConsoleTextAttribute(h, 15);
			system("pause");
			while (CountOfRooms != 0) {
				SetConsoleTextAttribute(h, 3);
				system("cls");
				cout << "Ты находишься в помещении" << endl;
				cout << "Осталось неосмотренных отделов: ";
				SetConsoleTextAttribute(h, 15);
				cout << CountOfRooms << endl;
				SetConsoleTextAttribute(h, 4);
				cout << "________________________________________" << endl;
				SetConsoleTextAttribute(h, 13);
				cout << "(1) ";
				SetConsoleTextAttribute(h, 15);
				int RoomType = 1;
				if (rand() % 2 == 0) RoomType++;
				if (rand() % 3 == 0) RoomType++;
				if (rand() % 4 == 0) RoomType++;
				if (rand() % 5 == 0) RoomType++;
				switch (RoomType) {
				case 1: cout << "Пойти в казармы" << endl; break;
				case 2: cout << "Пойти в столовую" << endl; break;
				case 3: cout << "Пойти на склад" << endl; break;
				case 4: cout << "Пойти в медпункт" << endl; break;
				case 5: cout << "Пойти в лабораторию" << endl; break;
				}
				while (true) {
					int Click = _getch();
					if (Click == 49) {
						switch (RoomType) {
						case 1: Bedrooms(); break;
						case 2: Cantin(I); break;
						case 3: Storage(); break;
						case 4: Hospital(); break;
						case 5: Laboratory(); break;
						}
						break;
					}
				}
				CountOfRooms--;
			}
		}
	};
	class Enemy {
	protected:
		int HP;
		int Power;
		string Name = "";
		void Attack(Human& H) {
			H.Set("HP", '-', Power);
		}
	};
	Buildings B;
	Human H;
	Text T;
	Inventory I;
	vector<vector<Item>> InventoryVector;
	class Saves {
	public:
		void Load(Human& H, bool &IsExit) {
			// Загрузка в файл
			ifstream fin("Do not open this file.txt");
			int Number;
			double NumberDouble;
			fin >> NewGame;
			fin >> Number;
			H.Set("HP", 'N', Number);
			fin >> Number;
			H.Set("FP", 'N', Number);
			fin >> Number;
			H.Set("EP", 'N', Number);
			fin >> Number;
			H.Set("PHP", 'N', Number);
			fin >> NumberDouble;
			H.Set("DP", 'N', 0, NumberDouble);
			fin >> Number;
			H.Set("Sol", 'N', Number);
			fin >> Number;
			H.Set("Hour", 'N', Number);
			fin >> IsExit;
		}
		void Download(Human& H, bool IsExit = false) {
			// Загрузка из файла
			ofstream fout("Do not open this file.txt");
			fout << NewGame << endl;
			fout << H.GetI(hi_HP) << endl;
			fout << H.GetI(hi_FP) << endl;
			fout << H.GetI(hi_EP) << endl;
			fout << H.GetI(hi_PHP) << endl;
			fout << H.GetD("DP") << endl;
			fout << H.GetI(hi_Sol) << endl;
			fout << H.GetI(hi_Hour) << endl;
			fout << IsExit << endl;
		}
		bool GetNew() {
			return NewGame;
		}
		void SetNew(bool Truelness) {
			NewGame = Truelness;
		}

	protected:
		bool NewGame = true;
	};
	Saves S;
	void Introduction() {
		SetConsoleTextAttribute(h, 15);
		system("cls");
		cout << "Раздалось потрескивание электрического тока, и дверца капсулы открылась." << endl;
		cout << "Ты приподнялся и начал осматривать помещение. По мере пробуждения у тебя в голове появлялись новые и новые вопросы" << endl;
		cout << "Ты осмотрелся. Стены госпиталя и никого вокруг. Где все?" << endl;
		cout << "Ты встал на ноги и подошёл к столу. На нём ты увидел кипу бумаг и фотографию" << endl;
		cout << "Эта фотография... Доктор Парклз и его жена Сьюзи... Ты вспомнил свою Софи! От этого воспоминания у тебя кольнуло в сердце" << endl;
		cout << "Ты сел на стоящее рядом кресло и попытался включить монитор" << endl;
		cout << "После третьего нажатия монитор вспыхнул и на нём отобразилось следущее..." << endl;
		T.V(4, 25);
		SetConsoleTextAttribute(h, 15);
		system("pause");
	}
	void InfoShowing(int HP, int FP, int EP, int PHP, double DP, int Sol, int Hour) {
		// Показывает состояние
		SetConsoleTextAttribute(h, 3);
		cout << "Сол ";
		SetConsoleTextAttribute(h, 15);
		cout << H.GetI(hi_Sol) << endl;
		T.V(4, 15);
		SetConsoleTextAttribute(h, 15);
		cout << Hour << ":00" << endl;
		T.V(4, 50);
		SetConsoleTextAttribute(h, 13);
		cout << "Состояние здоровья: ";
		SetConsoleTextAttribute(h, 15);
		if (HP >= 90) {
			SetConsoleTextAttribute(h, 1);
			cout << "Идеальное\n";
		}
		else if (HP >= 70) {
			SetConsoleTextAttribute(h, 3);
			cout << "Отличное\n";
		}
		else if (HP >= 50) {
			SetConsoleTextAttribute(h, 10);
			cout << "Хорошее\n";
		}
		else if (HP >= 30) {
			SetConsoleTextAttribute(h, 6);
			cout << "Плохое\n";
		}
		else if (HP >= 20) {
			SetConsoleTextAttribute(h, 4);
			cout << "Ужасное\n";
		}
		else {
			SetConsoleTextAttribute(h, 4);
			cout << "Критическое\n";
		}
		T.V(4, 45);
		SetConsoleTextAttribute(h, 13);
		cout << "Истощение организма: ";
		SetConsoleTextAttribute(h, 15);
		if (DP < 100.0 && DP >= 90.0) {
			SetConsoleTextAttribute(h, 4);
			cout << "Предсмертное" << endl;
		}
		else if (DP >= 75.0 && DP < 90) {
			SetConsoleTextAttribute(h, 4);
			cout << "Очень серьёзное" << endl;
		}
		else if (DP >= 50.0 && DP < 75.0) {
			SetConsoleTextAttribute(h, 4);
			cout << "Серьёзное" << endl;
		}
		else if (DP >= 25.0 && DP < 50.0) {
			SetConsoleTextAttribute(h, 6);
			cout << "Среднее" << endl;
		}
		else if (DP > 0.0 && DP < 25.0) {
			SetConsoleTextAttribute(h, 10);
			cout << "Слабое" << endl;
		}
		else {
			SetConsoleTextAttribute(h, 1);
			cout << "Отсутствует" << endl;
		}
		T.V(4, 45);
		SetConsoleTextAttribute(h, 13);
		cout << "Состояние психического здоровья: ";
		if (PHP >= 90) {
			SetConsoleTextAttribute(h, 1);
			cout << "Идеальное\n";
		}
		else if (PHP >= 70) {
			SetConsoleTextAttribute(h, 3);
			cout << "Отличное\n";
		}
		else if (PHP >= 50) {
			SetConsoleTextAttribute(h, 10);
			cout << "Хорошее\n";
		}
		else if (PHP >= 30) {
			SetConsoleTextAttribute(h, 6);
			cout << "Плохое\n";
		}
		else if (PHP >= 20) {
			SetConsoleTextAttribute(h, 4);
			cout << "Ужасное\n";
		}
		else {
			SetConsoleTextAttribute(h, 4);
			cout << "Критическое\n";
		}
		T.V(4, 45);
		SetConsoleTextAttribute(h, 13);
		cout << "Степень сытости: ";
		if (FP >= 90) {
			SetConsoleTextAttribute(h, 1);
			cout << "Полная" << endl;
		}
		else if (FP >= 75) {
			SetConsoleTextAttribute(h, 3);
			cout << "Хорошая" << endl;
		}
		else if (FP >= 50) {
			SetConsoleTextAttribute(h, 10);
			cout << "Средняя" << endl;
		}
		else if (FP >= 25) {
			SetConsoleTextAttribute(h, 6);
			cout << "Удовлетворительная" << endl;
		}
		else if (FP < 25) {
			SetConsoleTextAttribute(h, 4);
			cout << "Голод" << endl;
		}
		T.V(4, 45);
		SetConsoleTextAttribute(h, 13);
		cout << "Степень усталости: ";
		if (EP == 100) {
			SetConsoleTextAttribute(h, 1);
			cout << "Нулевая" << endl;
		}
		else if (EP >= 80) {
			SetConsoleTextAttribute(h, 3);
			cout << "Крайне малая" << endl;
		}
		else if (EP >= 60) {
			SetConsoleTextAttribute(h, 10);
			cout << "Малая" << endl;
		}
		else if (EP >= 40) {
			SetConsoleTextAttribute(h, 6);
			cout << "Средняя" << endl;
		}
		else if (EP >= 20) {
			SetConsoleTextAttribute(h, 4);
			cout << "Большая" << endl;
		}
		else {
			SetConsoleTextAttribute(h, 4);
			cout << "Полная" << endl;
		}
		T.V(4, 50);
		SetConsoleTextAttribute(h, 15);
	}
	int NewGame() {
		system("cls");
		SetConsoleTextAttribute(h, 13);
		T.V(1);
		SetConsoleTextAttribute(h, 4);
		T.V(4, 30);
		SetConsoleTextAttribute(h, 13);
		cout << "(1) ";
		SetConsoleTextAttribute(h, 15);
		cout << "Начать новую игру" << endl;
		if (S.GetNew() != true) {
			SetConsoleTextAttribute(h, 4);
			T.V(4, 20);
			SetConsoleTextAttribute(h, 13);
			cout << "(2) ";
			SetConsoleTextAttribute(h, 15);
			cout << "Продолжить игру" << endl;
		}
		S.SetNew(false);
		while (true) {
			int Click = _getch();
			if (Click == 49) return 1;
			else if (S.GetNew() != true && Click == 50) return 2;
		}
	}
	void Changes(bool& Life, int& Hour, bool& Working) {
		// Система организма персонажа, функция вызывается каждый игровой час
		H.Set("FP", '-', 5);
		if (H.GetI(hi_HP) > 100) H.Set("HP", 'N', 100);
		if (H.GetI(hi_FP) >= 75) H.Set("EP", '+', 10);
		if (H.GetI(hi_EP) > 100) H.Set("EP", 'N', 100);
		else if (H.GetI(hi_FP) >= 50) H.Set("EP", '+', 8);
		else if (H.GetI(hi_FP) >= 25) H.Set("EP", '+', 5);
		if (H.GetI(hi_FP) < 0) H.Set("FP", '0', 1);
		if (H.GetI(hi_FP) == 0) {
			H.Set("HP", '-', 1);
			H.Set("EP", '-', 5);
			H.Set("PHP", '-', 2);
			H.Set("DP", '+', 0, 0.25);
		}
		if (H.GetI(hi_PHP) < 0) H.Set("PHP", '0', 0);
		if (H.GetI(hi_PHP) > 100) H.Set("PHP", 'N', 100);
		if (H.GetD("DP") < 0.0) H.Set("DP", '0', 0);
		if (H.GetI(hi_HP) > 75 && H.GetI(hi_FP) >= 30) {
			H.Set("DP", '-', 0, 1.0);
			H.Set("PHP", '+', 2);
		}
		else if (H.GetI(hi_HP) > 50 && H.GetI(hi_FP) >= 30) {
			H.Set("DP", '-', 0, 0.5);
			H.Set("PHP", '+', 1);
		}
		if (H.GetI(hi_EP) > 100) H.Set("EP", 'N', 100);
		if (H.GetI(hi_EP) < 0) H.Set("EP", '0', 0);
		if (H.GetI(hi_EP) > 100) H.Set("EP", 'N', 100);
		if (H.GetI(hi_EP) < 0) H.Set("EP", '0', 0);
		if (H.GetI(hi_HP) < 0) H.Set("HP", '0', 0);
		if (H.GetI(hi_HP) >= 25 && H.GetI(hi_HP) < 50) {
			H.Set("DP", '+', 0, 0.1);
			H.Set("PHP", '-', 2);
		}
		else if (H.GetI(hi_HP) < 25 && H.GetI(hi_HP) > 0) {
			H.Set("DP", '+', 0, 0.5);
			H.Set("PHP", '-', 3);
		}
		else if (H.GetI(hi_HP) == 0) {
			H.Set("DP", '+', 0, 1.0);
			H.Set("PHP", '-', 5);
		}
		if (H.GetD("DP") > 100.0) H.Set("DP", 'N', 0, 100.0);
		if (H.GetD("DP") >= 100.0) {
			Life = false;
			Hour = 23;
			S.SetNew(true);
			S.Download(H);
			MenuReturning(Working);
		}
	}
	int ActionsChoose(int Sol, int Hour) {
		SetConsoleTextAttribute(h, 10);
		T.V(1);
		T.V(4, 30);
		bool FirstAction = false;
		if (Sol == 1 && Hour == 7) {
			FirstAction = true;
			T.HV(13, 1, 15, "Осмотреть помещение");
		}
		else {
			T.HV(13, 1, 15, "Надеть костюм и выйти");
			T.V(4, 15);
			T.HV(13, 2, 15, "Принять пищу");
			T.V(4, 15);
			T.HV(13, 3, 15, "Принять медикаменты");
			T.V(4, 15);
			T.HV(13, 4, 15, "Сесть за рабочий стол");
		}
		while (true) {
			int Click = _getch();
			if (Click == 49 && FirstAction) return 0;
			else {
				if (Click == 49 && !FirstAction) return 1;
				else if (Click == 50 && !FirstAction) return 2;
				else if (Click == 51 && !FirstAction) return 3;
				else if (Click == 52 && !FirstAction) return 4;
				else if (Click == 27) return 5;
			}
		}
	}
	void Eating(Inventory& I) {
		Consumable::Show(T);
		bool Refresh = true;
		while (Refresh) {
			int Click = _getch();
			switch (Click) {
			case 49: {
				if (ConsumableCount >= 1) (*ConsumableVector[0]).Taking(H);
				Refresh = false;
				break;
			}
			case 50: {
				if (ConsumableCount >= 2) (*ConsumableVector[1]).Taking(H);
				Refresh = false;
				break;
			}
			case 51: {
				if (ConsumableCount >= 3) (*ConsumableVector[2]).Taking(H);
				Refresh = false;
				break;
			}
			case 52: {
				if (ConsumableCount >= 4) (*ConsumableVector[3]).Taking(H);
				Refresh = false;
				break;
			}
			case 53: {
				if (ConsumableCount >= 5) (*ConsumableVector[4]).Taking(H);
				Refresh = false;
				break;
			}
			case 54: {
				if (ConsumableCount >= 6) (*ConsumableVector[5]).Taking(H);
				Refresh = false;
				break;
			}
			case 55: {
				if (ConsumableCount >= 7) (*ConsumableVector[6]).Taking(H);
				Refresh = false;
				break;
			}
			case 56: {
				if (ConsumableCount >= 8) (*ConsumableVector[7]).Taking(H);
				Refresh = false;
				break;
			}
			case 57: {
				if (ConsumableCount >= 9) (*ConsumableVector[8]).Taking(H);
				Refresh = false;
				break;
			}
			}
		}
	}
	void TakingMed(Inventory &I) {
		
	}
	void Outing() {
		B.LocationGeneration();
	}
	void Sleeping() {
		int Counter = 0;
		int HoursN = 23;
		while (Counter != 8) {
			system("cls");
			SetConsoleTextAttribute(h, 13);
			cout << "Ты спишь..." << endl;
			T.V(4, 30);
			SetConsoleTextAttribute(h, 3);
			cout << HoursN << ":00" << endl;
			HoursN++;
			if (HoursN == 24) HoursN = 0;
			Counter++;
			Sleep(970);
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		}

	}
	void Escape(bool& Life, int& Hour) {
		system("cls");
		T.PRC(1, "Вернуться в главное меню?\n");
		T.V(2);
		while (true) {
			int Click = _getch();
			if (Click == 49) {
				Life = false;
				H.Set("Sol", '-', 1);
				S.Download(H, true);
				break;
			}
			else if (Click == 50) {
				Hour--;
				break;
			}
		}
	}
	void Actions(int Choose, bool &Life, int& Hour) {
		switch (Choose) {
		case 0: RoomLooking(I); break;
		case 1: Outing(); break;
		case 2: Eating(I); break;
		case 3: TakingMed(I); break;
		case 4: {
			break;
		}
		case 5: Escape(Life, Hour); break;
		}
	}
	void RoomLooking(Inventory &I) {
		system("cls");
		SetConsoleTextAttribute(h, 15);
		cout << "Ты решил осмотреть помещение. Приоткрыв цинковый шкаф, обработанный специальным раствором нитрата серебра, ты увидел костюм для выхода на поверхность Марса.\nВ углу стоял ящик с гуманитарной помощью. Там находились консервы и галеты, а также некоторые медицинские препараты" << endl;
		T.V(4, 45);
		SetConsoleTextAttribute(h, 15);
		system("pause");
		I.Palont.SetNew(rand() % 2 + 1);
		I.Aspirin.SetNew(2 + rand() % 2);
		I.CannedBeef.SetNew(rand() % 3 + 1);
		I.EnergyBar.SetNew(1 + rand() % 2);
		I.Hardtack.SetNew(rand() % 3 + 2);
	}
	void MenuReturning(bool& Working) {
		system("cls");
		SetConsoleTextAttribute(h, 4);
		cout << "Вы умерли" << endl;
		T.V(4, 35);
		SetConsoleTextAttribute(h, 13);
		T.V(1);
		T.PRC(10, "(1) ");
		T.PRC(15, "Вернуться в главное меню");
		T.PRC(4, " (2) ");
		T.PRC(15, "Выйти из игры\n");
		int Click;
		while (true) {
			Click = _getch();
			if (Click == 49) {
				Click = 1;
				break;
			}
			else if (Click == 50) {
				Click = 2;
				break;
			}
		}
		if (Click == 2) Working = false;
	}
	void ChangesDay(bool IsExit) {
		// Изменения, проходящие после каждой ночи
		H.Set("Sol", '+', 1);
		if (H.GetI(hi_Sol) != 1 && !IsExit) {
			Sleeping();
			H.Set("HP", '+', 5);
			H.Set("DP", '-', 0, 1.0);
			H.Set("EP", '+', 50);
			H.Set("FP", '-', 15);
		}
		if (H.GetI(hi_HP) > 100) H.Set("HP", 'N', 100);
		else if (H.GetI(hi_HP) < 0) H.Set("HP", '0', 0);
		if (H.GetI(hi_FP) > 100) H.Set("FP", 'N', 100);
		else if (H.GetI(hi_FP) < 0) H.Set("FP", '0', 0);
		if (H.GetI(hi_EP) > 100) H.Set("EP", 'N', 100);
		else if (H.GetI(hi_EP) < 0) H.Set("EP", '0', 0);
		if (H.GetD("DP") > 100) H.Set("DP", 'N', 0, 100.0);
		else if (H.GetD("DP") < 0) H.Set("DP", '0', 0, 0.0);
	}
public:
	Game() {

	}
	int Menu() {
		system("cls");
		SetConsoleTextAttribute(h, 13);
		cout << "Выживание на Марсе 0.1" << endl;
		SetConsoleTextAttribute(h, 4);
		T.V(4, 25);
		SetConsoleTextAttribute(h, 13);
		cout << "(1) ";
		SetConsoleTextAttribute(h, 15);
		cout << "Начать игру" << endl;
		SetConsoleTextAttribute(h, 4);
		T.V(4, 5);
		SetConsoleTextAttribute(h, 13);
		cout << "(2) ";
		SetConsoleTextAttribute(h, 15);
		cout << "Помощь к игре" << endl;
		SetConsoleTextAttribute(h, 4);
		T.V(4, 5);
		SetConsoleTextAttribute(h, 13);
		cout << "(3) ";
		SetConsoleTextAttribute(h, 15);
		cout << "Разработчики" << endl;
		SetConsoleTextAttribute(h, 4);
		T.V(4, 5);
		SetConsoleTextAttribute(h, 13);
		cout << "(4) ";
		SetConsoleTextAttribute(h, 15);
		cout << "Выход из игры" << endl;
		SetConsoleTextAttribute(h, 4);
		T.V(4, 25);
		SetConsoleTextAttribute(h, 15);
		int Variety = _getch();
		switch (Variety) {
		case 49: Variety = 1; break;
		case 50: Variety = 2; break;
		case 51: Variety = 3; break;
		case 52: Variety = 4; break;
		}
		return Variety;
	}
	void GamingProcess(bool& Working) {	
		// Основная функция, именно в ней всё и происходит
		bool isExit = false;
		S.Load(H, isExit);
		bool Life = true;
		int GameType = NewGame();
		if (GameType == 1) {
			H.Null();
			Introduction();
		}
		else if (GameType == 2) S.Load(H, isExit);
		while (Life) {
			S.Download(H, isExit);
			ChangesDay(isExit);
			isExit = false;
			if (H.GetI(hi_Hour) >= 23) H.Set("Hour", 'N', 7);
			for (; H.GetI(hi_Hour) <= 22; H.Set("Hour", '+', 1)) {
				if (!Life) {
					H.Set("Hour", '-', 1);
					break;
					continue;
				}
				system("cls");
				InfoShowing(H.GetI(hi_HP), H.GetI(hi_FP), H.GetI(hi_EP), H.GetI(hi_PHP), H.GetD("DP"), H.GetI(hi_Sol), H.GetI(hi_Hour));
				int Choose = ActionsChoose(H.GetI(hi_Sol), H.GetI(hi_Hour));
				int Hour = H.GetI(hi_Hour);
				Actions(Choose, Life, Hour);
				H.Set("Hour", 'N', Hour);
				if (!(H.GetI(hi_Sol) == 1 && Hour == 7) && Choose != 5) Changes(Life, Hour, Working);
			}
		}
	}
	void Menu_2(bool& Working) {
		system("cls");
		SetConsoleTextAttribute(h, 13);
		cout << "Помощь к игре" << endl;
		SetConsoleTextAttribute(h, 4);
		T.V(4, 35);
		SetConsoleTextAttribute(h, 15);
		cout << "Бла бла" << endl;
		SetConsoleTextAttribute(h, 4);
		T.V(4, 35);
		SetConsoleTextAttribute(h, 15);
		T.V(3);
		T.V(2);
		SetConsoleTextAttribute(h, 4);
		T.V(4, 25);
		SetConsoleTextAttribute(h, 15);
		int variety = _getch();
		switch (variety) {
		case 49: variety = 1; break;
		case 50: variety = 2; break;
		}
		if (variety != 1) Working = false;
	}
	void Menu_3(bool& Working) {
		system("cls");
		SetConsoleTextAttribute(h, 13);
		cout << "Разработчики" << endl;
		SetConsoleTextAttribute(h, 4);
		T.V(4, 45);
		SetConsoleTextAttribute(h, 13);
		cout << "Ответственный за разработку: ";
		SetConsoleTextAttribute(h, 15);
		cout << "Галкин Захар" << endl;
		SetConsoleTextAttribute(h, 4);
		T.V(4, 25);
		SetConsoleTextAttribute(h, 13);
		cout << "Тестировка: ";
		SetConsoleTextAttribute(h, 15);
		cout << "Галкин Захар" << endl;
		SetConsoleTextAttribute(h, 4);
		T.V(4, 45);
		SetConsoleTextAttribute(h, 15);
		T.V(3);
		T.V(2);
		SetConsoleTextAttribute(h, 4);
		T.V(4, 25);
		SetConsoleTextAttribute(h, 15);
		int variety = _getch();
		switch (variety) {
		case 49: variety = 1; break;
		case 50: variety = 2; break;
		}
		if (variety != 1) Working = false;
	}
	void Menu_4(bool& Working) {
		system("cls");
		SetConsoleTextAttribute(h, 13);
		cout << "Вы точно хотите выйти?" << endl;
		T.V(2);
		T.V(4, 25);
		SetConsoleTextAttribute(h, 15);
		int variety = _getch();
		switch (variety) {
		case 49: variety = 1; break;
		case 50: variety = 2; break;
		}
		if (variety == 1) Working = false;
	}
};
int Game::ConsumableCount = 0;
vector<Game::Consumable*> Game::ConsumableVector;
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Game G;
	bool Working = true;
	while (Working) {
		int Menu = G.Menu();
		switch (Menu) {
		case 1: G.GamingProcess(Working); break;
		case 2: G.Menu_2(Working); break;
		case 3: G.Menu_3(Working); break;
		case 4: G.Menu_4(Working);  break;
		}
	}
}
void Game::Human::Null() {
	HP = 70 + (rand() % 5) * 5;
	FP = 30 + (rand() % 7) * 5;
	EP = 100;
	PHP = 30 + (rand() % 3) * 10;
	DP = rand() % 21;
	Sol = 0;
	Hour = 7;
}