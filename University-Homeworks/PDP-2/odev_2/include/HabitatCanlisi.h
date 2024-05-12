#ifndef HABITATCANLISI_H
#define HABITATCANLISI_H

#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"


struct HABITAT_CANLISI {
	Bitki bitki;
	Bocek bocek;
	Sinek sinek;
	Pire pire;

	int satirdaki_son_canlimi;
	void(*HabitatCanlisiGorunum)();
	void(*HabitatCanlisiYoket)();
	int(*CanliDegeri)(struct HABITAT_CANLISI*);
	char*(*CanliTuru)(struct HABITAT_CANLISI*);
	void(*CanliOlum)();
	struct HABITAT_CANLISI* next;
};
typedef struct HABITAT_CANLISI* HabitatCanlisi;

HabitatCanlisi HabitatCanlisiOlustur(int,int);
void habitatCanlisiGorunum(HabitatCanlisi);
void habitatCanlisiYoket(HabitatCanlisi);
int canliDegeri(HabitatCanlisi);
char *canliTuru(HabitatCanlisi);
void canliOlum(HabitatCanlisi);

#endif
