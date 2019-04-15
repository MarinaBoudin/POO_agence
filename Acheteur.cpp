#include <iostream>
#include "Acheteur.h"
#include <map>

using namespace std;

Acheteur::Acheteur(string nom) : Client(nom) {}

Acheteur::~Acheteur() {}

string Acheteur::getnom() { return nom; }

void Acheteur::show() {
    cout << "L'acheteur " << nom << " habite au " << endl;
    for (const auto &[k, v] : visites){
        std::cout << "bien:[" << k << "] = (" << v.first << ", " << v.second << ") " << std::endl;
    }
    adresse.show();
}


void Acheteur::Avisiter(string nomBien,int prop= 0, int montant=0){
    visites[nomBien]["Proposition"]=prop;
    visites[nomBien]["Montant"]=montant;


}

bool Acheteur::operator<(const Acheteur &other) {
    return false;
}
