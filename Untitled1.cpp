#include "biblioteka.h"
#include <string.h>
Sobe::Sobe(){
brojSobe="";
statusSobe="";
karakteristike="";
}
Sobe::Sobe(string a, string b, string c, char d){
    brojSobe=a;
    statusSobe=b;
    karakteristike=c;
    velicinaSobe=d;
}

string Sobe::getBroj(){
    return brojSobe;
}
string Sobe::getStatus(){
    return statusSobe;
}
    void Sobe::promijeniBroj(string noviBr){
    Sobe::brojSobe=noviBr;
    }
    void Sobe::promjeniStatus(string noviStatus){
        Sobe::statusSobe=noviStatus;
    }
    void Sobe::promjeniKar(string noveKar){
        Sobe::karakteristike=noveKar;
    }
    string Sobe::getKar(){
        return karakteristike;
    }
    char Sobe::getVelicina(){
        return velicinaSobe;
    }
gosti::gosti(){
    imeGosta="";
    brSobe="";
    prezimeGosta="";

}
gosti::gosti(string ime, string prezime, string brojSobe){
    imeGosta=ime;
    brSobe=brojSobe;
    prezimeGosta=prezime;
}
string gosti::getIme(){
    return imeGosta;
}
string gosti::getPrezime(){
    return prezimeGosta;
}
string gosti::getBroj(){
    return brSobe;
}

radnik::radnik(){
    imeRadnika="";
    prezimeRadnika="";
    pozicijaRadnika="";
    maticniBr="";
}
radnik::radnik(string ime, string prezime, string pozicija, string jmbg){
    imeRadnika=ime;
    prezimeRadnika=prezime;
    pozicijaRadnika=pozicija;
    maticniBr=jmbg;
}
void radnik::promjeniIme(string novoIme){
    radnik::imeRadnika=novoIme;
}

    void radnik::promjeniPrezime(string novoPrezime){
        radnik::prezimeRadnika=novoPrezime;
    }
    void radnik::promjeniMaticni(string noviMaticni){
        radnik::maticniBr=noviMaticni;
    }
    void radnik::promjeniPoziciju(string novaPozicija){
        radnik::pozicijaRadnika==novaPozicija;
    }
string radnik::getime(){
    return imeRadnika;
}
string radnik::getPrezime(){
    return prezimeRadnika;
}
string radnik::getJMBG(){
    return maticniBr;
}
string radnik::getPozicija(){
    return pozicijaRadnika;
}
rezervacije::rezervacije(string broj, string pocetak, string kraj, string usluge, string ime, string prezime){
    brojSobe=broj;
    datumPocetka=pocetak;
    datumKraja=kraj;
    dodatneUsluge=usluge;
    imeGosta=ime;
    prezimeGosta=prezime;
}
    string rezervacije::getBr(){
        return brojSobe;
    }
    string rezervacije::datPocetka(){
        return datumPocetka;
    }
    string rezervacije::datKraja(){
        return datumKraja;
    }
    string rezervacije::getUsluge(){
        return dodatneUsluge;
    }
    string rezervacije::getIme(){
        return imeGosta;
    }
    string rezervacije::getPrezime(){
        return prezimeGosta;
    }
