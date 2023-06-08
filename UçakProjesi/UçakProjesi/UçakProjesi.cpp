#include <iostream>
using namespace std;

const float bilet = 150;
const float biletCocuk = 75;
const int koltukSayisi = 50;
class Ucak {
public:
    Ucak() {  cout << "Hosgeldiniz"; }
    int biletAdet = 0;
    int biletAdetCocuk = 0;
    int rezerve = 0;
    int rezerveCocuk = 0;
    ~Ucak() { cout << "Gule Gule"; }
    void BiletAlma(int *Adet) {
        bool secim;
        cout << "Almak istediginiz bilet Sayisini giriniz :";
        cin >> *Adet;
        cout << "Lutfen Bilet Turu Seciniz\n";
        cout << "Ebeveynler icin 1:\n";
        cout << "Cocuklar icin 0:\n";
        for (int i = 0; i < *Adet; i++)
        {
            cin >> secim;
            if (secim == 1)
                biletAdet++;
            else if (secim == 0)
                biletAdetCocuk++;
            *Adet = biletAdet + biletAdetCocuk;
        }
        cout << "***************************************\n";
        cout <<"Almak istediginiz bilet sayisi : " << *Adet<<endl;
        cout <<"Secilen Cocuk bilet sayisi : " << biletAdetCocuk << endl;
        cout << "Secilen Ebeveyn bilet sayisi : " << biletAdet << endl;
        Fiyatlandırma(&biletAdet, &biletAdetCocuk);
    };
    void Fiyatlandırma(int* adet,int* adetCocuk) {
        cout << "***************************************\n";
        float Ucret = 0;
        Ucret = *adet * bilet + *adetCocuk * biletCocuk;
        Hediye(adet,adetCocuk);
        cout << "Odemeniz Gereken Ucret : " << Ucret <<"TL"<< endl;
        Indirim(adet, adetCocuk,Ucret);

    };
    void Hediye(int* adet, int* adetCocuk) {
        int AdetCocukYeni = *adetCocuk;
        if (*adetCocuk >= 3)
            AdetCocukYeni ++;
        else if (*adet >= 2)
            AdetCocukYeni++;
        cout << AdetCocukYeni - *adetCocuk << " Adet Hediye Biletiniz bulunmaktadir\n";
    };
    void Indirim(int* adet, int* adetCocuk,float Ucret){
        cout << "***************************************\n";
        if (*adet == 2 && *adetCocuk == 3)
            Ucret = Ucret - Ucret * 0.35;
        if (*adet == 2 && *adetCocuk == 5)
            Ucret = Ucret - Ucret * 0.5;
        cout << "Indirimli fiyat : " << Ucret << "TL" << endl;
    }
};

//Ucak bilet Similasyonu
//3 cocuk bilet alana 1 couk bilet bedava
//2 bilet alana 1 cocuk bileti bedava 
//2 bilet + 3 cocuk bileti %35 indirim
//2 bilet + 5 cocuk bileti %50 indirim
int main()
{
    int* adet = new int;
    Ucak *ucak =new Ucak;
    ucak->BiletAlma(adet);
}

