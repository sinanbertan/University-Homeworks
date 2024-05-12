#include "Sinek.h"

// Sinek nesnesi
Sinek SinekOlustur(int deger) {
	Sinek this;
	this = (Sinek)malloc(sizeof(struct SINEK));
	this->super = BocekOlustur(deger);
	this->super->super->tur = "S";
	this->super->super->GorunumGetir = &gorunum_Sinek;
	this->super->super->DegerGetir = &deger_Sinek;

	this->yoket = &SinekYoket;
}

char* gorunum_Sinek(const Sinek this) {
	return this->super->super->tur;
}
int deger_Sinek(const Sinek this) {
	return this->super->super->deger;
}
void SinekYoket(const Sinek this) {
	this->super->yoket(this->super);
	free(this);
}