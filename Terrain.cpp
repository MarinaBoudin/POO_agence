#include "Terrain.h"
#include "Adresse.h"
#include "Bien.h"
#include <iostream>
using namespace std;

Terrain::Terrain(int _prix, int _m2, int _ref_client, int _ref_catalogue,bool _constructive):Bien(_prix, _m2, _ref_client, _ref_catalogue){
  constructive=_constructive;
}
bool Terrain::get_constructive(){
  return constructive;
}
void Terrain::affiche(){
  Bien::affiche();
  if (constructive==true){
    cout << "Constructible : Oui." <<endl;
  }
  else {
    cout << "Constructible : Non." << endl;
  }
}
