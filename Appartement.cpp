#include "Appartement.h"
#include "Adresse.h"
#include "Bien.h"

Appartement::Appartement(int _prix, Adresse _adresse, int _m2, int _ref_client, int _ref_catalogue,int _pieces,int _etage,bool _garage,bool _cave,bool _balcon,int _nb_appart):Bien(_prix,_adresse,_m2,_ref_client,_ref_catalogue){
  pieces=_pieces;
  etage=_etage;
  garage=_garage;
  cave=_cave;
  balcon=_balcon;
  nb_appart=_nb_appart;
}
int Appartement::get_pieces(){
  return pieces;
}
int Appartement::get_etages(){
  return etages;
}
bool Appartement::get_garage(){
  return garage;
}
bool Appartement::get_cave(){
  return cave;
}
bool Appartement::get_balcon(){
  return balcon;
}
int Appartement::get_nb_appart(){
  return nb_appart;
}
