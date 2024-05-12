#ifndef CANLI_H
#define CANLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct CANLI
{
	int deger;
	char* tur;

	char* (*Gorunum)(struct CANLI*,void*);
	char* (*GorunumGetir)();
	int(*canli_deger)(struct CANLI*, void*);
	int(*DegerGetir)();
	void (*yoket)(struct CANLI*);
};
typedef struct CANLI* Canli;

Canli CanliOlustur(int,char*);
char* gorunum(const Canli, void*);
int deger_getir(const Canli, void*);
void CanliYoket(const Canli);

#endif