/*
 * Stos.h
 *
 *  Created on: 30 mar 2017
 *      Author: michal
 */

#ifndef STOS_H_
#define STOS_H_
#include <iostream>
#include "IStos.h"
#include "IProgram.h"

namespace std {

class Stos: public IStos, public IProgram{
public:
	Stos(int r=10);
	virtual ~Stos();
	//IStos
	virtual bool czy_pusty();		// sprawdza czy stos jest pusty (is_empty)
	virtual int gorny();            // zwraca wartość elementu na górze stosu (top)
	virtual void dodaj(int liczba); // dodaje nowy element na poczatek listy (push)
	virtual void zdejmij();			// ściąga element ze stosu (pop)
	virtual int rozmiar();          // zwraca aktualny rozmiar stosu
	virtual int wyszukaj(int klucz);// zwraca wskaźnik na element o podanym kluczu
	//IProgram
	virtual void wykonaj_obliczenia(int typ_alg, int ilosc);
private:
	int wsk;                     // "wskaźnik" na górny element stosu
	int Rozmiar;				 // rozmiar stosu
	int *tab;                    // tablica na elementy stosu
};

} /* namespace std */

#endif /* STOS_H_ */
