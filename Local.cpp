#include "Local.h"
#include "Bien.h"

Local::Local(int _prix, Adresse _adresse, int _m2, int _ref_client, int _ref_catalogue,int _taille_vitrine, bool _espace_stockage):Bien(_prix, _adresse, _m2, _ref_client, _ref_catalogue){
  taille_vitrine=_taille_vitrine;
  espace_stockage=_espace_stockage;
}
int Local::get_taille_vitrine(){
  return taille_vitrine;
}
bool Local::get_espace_stockage(){
  return espace_stockage;
}
