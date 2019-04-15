#include <iostream>
#include "Vendeur.h"

using namespace std;

Vendeur::Vendeur(string nom, int id) : Client(nom, id) {}

Vendeur::~Vendeur() {}

string Vendeur::getnom() { return nom; }

void Vendeur::show() {
    cout << "Le vendeur " << nom << " habite au " << endl;
    adresse.show();
}