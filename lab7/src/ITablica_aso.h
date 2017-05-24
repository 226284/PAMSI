/*
 * ITablica_aso.h
 *
 *  Created on: 11 maj 2017
 *      Author: michal
 */

#ifndef ITABLICA_ASO_H_
#define ITABLICA_ASO_H_
#include <iostream>

namespace std {

class ITablica_aso {
public:
	ITablica_aso();
	virtual ~ITablica_aso();
	virtual void dodaj(string klucz, int wartosc)=0;
	virtual void usun(string klucz)=0;
	virtual int wyszukaj(string klucz)=0;
};

} /* namespace std */

#endif /* ITABLICA_ASO_H_ */
