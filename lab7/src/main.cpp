//============================================================================
// Name        : main.cpp
// Author      : Michał Wieczorek
// Version     : 5.0
// Copyright   :
// Description : Przeszukiwanie tablicy asocjacyjnej
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tablica.h"
#include "Stoper.h"
#include "Lista.h"
#include "Stos.h"
#include "Kolejka.h"
#include "Sort_szybkie.h"
#include "Tablica_aso.h"
#include "Drzewo.h"
#include "Drzewo_elem.h"

using namespace std;

int main() {
	srand(time(NULL));

	Stoper pomiar;
	int liczba_elementow[8] = {10, 100, 1000, 5000, 10000, 20000, 50000, 100000};
	int i;

	for (i = 0; i < 8; i++) {
		Drzewo *test = new Drzewo(liczba_elementow[i]);

		pomiar.mierz_czas(test, 0, 0);
		cout << "(" << liczba_elementow[i];
		cout << ",";
		cout << pomiar.wypisz_czas() << ")";
		cout << endl;

		delete test;
	}

	return 0;
}
