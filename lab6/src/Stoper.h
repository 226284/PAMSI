/*
 * Stoper.h
 *
 *  Created on: 18 mar 2017
 *      Author: michal
 */

#ifndef STOPER_H_
#define STOPER_H_
#include "Tablica.h"
#include <iostream>
#include <ctime>
#include "IProgram.h"

using namespace std;

class Stoper
{
public:
	Stoper(); // Konstruktor
	~Stoper(); // Destruktor
	void mierz_czas (IProgram *obiekt, int typ_alg, int ilosc); // mierzy czas wykonania programu na podanym pojemniku z danymi
	double wypisz_czas() const; // zwraca wartość zmierzonego czasu
private:
	double ROZNICA;  // przechowuje czas w jakim został wykonany algorytm
	clock_t START; // przechowuje czas startu
	clock_t STOP; // czas zakończenia pomiaru
};

#endif /* STOPER_H_ */
