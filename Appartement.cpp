#include "Appartement.h"
#include "Adresse.h"
#include "Bien.h"
#include <iostream>

<<<<<<< HEAD
Appartement::Appartement(int _prix, int _m2, int _ref_client, int _ref_catalogue,int _pieces,int _etage,bool _garage,bool _cave,bool _balcon,int _nb_appart):Bien(_prix,_m2,_ref_client,_ref_catalogue){
  pieces=_pieces;
  etage=_etage;
  garage=_garage;
  cave=_cave;
  balcon=_balcon;
  nb_appart=_nb_appart;
=======
using namespace std;

Appartement::Appartement(int _prix, Adresse _adresse, int _m2, int _ref_client, int _ref_catalogue, int _pieces,
                         int _etage, bool _garage,
                         bool _cave, bool _balcon, int _nb_appart) : Bien(_prix, _adresse, _m2, _ref_client,
                                                                          _ref_catalogue) {
    pieces = _pieces;
    etage = _etage;
    garage = _garage;
    cave = _cave;
    balcon = _balcon;
    nb_appart = _nb_appart;
}

int Appartement::get_pieces() {
    return pieces;
>>>>>>> 476bc1e02c9a16c713257f7f43fe8d51c747817c
}

int Appartement::get_etage() {
    return etage;
}

bool Appartement::get_garage() {
    return garage;
}

bool Appartement::get_cave() {
    return cave;
}

bool Appartement::get_balcon() {
    return balcon;
}

int Appartement::get_nb_appart() {
    return nb_appart;
}
void Appartement::affiche(){
  Bien::affiche();
  cout << "Nombre de pièces : " << pieces << endl;
  cout << "Etages où se trouve l'appartement : " << etage << endl;
  if (garage==true){
    cout << "Présence d'un garage." << endl;
  }
  if (cave==true){
    cout << "Présence d'une cave." << endl;
  }
  if (balcon==true){
    cout << "Présence d'un balcon." << endl;
  }
  cout << "Nombre d'appartement dans l'immeuble : " << nb_appart << endl;
}
