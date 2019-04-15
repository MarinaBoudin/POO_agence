#include "Local.h"
#include "Adresse.h"
#include "Bien.h"
#include <iostream>
using namespace std;

Local::Local(int _prix, int _m2, int _ref_client,int _taille_vitrine, bool _espace_stockage):Bien(_prix, _m2, _ref_client){
  taille_vitrine=_taille_vitrine;
  espace_stockage=_espace_stockage;
}

int Local::get_taille_vitrine() {
    return taille_vitrine;
}

bool Local::get_espace_stockage() {
    return espace_stockage;
}
void Local::affiche(){
  Bien::affiche();
  cout << "Taille de la vitrine : " << taille_vitrine << endl;
  if (espace_stockage==true){
    cout << "Présence d'un espace de stockage." <<endl;
  }
}
