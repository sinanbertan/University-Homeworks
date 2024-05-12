#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK {
	Canli super;
	void(*yoket)(struct BOCEK*);
};
typedef struct BOCEK* Bocek;

Bocek BocekOlustur(int);
char* gorunum_Bocek(const Bocek);
void BocekYoket(const Bocek);
int deger_Bocek(const Bocek);
#endif