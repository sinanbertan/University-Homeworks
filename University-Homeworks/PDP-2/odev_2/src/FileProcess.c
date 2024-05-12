#include "FileProcess.h"

Habitat habitat = NULL; // Habitat nesnesi
int array_counter = 0; 
int size = 2;

// Dosya nesnesi olu�tur
File CreateFile(char* path) {
	File this= (File)malloc(sizeof(struct FILE));
	this->path = path;
	this->FileReader = &reader;
	this->StringSplitter = &splitter;
	return this;
}
// par�alama i�lemi
void splitter(char * line, char* seperator) {
	char *token = strtok(line, seperator);
	while (token != NULL)
	{
		habitat->HabitatYaraticisi(atoi(token));
		token = strtok(NULL, " ");
	}
	habitat->SatirSonuCanlisi();
}
// dosya oku
void reader(char* path,File this) {
	habitat = HabitatOlustur();
	
	FILE *fptr;
	fptr = fopen(path, "r");
	if (fptr == NULL) {
		printf("%s :No such file or directory!\n",path);
		return;
	}
	char myString[2000];
	while (fgets(myString, 2000, fptr)) {
		size = 2;
		array_counter = 0;
		this->StringSplitter(myString," ");
	}
	fclose(fptr);
	//habitat� yazd�r
	habitat->HabitatGorunum();
	printf("\nDevam etmek icin bir tusa basin ...");
	getch();
	habitat->HabitatKanunlari(); // canl�lar�n birbirini yemesi
	printf("\n");
	habitat->HabitatGorunum();
	habitat->HabitatYoket(); // yok et

	free(habitat);
}