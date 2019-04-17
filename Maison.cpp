#include "Maison.h"
#include "Adresse.h"
#include "Bien.h"
#include <iostream>
using namespace std;

Maison::Maison(int _prix, int _m2, int _ref_client,int _piece, bool _garage, bool _jardin, bool _piscine):Bien(_prix, _m2, _ref_client){
  piece=_piece;
  garage=_garage;
  jardin=_jardin;
  piscine=_piscine;
}

Maison::Maison(Adresse _adresse, int _prix, int _m2, int _ref_client, int _piece, bool _garage, bool _jardin,bool _piscine) : Bien(_adresse, _prix,_m2,_ref_client) {
    piece = _piece;
    garage = _garage;
    jardin = _jardin;
    piscine = _piscine;
}

int Maison::get_piece() {
    return piece;
}

bool Maison::get_garage() {
    return garage;
}

bool Maison::get_jardin() {
    return jardin;
}

bool Maison::get_piscine() {
    return piscine;
}
void Maison::affiche(){
  Bien::affiche();
  cout << "Nombre de pièces : " << piece <<endl;
  if (garage==true){
    cout << "Présence d'un garage." << endl;
  }
  if (jardin==true){
    cout << "Présence d'un jardin." << endl;
  }
  if (piscine==true){
    cout << "Présence d'une piscine." << endl;
  }
}

void Maison::recherche(){
  cout << "PIECES -> Entrez le nombre de pièces minimales :" << endl;
  int choixpieces;
  cin >> choixpieces;
  cout << "GARAGE -> Oui(1) ou Non(2)" << endl;
  int choixgarage;
  cin >> choixgarage;
  cout << "PISCINE -> Oui(1) ou Non(2)" << endl;
  int choixpiscine;
  cin >> choixpiscine;
  cout << "JARDIN -> Oui(1) ou Non(2)" << endl;
  int choixjardin;
  cin >> choixjardin;
  cout << " Ci-dessous, la liste des biens correspondant à votre recherche :\n" << endl;
  if ((piece <= choixpieces) || (choixpieces==0)){
    if (((choixgarage==0) || ((choixgarage==1) && (garage==true))) && ((choixpiscine==0) || ((choixpiscine==1) && (piscine==true))) && ((choixjardin==0) || ((choixjardin==1) && (jardin==true)))){
      cout << "### 1. ###\n" << endl;
      affiche();
      cout << "\n" << endl;
    }
  }
}
