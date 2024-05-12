#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"
struct BITKI
{
	Canli super;
	void(*yoket)(struct BITKI*);
};
typedef struct BITKI* Bitki;

Bitki BitkiOlustur(int);
char* gorunum_Bitki(const Bitki); 
int deger_Bitki(const Bitki);
void BitkiYoket(const Bitki);

#endif
