#include "HabitatCanlisi.h"

// Habitat nesnesi
HabitatCanlisi HabitatCanlisiOlustur(int yeni_canli,int satirdaki_son_canlimi) {
	HabitatCanlisi new = (HabitatCanlisi)malloc(sizeof(struct HABITAT_CANLISI));	
	new->satirdaki_son_canlimi = satirdaki_son_canlimi;
	new->HabitatCanlisiGorunum = &habitatCanlisiGorunum;
	new->HabitatCanlisiYoket = &habitatCanlisiYoket;
	new->CanliDegeri = &canliDegeri;
	new->CanliTuru = &canliTuru;
	new->CanliOlum = &canliOlum;
	// Hangi canlı atanacaksa karar ver
	if (yeni_canli >= 1 && yeni_canli <= 9) {
		new->bitki = BitkiOlustur(yeni_canli);
		new->bocek= NULL;
		new->pire = NULL;
		new->sinek = NULL;
	}
	else if (yeni_canli >= 10 && yeni_canli <= 20) {
		new->bocek = BocekOlustur(yeni_canli);
		new->bitki = NULL;
		new->pire = NULL;
		new->sinek = NULL;
	}
	else if (yeni_canli >= 21 && yeni_canli <= 50) {
		new->sinek = SinekOlustur(yeni_canli);
		new->bocek = NULL;
		new->pire = NULL;
		new->bitki = NULL;
	}
	else if (yeni_canli >= 51 && yeni_canli <= 99) {
		new->pire = PireOlustur(yeni_canli);
		new->bocek = NULL;
		new->bitki = NULL;
		new->sinek = NULL;
	}
	return new;
}

void habitatCanlisiGorunum(HabitatCanlisi this) {
	// hangi canlı ise karar ver ve çağır
	if (this->bitki != NULL)
		printf("%s ", this->bitki->super->Gorunum(this->bitki->super, this->bitki));
	else if (this->bocek != NULL)
		printf("%s ", this->bocek->super->Gorunum(this->bocek->super, this->bocek));
	else if (this->sinek != NULL)
		printf("%s ", this->sinek->super->super->Gorunum(this->sinek->super->super, this->sinek));
	else if (this->pire != NULL)
		printf("%s ", this->pire->super->super->Gorunum(this->pire->super->super, this->pire));
	else
		printf("%s ", "X");
}
// bir canlıyı yoket
void habitatCanlisiYoket(HabitatCanlisi this) {
	// hangi canlı ise karar ver ve çağır
	if (this->bitki != NULL) {
		this->bitki->yoket(this->bitki);
		this->bitki = NULL;
	}
	else if (this->bocek != NULL) {
		this->bocek->yoket(this->bocek);
		this->bocek = NULL;
	}
	else if (this->sinek != NULL) {
		this->sinek->yoket(this->sinek);
		this->sinek = NULL;
	}
	else if (this->pire != NULL) {
		this->pire->yoket(this->pire);
		this->pire = NULL;
	}
}
// bir canlıyı öldürme
void canliOlum(HabitatCanlisi this) {
	if (this->bitki != NULL) {
		this->bitki->yoket(this->bitki);
		this->bitki = NULL;
	}
	else if (this->bocek != NULL) {
		this->bocek->yoket(this->bocek);
		this->bocek = NULL;
	}
	else if (this->sinek != NULL) {
		this->sinek->yoket(this->sinek);
		this->sinek = NULL;
	}
	else if (this->pire != NULL) {
		this->pire->yoket(this->pire);
		this->pire = NULL;
	}
}
// bir canlının sayısal değerini getirir
int canliDegeri(HabitatCanlisi this) {
	if (this->bitki != NULL)
		return this->bitki->super->DegerGetir(this->bitki);
	else if (this->bocek != NULL)
		return this->bocek->super->DegerGetir(this->bocek);
	else if (this->sinek != NULL)
		this->sinek->super->super->DegerGetir(this->sinek);
	else if (this->pire != NULL)
		this->pire->super->super->DegerGetir(this->pire);
}
// bir canlının turunu getirir
char* canliTuru(HabitatCanlisi this) {
	if (this->bitki != NULL)
		return this->bitki->super->Gorunum(this->bitki->super, this->bitki);
	else if (this->bocek != NULL)
		return this->bocek->super->Gorunum(this->bocek->super, this->bocek);
	else if (this->sinek != NULL)
		return this->sinek->super->super->Gorunum(this->sinek->super->super, this->sinek);
	else if (this->pire != NULL)
		return this->pire->super->super->Gorunum(this->pire->super->super, this->pire);
}