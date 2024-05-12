#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

struct PIRE
{
	Bocek super;

	void(*yoket)(struct PIRE*);
};
typedef struct PIRE* Pire;

Pire PireOlustur(int);
char* gorunum_Pire(const Pire);
int deger_Pire(const Pire);
void PireYoket(const Pire);

#endif
