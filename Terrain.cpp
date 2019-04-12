#include "Terrain.h"
#include "Adresse.h"
#include "Bien.h"

Terrain::Terrain(int _prix, Adresse _adresse, int _m2, int _ref_client, int _ref_catalogue,bool _constructive):Bien(_prix, _adresse, _m2, _ref_client, _ref_catalogue){
  constructive=_constructive;
}
bool Terrain::get_constructive(){
  return constructive;
}
