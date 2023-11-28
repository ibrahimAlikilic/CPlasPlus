/**
* @file Basamak.hpp
* @description Tek yönlü bağlı liste ile işlemler
* @course 1. öğreim C grubu
* @assignment 1
* @date 06.11.2023
* @author ibrahim.alikilic@ogr.sakarya.edu.tr
*/
#ifndef BASAMAK_HPP
#define BASAMAK_HPP

#include<iostream>

class Basamak {
public:
    int basamak;
    Basamak* sonraki;

    Basamak(int basamak);
    ~Basamak();
};

#endif
