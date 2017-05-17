/*
 * ILista.h
 *
 *  Created on: 30 mar 2017
 *      Author: michal
 */

#ifndef ILISTA_H_
#define ILISTA_H_
#include "IProgram.h"
#include "Lista_Elem.h"

namespace std {

// ILista zawiera
class ILista{
public:
	ILista();
	virtual ~ILista();
	virtual void dodaj_poczatek(int liczba)=0;	// dodaje nowy element na początek listy
	virtual void usun_poczatek()=0;	// usuwa element z początku listy
	virtual int rozmiar()=0;               		// zwraca aktualny rozmiar listy
	virtual Lista_Elem* wyszukaj(int klucz)=0;	// zwraca wskaźnik na element o podanym kluczu
};

} /* namespace std */

#endif /* ILISTA_H_ */
