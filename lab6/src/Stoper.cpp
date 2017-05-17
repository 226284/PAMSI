/*
 * Stoper.cpp
 *
 *  Created on: 18 mar 2017
 *      Author: michal
 */

#include "Stoper.h"

using namespace std;

Stoper::Stoper()
{	// zerowanie i konfiguracja stopera
	ROZNICA = 0;
	START = 0;
	STOP = 0;
	cout.setf(ios::fixed); // notacja liczbowa
	cout.precision(8); // liczba miejsc po przecinku
}

void Stoper::mierz_czas (IProgram *obiekt, int typ_alg, int ilosc){
	START = clock(); // zapisanie czasu startu mierzenia
	obiekt->wykonaj_obliczenia(typ_alg, ilosc); // tykonanie obliczeń na podanym obiekcie
	STOP = clock(); // zapisanie końca mierzenia
	ROZNICA = (STOP - START) / (double)CLOCKS_PER_SEC;//obliczenie czasu wykonania
}

double Stoper::wypisz_czas() const{
	return ROZNICA; // zwraca czas
}

Stoper::~Stoper()
{
	// TODO Auto-generated destructor stub
}
