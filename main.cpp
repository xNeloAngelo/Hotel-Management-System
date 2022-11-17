
#include <iostream>
#include <vector>
#include <string.h>
#include "biblioteka.h"
#include <cstdlib>
#include <conio.h>
//ukljucivanje bilbioteka
using namespace std;
void meniSobe(vector<Sobe>&  listaSoba);
void meniRadnik(vector<radnik>& listaRadnika);
void meniGosti(vector<gosti>& listaGostiju, vector<Sobe>& listaSoba);
void meniRezervacije(vector<rezervacije>& listaRezervacija, vector<gosti>& listaGostiju, vector<Sobe>& listaSoba);
void kreirajSobu(vector<Sobe>&  listaSoba);
void printajSobu(vector<Sobe>& listaSoba);
void urediSobu(vector<Sobe>& listaSoba);
void izbrisiSobu(vector<Sobe>& listaSoba);
void dodajGosta(vector<gosti>& listaGostiju, vector<Sobe>& listaSoba);
void printajGoste(vector<gosti>& listaGostiju);
void izbrisiGosta(vector<gosti>& listaGostiju,vector<Sobe>& listaSoba);
void dodajRadnika(vector<radnik>& listaRadnika);
void ispisRadnika(vector<radnik>& listaRadnika);
void urediRadnika(vector<radnik>& listaRadnika);
void dodajRezervaciju(vector<rezervacije>& listaRezervacija, vector<gosti>& listaGostiju, vector<Sobe>& listaSoba);
void izbrisiRezervaciju(vector<rezervacije>& listaRezervacija, vector<Sobe>& listaSoba);
void ispisRezervacija(vector<rezervacije>& listaRezervacija);
// pozivanje svih funkcija koje koristimo sa referencom na objekat/te
int main()
{
vector<Sobe> listaSoba; // vector tipa clase sobe objekat listaSoba
vector<gosti> listaGostiju; // vector tipa clase gosti, objekat listaGostiju
vector<radnik> listaRadnika; // vector tipa klase radnik, objekat listaRadnika
vector<rezervacije> listaRezervacija; //vector tipa klase rezervacija, objekat listaRezervacija
int run,odabirPrv;
run =1;
   while (run==1){
        system("cls");

    cout<<"________________________________________"<<endl;
    cout<<endl;
    cout<<"           Hotel sistem"<<endl;
    cout<<"________________________________________"<<endl;
    cout<<endl;
    cout<<"         1.Sobe     2.Gosti"<<endl;
    cout<<endl;
    cout<<"         3.Radnici  4.Rezervacije"<<endl;
    cout<<endl;
    cout<<"         5.Exit"<<endl;
    cout<<endl;
    cout<<"________________________________________"<<endl;
    cout<<endl;
    cout<<"Odabir : ";
    cin>>odabirPrv;
    cout<<"________________________________________"<<endl;
    if(odabirPrv==1)
        meniSobe(listaSoba);
    else if(odabirPrv==2)
        meniGosti(listaGostiju,listaSoba);
    else if(odabirPrv==3)
        meniRadnik(listaRadnika);
    else if (odabirPrv==4)
        meniRezervacije(listaRezervacija,listaGostiju,listaSoba);
    else if(odabirPrv==5)
        run=0;
    else
        cout<<"Opcija nije validna, pritisnite enter da nastavite!";
        getch();

   }
    return 0;
}

void kreirajSobu(vector<Sobe>& listaSoba){
    string br,status,kar;
    char velSobe;
    cout<<"________________________________________"<<endl;
    cout<<endl;
    cout<<"\tUnesite broj sobe: ";
    cin>>br;
    cout<<"\tUnesite status sobe (s,r): ";
    cin>>status;
    cout<<"\tUnesite velicinu sobe (s,m,l): ";
    cin>>velSobe;
    cin.get();
    cout<<"\tUnesite karakteritsike sobe: ";
    getline(cin,kar);
    cout<<"________________________________________"<<endl;
    cout<<endl;
    Sobe novaSoba(br,status,kar,velSobe);
    listaSoba.push_back(novaSoba);
}

void printajSobu(vector<Sobe>& listaSoba){
    unsigned int vSize;
    vSize=listaSoba.size();
    for(unsigned int i=0; i<vSize; i++){
    cout<<"________________________________________"<<endl;
    cout<<endl;
    cout<<"\tBroj sobe je : "<<listaSoba[i].getBroj()<<endl;
    cout<<"\tStatus sobe je: "<<listaSoba[i].getStatus()<<endl;
    cout<<"\tKarakteristike sobe su:"<<listaSoba[i].getKar()<<endl;
    cout<<"\tVelicina sobe je: "<<listaSoba[i].getVelicina()<<endl;
    cout<<"________________________________________"<<endl;
    cout<<endl;

        }
        getch();
}

