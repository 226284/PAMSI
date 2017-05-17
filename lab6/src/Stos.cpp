/*
 * Stos.cpp
 *
 *  Created on: 30 mar 2017
 *      Author: michal
 */

#include "Stos.h"

namespace std {

//Konstruktor
Stos::Stos(int r) {
	tab = new int[r]; // alokacja pamięci pod stos
	Rozmiar = r;
	wsk = 0;
}

//Dekonstruktor
Stos::~Stos() {
	delete[] tab;  // zwolnienie zaalokowanej pamięci
}

//Sprawdzenie czy stos jest pusty
bool Stos::czy_pusty() {
	if (wsk == 0) {
		return true;
	}
	return false;
}

//Dodaje element na stos
void Stos::dodaj(int liczba) {
	if (wsk < Rozmiar) { // jeśli liczba el < rozmiaru
		tab[wsk++] = liczba; // dodaje nową liczbę na stos
	}
}

//Zwraca górny element stosu
int Stos::gorny() {
	if (wsk != 0) { //jeżeli są elementy na stosie
		return tab[wsk - 1]; //zwraca wartość górnego elementu stosu
	}
	return -1;
}

//Zdejmuje element ze stosu
void Stos::zdejmij() {
	if (wsk != 0) {
		wsk--; // przesunięcie skaźnika na element poprzedni
	}
}

//Zwraca aktualny rozmiar tablicy
int Stos::rozmiar() {
	return Rozmiar;
}

//zwraca wskaźnik na element o podanym kluczu
int Stos::wyszukaj(int klucz) {
	int i;
	int ile_this = this->wsk; // zapisuje informację na temat ilości elem stosu
	int n;
	Stos *tmp = new Stos(this->Rozmiar); // tworzy nowy stos

	for (i = 1; i <= ile_this; i++) {
		tmp->dodaj(this->gorny()); // przepisuje elementu ze starego do nowego stosu
		this->zdejmij();			// a następnie usuwa ze starego stosu
		if (tmp->gorny() == klucz) { // sprawdza czy wartość elementu zgadza się z kluczem
			for (n = tmp->wsk; n > 0; n--) { // jeśli się zgodzi, wstawiamy elementy z powrotem na stary stos
				this->dodaj(tmp->gorny());
				tmp->zdejmij();
			}
			delete tmp;
			return i;
		}
	}
	delete tmp;
	return -1;
}
//wypełnia stos a następnie znajduje element zgodny z kluczem
void Stos::wykonaj_obliczenia(int typ_alg, int ilosc) {
	int i;

	this->dodaj(5);
	for (i = 1; i < ilosc; i++) {
		this->dodaj(1);
	}

	this->wyszukaj(5);
}

} /* namespace std */
