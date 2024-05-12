#include "HabitatCanlisi.h"
struct HABITAT {

	void (*HabitatYaraticisi)(int);
	void(*HabitatGorunum)();
	void(*HabitatYoket)();
	void(*SatirSonuCanlisi)();
	void(*HabitatKanunlari)();
};
typedef struct HABITAT* Habitat;

Habitat HabitatOlustur();
void habitatYaraticisi(int);
void habitatGorunum();
void satirSonuCanlisi();
void habitatKanunlari();
void habitatYoket();