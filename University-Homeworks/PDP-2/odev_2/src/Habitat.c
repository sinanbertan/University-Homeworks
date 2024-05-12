#include "Habitat.h"

// canl�lar�n tutuldu�u dizi pointer
HabitatCanlisi* habitat_canlilari = NULL;
HabitatCanlisi kazananCanli = NULL;
int kazananCanli_x = 0, kazananCanli_y = 0; // kazanan canl� konumu
int habitat_canlilari_boyut = 5; // default dizi boyutu
int current_canli_indeks = 0;
int canli_sayisi = 0;

// nesne olu�tur
Habitat HabitatOlustur() {
	Habitat this = (Habitat)malloc(sizeof(struct HABITAT));
	this->HabitatYaraticisi = &habitatYaraticisi;
	this->HabitatYoket = &habitatYoket;
	this->SatirSonuCanlisi = &satirSonuCanlisi;
	this->HabitatGorunum = &habitatGorunum;
	this->HabitatKanunlari = &habitatKanunlari;
	return this;
}

void satirSonuCanlisi() {
	//son eklenen canl� sat�rdaki son canl� olarak atan�r
	// ama� yazd�r�rken alt sat�ra ge�mek
	// canl�lat matris olarak de�il tek boyutlu dize olarak tasarland��� i�in
	habitat_canlilari[current_canli_indeks - 1]->satirdaki_son_canlimi = 1;
}
// dizi boyutu yetmezse 2 ye katla
HabitatCanlisi* DiziBoyutArttir(HabitatCanlisi* array) {
	habitat_canlilari_boyut *= 2;
	HabitatCanlisi* yeni_dizi = (HabitatCanlisi*)malloc(sizeof(struct HABITAT_CANLISI) * habitat_canlilari_boyut);
	for (int i = 0; i < current_canli_indeks; i++)
		yeni_dizi[i] = array[i];
	free(array);// eski� diziyi sil
	array = yeni_dizi;
	return array;
}
// listeye yeni bir canl� ekler
void habitatYaraticisi(int yeni_canli) {
	if (habitat_canlilari == NULL) // bo�sa
		habitat_canlilari= (HabitatCanlisi*)malloc(sizeof(struct HABITAT_CANLISI)*habitat_canlilari_boyut);
	// dizi boyutunu artt�r
	if (current_canli_indeks >= habitat_canlilari_boyut)
		habitat_canlilari = DiziBoyutArttir(habitat_canlilari);
	HabitatCanlisi new = HabitatCanlisiOlustur(yeni_canli, 0);
	habitat_canlilari[current_canli_indeks] = new;
	current_canli_indeks++;
	canli_sayisi++;
}
// habitat� yazd�r
void habitatGorunum() {
	system("cls");
	for (int i = 0; i < canli_sayisi; i++) {
		habitat_canlilari[i]->HabitatCanlisiGorunum(habitat_canlilari[i]);
		//sat�rdaki son canl� ise alt sat�ra ge�
		if (habitat_canlilari[i]->satirdaki_son_canlimi == 1)
			printf("\n");
	}
	if (kazananCanli != NULL) // Kazanan
		printf("\nKazanan : %s : (%d,%d)\n", kazananCanli->CanliTuru(kazananCanli), kazananCanli_x, kazananCanli_y);
}
HabitatCanlisi Kapisma(HabitatCanlisi avci, HabitatCanlisi av) {
	if (strcmp(avci->CanliTuru(avci),"B")==0 && strcmp(av->CanliTuru(av), "P") == 0)
		return avci;
	else if (strcmp(avci->CanliTuru(avci), "C") == 0 && strcmp(av->CanliTuru(av), "B") == 0) // C B
		return avci;
	else if (strcmp(avci->CanliTuru(avci), "S") == 0 && strcmp(av->CanliTuru(av), "P") == 0)// S P
		return avci;
	else if (strcmp(avci->CanliTuru(avci), "B") == 0 && strcmp(av->CanliTuru(av), "S") == 0)// B S
		return avci;
	else if (strcmp(avci->CanliTuru(avci), "S") == 0 && strcmp(av->CanliTuru(av), "C") == 0) // S C
		return avci;
	else if (strcmp(avci->CanliTuru(avci), "C") == 0 && strcmp(av->CanliTuru(av), "P") == 0)// C P
		return avci;
	else if (strcmp(avci->CanliTuru(avci),av->CanliTuru(av))== 0) // ayn� canl� t�r� ise
		return NULL;
	else
		return av;
}
// kazanan canl�n�n konumunu bul
void KazananCanliKonumu() {
	int indeks = 0;
	while (habitat_canlilari[indeks] != kazananCanli)
	{
		kazananCanli_y++;
		if (habitat_canlilari[indeks]->satirdaki_son_canlimi == 1) {
			kazananCanli_y = 0;
			kazananCanli_x++;
		}
		indeks++;
	}	
}
// habitat ya�am d�ng�g�
// canl�alr biribirini yer ve sona kalan kazan�r
void habitatKanunlari() {
	HabitatCanlisi avci;
	HabitatCanlisi av;
	avci = habitat_canlilari[0];
	for (int i = 1; i < canli_sayisi; i++) {
		av= habitat_canlilari[i];
		HabitatCanlisi sonuc = Kapisma(avci, av);
		if (sonuc == avci) { // kazanan avc� ise
			av->CanliOlum(av);
		}
		else if(sonuc==av){// kazanan av ise
			avci->CanliOlum(avci); // eski avc� �ld�
			avci = av;//  yeni avc� bu
		}
		else {// ayn� canl� t�r� demektir
			if(avci->CanliDegeri(avci)>av->CanliDegeri(av))
				av->CanliOlum(av);
			else if (av->CanliDegeri(av) > avci->CanliDegeri(avci)) {
				avci->CanliOlum(avci);
				avci = av;
			}
			else { // canli de�erleri de e�itse
				av->CanliOlum(av);
			}
		}
		//habitatGorunum();
	}
	kazananCanli = avci;
	KazananCanliKonumu();
}
// b�t�n canl�lar� yok eder. Zten canl�lar �l�rkende yok ediliyor.
void habitatYoket() {
	for (int i = 0; i < canli_sayisi; i++) {
		habitat_canlilari[i]->HabitatCanlisiYoket(habitat_canlilari[i]);
	}
}