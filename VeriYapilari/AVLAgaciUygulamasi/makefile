all:derle bagla calistir makefile
derle:
	g++  -c -I "./include"  ./src/AVLagaci.cpp -o ./lib/AVLagaci.o
	g++  -c -I "./include"  ./src/Dugum.cpp -o ./lib/Dugum.o
	g++  -c -I "./include"  ./src/Yigin.cpp -o ./lib/Yigin.o
	g++  -c -I "./include"  ./src/main.cpp -o ./lib/main.o
bagla: 
	g++  ./lib/AVLagaci.o ./lib/Yigin.o ./lib/Dugum.o ./lib/main.o -o ./bin/program 
calistir:
	./bin/program

