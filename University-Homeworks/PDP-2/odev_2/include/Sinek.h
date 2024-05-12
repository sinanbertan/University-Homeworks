#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK
{
	Bocek super;

	void(*yoket)(struct SINEK*);
};
typedef struct SINEK* Sinek;

Sinek SinekOlustur(int);
char* gorunum_Sinek(const Sinek);
void SinekYoket(const Sinek);
int deger_Sinek(const Sinek);

#endif
