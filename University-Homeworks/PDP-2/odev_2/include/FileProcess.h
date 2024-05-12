#ifndef FILEPROCESS_H
#define FILEPROCESS_H

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Habitat.h"
struct FILE {
	char* path;
	void(*FileReader)(char*,struct FILE*);
	void(*StringSplitter)(char *,char*);
};
typedef struct FILE* File;


File CreateFile(char*);
void reader(char*,File);
void splitter(char*,char*);

#endif