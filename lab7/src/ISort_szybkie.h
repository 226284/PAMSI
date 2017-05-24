/*
 * ISortowanieszybkie.h
 *
 *  Created on: 11 kwi 2017
 *      Author: michal
 */

#ifndef ISORT_SZYBKIE_H_
#define ISORT_SZYBKIE_H_

namespace std {

class ISort_szybkie {
public:
	ISort_szybkie();
	virtual ~ISort_szybkie();
	virtual void sortuj_dane(int min, int max)=0;
};

} /* namespace std */

#endif /* ISORT_SZYBKIE_H_ */
