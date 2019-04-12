#include "Maison.h"
#include "Bien.h"

Maison::Maison(int _prix, Adresse _adresse, int _m2, int _ref_client, int _ref_catalogue,int _piece, bool _garage, bool _jardin, bool _piscine):Bien(_prix, _adresse, _m2, _ref_client, _ref_catalogue){
  piece=_piece;
  garage=_garage;
  jardin=_jardin;
  piscine=_piscine;
}
int Maison::get_piece(){
  return piece;
}
bool Maison::get_garage(){
  return garage;
}
bool Maison::get_jardin(){
  return jardin;
}
bool Maison::get_piscine(){
  return piscine;
}
