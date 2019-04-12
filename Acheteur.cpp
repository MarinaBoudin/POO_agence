#include <iostream>
#include "Acheteur.h"

using namespace std;

Acheteur::Acheteur(string nom) : Client(nom) {}

Acheteur::~Acheteur() {}

string Acheteur::getnom() { return nom; }

void Acheteur::show() {
    cout << "L'acheteur " << nom << " habite au " << endl;
    adresse.show();
}