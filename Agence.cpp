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

map<string, map<Bien, vector<Acheteur>>> Agence::get_dico_biens() {
    return dico_biens;
}

vector<Acheteur> const& Agence::get_acheteurs() const {
  return acheteurs;
}

vector<Vendeur> Agence::get_vendeurs() {
  return vendeurs;
}

void Agence::ajout_acheteur(Acheteur& a){
  acheteurs.push_back(a);
  int taille_a = acheteurs.size();
    cout << taille_a << endl;
    for (int k =0;k<taille_a;k++){
      acheteurs[k].show();
    }
}

void Agence::ajout_vendeur(Vendeur v){
  vendeurs.push_back(v);
}

void Agence::ajout_bien(string a, Bien b){
  dico_biens[a][b];
  int ref = b.get_ref_catalogue();
  cout << "La ref cata est "<<ref<<endl;
}

void Agence::recherche_biens(){
  cout << "Recherchez vous un appartement(1), une maison(2), un local (3) ou un terrain(4) ?";
  int nb;
  cin >> nb;
  string type;
  cout << "Choix de filtres de recherche. Tappez 0 si vous ne désirez pas filtrer suivant le paramètre demandé -> " << endl;
  cout << "PRIX -> Entrez le prix maximal du bien que vous désirez acheter :" << endl;
  int choixprix;
  cin >> choixprix;
  cout << "SURFACE -> Entrez la surface minimale en m2 :" << endl;
  int choixm2;
  cin >> choixm2;
  vector<Bien> vectorfiltre;
  map<Bien,vector<Acheteur>>::iterator im;
  for (im=dico_biens[type].begin();im!=dico_biens[type].end();im++){
    Bien biencible = im->first;
    if (((biencible.get_prix() <= choixprix) || (choixprix==0)) && ((biencible.get_m2() <= choixm2) || (choixm2==0))){
      vectorfiltre.push_back(biencible);
    }
  }
  switch(nb){
    case 1:
      type = "Appartement";
      for (int i=0; i<vectorfiltre.size();i++){
        Bien a = vectorfiltre[i];
        a.recherche_appart();
      }
      break;
    case 2:
      type = "Maison";
      // recherche_maison();
      break;
    case 3:
      type = "Local";
      // recherche_local();
      break;
    case 4:
      type = "Terrain";
      // recherche_terrain();
      break;
    default :
      cout << "Choix non reconnu." << endl;
      break;
  }
}
