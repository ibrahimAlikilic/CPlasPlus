/**
* @file Dugum.hpp
* @description Tek yönlü bağlı liste ile işlemler
* @course 1. öğreim C grubu
* @assignment 1
* @date 06.11.2023
* @author ibrahim.alikilic@ogr.sakarya.edu.tr
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP
#include "Dugum.hpp"
#include<iostream>
class Dugum{
public:
    int sayi;
    Dugum* sonrakiDugum;
    Dugum(int sayi);
    ~Dugum();
};
#endif
