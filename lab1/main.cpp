#include <iostream>
#include <locale.h>
#include "node.h"
#include "functions.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	//cout << "Выберите версию программы:\n1. Cписки вводятся вручную. Результаты работы функций ";
	cout << "\nСписки заполняются рандомными числами и на экран выводится время работы функций.";
	unsigned int choice = 2;

	//cin >> choice;
	menu(choice);
}