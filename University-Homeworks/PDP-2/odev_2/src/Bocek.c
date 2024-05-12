#include "Bocek.h"

Bocek BocekOlustur(int deger) {
	Bocek this;
	this = (Bocek)malloc(sizeof(struct BOCEK));

	// miras alma benzetimi
	this->super = CanliOlustur(deger,"C"); // ez
	this->super->GorunumGetir = &gorunum_Bocek;
	this->super->DegerGetir = &deger_Bocek;
	this->yoket = &BocekYoket;
}

char* gorunum_Bocek(const Bocek this) {
	return this->super->tur;
}
int deger_Bocek(const Bocek this) {
	return this->super->deger;
}
void BocekYoket(const Bocek this) {
	this->super->yoket(this->super);
	free(this);
}