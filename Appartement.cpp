#include "Appartement.h"
#include "Adresse.h"
#include "Bien.h"
#include "Acheteur.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;

Appartement::Appartement(int _prix, int _m2, int _ref_client,int _pieces,int _etage,bool _garage,bool _cave,bool _balcon,int _nb_appart):Bien(_prix,_m2,_ref_client){
  pieces=_pieces;
  etage=_etage;
  garage=_garage;
  cave=_cave;
  balcon=_balcon;
  nb_appart=_nb_appart;
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


void Appartement::recherche_appart(){
  cout << "PIECES -> Entrez le nombre de pièces minimales :" << endl;
  int choixpieces;
  cin >> choixpieces;
  cout << "BALCON -> Oui(2) ou Non(1)" << endl;
  int choixbalcon;
  cin >> choixbalcon;
  // map<Bien,vector<Acheteur>>::iterator im;
  // for (im=dico_biens["Appartement"].begin();im!=dico_biens["Appartement"].end();im++){
  //   Bien biencible = im->first;
  if ((pieces <= choixpieces) || (choixpieces==0)){
    if ((choixbalcon==0) || ((choixbalcon==2) && (balcon==true))){
      affiche();
    }
  }
}
