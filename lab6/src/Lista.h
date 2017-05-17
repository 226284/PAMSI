/*
 * Lista.h
 *
 *  Created on: 30 mar 2017
 *      Author: michal
 */

#ifndef LISTA_H_
#define LISTA_H_
#include "IProgram.h"
#include "ILista.h"
#include "Lista_Elem.h"

namespace std {

class Lista: public ILista, public IProgram {
public:
	Lista();
	virtual ~Lista();
	// ILista
	virtual void dodaj_poczatek(int liczba); // dodaje nowy element na poczatek listy
	void dodaj_poczatek(string klucz, int liczba); // dodaje nowy element na poczatek listy (klucz+wartosc)

	virtual int rozmiar();                     	// zwraca aktualny rozmiar listy

	virtual Lista_Elem* wyszukaj(int klucz); // zwraca wskaźnik na element o podanym kluczu
	int wyszukaj(string klucz);				// zwraca wartosć, o podaniu stringa

	virtual void usun_poczatek();
	void usun(string wyraz);

	void wyswietl();
	//IProgram
	virtual void wykonaj_obliczenia(int typ_alg, int ilosc); // nadpisuje listę danymi, a następnie wyszukuje element
private:
	Lista_Elem* pierwszy;  // wskaźnik na pierwszy element listy
	Lista_Elem* ostatni;   // wskaźnik na ostatni element listy
	int Rozmiar;           // pole przechowuje rozmiar listy
};

} /* namespace std */

#endif /* LISTA_H_ */
