/*
 * Kolejka.h
 *
 *  Created on: 30 mar 2017
 *      Author: michal
 */

#ifndef KOLEJKA_H_
#define KOLEJKA_H_
#include <iostream>
#include "IProgram.h"
#include "IKolejka.h"

namespace std {

class Kolejka: public IKolejka, public IProgram {
public:
	Kolejka(int r = 10);
	virtual ~Kolejka();
	//IKolejka
	virtual void dodaj(int element);  	// realizuje push, dodaje element na początek kolejki
	virtual void usun();       			// realizuje pop, pobiera ostatni element kolejki
	virtual int rozmiar();           	// podaje aktualny rozmiar kolejki
	virtual bool czy_pusta();		   	// sprawdza czy kolejka jest pusta
	virtual int pierwszy();            	// zwraca wartość pierwszego elementu
	virtual int wyszukaj(int klucz); 	// szuka elementu o podanym kluczu na liście
	//IProgram
	virtual void wykonaj_obliczenia(int typ_alg, int ilosc);
private:
	int glowa;		// "wskaźnik" na pierwszy element kolejki
	int ogon;	    // "wskaźnik" na ostatni element kolejki
	int Rozmiar;	// rozmiar kolejki
	int *tab;      	// tablica na elementy kolejki
};

} /* namespace std */

#endif /* KOLEJKA_H_ */
