#include <iostream>
#include "Acheteur.h"
#include <map>

using namespace std;

Acheteur::Acheteur(string nom) : Client(nom) {}

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

void Acheteur::retirerVisite(int ref_catalogue) {
    //Retirer une visite si elle a été faite mais que le bien est vendu
}

bool Acheteur::operator<(const Acheteur &other) {
    return false;
}
