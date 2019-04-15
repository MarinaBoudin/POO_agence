#include "Bien.h"
#include "Adresse.h"
#include <string>
#include <iostream>

using namespace std;

Bien::Bien(int _prix, int _m2, int _ref_client, int _ref_catalogue){
  prix=_prix;
  m2=_m2;
  ref_client=_ref_client;
  ref_catalogue=_ref_catalogue;
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
