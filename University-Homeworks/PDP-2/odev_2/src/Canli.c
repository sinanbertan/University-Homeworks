#include "Canli.h"

// Canli nesnesi
Canli CanliOlustur(int deger,char* tur) {
	Canli this;
	this = (Canli)malloc(sizeof(struct CANLI));
	this->deger = deger;
	this->tur = tur;

	this->Gorunum = &gorunum;
	this->canli_deger = &deger_getir;
	this->yoket = &CanliYoket;
	return this;
}

char* gorunum(const Canli this, void* yapi) {
	// hangi yapý çaðýrdýysa o fonksiyona gider
	return this->GorunumGetir(yapi);
}
int deger_getir(const Canli this, void* yapi) {
	// hangi yapý çaðýrdýysa o fonksiyona gider
	return this->DegerGetir(yapi);
}
void CanliYoket(const Canli this) {
	if (this == NULL) 
		return;
	free(this);
}