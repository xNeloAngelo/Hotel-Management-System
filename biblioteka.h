#ifndef BIBLIOTEKA_H_INCLUDED
#define BIBLIOTEKA_H_INCLUDED
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Sobe{
private:
 string brojSobe;
 string statusSobe;
 string karakteristike;
 char velicinaSobe;
public:
    void promijeniBroj(string noviBr);
    void promjeniStatus(string noviStatus);
    void promjeniKar(string noveKar);
    string getStatus();
    string getBroj();
    string getKar();
    char getVelicina();
    Sobe();
    Sobe(string, string, string, char);

};

class gosti{
private:
    string imeGosta;
    string prezimeGosta;
    string brSobe;
public:
    gosti();
    gosti(string, string, string);
    string getIme();
    string getPrezime();
    string getBroj();

};

class radnik{
private:
    string imeRadnika;
    string prezimeRadnika;
    string maticniBr;
    string pozicijaRadnika;
public:
    void promjeniIme(string novoIme);
    void promjeniPrezime(string novoPrezime);
    void promjeniMaticni(string noviMaticni);
    void promjeniPoziciju(string novaPozicija);
    string getime();
    string getPrezime();
    string getPozicija();
    string getJMBG();
    radnik();
    radnik(string, string, string, string);

};

class rezervacije{
private:
    string brojSobe;
    string datumPocetka;
    string datumKraja;
    string dodatneUsluge;
    string imeGosta;
    string prezimeGosta;
public:
    string getBr();
    string datPocetka();
    string datKraja();
    string getUsluge();
    string getIme();
    string getPrezime();
    rezervacije();
    rezervacije(string, string, string, string, string, string);
};

#endif // BIBLIOTEKA_H_INCLUDED
