#include <stdio.h>
#include <stdlib.h> //renk ve sayfa temizleme
#include <conio.h>
#include <iostream>

int main() {
    char giris; //hoşgeldiniz ekranını geçmek için
    char deger; //Kahve menüsünde seçim yapmak için ESC olduğu için int yerine char yapıp '' ifadeleri ile tam sayıları aldım.
    bool kontrol=true;
    bool fiyatkontrol = true;
    int adet;
    int fiyat;
    int ucret;

    do
    {
        system("color F1");
        system("cls");
        //ascii kodların çevrilmiş halini bulup tablo oluşturmaya çalıştım.
        printf("\n\n\n");
        printf("\t\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
        printf("\t\t\t\t\xBA\t\t\t\t\t     \xBA\t\t\t   \n");
        printf("\t\t\t\t\xBA\t\t\t\t\t     \xBA\t\t\t   \n");
        printf("\t\t\t\t\xBA\t\t\t\t\t     \xBA\t\t\t   \n");
        printf("\t\t\t\t\xBA\t  SANAL KAFEYE HOSGELDINIZ\t     \xBA\n");
        printf("\t\t\t\t\xBA\t\t\t\t\t     \xBA\n");
        printf("\t\t\t\t\xBA\t\t\t\t\t     \xBA\n");
        printf("\t\t\t\t\xBA\t\t\t\t\t     \xBA\n");
        printf("\t\t\t\t\xBA  devam etmek icin D veye d tusuna basiniz  \xBA\n");
        printf("\t\t\t\t\xBA \t cikis icin ESC tusuna basiniz\t     \xBA\n");
        printf("\t\t\t\t\xBA\t\t\t\t\t     \xBA\n");
        printf("\t\t\t\t\xBA\t\t\t\t\t     \xBA\n");
        printf("\t\t\t\t\xBA\t\t\t\t\t     \xBA\n");
        printf("\t\t\t\t\xBA\t\t\t\t\t     \xBA\n");
        printf("\t\t\t\t\xBA\t\t\t\t\t     \xBA\n");
        printf("\t\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
        giris = _getch();
        if (giris == 'D' || giris == 'd') {
            system("cls");
            printf("\n\n\n");
            for (int i = 0; i < 3; i++) {
                printf("\t");
            }
            printf("KAHVE CESITLERI\n");
            printf("\t\t------------------------------------------\n\n");
            printf("\t\t1- TURK KAHVESI\t\t  40 TL\n\n");
            printf("\t\t2- ESPRESSO \t\t  33 TL\n\n");
            printf("\t\t3- MOCHA \t\t  70 TL\n\n");
            printf("\t\t4- AMERICANO \t\t  47 TL\n\n");
            printf("\t\t5- CAPPUCINO \t\t  52 TL\n\n");
            printf("\t\t6- CAFFE LATTE \t\t  54 TL\n\n");
            printf("\t\t7- SICAK CIKOLATA \t  69 TL\n\n");
            printf("\t\t8- SALEP \t\t  73 TL\n\n\n\n");
            printf("\t\tLutfen seciminizi yapiniz.");
            deger = _getch();
            system("color E0");
            switch (deger) {
            case '1':
                system("cls");              
                char turkahve;
                printf("\n\n\n");
                for (int i = 0; i < 3; i++) {
                    printf("\t");
                }
                printf("TURK KAHVESI MENUSU\n");
                printf("\t\t------------------------------------------\n\n");
                printf("\t\t1- SUTLU TURK KAHVESI\t\t  49 TL\n\n");
                printf("\t\t2- DAMLA SAKIZLI TURK KAHVESI\t  46 TL\n\n");
                printf("\t\t3- CIKOLATALI TURK KAHVESI\t  50 TL\n\n");
                printf("\t\t4- SADE TURK KAHVESI\t\t  40 TL\n\n\n\n");
                printf("\t\tLutfen seciminizi yapiniz.");
                turkahve = _getch();
                switch (turkahve) {
                case '1':
                    system("cls");
                    printf("\n\n\n");
                    for (int i = 0; i < 4; i++) {
                        printf("\t");
                    }
                    printf("Kac adet SUTLU TURK KAHVESI istiyorsunuz ?\n");
                    printf("\t\t\tAdet giriniz:");
                    scanf_s("%d", &adet);
                    fiyat = adet * 49;
                    printf("\n\n\n\t\t\t\tToplam odemeniz gereken tutar: %d\n\n", fiyat);
                    printf("\t\t\t\tYatiracaginiz ucreti giriniz: ");
                    scanf_s("%d", &ucret);
                    do
                    {
                        system("cls");
                        if (ucret >= fiyat) {
                            fiyatkontrol = false;
                            printf("\t\t\t%d adet SUTLU TURK KAHVESI icin %d TL odemeniz alinmistir.\n", adet, ucret);
                            printf("\t\t\t\tGeri odeme: %d TL\n", ucret - fiyat);
                            printf("\t\t\t\tAFIYET OLSUN.YINE BEKLERIZ.");
                        }
                        else {
                            fiyatkontrol = true;
                            int ek;
                            printf("\n\n\n\n\n\n\t\t\tODEME MIKTARI YETERSIZ! Lutfen odediginiz miktara ilave ucret yatiriniz:\n");
                            printf("\t\t\t\tToplam odemeniz gereken tutar: %d\n", fiyat);
                            printf("\t\t\t\tSu ana kadar odediginiz miktar: %d\n", ucret);
                            printf("\t\t\t\tEk ucreti giriniz: ");
                            scanf_s("%d", &ek);
                            ucret += ek;
                        }

                    } while (fiyatkontrol);
                    break;
                case '2':
                    system("cls");
                    printf("\n\n\n");
                    for (int i = 0; i < 4; i++) {
                        printf("\t");
                    }
                    printf("Kac adet DAMLA SAKIZLI TURK KAHVESI istiyorsunuz ?\n");
                    printf("\t\t\tAdet giriniz:");
                    scanf_s("%d", &adet);
                    fiyat = adet * 46;
                    printf("\n\n\n\t\t\t\tToplam odemeniz gereken tutar: %d\n\n", fiyat);
                    printf("\t\t\t\tYatiracaginiz ucreti giriniz: ");
                    scanf_s("%d", &ucret);
                    do
                    {
                        system("cls");
                        if (ucret >= fiyat) {
                            fiyatkontrol = false;
                            printf("\t\t\t%d adet DAMLA SAKIZLI TURK KAHVESI icin %d TL odemeniz alinmistir.\n", adet, ucret);
                            printf("\t\t\t\tGeri odeme: %d TL\n", ucret - fiyat);
                            printf("\t\t\t\tAFIYET OLSUN.YINE BEKLERIZ.");
                        }
                        else {
                            fiyatkontrol = true;
                            int ek;
                            printf("\n\n\n\t\t\tODEME MIKTARI YETERSIZ! Lutfen odediginiz miktara ilave ucret yatiriniz:\n");
                            printf("\t\t\t\tToplam odemeniz gereken tutar: %d\n", fiyat);
                            printf("\t\t\t\tSu ana kadar odediginiz miktar: %d\n", ucret);
                            printf("\t\t\t\tEk ucreti giriniz: ");
                            scanf_s("%d", &ek);
                            ucret += ek;
                        }

                    } while (fiyatkontrol);
                    break;
                case '3':
                    system("cls");
                    printf("\n\n\n");
                    for (int i = 0; i < 4; i++) {
                        printf("\t");
                    }
                    printf("Kac adet CIKOLATALI TURK KAHVESI istiyorsunuz ?\n");
                    printf("\t\t\tAdet giriniz:");
                    scanf_s("%d", &adet);
                    fiyat = adet * 50;
                    printf("\n\n\n\t\t\t\tToplam odemeniz gereken tutar: %d\n\n", fiyat);
                    printf("\t\t\t\tYatiracaginiz ucreti giriniz: ");
                    scanf_s("%d", &ucret);
                    do
                    {
                        system("cls");
                        if (ucret >= fiyat) {
                            fiyatkontrol = false;
                            printf("\t\t\t%d adet CIKOLATALI TURK KAHVESI icin %d TL odemeniz alinmistir.\n", adet, ucret);
                            printf("\t\t\t\tGeri odeme: %d TL\n", ucret - fiyat);
                            printf("\t\t\t\tAFIYET OLSUN.YINE BEKLERIZ.");
                        }
                        else {
                            fiyatkontrol = true;
                            int ek;
                            printf("\n\n\n\t\t\tODEME MIKTARI YETERSIZ! Lutfen odediginiz miktara ilave ucret yatiriniz:\n");
                            printf("\t\t\t\tToplam odemeniz gereken tutar: %d\n", fiyat);
                            printf("\t\t\t\tSu ana kadar odediginiz miktar: %d\n", ucret);
                            printf("\t\t\t\tEk ucreti giriniz: ");
                            scanf_s("%d", &ek);
                            ucret += ek;
                        }

                    } while (fiyatkontrol);
                    break;
                case '4':
                    system("cls");
                    printf("\n\n\n");
                    for (int i = 0; i < 4; i++) {
                        printf("\t");
                    }
                    printf("Kac adet SADE TURK KAHVESI istiyorsunuz ?\n");
                    printf("\t\t\tAdet giriniz:");
                    scanf_s("%d", &adet);
                    fiyat = adet * 40;
                    printf("\n\n\n\t\t\t\tToplam odemeniz gereken tutar: %d\n\n", fiyat);
                    printf("\t\t\t\tYatiracaginiz ucreti giriniz: ");
                    scanf_s("%d", &ucret);
                    do
                    {
                        system("cls");
                        if (ucret >= fiyat) {
                            fiyatkontrol = false;
                            printf("\t\t\t%d adet SADE TURK KAHVESI icin %d TL odemeniz alinmistir.\n", adet, ucret);
                            printf("\t\t\t\tGeri odeme: %d TL\n", ucret - fiyat);
                            printf("\t\t\t\tAFIYET OLSUN.YINE BEKLERIZ.");
                        }
                        else {
                            fiyatkontrol = true;
                            int ek;
                            printf("\n\n\n\t\t\tODEME MIKTARI YETERSIZ! Lutfen odediginiz miktara ilave ucret yatiriniz:\n");
                            printf("\t\t\t\tToplam odemeniz gereken tutar: %d\n", fiyat);
                            printf("\t\t\t\tSu ana kadar odediginiz miktar: %d\n", ucret);
                            printf("\t\t\t\tEk ucreti giriniz: ");
                            scanf_s("%d", &ek);
                            ucret += ek;
                        }

                    } while (fiyatkontrol);
                }
            break;
            case '2':
                system("cls");
              
                char esp;
                printf("\n\n\n");
                for (int i = 0; i < 3; i++) {
                    printf("\t");
                }
                printf("ESPRESSO MENUSU\n");
                printf("\t\t------------------------------------------\n\n");
                printf("\t\t1- DOUBLE ESPRESSO\t\t  43 TL\n\n");
                printf("\t\t2- ESPRESSO MACCHIATO\t  40 TL\n\n");
                printf("\t\t3- DOUBLE ESPRESSO MACCHIATO\t  46 TL\n\n");
                printf("\t\t4- ESPRESSO\t\t  33 TL\n\n\n\n");
                printf("\t\tLutfen seciminizi yapiniz.");
                esp= _getch();
                switch (esp) {
                case '1':
                    system("cls");
                    printf("\n\n\n");
                    for (int i = 0; i < 4; i++) {
                        printf("\t");
                    }
                    printf("Kac adet DOUBLE ESPRESSO istiyorsunuz ?\n");
                    printf("\t\t\tAdet giriniz:");
                    scanf_s("%d", &adet);
                    fiyat = adet * 43;
                    printf("\n\n\n\t\t\t\tToplam odemeniz gereken tutar: %d\n\n", fiyat);
                    printf("\t\t\t\tYatiracaginiz ucreti giriniz: ");
                    scanf_s("%d", &ucret);
                    do
                    {
                        system("cls");
                        if (ucret >= fiyat) {
                            fiyatkontrol = false;
                            printf("\t\t\t%d adet DOUBLE ESPRESSO icin %d TL odemeniz alinmistir.\n", adet, ucret);
                            printf("\t\t\t\tGeri odeme: %d TL\n", ucret - fiyat);
                            printf("\t\t\t\tAFIYET OLSUN.YINE BEKLERIZ.");
                        }
                        else {
                            fiyatkontrol = true;
                            int ek;
                            printf("\n\n\n\t\t\tODEME MIKTARI YETERSIZ! Lutfen odediginiz miktara ilave ucret yatiriniz:\n");
                            printf("\t\t\t\tToplam odemeniz gereken tutar: %d\n", fiyat);
                            printf("\t\t\t\tSu ana kadar odediginiz miktar: %d\n", ucret);
                            printf("\t\t\t\tEk ucreti giriniz: ");
                            scanf_s("%d", &ek);
                            ucret += ek;
                        }

                    } while (fiyatkontrol);
                    break;
                case '2':
                    system("cls");
                    printf("\n\n\n");
                    for (int i = 0; i < 4; i++) {
                        printf("\t");
                    }
                    printf("Kac adet ESPRESSO MACCHIATO istiyorsunuz ?\n");
                    printf("\t\t\tAdet giriniz:");
                    scanf_s("%d", &adet);
                    fiyat = adet * 40;
                    printf("\n\n\n\t\t\t\tToplam odemeniz gereken tutar: %d\n\n", fiyat);
                    printf("\t\t\t\tYatiracaginiz ucreti giriniz: ");
                    scanf_s("%d", &ucret);
                    do
                    {
                        system("cls");
                        if (ucret >= fiyat) {
                            fiyatkontrol = false;
                            printf("\t\t\t%d adet ESPRESSO MACCHIATO icin %d TL odemeniz alinmistir.\n", adet, ucret);
                            printf("\t\t\t\tGeri odeme: %d TL\n", ucret - fiyat);
                            printf("\t\t\t\tAFIYET OLSUN.YINE BEKLERIZ.");
                        }
                        else {
                            fiyatkontrol = true;
                            int ek;
                            printf("\n\n\n\t\t\tODEME MIKTARI YETERSIZ! Lutfen odediginiz miktara ilave ucret yatiriniz:\n");
                            printf("\t\t\t\tToplam odemeniz gereken tutar: %d\n", fiyat);
                            printf("\t\t\t\tSu ana kadar odediginiz miktar: %d\n", ucret);
                            printf("\t\t\t\tEk ucreti giriniz: ");
                            scanf_s("%d", &ek);
                            ucret += ek;
                        }

                    } while (fiyatkontrol);
                    break;
                case '3':
                    system("cls");
                    printf("\n\n\n");
                    for (int i = 0; i < 4; i++) {
                        printf("\t");
                    }
                    printf("Kac adet DOUBLE ESPRESSO MACCHIATO istiyorsunuz ?\n");
                    printf("\t\t\tAdet giriniz:");
                    scanf_s("%d", &adet);
                    fiyat = adet * 46;
                    printf("\n\n\n\t\t\t\tToplam odemeniz gereken tutar: %d\n\n", fiyat);
                    printf("\t\t\t\tYatiracaginiz ucreti giriniz: ");
                    scanf_s("%d", &ucret);
                    do
                    {
                        system("cls");
                        if (ucret >= fiyat) {
                            fiyatkontrol = false;
                            printf("\t\t\t%d adet DOUBLE ESPRESSO MACCHIATO icin %d TL odemeniz alinmistir.\n", adet, ucret);
                            printf("\t\t\t\tGeri odeme: %d TL\n", ucret - fiyat);
                            printf("\t\t\t\tAFIYET OLSUN.YINE BEKLERIZ.");
                        }
                        else {
                            fiyatkontrol = true;
                            int ek;
                            printf("\n\n\n\t\t\tODEME MIKTARI YETERSIZ! Lutfen odediginiz miktara ilave ucret yatiriniz:\n");
                            printf("\t\t\t\tToplam odemeniz gereken tutar: %d\n", fiyat);
                            printf("\t\t\t\tSu ana kadar odediginiz miktar: %d\n", ucret);
                            printf("\t\t\t\tEk ucreti giriniz: ");
                            scanf_s("%d", &ek);
                            ucret += ek;
                        }

                    } while (fiyatkontrol);
                    break;
                case '4':
                    system("cls");
                    printf("\n\n\n");
                    for (int i = 0; i < 4; i++) {
                        printf("\t");
                    }
                    printf("Kac adet ESPRESSO istiyorsunuz ?\n");
                    printf("\t\t\tAdet giriniz:");
                    scanf_s("%d", &adet);
                    fiyat = adet * 33;
                    printf("\n\n\n\t\t\t\tToplam odemeniz gereken tutar: %d\n\n", fiyat);
                    printf("\t\t\t\tYatiracaginiz ucreti giriniz: ");
                    scanf_s("%d", &ucret);
                    do
                    {
                        system("cls");
                        if (ucret >= fiyat) {
                            fiyatkontrol = false;
                            printf("\t\t\t%d adet ESPRESSO icin %d TL odemeniz alinmistir.\n", adet, ucret);
                            printf("\t\t\t\tGeri odeme: %d TL\n", ucret - fiyat);
                            printf("\t\t\t\tAFIYET OLSUN.YINE BEKLERIZ.");
                        }
                        else {
                            fiyatkontrol = true;
                            int ek;
                            printf("\n\n\n\t\t\tODEME MIKTARI YETERSIZ! Lutfen odediginiz miktara ilave ucret yatiriniz:\n");
                            printf("\t\t\t\tToplam odemeniz gereken tutar: %d\n", fiyat);
                            printf("\t\t\t\tSu ana kadar odediginiz miktar: %d\n", ucret);
                            printf("\t\t\t\tEk ucreti giriniz: ");
                            scanf_s("%d", &ek);
                            ucret += ek;
                        }

                    } while (fiyatkontrol);
                }
             break;
             case '3':
                system("cls");
              
                char moc;
                printf("\n\n\n");
                for (int i = 0; i < 3; i++) {
                    printf("\t");
                }
                printf("MOCHA MENUSU\n");
                printf("\t\t------------------------------------------\n\n");
                printf("\t\t1- SADE MOCHA\t\t  70 TL\n\n");
                printf("\t\t2- CIKOLATALI MOCHA\t  75 TL\n\n");
                printf("\t\tLutfen seciminizi yapiniz.");
                moc= _getch();
                switch (moc) {
                case '1':
                    system("cls");
                    printf("\n\n\n");
                    for (int i = 0; i < 4; i++) {
                        printf("\t");
                    }
                    printf("Kac adet SADE MOCHA istiyorsunuz ?\n");
                    printf("\t\t\tAdet giriniz:");
                    scanf_s("%d", &adet);
                    fiyat = adet * 70;
                    printf("\n\n\n\t\t\t\tToplam odemeniz gereken tutar: %d\n\n", fiyat);
                    printf("\t\t\t\tYatiracaginiz ucreti giriniz: ");
                    scanf_s("%d", &ucret);
                    do
                    {
                        system("cls");
                        if (ucret >= fiyat) {
                            fiyatkontrol = false;
                            printf("\t\t\t%d adet SADE MOCHA icin %d TL odemeniz alinmistir.\n", adet, ucret);
                            printf("\t\t\t\tGeri odeme: %d TL\n", ucret - fiyat);
                            printf("\t\t\t\tAFIYET OLSUN.YINE BEKLERIZ.");
                        }
                        else {
                            fiyatkontrol = true;
                            int ek;
                            printf("\n\n\n\t\t\tODEME MIKTARI YETERSIZ! Lutfen odediginiz miktara ilave ucret yatiriniz:\n");
                            printf("\t\t\t\tToplam odemeniz gereken tutar: %d\n", fiyat);
                            printf("\t\t\t\tSu ana kadar odediginiz miktar: %d\n", ucret);
                            printf("\t\t\t\tEk ucreti giriniz: ");
                            scanf_s("%d", &ek);
                            ucret += ek;
                        }

                    } while (fiyatkontrol);
                    break;
                case '2':
                    system("cls");
                    printf("\n\n\n");
                    for (int i = 0; i < 4; i++) {
                        printf("\t");
                    }
                    printf("Kac adet CIKOLATALI MOCHA istiyorsunuz ?\n");
                    printf("\t\t\tAdet giriniz:");
                    scanf_s("%d", &adet);
                    fiyat = adet * 75;
                    printf("\n\n\n\t\t\t\tToplam odemeniz gereken tutar: %d\n\n", fiyat);
                    printf("\t\t\t\tYatiracaginiz ucreti giriniz: ");
                    scanf_s("%d", &ucret);
                    do
                    {
                        system("cls");
                        if (ucret >= fiyat) {
                            fiyatkontrol = false;
                            printf("\t\t\t%d adet CIKOLATALI MOCHA icin %d TL odemeniz alinmistir.\n", adet, ucret);
                            printf("\t\t\t\tGeri odeme: %d TL\n", ucret - fiyat);
                            printf("\t\t\t\tAFIYET OLSUN.YINE BEKLERIZ.");
                        }
                        else {
                            fiyatkontrol = true;
                            int ek;
                            printf("\n\n\n\t\t\tODEME MIKTARI YETERSIZ! Lutfen odediginiz miktara ilave ucret yatiriniz:\n");
                            printf("\t\t\t\tToplam odemeniz gereken tutar: %d\n", fiyat);
                            printf("\t\t\t\tSu ana kadar odediginiz miktar: %d\n", ucret);
                            printf("\t\t\t\tEk ucreti giriniz: ");
                            scanf_s("%d", &ek);
                            ucret += ek;
                        }

                    } while (fiyatkontrol);
                    break;

            }
            break;
            case '4':
                system("cls");            
                printf("\n\n\n");
                for (int i = 0; i < 3; i++) {
                    printf("\t");
                }                         
                printf("Kac adet AMERICANO istiyorsunuz ?\n");
                printf("\t\t\tAdet giriniz:");
                scanf_s("%d", &adet);
                fiyat = adet * 47;
                printf("\n\n\n\t\t\t\tToplam odemeniz gereken tutar: %d\n\n", fiyat);
                printf("\t\t\t\tYatiracaginiz ucreti giriniz: ");
                scanf_s("%d", &ucret);
                do
                {
                    system("cls");
                    if (ucret >= fiyat) {
                        fiyatkontrol = false;
                        printf("\t\t\t%d adet AMERICANO icin %d TL odemeniz alinmistir.\n", adet, ucret);
                        printf("\t\t\t\tGeri odeme: %d TL\n", ucret - fiyat);
                        printf("\t\t\t\tAFIYET OLSUN.YINE BEKLERIZ.");
                    }
                    else {
                        fiyatkontrol = true;
                        int ek;
                        printf("\n\n\n\t\t\tODEME MIKTARI YETERSIZ! Lutfen odediginiz miktara ilave ucret yatiriniz:\n");
                        printf("\t\t\t\tToplam odemeniz gereken tutar: %d\n", fiyat);
                        printf("\t\t\t\tSu ana kadar odediginiz miktar: %d\n", ucret);
                        printf("\t\t\t\tEk ucreti giriniz: ");
                        scanf_s("%d", &ek);
                        ucret += ek;
                    }

                } while (fiyatkontrol);
                break;
            case '5':
                system("cls");            
                printf("\n\n\n");
                for (int i = 0; i < 3; i++) {
                    printf("\t");
                }
                printf("Kac adet CAPPUCINO istiyorsunuz ?\n");
                printf("\t\t\tAdet giriniz:");
                scanf_s("%d", &adet);
                fiyat = adet * 52;
                printf("\n\n\n\t\t\t\tToplam odemeniz gereken tutar: %d\n\n", fiyat);
                printf("\t\t\t\tYatiracaginiz ucreti giriniz: ");
                scanf_s("%d", &ucret);
                do
                {
                    system("cls");
                    if (ucret >= fiyat) {
                        fiyatkontrol = false;
                        printf("\t\t\t%d adet CAPPUCINO icin %d TL odemeniz alinmistir.\n", adet, ucret);
                        printf("\t\t\t\tGeri odeme: %d TL\n", ucret - fiyat);
                        printf("\t\t\t\tAFIYET OLSUN.YINE BEKLERIZ.");
                    }
                    else {
                        fiyatkontrol = true;
                        int ek;
                        printf("\n\n\n\t\t\tODEME MIKTARI YETERSIZ! Lutfen odediginiz miktara ilave ucret yatiriniz:\n");
                        printf("\t\t\t\tToplam odemeniz gereken tutar: %d\n", fiyat);
                        printf("\t\t\t\tSu ana kadar odediginiz miktar: %d\n", ucret);
                        printf("\t\t\t\tEk ucreti giriniz: ");
                        scanf_s("%d", &ek);
                        ucret += ek;
                    }

                } while (fiyatkontrol);
                break;
            case '6':
                system("cls");
              
                printf("\n\n\n");
                for (int i = 0; i < 3; i++) {
                    printf("\t");
                }
                printf("Kac adet CAFFE LATTE istiyorsunuz ?\n");
                printf("\t\t\tAdet giriniz:");
                scanf_s("%d", &adet);
                fiyat = adet * 54;
                printf("\n\n\n\t\t\t\tToplam odemeniz gereken tutar: %d\n\n", fiyat);
                printf("\t\t\t\tYatiracaginiz ucreti giriniz: ");
                scanf_s("%d", &ucret);
                do
                {
                    system("cls");
                    if (ucret >= fiyat) {
                        fiyatkontrol = false;
                        printf("\t\t\t%d adet CAFFE LATTE icin %d TL odemeniz alinmistir.\n", adet, ucret);
                        printf("\t\t\t\tGeri odeme: %d TL\n", ucret - fiyat);
                        printf("\t\t\t\tAFIYET OLSUN.YINE BEKLERIZ.");
                    }
                    else {
                        fiyatkontrol = true;
                        int ek;
                        printf("\n\n\n\t\t\tODEME MIKTARI YETERSIZ! Lutfen odediginiz miktara ilave ucret yatiriniz:\n");
                        printf("\t\t\t\tToplam odemeniz gereken tutar: %d\n", fiyat);
                        printf("\t\t\t\tSu ana kadar odediginiz miktar: %d\n", ucret);
                        printf("\t\t\t\tEk ucreti giriniz: ");
                        scanf_s("%d", &ek);
                        ucret += ek;
                    }

                } while (fiyatkontrol);
                break;
            case '7':
                system("cls");
              
                char sca;
                printf("\n\n\n");
                for (int i = 0; i < 3; i++) {
                    printf("\t");
                }
                printf("SICAK CIKOLATA MENUSU\n");
                printf("\t\t------------------------------------------\n\n");
                printf("\t\t1- KAHVELI SICAK CIKOLATA\t\t  69 TL\n\n");
                printf("\t\t2- BEYAZ SICAK CIKOLATA\t  73 TL\n\n");
                printf("\t\tLutfen seciminizi yapiniz.");
                sca = _getch();
                switch (sca) {
                case '1':
                    system("cls");
                    printf("\n\n\n");
                    for (int i = 0; i < 4; i++) {
                        printf("\t");
                    }
                    printf("Kac adet KAHVELI SICAK CIKOLATA istiyorsunuz ?\n");
                    printf("\t\t\tAdet giriniz:");
                    scanf_s("%d", &adet);
                    fiyat = adet * 69;
                    printf("\n\n\n\t\t\t\tToplam odemeniz gereken tutar: %d\n\n", fiyat);
                    printf("\t\t\t\tYatiracaginiz ucreti giriniz: ");
                    scanf_s("%d", &ucret);
                    do
                    {
                        system("cls");
                        if (ucret >= fiyat) {
                            fiyatkontrol = false;
                            printf("\t\t\t%d adet KAHVELI SICAK CIKOLATA icin %d TL odemeniz alinmistir.\n", adet, ucret);
                            printf("\t\t\t\tGeri odeme: %d TL\n", ucret - fiyat);
                            printf("\t\t\t\tAFIYET OLSUN.YINE BEKLERIZ.");
                        }
                        else {
                            fiyatkontrol = true;
                            int ek;
                            printf("\n\n\n\t\t\tODEME MIKTARI YETERSIZ! Lutfen odediginiz miktara ilave ucret yatiriniz:\n");
                            printf("\t\t\t\tToplam odemeniz gereken tutar: %d\n", fiyat);
                            printf("\t\t\t\tSu ana kadar odediginiz miktar: %d\n", ucret);
                            printf("\t\t\t\tEk ucreti giriniz: ");
                            scanf_s("%d", &ek);
                            ucret += ek;
                        }

                    } while (fiyatkontrol);
                    break;
                case '2':
                    system("cls");
                    printf("\n\n\n");
                    for (int i = 0; i < 4; i++) {
                        printf("\t");
                    }
                    printf("Kac adet BEYAZ SICAK CIKOLATA istiyorsunuz ?\n");
                    printf("\t\t\tAdet giriniz:");
                    scanf_s("%d", &adet);
                    fiyat = adet * 73;
                    printf("\n\n\n\t\t\t\tToplam odemeniz gereken tutar: %d\n\n", fiyat);
                    printf("\t\t\t\tYatiracaginiz ucreti giriniz: ");
                    scanf_s("%d", &ucret);
                    do
                    {
                        system("cls");
                        if (ucret >= fiyat) {
                            fiyatkontrol = false;
                            printf("\t\t\t%d adet BEYAZ SICAK CIKOLATA icin %d TL odemeniz alinmistir.\n", adet, ucret);
                            printf("\t\t\t\tGeri odeme: %d TL\n", ucret - fiyat);
                            printf("\t\t\t\tAFIYET OLSUN.YINE BEKLERIZ.");
                        }
                        else {
                            fiyatkontrol = true;
                            int ek;
                            printf("\n\n\n\t\t\tODEME MIKTARI YETERSIZ! Lutfen odediginiz miktara ilave ucret yatiriniz:\n");
                            printf("\t\t\t\tToplam odemeniz gereken tutar: %d\n", fiyat);
                            printf("\t\t\t\tSu ana kadar odediginiz miktar: %d\n", ucret);
                            printf("\t\t\t\tEk ucreti giriniz: ");
                            scanf_s("%d", &ek);
                            ucret += ek;
                        }

                    } while (fiyatkontrol);
                    
                
                }
                break;
            case '8':
                system("cls");
              
                char sal;
                printf("\n\n\n");
                for (int i = 0; i < 3; i++) {
                    printf("\t");
                }
                printf("SALEP MENUSU\n");
                printf("\t\t------------------------------------------\n\n");
                printf("\t\t1- SEKERLI SALEP\t\t  73 TL\n\n");
                printf("\t\t2- SEKERSIZ SALEP\t  73 TL\n\n");
                printf("\t\tLutfen seciminizi yapiniz.");
                sal = _getch();
                switch (sal) {
                case '1':
                    system("cls");
                    printf("\n\n\n");
                    for (int i = 0; i < 4; i++) {
                        printf("\t");
                    }
                    printf("Kac adet SEKERLI SALEP istiyorsunuz ?\n");
                    printf("\t\t\tAdet giriniz:");
                    scanf_s("%d", &adet);
                    fiyat = adet * 73;
                    printf("\n\n\n\t\t\t\tToplam odemeniz gereken tutar: %d\n\n", fiyat);
                    printf("\t\t\t\tYatiracaginiz ucreti giriniz: ");
                    scanf_s("%d", &ucret);
                    do
                    {
                        system("cls");
                        if (ucret >= fiyat) {
                            fiyatkontrol = false;
                            printf("\t\t\t%d adet SEKERLI SALEP icin %d TL odemeniz alinmistir.\n", adet, ucret);
                            printf("\t\t\t\tGeri odeme: %d TL\n", ucret - fiyat);
                            printf("\t\t\t\tAFIYET OLSUN.YINE BEKLERIZ.");
                        }
                        else {
                            fiyatkontrol = true;
                            int ek;
                            printf("\n\n\n\t\t\tODEME MIKTARI YETERSIZ! Lutfen odediginiz miktara ilave ucret yatiriniz:\n");
                            printf("\t\t\t\tToplam odemeniz gereken tutar: %d\n", fiyat);
                            printf("\t\t\t\tSu ana kadar odediginiz miktar: %d\n", ucret);
                            printf("\t\t\t\tEk ucreti giriniz: ");
                            scanf_s("%d", &ek);
                            ucret += ek;
                        }

                    } while (fiyatkontrol);
                    break;
                case '2':
                    system("cls");
                    printf("\n\n\n");
                    for (int i = 0; i < 4; i++) {
                        printf("\t");
                    }
                    printf("Kac adet SEKERSIZ SALEP istiyorsunuz ?\n");
                    printf("\t\t\tAdet giriniz:");
                    scanf_s("%d", &adet);
                    fiyat = adet * 73;
                    printf("\n\n\n\t\t\t\tToplam odemeniz gereken tutar: %d\n\n", fiyat);
                    printf("\t\t\t\tYatiracaginiz ucreti giriniz: ");
                    scanf_s("%d", &ucret);
                    do
                    {
                        system("cls");
                        if (ucret >= fiyat) {
                            fiyatkontrol = false;
                            printf("\t\t\t%d adet SEKERSIZ SALEP icin %d TL odemeniz alinmistir.\n", adet, ucret);
                            printf("\t\t\t\tGeri odeme: %d TL\n", ucret - fiyat);
                            printf("\t\t\t\tAFIYET OLSUN.YINE BEKLERIZ.");
                        }
                        else {
                            fiyatkontrol = true;
                            int ek;
                            printf("\n\n\n\t\t\tODEME MIKTARI YETERSIZ! Lutfen odediginiz miktara ilave ucret yatiriniz:\n");
                            printf("\t\t\t\tToplam odemeniz gereken tutar: %d\n", fiyat);
                            printf("\t\t\t\tSu ana kadar odediginiz miktar: %d\n", ucret);
                            printf("\t\t\t\tEk ucreti giriniz: ");
                            scanf_s("%d", &ek);
                            ucret += ek;
                        }

                    } while (fiyatkontrol);

  
                }
                break;
            case 27:
                system("cls");
                system("color F1");
                char karar;
                printf("\nCikmak istediginizden emin misiniz? (E/H) ");
                scanf_s("%c", &karar);
                if (karar == 'E' || karar == 'e')
                    kontrol = false;
                else
                    kontrol = true;
                break;
            }
            char a;
            a = _getch();
            

        }
        else if (giris == 27) {
            system("cls");
            system("color F1");
            char karar;
            printf("\nCikmak istediginizden emin misiniz? (E/H) ");
            scanf_s("%c", &karar);
            if (karar == 'E' || karar == 'e')
                kontrol = false;             
            else
                kontrol = true;
        }
    } while (kontrol);
    
        

    return 0;
}