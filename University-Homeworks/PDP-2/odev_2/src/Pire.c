#include "Pire.h"

// Pire nesnesi
Pire PireOlustur(int deger) {
	Pire this;
	this = (Pire)malloc(sizeof(struct PIRE));
	this->super = BocekOlustur(deger);
	this->super->super->tur = "P";
	this->super->super->GorunumGetir = &gorunum_Pire;
	this->super->super->DegerGetir = &deger_Pire;
	this->yoket = &PireYoket;
}
char* gorunum_Pire(const Pire this) {
	return this->super->super->tur;
}
int deger_Pire(const Pire this) {
	return this->super->super->deger;
}
void PireYoket(const Pire this) {
	this->super->yoket(this->super);
	free(this);
}