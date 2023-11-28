all:derle bagla calistir makefile
derle:
	g++  -c -I "./include"  ./src/Basamak.cpp -o ./lib/Basamak.o
	g++  -c -I "./include"  ./src/Sayi.cpp -o ./lib/Sayi.o
	g++  -c -I "./include"  ./src/Dugum.cpp -o ./lib/Dugum.o
	g++  -c -I "./include"  ./src/SayilarListesi.cpp -o ./lib/SayilarListesi.o
	g++  -c -I "./include"  ./src/main.cpp -o ./lib/main.o

bagla: 
	g++  ./lib/Basamak.o ./lib/Sayi.o ./lib/Dugum.o ./lib/SayilarListesi.o ./lib/main.o -o ./bin/program 
calistir:
	./bin/program