/**
* Yigin.hpp
* @description Veri.txt den sayıları okuyup avl ağacı ve yigit lar oluşturup kurala silme işlemleri yapıyor
* @course Dersi aldığınız eğitim türü : 1/C
* @assignment Kaçıncı ödev olduğu : 2
* Kodu oluşturduğunuz Tarih : 11.12.2023
* Gruptakilerin yazar adları ve mail adresleri : İbrahim ALİKILIÇ / ibrahim.alikilic@ogr.sakarya.edu.tr
*/
#ifndef YIGIN_HPP
#define YIGIN_HPP
#include "Dugum.hpp"
class Yigin
{
public:
    Yigin();
    ~Yigin();
    void ekle(int veri);
    int cikar();
    void bosalt();
    int getir();
    int* veriler;
    // iki tepe var karıştırma biri yığınnların adresleri için 0 dan başlıyor diyeri index için
    int tepe;
    int anaTepe;
    Dugum* tepe2; // kullanmıyorum duruyor en son kontrol et sil
    Yigin* sonraki;
    char tekamulHarf;
    int kacinciYigin;
private:
    void genislet(int boyut);
    int kapasite;
};

#endif