#include "Terrain.h"
#include "Adresse.h"
#include "Bien.h"
#include <iostream>
using namespace std;

Terrain::Terrain(int _prix, int _m2, int _ref_client,bool _constructible):Bien(_prix, _m2, _ref_client){
  constructible=_constructible;
}

Terrain::Terrain(Adresse _adresse, int _prix, int _m2, int _ref_client, bool _constructible) : Bien(_adresse, _prix,
                                                                                                    _m2, _ref_client) {
    constructible = _constructible;
}

bool Terrain::get_constructible(){
  return constructible;
}
void Terrain::affiche(){
  Bien::affiche();
  if (constructible==true){
    cout << "Constructible : Oui." <<endl;
  }
  else {
    cout << "Constructible : Non." << endl;
  }
}

void Terrain::recherche(){
  cout << "CONSTRUCTIBLE -> Oui(1) ou Non(2)" << endl;
  int choixconstru;
  cin >> choixconstru;
  cout << " Ci-dessous, la liste des biens correspondant à votre recherche :\n" << endl;
  if ((choixconstru==0) || ((choixconstru==1) && (constructible==true))) {
    cout << "### 1. ###\n" << endl;
    affiche();
    cout << "\n" << endl;
  }
}
