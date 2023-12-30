/**
* Dugum.cpp
* @description Veri.txt den sayıları okuyup avl ağacı ve yigit lar oluşturup kurala silme işlemleri yapıyor
* @course Dersi aldığınız eğitim türü : 1/C
* @assignment Kaçıncı ödev olduğu : 2
* Kodu oluşturduğunuz Tarih : 11.12.2023
* Gruptakilerin yazar adları ve mail adresleri : İbrahim ALİKILIÇ / ibrahim.alikilic@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"
#include<iostream>
Dugum::Dugum(int veri)
{
    this->veri = veri;
    sol = 0;
    sag = 0;
    sonraki = NULL;
}
Dugum::~Dugum()
{
    sol = 0;
    sag = 0;
    delete sol;
    delete sag;
}