#include "Bitki.h"

// bitki nesnesi
Bitki BitkiOlustur(int deger) {
	Bitki this;
	this = (Bitki)malloc(sizeof(struct BITKI));
	this->super = CanliOlustur(deger,"B");
	
	// fonksiyon atamalarý
	this->super->deger = deger;
	this->super->GorunumGetir = &gorunum_Bitki;
	this->super->DegerGetir = &deger_Bitki;
	this->yoket = &BitkiYoket;
}
char* gorunum_Bitki(const Bitki this){
	return this->super->tur;
}
int deger_Bitki(const Bitki this) {
	return this->super->deger;
}
void BitkiYoket(const Bitki this) {
	if (this == NULL) 
		return;
	this->super->yoket(this->super);// miras aldýðýný yoket
	free(this);// kendini yok et
}