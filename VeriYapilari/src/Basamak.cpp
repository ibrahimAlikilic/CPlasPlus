/**
* @file Basamak.cpp
* @description Tek yönlü bağlı liste ile işlemler
* @course 1. öğreim C grubu
* @assignment 1
* @date 06.11.2023
* @author ibrahim.alikilic@ogr.sakarya.edu.tr
*/
#include "Basamak.hpp"
#include <iostream>
int basamak;
Basamak *sonraki;
Basamak::Basamak(int basamak)
{ // Null olmayabiliri hatta olmayacak sanki ama bakçaz
    this->basamak = basamak;
    sonraki = NULL;
}
Basamak::~Basamak(){
    delete sonraki;
}
