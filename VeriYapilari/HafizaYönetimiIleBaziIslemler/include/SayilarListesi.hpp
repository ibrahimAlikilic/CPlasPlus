/**
* @file SayilarListesi.hpp
* @description Tek yönlü bağlı liste ile işlemler
* @course 1. öğreim C grubu
* @assignment 1
* @date 06.11.2023
* @author ibrahim.alikilic@ogr.sakarya.edu.tr
*/
#ifndef SAYiLARLiSTESi_HPP
#define SAYiLARLiSTESi_HPP
#include <iostream>
#include "Dugum.hpp"
#include <iomanip> // stringstream için 
using namespace std;
class SayilarListesi
{
public:
    SayilarListesi();
    void Ekle(int sayi);
    void UstYaz();
    void SayilarListesiAdresYaz();
    void AdresDegerAyirma();
    void SayilarListesiDegerYaz();
    void AdresBosalt();
    void SonradanEkle(int sayi);
    void DegerleriSifirlama();
    int EnBuyuguBulma();
    void YenidenSirala(int eb);
    void ElemanSayisiArttir();
    ~SayilarListesi();
private:
    Dugum *ilk;
    int elemanSayisi;
    string basamakAdres;
};
#endif