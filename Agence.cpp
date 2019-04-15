#include "Agence.h"

#include "Bien.h"
#include "Appartement.h"
#include "Maison.h"
#include "Local.h"
#include "Terrain.h"
#include "Client.h"
#include "Acheteur.h"
#include "Vendeur.h"

#include <map>
#include <vector>

using namespace std;

Agence::Agence(){
  // Bien test = Bien(2,1,65,98);
  // Acheteur lol = Acheteur("bob");
  // map<Bien,vector<Acheteur>> a;
  // vector<Acheteur> poo;
  // poo.push_back(lol);
  // a[test]=poo;
  dico_biens["Appartement"];
  dico_biens["Maison"];
  dico_biens["Local"];
  dico_biens["Terrain"];
}

map<string, map<Bien, vector<Acheteur*>>> Agence::get_dico_biens() {
    return dico_biens;
}

vector<Acheteur> Agence::get_acheteurs(){
  return acheteurs;
}

vector<Vendeur> Agence::get_vendeurs(){
  return vendeurs;
}

void Agence::ajout_acheteur(Acheteur a){
  acheteurs.push_back(a);
}

void Agence::ajout_vendeur(Vendeur v){
  vendeurs.push_back(v);
}
