#include "Local.h"
#include "Adresse.h"
#include "Bien.h"
#include <iostream>
using namespace std;

Local::Local(int _prix, int _m2, int _ref_client,float _taille_vitrine, bool _espace_stockage):Bien(_prix, _m2, _ref_client){
  taille_vitrine=_taille_vitrine;
  espace_stockage=_espace_stockage;
}

Local::Local(Adresse _adresse, int _prix, int _m2, int _ref_client, float _taille_vitrine, bool _espace_stockage) : Bien(_adresse, _prix, _m2,_ref_client) {
    taille_vitrine = _taille_vitrine;
    espace_stockage = _espace_stockage;
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

void Local::recherche(){
  cout << "TAILLE VITRINE -> Entrez la surface de la vitrine en m2 :" << endl;
  float choixvitrine;
  cin >> choixvitrine;
  cout << "ESPACE DE STOCKAGE -> Oui(1) ou Non(2)" << endl;
  int choixstockage;
  cin >> choixstockage;
  cout << " Ci-dessous, la liste des biens correspondant à votre recherche :\n" << endl;
  if ((taille_vitrine <= choixvitrine) || (choixvitrine==0)){
    if ((choixstockage==0) || ((choixstockage==1) && (espace_stockage==true))) {
      cout << "### 1. ###\n" << endl;
      affiche();
      cout << "\n" << endl;
    }
  }
}
