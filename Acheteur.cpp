#include <iostream>
#include "Acheteur.h"
#include <map>

using namespace std;

Acheteur::Acheteur():Client(){}

Acheteur::Acheteur(string nom) : Client(nom) {}

Acheteur::Acheteur(std::string nom, Adresse _adresse) : Client(nom, _adresse) {}

Acheteur::~Acheteur() {}

string Acheteur::getnom() { return nom; }

void Acheteur::show() {
    cout << "L'acheteur " << nom << " habite au " << endl;
    adresse.show();
    cout << " Id : " << ref_client << endl;
}

map<int, pair<int, int>> Acheteur::get_visites(){
  return visites;
}

void Acheteur::Avisiter(int ref_catalogue, int prop = 0, int montant = 0) {
    visites[ref_catalogue].first = prop;
    visites[ref_catalogue].second = montant;
}

bool Acheteur::operator<(const Acheteur &other) {
    return false;
}

void Acheteur::affiche_visites(int ref){
  cout << "L'acheteur " << id_client << " a visité le bien " << ref << "." << endl;
  int proposition = visites[ref].first;
  if (proposition==1){
    int prix = visites[ref].second;
    cout << "Une proposition d'achat a été faite pour ce prix. Montant : " << prix << "." << endl;
  }
  else {
    cout << " Aucune proposition n'a été faite pour ce bien." << endl;
  }
}
