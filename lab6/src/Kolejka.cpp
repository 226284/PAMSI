/*
 * Kolejka.cpp
 *
 *  Created on: 30 mar 2017
 *      Author: michal
 */

#include "Kolejka.h"

namespace std {

Kolejka::Kolejka(int r) {
	glowa = 0;		// "wskaźnik" na pierwszy element kolejki
	ogon = 0;	    // "wskaźnik" na ostatni element kolejki
	Rozmiar = r;	// rozmiar kolejki
	tab = new int[r]; // tablica na elementy kolejki
}

Kolejka::~Kolejka() {
	delete[] tab;
}

// dodaje nowy element na koniec kolejki
void Kolejka::dodaj(int element) {
	int i;

	if (ogon < Rozmiar) { // jeśli jest wolne miejsce
		i = glowa + ogon++; //  i jest sumą liczby elem między ogonem a głową
		if (i >= Rozmiar) {
			i = i - Rozmiar; // zapisuje od nowego końca, czyli od początku
		}
		tab[i] = element; // przypisanie elementu
	}
}

// usuwa elememt z kolejki
void Kolejka::usun() {
	if (ogon != 0) { // jeśli znajdują się elementy
		ogon--;
		glowa++;
		if (glowa == Rozmiar) {
			glowa = 0;
		}
	}
}

// zwraca aktulany rozmiar kolejki
int Kolejka::rozmiar() {
	return Rozmiar;
}

// sprawdza czy kolejka jest pusta
bool Kolejka::czy_pusta() {
	if (ogon == 0) {
		return true;
	}
	return false;
}

// zwraca wartość pierwszego elementu kolejki
int Kolejka::pierwszy() {
	if (ogon == 0) {
		return -1;
	}
	return tab[this->glowa];
}

// wyszukuje element zgodny z kluczem
int Kolejka::wyszukaj(int klucz) {
	int i;
	int glowa_c = this->glowa;

	for (i = 1; i <= this->ogon; i++) {
		if (this->pierwszy() == klucz) {
			this->glowa = glowa_c;
			return ++glowa_c;
		}
		this->glowa++;
	}
	this->glowa = glowa_c;
	return -1;
}

// wypełnia kolejkę danymi, a następnie ją przeszukuje
void Kolejka::wykonaj_obliczenia(int typ_alg, int ilosc) {
	int i;

	for (i = 1; i < ilosc; i++) {
		this->dodaj(1);
	}
	this->dodaj(5);

	this->wyszukaj(5);
/*
	while (!this->czy_pusta()) {
		cout << this->pierwszy() << endl;
		this->usun();
}*/
}

} /* namespace std */
