#include <iostream>
#include "Acheteur.h"
#include <map>

using namespace std;

Acheteur::Acheteur(string nom, int id) : Client(nom, id) {}

Acheteur::~Acheteur() {}

string Acheteur::getnom() { return nom; }

void Acheteur::show() {
    cout << "L'acheteur " << nom << " habite au " << endl;
    adresse.show();
}

void Acheteur::Avisiter(int ref_catalogue, int prop = 0, int montant = 0) {
    visites[ref_catalogue].first = prop;
    visites[ref_catalogue].second = montant;
}

bool Acheteur::operator<(const Acheteur &other) {
    return false;
}
