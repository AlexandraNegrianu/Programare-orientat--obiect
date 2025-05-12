#include <iostream>
#include <cstring>
#include "Number.h"
using namespace std;

Number::Number(const char* value, int base)
{
    strcpy(numar, value);
    baza = base;
    lungime = strlen(value);
}

void Number::Print() {
    cout << "Scrierea in baza " << baza << " a numarului este " << numar << endl;
}

void Number::Print1() {
	cout << "Numarul este: " << numar << endl;
}

int Number::GetBase10Value() const // Funcția convertește numărul din baza curentă în baza 10
{
    int rez = 0, putere = 1;
    int i;

    for (i = lungime - 1; i >= 0; i--)
    {
        if (numar[i] >= '0' && numar[i] <= '9') { // Dacă numărul este într-o bază mai mică decât 10
            rez = rez + (numar[i] - '0') * putere; // Adunăm la rezultat valoarea cifrei înmulțită cu puterea bazei

        }
        else // Dacă numărul este într-o bază mai mare decât 10
        {
            rez = rez + (numar[i] - 'A' + 10) * putere; // A = 11, B = 12, C = 13, D = 14, E = 15, F = 16 -> pentru baza 16 :)
        }
        putere = putere * baza; // Creștem puterea bazei (ex: 2^0, 2^1, 2^2, ...)
    }
    return rez;
}

void Number::SwitchBase(int newBase) {

    int val = GetBase10Value();
    int rest = 0, contor = 0;
    char rez[100];

    while (val) {
        rest = val % newBase; // Obținem restul împărțirii la noua bază
        val = val / newBase; // Obținem valoarea împărțită la noua bază, pentru a continua conversia 
        if (rest <= 9) rez[contor] = (char)rest + '0';
        else rez[contor] = (char)rest + 'A'; // Dacă restul este mai mare decât 9, adăugăm litera corespunzătoare
        contor++;
    }
    rez[contor] = '\0'; // Adăugăm NULL la finalul șirului
    _strrev(rez); // Inversăm șirul pentru a obține numărul corect
    strcpy(numar, rez);
    baza = newBase;
}

int Number::GetDigitsCount() const{
    return lungime;
}

int Number::GetBase() const{
    return baza;
}

/// OPERATORI

bool Number::operator<(Number& num) {
    return GetBase10Value() < num.GetBase10Value();
}

bool Number::operator>(Number& num) {
    return GetBase10Value() > num.GetBase10Value();
}

bool Number::operator<=(Number& num) {
    return GetBase10Value() <= num.GetBase10Value();
}

bool Number::operator>=(Number& num) {
    return GetBase10Value() >= num.GetBase10Value();
}

bool Number::operator==(Number& num) {
    return GetBase10Value() == num.GetBase10Value();
}

Number operator+(const Number& num1, const Number& num2) {
    int suma = num1.GetBase10Value() + num2.GetBase10Value();
    char rezultat[100];
    int contor = 0, bazamaxima;

    if (num1.GetBase() > num2.GetBase()) bazamaxima = num1.GetBase();
    else bazamaxima = num2.GetBase();

    while (suma) {
        int rest = suma % bazamaxima;
        suma = suma / bazamaxima;
        if (rest < 9) rezultat[contor] = (char)rest + '0';
        else rezultat[contor] = (char)rest + 'A';
        contor++;
    }
    rezultat[contor] = '\0';
    _strrev(rezultat);
    return Number(rezultat, bazamaxima);
}

Number operator-(const Number& num1, const Number& num2){
    int dif = num1.GetBase10Value() - num2.GetBase10Value();
    char rezultat[100];
    int contor = 0, bazamaxima = 0;

    if (num1.GetBase() > num2.GetBase()) bazamaxima = num1.GetBase();
    else bazamaxima = num2.GetBase();

    while (dif) {
        int rest = dif % bazamaxima;
        dif = dif / bazamaxima;
        if (rest < 9) rezultat[contor] = (char)rest + '0';
        else rezultat[contor] = (char)rest + 'A';
        contor++;
    }
    rezultat[contor] = '\0';
    _strrev(rezultat);
    return Number(rezultat, bazamaxima);
}

Number& Number::operator--() // Prefix și returnează o referință la obiectul dat
{
    strcpy(numar, numar + 1);
    lungime = strlen(numar); // Actualizăm lungimea după modificare 
    return *this; // *this este obiectul curent, iar funcția returnează o copie a acestuia
}
 
Number Number::operator--(int) // Sufix. (int) este un parametru fictiv pentru a face diferența între sufix și prefix. Returnează o copie a obiectului dat
{
    numar[strlen(numar) - 1] = '\0';
    lungime = strlen(numar); 
    return *this;
}


Number::~Number()
{
    numar[0] = NULL;
}
