#include <iostream>
#include <cctype>

using namespace std;

void Trans(char* harf) {
    for (int i = 0; harf[i] != '\0'; i++) {
        harf[i] = tolower(harf[i]);
    }
}
int main()
{
    setlocale(LC_ALL, "Turkish");
    char Metin[] = "bİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ Bilgisayar Mühendisliği Bölümü";
    Trans(Metin);
    cout << Metin << endl;
}

