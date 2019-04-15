#include "Local.h"
#include "Adresse.h"
#include "Bien.h"
#include <iostream>
using namespace std;

<<<<<<< HEAD
Local::Local(int _prix, int _m2, int _ref_client, int _ref_catalogue,int _taille_vitrine, bool _espace_stockage):Bien(_prix, _m2, _ref_client, _ref_catalogue){
  taille_vitrine=_taille_vitrine;
  espace_stockage=_espace_stockage;
=======
Local::Local(int _prix, Adresse _adresse, int _m2, int _ref_client, int _ref_catalogue, int _taille_vitrine,
             bool _espace_stockage)
        : Bien(_prix, _adresse, _m2, _ref_client, _ref_catalogue) {
    taille_vitrine = _taille_vitrine;
    espace_stockage = _espace_stockage;
>>>>>>> 476bc1e02c9a16c713257f7f43fe8d51c747817c
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
