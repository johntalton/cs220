#ifndef LONGINT_H
#define LONGINT_H
#include <iostream.h>

#include "list.h"
#include "LIterator.h"

#define MAXLEN 1000
#define maxslice  10000

struct longintnode 
{
	int value;
	longintnode(){};
	void Init(int val) {value = val;};
};


class longint 
{
	friend longint operator*(const longint&, const longint&);
 friend	longint operator+(const longint&, const longint&);
	friend  ostream& operator <<(ostream& , const longint&);
	friend  istream& operator >>(istream& , longint&);
	friend  void printLongInt(ListIterator<longintnode> &Aiter);
	public:
		longint(){};
		~longint(){};
	private:
  		List <longintnode> lngint;
};
#endif