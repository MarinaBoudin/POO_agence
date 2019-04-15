#include "Bien.h"
#include "Adresse.h"
#include <string>
#include <iostream>

using namespace std;

<<<<<<< HEAD
Bien::Bien(int _prix, int _m2, int _ref_client, int _ref_catalogue){
  prix=_prix;
  m2=_m2;
  ref_client=_ref_client;
  ref_catalogue=_ref_catalogue;
=======
Bien::Bien(int _prix, Adresse _adresse, int _m2, int _ref_client, int _ref_catalogue) {
    prix = _prix;
    adresse = _adresse;
    m2 = _m2;
    ref_client = _ref_client;
    ref_catalogue = _ref_catalogue;
>>>>>>> 476bc1e02c9a16c713257f7f43fe8d51c747817c
}

int Bien::get_prix() {
    return prix;
}

Adresse Bien::get_adresse() {
    return adresse;
}

int Bien::get_m2() {
    return m2;
}

int Bien::get_ref_client() {
    return ref_client;
}

int Bien::get_ref_catalogue() {
    return ref_catalogue;
}
void Bien::affiche(){
  cout << "Prix : " << prix << endl;
  cout << "Adresse : " ;
  adresse.show() ;
  cout << "\n";
  cout << "Nombre de m² : " << m2 << endl;
  cout << "Référence client : " << ref_client << endl;
  cout << "Référence catalogue : " << ref_catalogue << endl;
}
