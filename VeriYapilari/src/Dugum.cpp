/**
* @file Dugum.cpp
* @description Tek yönlü bağlı liste ile işlemler
* @course 1. öğreim C grubu
* @assignment 1
* @date 06.11.2023
* @author ibrahim.alikilic@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"
#include<iostream>
    int sayi;
    Dugum* sonrakiDugum;
    Dugum::Dugum(int sayi){
        this->sayi=sayi;
        sonrakiDugum=NULL;
    }
    Dugum::~Dugum(){
        delete sonrakiDugum;
    }
