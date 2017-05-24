/*
 * IDrzewo.h
 *
 *  Created on: 18 maj 2017
 *      Author: michal
 */

#ifndef IDRZEWO_H_
#define IDRZEWO_H_
#include "Drzewo_elem.h"

namespace std {

class IDrzewo {
public:
	IDrzewo();
	virtual ~IDrzewo();
	virtual bool dodaj(int klucz)=0;
	virtual bool usun(int klucz)=0;
	virtual Drzewo_elem *wyszukaj(Drzewo_elem *element, int klucz)=0;
	virtual void wyswietl(Drzewo_elem *element)=0;
	virtual void wyswietl_pre(Drzewo_elem *element)=0;
};

} /* namespace std */

#endif /* IDRZEWO_H_ */
