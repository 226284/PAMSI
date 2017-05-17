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

using namespace std;

int main() {
	srand(time( NULL));

	int i, j;
	double suma = 0;
	int rozmiar_tab = 1000; // Wybór rozmiaru tablicy asocjacyjnej
	int ilosc_elem[7] = { 10, 20, 50, 100, 200, 500, 1000 }; // Ilość elementów do zapisu w tablicy
	int typ_alg = 1;		// Wybór metody haszowania
	Stoper pomiar;
	int liczba_pomiarow = 1000;

	for (j = 0; j < 7; j++) {
		for (i = 0; i < liczba_pomiarow; i++) {
			// Stworzenie tablicy asocjacyjnej
			Tablica_aso *tab = new Tablica_aso(rozmiar_tab, typ_alg,
					ilosc_elem[j]);

			pomiar.mierz_czas(tab, typ_alg, ilosc_elem[j]);
			suma += pomiar.wypisz_czas();

			delete tab;
		}
		cout << suma / liczba_pomiarow << endl;
		suma = 0;
	}

	return 0;
}
