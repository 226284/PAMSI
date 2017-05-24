/*
 * Sort_szybkie.cpp
 *
 *  Created on: 11 kwi 2017
 *      Author: michal
 */

#include "Sort_szybkie.h"

namespace std {

Sort_szybkie::Sort_szybkie(int rozmiar, int rodzaj, int pivot) {
	tab = new Tablica(rozmiar);
	wypelnij_danymi(rodzaj); // rodzaj określa jak ułożone są liczby w tablicy
	typ_pivot = pivot;
	ilosc = rozmiar;
}

Sort_szybkie::~Sort_szybkie() {
	delete tab;
}

void Sort_szybkie::wypelnij_danymi(int rodzaj) {
	int i;

	if (rodzaj == 0) { // wypełnienie pseudolosowe
		for (i = 0; i < tab->rozmiar(); i++) {
			tab->przypisanie(i, rand() % tab->rozmiar() + 1);
		}
	}
	else if (rodzaj == 1) { // wypełnienie rosnąco
		for (i = 0; i < tab->rozmiar(); i++) {
			tab->przypisanie(i, i + 1);
		}
	}
	else if (rodzaj == 2) { // wypełnienie malejąco
		for (i = 0; i < tab->rozmiar(); i++) {
			tab->przypisanie(i, tab->rozmiar() - i);
		}
	}
}

void Sort_szybkie::sortuj_dane(int min, int max) {
	int sr;

	if (min < max) {
		sr = podziel(min, max);
		sortuj_dane(min, sr - 1);
		sortuj_dane(sr + 1, max);
	}
}

int Sort_szybkie::wyb_pivot(int min, int max) {
	if (typ_pivot == 0) {
		return min;
	}
	else if (typ_pivot == 1) {
		return min + (max - min) / 2;
	}
	else if (typ_pivot == 2) {
		return max;
	}
	else {
		return -1;
	}
}

int Sort_szybkie::podziel(int min, int max) {
	int x = wyb_pivot(min, max); // element dzielący
	int pivot = tab->odczytanie(x); //wartość elementu dzielącego
	int i;
	int j = min;

	zamien(x, max);
	for (i = min; i <= max - 1; i++) {
		if (tab->odczytanie(i) < pivot) {
			zamien(i, j);
			j = j + 1;
		}
	}
	zamien(j, max);
	return j;
}

void Sort_szybkie::zamien(int i, int j) {
	int tmp;

	tmp = tab->odczytanie(i);
	tab->przypisanie(i, tab->odczytanie(j));
	tab->przypisanie(j, tmp);
}

void Sort_szybkie::wykonaj_obliczenia(int typ_alg, int ilosc) {
	//tab->wyswietlanie();
	this->sortuj_dane(0, ilosc - 1);
	//tab->wyswietlanie();
}

} /* namespace std */
