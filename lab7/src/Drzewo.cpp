/*
 * Drzewo.cpp
 *
 *  Created on: 18 maj 2017
 *      Author: michal
 */

#include <iostream>
#include "Drzewo.h"

namespace std {

Drzewo::Drzewo(int ile_wezlow) {
	liczba_wezlow = ile_wezlow;

	// konfiguracja wartownika
	wartownik.kolor = 0; 	// kolor czarny
	wartownik.wartosc = 0;
	wartownik.lewy = &wartownik;
	wartownik.prawy = &wartownik;
	wartownik.rodzic = &wartownik;
	korzen = &wartownik;		// korzeń wskazuje na wartownika

	//wypelnienie drzewa
	wypelnij();
}

Drzewo::~Drzewo() {
	zwolnij_pamiec(korzen);
}

bool Drzewo::dodaj(int klucz) {
	Drzewo_elem *y, *x, *element;

	element = new Drzewo_elem(klucz);

	y = &wartownik;
	x = korzen;

	while (x != &wartownik) {
		y = x;
		if (element->wartosc < x->wartosc) {
			x = x->lewy;
		}
		else {
			x = x->prawy;
		}
	}

	element->rodzic = y;

	if (y == &wartownik) {
		korzen = element;
	}
	else if (element->wartosc < y->wartosc) {
		y->lewy = element;
	}
	else {
		y->prawy = element;
	}

	element->lewy = &wartownik; 	// lewy liść wskazuje na wartownika
	element->prawy = &wartownik;	// prawy tez
	element->kolor = 1; 			// zmieniamy kolor węzła na czerwony
	uporzadkuj_dodawanie(element);			// porzadkujemy drzewo

	return true;
}

bool Drzewo::usun(int klucz) {
	Drzewo_elem *x, *y, *element;
	element = new Drzewo_elem(klucz);

	if (element->lewy == &wartownik || element->prawy == &wartownik) {
		y = element;
	}
	else {
		y = nastepnik(element);
	}

	if (y->lewy != &wartownik) {
		x = y->lewy;
	}
	else {
		x = y->prawy;
	}
	x->rodzic = y->rodzic;

	if (y->rodzic == &wartownik) {
		korzen = element;
	}
	else if (y == y->rodzic->lewy) {
		y->rodzic->lewy = x;
	}
	else {
		y->rodzic->prawy = x;
	}

	if (y != element) {
		element->wartosc = y->wartosc;
	}

	if (y->kolor == 0) { //czarny
		uporzadkuj_usuwanie(x);
	}
	return true;
}

bool Drzewo::uporzadkuj_dodawanie(Drzewo_elem *element) {
	Drzewo_elem *element2;
	//element2 = &wartownik;

	while (element->rodzic->kolor == 1) { // jeśli rodzic ma kolor czerwony trzeba dokonać równoważenia
		// rodzic jest lewym synem
		if (element->rodzic == element->rodzic->rodzic->lewy) {
			element2 = element->rodzic->rodzic->prawy;
			// przypadek z czerwonym wujkiem
			if (element2->kolor == 1) {
				element->rodzic->kolor = 0;
				element2->kolor = 0;
				element->rodzic->rodzic->kolor = 1;
				element = element->rodzic->rodzic;
				continue;
			}
			// element jest prawym synem
			else if (element == element->rodzic->prawy) {
				element = element->rodzic;
				lewa_rotacja(element);
			}
			//element jest lewym synem
			element->rodzic->kolor = 0;
			element->rodzic->rodzic->kolor = 1;
			prawa_rotacja(element->rodzic->rodzic);
			break;
		}
		// rodzic jest prawym synem
		else {
			element2 = element->rodzic->rodzic->lewy;
			if (element2->kolor == 1) {
				element->rodzic->kolor = 0;
				element2->kolor = 0;
				element->rodzic->rodzic->kolor = 1;
				element = element->rodzic->rodzic;
				continue;
			}
			else if (element == element->rodzic->lewy) {
				element = element->rodzic;
				prawa_rotacja(element);
			}
			element->rodzic->kolor = 0;
			element->rodzic->rodzic->kolor = 1;
			lewa_rotacja(element->rodzic->rodzic);
			break;
		}
	}
	korzen->kolor = 0; // korzeń zawsze musi być czarny

	return true;
}

bool Drzewo::uporzadkuj_usuwanie(Drzewo_elem *element) {
	Drzewo_elem *element2;

	while (element != korzen && element->kolor == 0) {
		if (element == element->rodzic->lewy) {
			element2 = element->rodzic->prawy;

			if (element2->kolor == 0) {
				element->rodzic->kolor = 1;
				lewa_rotacja(element->rodzic);
				element2 = element->rodzic->prawy;
			}
			if (element2->lewy->kolor == 0 && element2->prawy->kolor == 0) {
				element2->kolor = 1;
				element = element->rodzic;
			}
			else if (element2->prawy->kolor == 0) {
				element2->lewy->kolor = 0;
				element2->kolor = 1;
				prawa_rotacja(element2);
				element2 = element->rodzic->prawy;
			}
			element2->kolor = element->rodzic->kolor;
			element->rodzic->kolor = 0;
			element2->prawy->kolor = 0;
			lewa_rotacja(element->rodzic);
			element = korzen;
		}
		else {
			element2 = element->rodzic->lewy;

			if (element2->kolor == 0) {
				element->rodzic->kolor = 1;
				prawa_rotacja(element->rodzic);
				element2 = element->rodzic->lewy;
			}
			if (element2->prawy->kolor == 0 && element2->lewy->kolor == 0) {
				element2->kolor = 1;
				element = element->rodzic;
			}
			else if (element2->lewy->kolor == 0) {
				element2->prawy->kolor = 0;
				element2->kolor = 1;
				lewa_rotacja(element2);
				element2 = element->rodzic->lewy;
			}
			element2->kolor = element->rodzic->kolor;
			element->rodzic->kolor = 0;
			element2->lewy->kolor = 0;
			prawa_rotacja(element->rodzic);
			element = korzen;
		}
	}
	element->kolor = 0;

	return true;
}

void Drzewo::lewa_rotacja(Drzewo_elem *element) {
	Drzewo_elem *element2 = element->prawy;
	element->prawy = element2->lewy;
	element2->lewy->rodzic = element;
	element2->rodzic = element->rodzic;

	if (element->rodzic == &wartownik) {
		korzen = element2;
	}
	else if (element == element->rodzic->lewy) {
		element->rodzic->lewy = element2;
	}
	else {
		element->rodzic->prawy = element2;
	}
	element2->lewy = element;
	element->rodzic = element2;
}

void Drzewo::prawa_rotacja(Drzewo_elem *element) {
	Drzewo_elem *element2 = element->lewy;
	element->lewy = element2->prawy;
	element2->prawy->rodzic = element;
	element2->rodzic = element->rodzic;

	if (element->rodzic == &wartownik) {
		korzen = element2;
	}
	else if (element == element->rodzic->prawy) {
		element->rodzic->prawy = element2;
	}
	else {
		element->rodzic->lewy = element2;
	}
	element2->prawy = element;
	element->rodzic = element2;
}

void Drzewo::wyswietl(Drzewo_elem *element) {
	if (element != &wartownik) {
		wyswietl(element->lewy);
		cout << element->wartosc;
		if (element->kolor == 0) {
			cout << "B";
		}
		else {
			cout << "R";
		}
		cout << " ";
		wyswietl(element->prawy);
	}
}

void Drzewo::wyswietl_pre(Drzewo_elem *element) {
	if (element != &wartownik) {
		cout << element->wartosc;
		if (element->kolor == 0) {
			cout << "B";
		}
		else {
			cout << "R";
		}
		cout << " ";
		wyswietl(element->lewy);
		wyswietl(element->prawy);
	}
}

Drzewo_elem *Drzewo::wyszukaj(Drzewo_elem *element, int klucz) {
	while (element != &wartownik && klucz != element->wartosc) {
		if (klucz < element->wartosc) {
			element = element->lewy;
		}
		else {
			element = element->prawy;
		}
	}
	return element;
}

Drzewo_elem *Drzewo::minimum(Drzewo_elem *element) {
	while (element->lewy != &wartownik) {
		element = element->lewy;
	}
	return element;
}

Drzewo_elem *Drzewo::maksimum(Drzewo_elem *element) {
	while (element->prawy != &wartownik) {
		element = element->prawy;
	}
	return element;
}

Drzewo_elem *Drzewo::nastepnik(Drzewo_elem *element) {
	Drzewo_elem *element2;

	if (element->prawy != &wartownik) {
		return minimum(element->prawy);
	}
	element2 = element->rodzic;

	while (element2 != &wartownik && element == element2->prawy) {
		element = element2;
		element2 = element2->rodzic;
	}
	return element2;
}

void Drzewo::wypelnij() {
	int i;

	for (i = 0; i < liczba_wezlow; i++) {
		dodaj(liczba_wezlow - i);
	}
}

void Drzewo::wykonaj_obliczenia(int typ_alg, int ilosc) {
	//Drzewo_elem *tmp;

	//this->wyswietl(korzen);
	//cout << endl;
	//this->wyswietl_pre(korzen);
	//cout << endl;

	for (int i = 0; i < 1000000; i++) {
		this->wyszukaj(korzen, liczba_wezlow);
	}

	//cout << "Czy to ta sama wartość: " << tmp->wartosc;

	//cout << endl;
}

void Drzewo::zwolnij_pamiec(Drzewo_elem *element) {
	if (element != &wartownik) {
		zwolnij_pamiec(element->lewy);
		zwolnij_pamiec(element->prawy);
		delete element;
	}
}

} /* namespace std */