void urediSobu(vector<Sobe>& listaSoba){
    unsigned int vSize;
    string brEdit,noviBr,noveKar;
    int izmjena;
    string noviStatus;
    vSize=listaSoba.size();
    cout<<"Unesite broj sobe koju zelite editovat: ";
    cin>>brEdit;
    for(unsigned int i=0; i<vSize; i++){
            if (listaSoba[i].getBroj() == brEdit){
                cout<<"________________________________________"<<endl;
                cout<<endl;
                cout<<"\tSta zelite izmjeniti?"<<endl;
                cout<<"________________________________________"<<endl;
                cout<<endl;
                cout<<" 1.Broj sobe \n 2.Status sobe \n 3.Karakteristike sobe" <<endl;
                cin>>izmjena;
                if(izmjena==1){
                    cout<<"Unesite novi broj sobe: ";
                    cin>>noviBr;
                    listaSoba[i].promijeniBroj(noviBr);
                }
                else if(izmjena==2){
                    cout<<"Unesite novi status sobe: ";
                    cin>>noviStatus;
                    listaSoba[i].promjeniStatus(noviStatus);}

                else if(izmjena==3){
                    cout<<"Unesite nove karakteristike sobe: ";
                    cin.get();
                    getline(cin,noveKar);
                    listaSoba[i].promjeniKar(noveKar);
                }
                else
                    cout<<"Nevazeci unos!"<<endl;
                    getch();

                }
            else
                cout<<"Broj sobe nije pronadjen!"<<endl;
                getch();
                }
}

void izbrisiSobu(vector<Sobe>& listaSoba){
  unsigned int vSize;
  string brBrisanje;
    vSize=listaSoba.size();
    cout<<"Unesite broj sobe koju zelite izbrisati: ";
    cin>>brBrisanje;
        for(unsigned int i=0; i<vSize; i++){
            if (listaSoba[i].getBroj() == brBrisanje){
                listaSoba.erase(listaSoba.begin()+i);
            }
            else
                cout<<"Broj sobe nije pronadjen!"<<endl;
                }

}

void dodajGosta(vector<gosti>& listaGostiju, vector<Sobe>& listaSoba){
    string ime,prezime,soba;
    int odabir=2;
    unsigned int vSize;
    vSize=listaSoba.size();
    cout<<"Unesite ime gosta: ";
    cin>>ime;
    cout<<"Unesite prezime gosta: ";
    cin>>prezime;
    cout<<"Odaberite sobu za gosta: ";
    while(odabir==2){
    cin>>soba;
        for(unsigned int i=0; i<vSize; i++){
        if(listaSoba[i].getBroj() == soba)
            odabir--;
        if(listaSoba[i].getStatus()== "s")
            odabir--;
        else
            cout<<"Soba nije dostupna, pokusajte drugu sobu"<<endl;
        listaSoba[i].promjeniStatus("r");
            }
    }
    gosti noviGost(ime,prezime,soba);

    listaGostiju.push_back(noviGost);
}

void printajGoste(vector<gosti>& listaGostiju){
    unsigned int vSize;
    vSize=listaGostiju.size();
    for(unsigned int i=0; i<vSize; i++){
        cout<<"________________________________________"<<endl;
        cout<<endl;
        cout<<"\tIme i prezime gosta: "<<listaGostiju[i].getIme()<<" "<<listaGostiju[i].getPrezime()<<endl;
        cout<<"\tBroj sobe gosta je: "<<listaGostiju[i].getBroj()<<endl;
        cout<<"________________________________________"<<endl;
        cout<<endl;
        getch();
    }

}

void izbrisiGosta(vector<gosti>& listaGostiju, vector<Sobe>& listaSoba){
  unsigned int vGosti,vSobe;
  string brBrisanje;
    vGosti=listaGostiju.size();
    vSobe=listaSoba.size();
    cout<<"Unesite broj sobe u kojoj se gost nalazi:";
    cin>>brBrisanje;
    for(unsigned int i=0; i<vGosti; i++){
        if (listaGostiju[i].getBroj() == brBrisanje){
        listaGostiju.erase(listaGostiju.begin()+i);
            }
        else
        cout<<"Broj sobe nije pronadjen!"<<endl;
    }
    for(unsigned int i=0; i<vSobe; i++){
        if (listaSoba[i].getBroj() == brBrisanje)
        listaSoba[i].promjeniStatus("s");
    }
}

