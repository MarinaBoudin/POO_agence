#include <iostream>
#include "Vendeur.h"
#include <vector>

using namespace std;

Vendeur::Vendeur(string nom) : Client(nom) {}

Vendeur::Vendeur(std::string nom, Adresse _adresse) : Client(nom, _adresse) {}

Vendeur::~Vendeur() {}

string Vendeur::getnom() { return nom; }

void Vendeur::show() {
    cout << "Le vendeur " << nom << " habite au " << endl;
    adresse.show();
    cout << " Id : " << ref_client << endl;
}

void Vendeur::ajouter_vente(Bien *b) {
    listBiens.push_back(b);
}

void Vendeur::retirer_vente(Bien *b) {
    for (int k = 0; k < listBiens.size(); k++) {
        if (listBiens[k] == b) {
            listBiens.erase(listBiens.begin() + k);
        }
    }
}
