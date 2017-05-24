/*
 * Tablica_aso.cpp
 *
 *  Created on: 27 kwi 2017
 *      Author: michal
 */

#include "Tablica_aso.h"

namespace std {

//Tablica_aso
Tablica_aso::Tablica_aso(int r, int typ, int ilosc_elem) {
	tab = new Lista[r];
	Rozmiar = r;
	rodzaj_haszu = typ;
	wypelnienie = ilosc_elem;

	wypelnij(); // wypełnia tablicę wylosowanymi wartościami
}

Tablica_aso::~Tablica_aso() {
	//delete tab;
}

void Tablica_aso::dodaj(string klucz, int wartosc) {
	int hasz;

	hasz = haszuj(klucz);
	tab[hasz].dodaj_poczatek(klucz, wartosc);
}

void Tablica_aso::usun(string klucz) {
	int hasz;

	hasz = haszuj(klucz);
	tab[hasz].usun_poczatek();
}

int Tablica_aso::wyszukaj(string klucz) {
	int hasz;
	int wartosc;

	hasz = haszuj(klucz);
	wartosc = tab[hasz].wyszukaj(klucz);

	return wartosc;
}

int Tablica_aso::haszuj(string slowo) {
	int suma = 0;
	unsigned int i;

	for (i = 0; i < slowo.length(); i++) { // suma znaków ASCI
		suma += (int) slowo[i];
	}

	if (rodzaj_haszu == 0) { // haszowanie modulo
		return suma % Rozmiar;
	}
	else if (rodzaj_haszu == 1) { // haszowanie przez mnożenie
		double A = (sqrt(5) - 1) / 2;

		return (int) (Rozmiar * fmod(suma * A, 1));
	}
	else { // w przypadku błędu
		cout << "Nieprawidłowa wartość haszu";
		return -1;
	}
}

string Tablica_aso::losuj_wyraz() {
	string wyraz;
	for (int j = 0; j < 4; j++) {
		wyraz += 65 + (rand() % 26);
	}
	return wyraz;
}

int Tablica_aso::losuj_wartosc() {
	int liczba;

	liczba = 1000 + rand() % 9000;

	return liczba;
}

void Tablica_aso::wyswietl() {
	int i;

	for (i = 0; i < Rozmiar; i++) {
		cout << i << ". ";
		tab[i].wyswietl();
		cout << endl;
	}
}

void Tablica_aso::wypelnij() {
	pierwszy_klucz = losuj_wyraz();
	int pierwsza_wartosc = losuj_wartosc();

	dodaj(pierwszy_klucz, pierwsza_wartosc); // pierwszy element jest po to, aby później go wyszukać

	for (int i = 0; i < wypelnienie - 1; i++) { // zapełnienie tablicy pozostałymi elementami
		dodaj(losuj_wyraz(), losuj_wartosc());
	}
}

void Tablica_aso::wykonaj_obliczenia(int typ_alg, int ilosc) {
	//wyswietl();

	wyszukaj(pierwszy_klucz);
}

} /* namespace std */