void dodajRadnika(vector<radnik>& listaRadnika){
    string ime,prezime,pozicija,jmbg;
    cout<<"Unesite ime radnika: ";
    cin>>ime;
    cout<<"Unesite prezime radnika: ";
    cin>>prezime;
    cout<<"Unesite poziciju radnika: ";
    cin>>pozicija;
    cout<<"Unesite JMBG radnika: ";
    cin>>jmbg;
    radnik noviRadnik(ime,prezime,pozicija,jmbg);
    listaRadnika.push_back(noviRadnik);
}
void urediRadnika(vector<radnik>& listaRadnika){
    string jmbg,novi,ime,prezime,pozicija;
    cout<<"Unesite JMBG radnika kojeg zelite promijeniti: ";
    cin>>jmbg;
    int izmjena;
    unsigned int vSize;
    vSize=listaRadnika.size();
        for(unsigned int i=0; i<vSize; i++){
            if (listaRadnika[i].getJMBG() == jmbg){
                cout<<"Sta zelite izmjeniti?"<<endl;
                cout<<"________________________________________"<<endl;
                cout<<endl;
                cout<<"1.JMBG\t 2.Ime radnika"<<endl;
                cout<<"3.Prezime radnika\t 4.Poziciju radnika";
                cout<<"________________________________________"<<endl;
                cout<<endl;
                cin>>izmjena;
                if (izmjena==1){
                    cout<<"Unesite novi JMBG: "<<endl;
                    cin>>novi;
                    listaRadnika[i].promjeniMaticni(novi);
                }
                else if(izmjena==2){
                    cout<<"Unesite novo ime: ";
                    cin>>ime;
                    listaRadnika[i].promjeniIme(ime);
                }
                else if(izmjena==3){
                    cout<<"Unesite novo prezime: ";
                    cin>>prezime;
                    listaRadnika[i].promjeniPrezime(prezime);
                }
                else if(izmjena==3){
                    cout<<"Unesite novu poziciju: ";
                    cin>>pozicija;
                    listaRadnika[i].promjeniPoziciju(pozicija);
                }

                }
                else
                    cout<<"Radnik nije pronadjen!"<<endl;
        }
}
void ispisRadnika(vector<radnik>& listaRadnika){
    unsigned int vSize;
    vSize=listaRadnika.size();
    for(unsigned int i=0; i<vSize; i++){
    cout<<"________________________________________"<<endl;
    cout<<endl;
    cout<<"Ime i prezime radnika: "<<listaRadnika[i].getime()<<" "<<listaRadnika[i].getPrezime()<<endl;
    cout<<"JMBG: "<<listaRadnika[i].getJMBG()<<endl;
    cout<<"Pozicija radnika: "<<listaRadnika[i].getPozicija()<<endl;
    cout<<"________________________________________"<<endl;
    cout<<endl;

        }
         getch();
}

void dodajRezervaciju(vector<rezervacije>& listaRezervacija, vector<gosti>& listaGostiju, vector<Sobe>& listaSoba){
    string brojSobe,datumPocetka,datumKraja,dodatneUsluge,gIme,gPrezime;
    int odabir,drugi;
    odabir=2;
    drugi=2;
    unsigned int vGosti,vSobe;
    vGosti=listaGostiju.size();
    vSobe=listaSoba.size();
    cout<<"Unesite broj sobe za rezervaciju: ";
        while(odabir==2){
    cin>>brojSobe;
        for(unsigned int i=0; i<vSobe; i++){
        if(listaSoba[i].getBroj() == brojSobe)
            odabir--;
        if(listaSoba[i].getStatus()== "s")
            odabir--;
        else
            cout<<"Soba nije dostupna, pokusajte drugu sobu"<<endl;
        listaSoba[i].promjeniStatus("r");
            }

            }
        cout<<"Unesite ime i prezime gosta: ";
        while(drugi==2){
            cin>>gIme;
            cin>>gPrezime;
        for(unsigned int n=0; n<vGosti; n++){
            if(listaGostiju[n].getIme() == gIme)
                drugi--;
            if(listaGostiju[n].getPrezime()== gPrezime)
                drugi--;
            else
                cout<<"Odabrani gost nije na spisku"<<endl;
        }
        }
       cin.get();
    cout<<"Unesite datum pocetka: ";
    getline(cin,datumPocetka);
    cout<<"Unesite datum kraja: ";
    getline(cin,datumKraja);
    cout<<"Unesite odabrane dodatne usluge: ";
   getline(cin,dodatneUsluge);
   rezervacije novaRezervacija(brojSobe,datumPocetka,datumKraja,dodatneUsluge,gIme,gPrezime);
   listaRezervacija.push_back(novaRezervacija);
}
void izbrisiRezervaciju(vector<rezervacije>& listaRezervacija, vector<Sobe>& listaSoba){
  unsigned int vSobe,vRezervacije;
  string brBrisanje;
    vSobe=listaSoba.size();
    vRezervacije=listaRezervacija.size();
    cout<<"Unesite broj sobe koju zelite izbrisati: ";
    cin>>brBrisanje;
        for(unsigned int i=0; i<vSobe; i++){
            if (listaSoba[i].getBroj() == brBrisanje){
                listaSoba[i].promjeniStatus("s");
            }
            else
                cout<<"Broj sobe nije pronadjen!"<<endl;
                }

        for(unsigned int i=0; i<vRezervacije; i++){
            if(listaRezervacija[i].getBr()==brBrisanje)
                listaRezervacija.erase(listaRezervacija.begin()+i);
            else
                cout<<"Rezervacija ne postoji"<<endl;
        }
}

