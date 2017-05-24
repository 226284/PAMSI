/*
 * Tablica_aso.h
 *
 *  Created on: 27 kwi 2017
 *      Author: michal
 */

#ifndef TABLICA_ASO_H_
#define TABLICA_ASO_H_
#include "Lista.h"
#include "IProgram.h"
#include "ITablica_aso.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

namespace std {

class Tablica_aso: public IProgram {
public:
	Tablica_aso(int r = 10, int typ = 0, int ilosc_elem = 10);
	virtual ~Tablica_aso();
	virtual void dodaj(string klucz, int wartosc);
	virtual void usun(string klucz);
	virtual int wyszukaj(string klucz);
	// IProgram
	virtual void wykonaj_obliczenia(int typ_alg, int ilosc);
private:
	Lista *tab;
	int Rozmiar;		// rozmiar tablicy
	int rodzaj_haszu;	// 0 - haszowanie modularne, 1 - haszowanie przez mnożenie
	int wypelnienie;	// ilosc wprowadzanych kluczy
	string pierwszy_klucz; // przechowywany pierwszy klucz (tylko do mierzenia czasu wyszukiwania)

	int haszuj(string slowo); 	// haszowanie
	string losuj_wyraz();
	int losuj_wartosc();
	void wypelnij();
	void wyswietl();
};

} /* namespace std */

#endif /* TABLICA_ASO_H_ */
