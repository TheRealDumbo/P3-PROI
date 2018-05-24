#include <iostream>
#include <iostream>
#include <ostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <windows.h>
using namespace std;


class lek //klasa bazowa
{
    friend class farmaceuta;
private:
    string nazwa;
    int cena;
    int zapas;
    bool narecepte;
public:
    void fnazwa(string a)
    {
        nazwa=a;
    }
    void fcenazapas(int a, int b)
    {
        cena=a;
        zapas=b;
    }
    void fnarecepte(bool a)
    {
        narecepte=a;
    }
    bool zrecepta()
    {
        return narecepte;
    }
    int zcena()
    {
        return cena;
    }
    friend ostream & operator<<(ostream & a, lek &b)
    {
        a<<b.nazwa<<endl<<b.cena<<endl<<b.zapas<<endl<<b.narecepte<<endl<<endl<<endl;
        return a;
    }
};


class tabletki : public lek //klasy pochodne od klasy lek
{
public:
    tabletki() {}
    tabletki(string a, int b, int c, bool e)
    {
        fnazwa(a);
        fcenazapas(b, c);
        fnarecepte(e);
    }
    string ftyp()
    {
        return typ;
    }
private:
    const string typ="tabletki";
};


class syrop : public lek
{
public:
    syrop() {}
    syrop(string a, int b, int c, bool e)
    {
        fnazwa(a);
        fcenazapas(b, c);
        fnarecepte(e);
    }
    string ftyp()
    {
        return typ;
    }
private:
    const string typ="syrop";
};


class krople : public lek
{
public:
    krople() {}
    krople(string a, int b, int c, bool e)
    {
        fnazwa(a);
        fcenazapas(b, c);
        fnarecepte(e);
    }
    string ftyp()
    {
        return typ;
    }
private:
    const string typ="krople";
};


class aerozol : public lek
{
public:
    aerozol() {}
    aerozol(string a, int b, int c, bool e)
    {
        fnazwa(a);
        fcenazapas(b, c);
        fnarecepte(e);
    }
private:
    const string typ="aerozol";
};


