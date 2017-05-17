/*
 * Sort_szybkie.h
 *
 *  Created on: 11 kwi 2017
 *      Author: michal
 */

#ifndef SORT_SZYBKIE_H_
#define SORT_SZYBKIE_H_
#include "IProgram.h"
#include "ISort_szybkie.h"
#include "Tablica.h"

namespace std {

class Sort_szybkie: public IProgram, public ISort_szybkie {
public:
	Sort_szybkie(int rozmiar = 10, int rodzaj = 0, int pivot = 0);
	virtual ~Sort_szybkie();
	void wypelnij_danymi(int rodzaj); // wypełnia tablicę liczbami w zależności od podanego typu
	int podziel(int min, int max);	  // dzieli tablicę na dwie części
	int wyb_pivot(int min, int max);  // dobiera pivot w zależności od typu pivota podanego w konstruktorze
	void zamien(int i, int j);        // zamienia ze sobą 2 pozycje w tablicy

	//ISort_szybkie
	virtual void sortuj_dane(int min, int max); // sortuje dane w tablicy (f rekurencyjna)
	//IProgram
	virtual void wykonaj_obliczenia(int typ_alg, int ilosc); // wywołuje algorytm sortowania
private:
	Tablica *tab;  // na tej tablicy odbywa się sortowanie
	int typ_pivot; // typ wybierania pivota (pierwszy, środkowy, ostatni)
	int ilosc;     // ilość danych w tablicy
};

} /* namespace std */

#endif /* SORT_SZYBKIE_H_ */
