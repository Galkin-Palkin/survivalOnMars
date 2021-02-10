#include "Game.h"
int Game::Human::GetI(HumanInfo Type) {
	switch (Type)
	{
	case hi_HP: {
		return HP;
		break;
	}case hi_FP: {
		return FP;
		break;
	}case hi_EP: {
		return EP;
		break;
	}case hi_PHP: {
		return PHP;
		break;
	}case hi_Sol: {
		return Sol;
		break;
	}case hi_Hour: {
		return Hour;
		break;
	}
	default: {
		return -100000;
		break;
	}
	}
}
double Game::Human::GetD(HumanInfo Type) {
	switch (Type) {
	case hi_DP:
		return DP; break;
	default:
		return -100000;
	}
}
void Game::Human::Set(HumanInfo Type, char Sign, int NumberI, double NumberD) {
	// Реализовано криво, потом переделаю. Нужно заменить 'N' на '=', убрать '0'. Перегрузить функцию для вещественных чисел
	switch (Type) {
	case hi_HP: {
		switch (Sign) {
		case '+': HP += NumberI; break;
		case '0': HP = 0; break;
		case '-': HP -= NumberI; break;
		case 'N': HP = NumberI; break;
		}
		break;
	}
	case hi_FP:
	{
		switch (Sign) {
		case '+': FP += NumberI; break;
		case '0': FP = 0; break;
		case '-': FP -= NumberI; break;
		case 'N': FP = NumberI; break;
		}
		break;
	}
	case hi_EP: {
		switch (Sign) {
		case '+': EP += NumberI; break;
		case '0': EP = 0; break;
		case '-': EP -= NumberI; break;
		case 'N': EP = NumberI; break;
		}
		break;
	}
	case hi_PHP: {
		switch (Sign) {
		case '+': PHP += NumberI; break;
		case '0': PHP = 0; break;
		case '-': PHP -= NumberI; break;
		case 'N': PHP = NumberI; break;
		}
		break;
	}
	case hi_DP: {
		switch (Sign) {
		case '+': DP += NumberD; break;
		case '0': DP = 0.0; break;
		case '-': DP -= NumberD; break;
		case 'N': DP = NumberD; break;
		}
		break;
	}
	case hi_Sol: {
		switch (Sign) {
		case '+': Sol += NumberI; break;
		case '0': Sol = 0; break;
		case '-': Sol -= NumberI; break;
		case 'N': Sol = NumberI; break;
		}
		break;
	}
	case hi_Hour: {
		switch (Sign) {
		case '+': Hour += NumberI; break;
		case '0': Hour = 0; break;
		case '-': Hour -= NumberI; break;
		case 'N': Hour = NumberI; break;
		}
		break;
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
	ConsumableVector.clear();
	ConsumableCount = 0;
}