class farmaceuta // klasa bedaca zbiorem zadan wykonywanych przez farmaceutow
{
public:
    lek kup(lek *a)
    {
        a->zapas=a->zapas-1;
        cout<<"Dokonano sprzedazy leku: "<<a->nazwa<<endl;
        return *a;
    }
    lek ustaw(lek *a)
    {
        a->zapas=a->zapas+3;
        cout<<"Ustawiono lek "<<a->nazwa<<" na polke"<<endl;
        return *a;
    }
    void doradz()
    {
        cout<<"Doradzono klientowi"<<endl;
    }
};
void symulacja() // funkcja przeprowadzajaca symulacje
{
    srand(time(NULL)); //tworzenie bazy lekow
    farmaceuta farmac;
    tabletki tab1("tab1", 10, 30, true);
    tabletki tab2("tab2", 15, 30, true);
    tabletki tab3("tab3", 20, 30, false);
    tabletki tab4("tab4", 7, 30, true);
    syrop syr1("syr1", 10, 30, false);
    syrop syr2("syr2", 11, 30, false);
    syrop syr3("syr3", 14, 30, true);
    syrop syr4("syr4", 16, 30, false);
    krople kro1("kro1", 10, 30, true);
    krople kro2("kro2", 20, 30, false);
    krople kro3("kro3", 25, 30, true);
    krople kro4("kro4", 17, 30, false);
    aerozol aero1("aero1", 30, 30, true);
    aerozol aero2("aero2", 40, 30, true);
    aerozol aero3("aero3", 39, 30, false);
    aerozol aero4("aero4", 14, 30, false);
    vector <tabletki> polka1(0); // robimy 4 polki, kazda na oddzielny typ leku
    vector <syrop> polka2(0);
    vector <krople> polka3(0);
    vector <aerozol> polka4(0);
    polka1.push_back(tab1); // zapelniamy polki lekami
    polka1.push_back(tab2);
    polka1.push_back(tab3);
    polka1.push_back(tab4);
    polka2.push_back(syr1);
    polka2.push_back(syr2);
    polka2.push_back(syr3);
    polka2.push_back(syr4);
    polka3.push_back(kro1);
    polka3.push_back(kro2);
    polka3.push_back(kro3);
    polka3.push_back(kro4);
    polka4.push_back(aero1);
    polka4.push_back(aero2);
    polka4.push_back(aero3);
    polka4.push_back(aero4);
    int ilerecept, ilebez, obrot;
    ilerecept=ilebez=obrot=0;
    int t, n, m;
    int ileprzyokienkach, ilebezroboty;
    int akcja;
    ileprzyokienkach=ilebezroboty=0;
    cin>>t; //wczytywanie parametrow
    cin>>n;
    cin>>m;
    int okn=0;
    for(int i=0; i<t; i++)
    {
        vector <int> okienka(n, 0); // ustalanie ilu klientow jest przy okienkach
        for(int i=0; i<m; i++)
        {
            okienka[i]=rand()%2;
        }
        for(int i=0; i<m; i++) //ustalanie ilu farmacmaceutow trzeba przydzielic do okienek
        {
            if(okienka[i]==1)
            {
                okn++;
            }
            if(i==n-1)
            {
                break;
            }
        }
        ileprzyokienkach=okn; //przypisanie farmaceutow do obowiazkow
        ilebezroboty=m-okn;
        cout<<"przy: "<<ileprzyokienkach<<endl;
        cout<<"bez: "<<ilebezroboty<<endl;
        okn=0;
        for(int i=0; i<ileprzyokienkach; i++) //petla, ktora losuje rodzaj akcji wykonywanej przez farmaceutow przy okienkach
        {
            akcja=rand()%2;
            switch (akcja)
            {
            case 0:
                farmac.doradz();
                break;
            case 1:
                int k=rand()%4 + 1; //sprzedaz losowego leku
                int l=rand()%4;
                switch (k)
                {
                case 1:
                    farmac.kup(&polka1[l]);
                    if(polka1[l].zrecepta()==1)
                    {
                        ilerecept+=1;
                    }
                    else
                    {
                        ilebez+=1;
                    }
                    obrot+=polka1[l].zcena();
                    break;
                case 2:
                    farmac.kup(&polka2[l]);
                    if(polka2[l].zrecepta()==1)
                    {
                        ilerecept+=1;
                    }
                    else
                    {
                        ilebez+=1;
                    }
                    obrot+=polka2[l].zcena();
                    break;
                case 3:
                    farmac.kup(&polka3[l]);
                    if(polka3[l].zrecepta()==1)
                    {
                        ilerecept+=1;
                    }
                    else
                    {
                        ilebez+=1;
                    }
                    obrot+=polka3[l].zcena();
                    break;
                case 4:
                    farmac.kup(&polka4[l]);
                    if(polka4[l].zrecepta()==1)
                    {
                        ilerecept+=1;
                    }
                    else
                    {
                        ilebez+=1;
                    }
                    obrot+=polka4[l].zcena();
                    break;
                }
            }
        }
        for(int i=0; i<ilebezroboty; i++) // petla dla pracy farmaceutow, ktorych obecnosc nie jest aktualnie wymagana przy okienkach
        {
            int k=rand()%4;
            int l=rand()%4;
            switch (k)
            {
            case 0:
                farmac.ustaw(&polka1[l]);
                break;
            case 1:
                farmac.ustaw(&polka2[l]);
                break;
            case 2:
                farmac.ustaw(&polka3[l]);
                break;
            case 3:
                farmac.ustaw(&polka4[l]);
                break;
            }
        }
        cout<<endl<<endl;
        Sleep(3000); //wstrzyamnie programu na 3s
    }
    cout<<endl<<endl<<endl;
    cout<<"Obrot apteki: "<<obrot<<endl;
    cout<<"Zrealizowane recepty: "<<ilerecept<<endl;
    cout<<"Ilosc lekow kupionych bez recepty: "<<ilebez<<endl;
}

int main()
{
    symulacja();
    return 0;
}
