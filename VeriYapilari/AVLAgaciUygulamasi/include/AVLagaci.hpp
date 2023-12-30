/**
* AVLagaci.hpp
* @description Veri.txt den sayıları okuyup avl ağacı ve yigit lar oluşturup kurala silme işlemleri yapıyor
* @course Dersi aldığınız eğitim türü : 1/C
* @assignment Kaçıncı ödev olduğu : 2
* Kodu oluşturduğunuz Tarih : 11.12.2023
* Gruptakilerin yazar adları ve mail adresleri : İbrahim ALİKILIÇ / ibrahim.alikilic@ogr.sakarya.edu.tr
*/
#ifndef AVLagaci_HPP
#define AVLagaci_HPP
#include<iostream>
#include "Dugum.hpp"
#include <iostream>
class AVLagaci
{
public:
    AVLagaci();
    ~AVLagaci();
    int Yukseklik(Dugum* aktifDugum);
    bool varmi(int aranan, Dugum* aktif);
    int enBuyuk(Dugum* aktif);// en büyük aramam lazım silme işleminde lazım
    // ekleme işleminden önce sola ve sağa döndürmeleri kurmam lazım ki düzenli bir şekilde ekleyebileyim
    Dugum* solaDondur(Dugum* buyukEbeveyin);
    Dugum* sagaDondur(Dugum* buyukEbeveyin);
    // artık ekleme kısmına geldik
    Dugum* ekle(int veri, Dugum* aktifDugum);
    Dugum* kok;
    AVLagaci* agacSonraki;
    void postOrder(Dugum* aktif);
    void yiginEkle(Dugum* aktif);
    int AVLToplamDugumDeger;
    void HarfleriYazdir();
    int TepeGetir(int kacinciYigin);
    int enBuyukVeri;
    int yiginAzalt(int kacinciYigin);
    void esitleme(bool sonMu);
    void HarfOlustur();
    bool ilkHarfYiginMi;
    void SonYazma();
    void AnaTepeOlusturma();
    void TepeSifirlama();
    void PointerSilici();
};
#endif
