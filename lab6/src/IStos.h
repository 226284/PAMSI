/*
 * IStos.h
 *
 *  Created on: 2 kwi 2017
 *      Author: michal
 */

#ifndef ISTOS_H_
#define ISTOS_H_

namespace std {

class IStos {
public:
	IStos();
	virtual ~IStos();
	virtual bool czy_pusty()=0;						// sprawdza czy stos jest pusty
	virtual int gorny()=0;						   // zwraca wartość elementu na górze stosu
	virtual void dodaj(int liczba)=0;             // dodaje nowy element na poczatek listy
	virtual void zdejmij()=0;					 // ściąga element ze stosu
	virtual int rozmiar()=0;                    // zwraca aktualny rozmiar listy
	virtual int wyszukaj(int klucz)=0;         // zwraca wskaźnik na element o podanym kluczu
};

} /* namespace std */

#endif /* ISTOS_H_ */
