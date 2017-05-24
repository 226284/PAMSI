/*
 * Tablica.cpp
 *
 *  Created on: 17 mar 2017
 *      Author: michal
 */

#include "Tablica.h"

using namespace std;

// Konstruktor
Tablica::Tablica(int r) {
	TABLICA = new int[r];
	ROZMIAR = r;
	WYPELNIENIE = 0;
}
//Destruktor
Tablica::~Tablica() {
	delete[] TABLICA;
}
// Przypisanie wartosci do konkretnego miejsca w tablicy
int Tablica::przypisanie(int pozycja, int wartosc) {
	// jeżeli podano pozycję w zakresie tablicy
	if (pozycja < rozmiar()) {
		return TABLICA[pozycja] = wartosc;
	}
	//jeżeli podano nieprawodłową - ujemną pozycję
	else if (pozycja < 0) {
		cout << "BŁĄD: Nieprawidlowy indeks do zapisu liczby" << endl;
		return 0; // błąd domyślnie będzie zwracać 0;
	}
	// jeżeli podano pozycję poza zakresem tablicy -> powieksz tablice
	else {
		//cout << "Uwaga: ROZSZERZENIE OBSZARU PAMIECI" << endl;
		TABLICA = Tablica::powieksz_tablice(pozycja + 1, TABLICA); // do ostatniego elementu powiekszonej tablicy
		ROZMIAR = pozycja + 1;                      // wpisuje podaną mu wartosc
		return TABLICA[pozycja] = wartosc;
	}
}
// Odczytanie wartosci z konkretnego miejsca w tablicy
int Tablica::odczytanie(int pozycja) {
	// jeżeli indeks zawiera się w rozmiare tablicy, możemy wypisać jej komórkę
	if (pozycja < rozmiar()) {
		return TABLICA[pozycja];
	} else {
		cout << "BLAD: ODWOLANIE DO NIEISTNIEJACEGO OBSZARU PAMIECI" << endl;
		return 0; // błąd odczytu jeśli podano pozycję poza zakresem tablicy
	}
}
// Odczytanie aktualnego rozmiaru tablicy
int Tablica::rozmiar() {
	if (ROZMIAR >= 0) {
		return ROZMIAR;
	} else {
		cout << "BLAD: NIEPRAWIDLOWY ROZMIAR TABLICY" << endl;
		return 0; // błąd który nie powinien się pojawić
	}
}
// Zwraca ilość wypełnionych komórek tablicy
int Tablica::wypelnienie() {
	if (WYPELNIENIE >= 0) {
		return WYPELNIENIE;
	} else {
		cout << "BLAD: NIEPRWIDLOWY ROZMIAR TABLICY" << endl;
		return 0;
	}
}

void Tablica::wyswietlanie(){
	int i;

	for (i=0; i<rozmiar(); i++){
		cout << this->odczytanie(i) << " ";
	}
	cout << endl;
}

void Tablica::algorytm_n1(int ilosc) {
	// algorytm N+1 ******************************************************************************
	for (int i = 0; i < ilosc; i++) {
		Tablica::przypisanie(i, 1 + rand() % 9); // po każdym kroku, następuje nadpisanie tablicy o jeden element
	}

}

void Tablica::algorytm_2n(int ilosc) {
	// Algorytm 2*N (nowy) ***********************************************************************
	int rozmiar_poprz = 0;
	int rozmiar = ROZMIAR;
	int i = 0;

	while (rozmiar < ilosc) { //jeżeli ilosc docelowa elementow > od  aktualnego rozmiaru to zapisuje
		for (i = rozmiar; i > rozmiar_poprz; i--) { // petla zapisuje w odwrotnym kierunku, gdyż najpierw tworzy ostatni element
			Tablica::przypisanie(i, 1 + rand() % 9); // nowej tablicy, a później wypełnia pusty obszar poniżej liczbami pseudolosowymi
			WYPELNIENIE++;
		}
		rozmiar_poprz = rozmiar; //zapis poprzedniego rozmiaru tablicy w którym korzysta w kolejnym kroku
		rozmiar = 2 * rozmiar; // dwukrotne zwiększenie aktualnej tablicy
	}
	Tablica::przypisanie(rozmiar, 0); // w ostatnim kroku następuje poszerzenie tablicy, ale jest ona większa od docelowego
	for (i = ilosc; i > rozmiar_poprz; i--) { // rozmiaru, dlatego ostatnia pętla nadpisuje elementy do docelowej ilosci elementow
		Tablica::przypisanie(i, 1 + rand() % 9); // pozostała przestrzeń pozostaje pusta
		WYPELNIENIE++;
	}
}

// wypełnia tablicę pseudolosowymi liczbami
void Tablica::wykonaj_obliczenia(int typ_alg, int ilosc) {
	if (typ_alg == 0) {
		this->algorytm_n1(ilosc);
	}
	else if (typ_alg == 1) {
		this->algorytm_2n(ilosc);
	}
	else {
		cout << "Blad: Nieprawidlowy wybor algorytmu" << endl;
	}
}

// Metody prywatne
// Tworzy nową tablicę, która jest większa o tyle elementów ile podano
int *Tablica::powieksz_tablice(int rozmiar, int stara_tablica[]) {
	int i;
	int *nowa_tablica = new int[rozmiar];

	for (i = 0; i < ROZMIAR; i++) {
		nowa_tablica[i] = stara_tablica[i]; // jednoczenieśnie odbywa się jednorazowe kopiowanie tablicy
	}
	delete[] stara_tablica;
	return nowa_tablica;
}
// Zmniejsza tablicę, w zależności od jej wypełnienia (można użyć <=> gdy wypelnienie < rozmiaru)
int * Tablica::zmniejsz_tablice(int rozmiar, int wypelnienie,
		int stara_tablica[]) {
	int i;
	int *nowa_tablica = new int[wypelnienie];

	for (i = 0; i < wypelnienie; i++) {
		nowa_tablica[i] = stara_tablica[i]; // tu również przpisuje się tablicę, jednak teraz do mniejszej
	}
	delete[] stara_tablica;
	return nowa_tablica;
}