void ispisRezervacija(vector<rezervacije>& listaRezervacija){
        unsigned int vSize;
    vSize=listaRezervacija.size();
    for(unsigned int i=0; i<vSize; i++){
        cout<<"________________________________________"<<endl;
        cout<<endl;
        cout<<"Broj sobe: "<<listaRezervacija[i].getBr()<<endl;
        cout<<"Trajanje od "<<listaRezervacija[i].datPocetka()<< " do "<< listaRezervacija[i].datKraja()<<endl;
        cout<<"Gost: "<<listaRezervacija[i].getIme()<<" "<< listaRezervacija[i].getPrezime()<<endl;
        cout<<"Paket koristenja: "<<listaRezervacija[i].getUsluge()<<endl;
        cout<<"________________________________________"<<endl;
        cout<<endl;
    }

}

void meniSobe(vector<Sobe>&  listaSoba){
    int odabir,stop;
    stop=0;
    while(stop==0){
            system("cls");
    cout<<"________________________________________"<<endl;
    cout<<endl;
    cout<<"1.Kreiraj sobu"<<endl<<"2.Lista soba"<<endl<<"3.Uredi sobu"<<endl<<"4.Izbrisi sobu"<<endl<<"5.Nazad"<<endl;
    cout<<"________________________________________"<<endl;
    cout<<endl;
    cin>>odabir;
    if(odabir==1)
        kreirajSobu(listaSoba);
    else if(odabir==2)
        printajSobu(listaSoba);
    else if(odabir==3)
        urediSobu(listaSoba);
    else if(odabir==4)
        izbrisiSobu(listaSoba);
    else if(odabir==5)
        stop++;
    }
}
void meniGosti(vector<gosti>& listaGostiju, vector<Sobe>& listaSoba){
        int odabir,stop;
    stop=0;
    while(stop==0){
             system("cls");
    cout<<"________________________________________"<<endl;
    cout<<endl;
    cout<<"1.Dodaj gosta"<<endl<<"2.Lista gostiju"<<endl<<"3.Izbrisi gosta"<<endl<<"4.Nazad"<<endl;
    cout<<"________________________________________"<<endl;
    cout<<endl;
    cin>>odabir;
    if(odabir==1)
        dodajGosta(listaGostiju,listaSoba);
    else if(odabir==2)
        printajGoste(listaGostiju);
    else if(odabir==3)
        izbrisiGosta(listaGostiju,listaSoba);
    else if(odabir==4)
        stop++;
    }
}
void meniRadnik(vector<radnik>& listaRadnika){
    int odabir,stop;
    stop=0;
    while(stop==0){
             system("cls");
    cout<<"________________________________________"<<endl;
    cout<<endl;
    cout<<"1.Dodaj radnika"<<endl<<"2.Lista radnika"<<endl<<"3.Izbrisi radnika"<<endl<<"4.Nazad"<<endl;
    cout<<"________________________________________"<<endl;
    cout<<endl;
    cin>>odabir;
    if(odabir==1)
        dodajRadnika(listaRadnika);
    else if(odabir==2)
        ispisRadnika(listaRadnika);
    else if(odabir==3)
        urediRadnika(listaRadnika);
    else if (odabir==4)
        stop++;
}}
void meniRezervacije(vector<rezervacije>& listaRezervacija, vector<gosti>& listaGostiju, vector<Sobe>& listaSoba){
    int odabir,stop;
    stop=0;
    while(stop==0){
             system("cls");
    cout<<"________________________________________"<<endl;
    cout<<endl;
    cout<<"1.Dodaj rezervaciju"<<endl<<"2.Lista rezervacija"<<endl<<"3.Izbrisi Rezervaciju"<<endl<<"4.Nazad"<<endl;
    cout<<"________________________________________"<<endl;
    cout<<endl;
    cin>>odabir;
    if(odabir==1)
        dodajRezervaciju(listaRezervacija,listaGostiju,listaSoba);
    else if(odabir==2)
        ispisRezervacija(listaRezervacija);
    else if(odabir==3)
        izbrisiRezervaciju(listaRezervacija,listaSoba);
    else if(odabir==4)
        stop++;
}
}

