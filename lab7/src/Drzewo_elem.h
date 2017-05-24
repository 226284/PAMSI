/*
 * Drzewo_elem.h
 *
 *  Created on: 18 maj 2017
 *      Author: michal
 */

#ifndef DRZEWO_ELEM_H_
#define DRZEWO_ELEM_H_

namespace std {

class Drzewo_elem {
public:
	Drzewo_elem(int ile = 0);
	virtual ~Drzewo_elem();
	int wartosc;			// wartość przechowywana w węźle
	bool kolor;				// kolor węzła 0 - czarny, 1 - czerwony
	Drzewo_elem *lewy;		// wskażnik na lewego syna
	Drzewo_elem *prawy;		// wskaźnik na prawego syna
	Drzewo_elem *rodzic;	// wskaźnik na ojca
};

} /* namespace std */

#endif /* DRZEWO_ELEM_H_ */
