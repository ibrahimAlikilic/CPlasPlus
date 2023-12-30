/**
* Yigin.cpp
* @description Veri.txt den sayıları okuyup avl ağacı ve yigit lar oluşturup kurala silme işlemleri yapıyor
* @course Dersi aldığınız eğitim türü : 1/C
* @assignment Kaçıncı ödev olduğu : 2
* Kodu oluşturduğunuz Tarih : 11.12.2023
* Gruptakilerin yazar adları ve mail adresleri : İbrahim ALİKILIÇ / ibrahim.alikilic@ogr.sakarya.edu.tr
*/
#include "Yigin.hpp"
#include "Dugum.hpp"
#include <iostream>
using namespace std;
Yigin::Yigin()
{
    tepe = -1; // -1 den başlatıyoruz çünkü ilk index 0dır
    tepe2 = NULL;
    veriler = 0;
    kapasite = 0;
    sonraki = NULL;
    genislet(5); // şimdi eğer benim dizim 5 eleman alabildiği halde ben 6. bir eleman eklemek istiyorsam dizimi genişletmem gerekir
}
void Yigin::genislet(int boyut)
{
    int* yeniAlan = new int[boyut + kapasite]; // sabit bir genişlet değerim var ve önceden genişleterek oluşturmuş olduğum kapasitem var bunları toplayıp yeni alan oluşturuyorum
    for (int i = 0; i <= tepe; i++)
    {
        yeniAlan[i] = veriler[i]; // elemanlarımı atıyorum
    }
    if (veriler)
        delete[] veriler; // artık bunu kullanmayacağım çöp bırakmayıp siliyorum daha doğrusu eski verilerin oldupu alanı siliyorum
    veriler = yeniAlan;   // yenileri eski ismime atıyorum
    kapasite += boyut;    // kapasitemi yeniliyorum
}
void Yigin::ekle(int veri)
{
    if (tepe == kapasite - 1)
    { // yani benim index değerim kapasitemden 1 az ise demek ben kapasitem kadar eleman eklemişim ve kapasitemi arttırmam lazım demek
        genislet(kapasite);
    }
    tepe++; // elemanı ekleyeceğim index
    veriler[tepe] = veri;
}
int Yigin::cikar()
{
    if (tepe != -1)
    {
        tepe--; // silme felan yok yığında direk tepe değeri azaltınca zaten bir önceki indexe kadar ayarlamış olduğumuzdan halloluyor
    }
    return tepe;
}
int Yigin::getir()
{
    if (tepe != -1) // eğer yığın boş değilse eleman atamadığımızda ya da hepsini sildiğimizde tepe -1 olduğundan bu şekilde kontrol ediyoruz
        return veriler[tepe];
    return -1;
}
void Yigin::bosalt()
{
    tepe = -1;
}
Yigin::~Yigin()
{
    delete[] veriler;
    delete tepe2;
    delete sonraki;
}