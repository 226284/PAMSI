/*
 * Element.h
 *
 *  Created on: 1 kwi 2017
 *      Author: michal
 */

#ifndef LISTA_ELEM_H_
#define LISTA_ELEM_H_
#include <string>

namespace std {

class Lista_Elem {
public:
	Lista_Elem *nastepny;
	int wartosc;
	string klucz;

	Lista_Elem();
	virtual ~Lista_Elem();
};

} /* namespace std */

#endif /* LISTA_ELEM_H_ */
