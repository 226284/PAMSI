/*
 * Drzewo.h
 *
 *  Created on: 18 maj 2017
 *      Author: michal
 */

#ifndef DRZEWO_H_
#define DRZEWO_H_
#include "IDrzewo.h"
#include "IProgram.h"
#include "Drzewo_elem.h"

namespace std {

class Drzewo: public IDrzewo, public IProgram {
public:
	Drzewo(int ile_wezlow);
	virtual ~Drzewo();
	// IDrzewo
	virtual bool dodaj(int klucz);
	virtual bool usun(int klucz); // retard alert
	virtual Drzewo_elem *wyszukaj(Drzewo_elem *element, int klucz);
	virtual void wyswietl(Drzewo_elem *element);
	virtual void wyswietl_pre(Drzewo_elem *element);
	// IProgram
	virtual void wykonaj_obliczenia(int typ_alg, int ilosc);

	bool uporzadkuj_dodawanie(Drzewo_elem *element);
	bool uporzadkuj_usuwanie(Drzewo_elem *element);
	void lewa_rotacja(Drzewo_elem *element);
	void prawa_rotacja(Drzewo_elem *element);
	Drzewo_elem *minimum(Drzewo_elem *element);
	Drzewo_elem *maksimum(Drzewo_elem *element);
	Drzewo_elem *nastepnik(Drzewo_elem *element);

private:
	Drzewo_elem *korzen;
	Drzewo_elem wartownik;
	int liczba_wezlow;

	void wypelnij();
	void zwolnij_pamiec(Drzewo_elem *element);
};

} /* namespace std */

#endif /* DRZEWO_H_ */
