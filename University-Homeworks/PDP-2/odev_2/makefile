all: compile run
compile:
	gcc -I ./include/ -o ./lib/Canli.o -c ./src/Canli.c
	gcc -I ./include/ -o ./lib/Bitki.o -c ./src/Bitki.c
	gcc -I ./include/ -o ./lib/Bocek.o -c ./src/Bocek.c
	gcc -I ./include/ -o ./lib/Sinek.o -c ./src/Sinek.c	
	gcc -I ./include/ -o ./lib/Pire.o -c ./src/Pire.c
	gcc -I ./include/ -o ./lib/Habitat.o -c ./src/Habitat.c
	gcc -I ./include/ -o ./lib/HabitatCanlisi.o -c ./src/HabitatCanlisi.c
	gcc -I ./include/ -o ./lib/FileProcess.o -c ./src/FileProcess.c
	gcc -I ./include/ -o ./bin/program ./lib/Canli.o ./lib/Bitki.o ./lib/Bocek.o ./lib/Sinek.o ./lib/Pire.o ./lib/Habitat.o ./lib/HabitatCanlisi.o ./lib/FileProcess.o ./src/Test.c
run:
	./bin/program