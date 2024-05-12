#include "FileProcess.h"

int main() {
	File file = CreateFile("./doc/Veri.txt"); // File s�n�f�ndan nesne olu�turur
	file->FileReader(file->path,file); // dosya okumay� ve dier i�lemleri ba�lat�r.
	free(file); // i�lem bitiminde iade eder.
	return 0;
}