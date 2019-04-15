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

void Agence::ajout_bien(string a, Bien b){
  dico_biens[a][b];
}

// void Agence::recherche_biens(){
//   cout << "Recherchez vous un appartement(1), une maison(2), un local (3) ou un terrain(4) ?";
//   cin >> int type;
//   switch(type){
//     case 1:
//       string type = "Appartement";
//       break;
//     case 2:
//       string type = "Maison";
//       break;
//     case 3:
//       string type = "Local";
//       break;
//     case 4:
//       string type = "Terrain";
//       break;
//     default :
//       cout << "Choix non reconnu." << endl;
//       break;
//   }
//   cout << "Choix de filtres de recherche. Tappez sur ENTREE si vous ne désirez pas filtrer suivant le paramètre demandé -> " << endl;
//   cout << "PRIX -> Entrez le prix maximal du bien que vous désirez acheter :" << endl;
//   cin >> int prix;
//   cout << "SURFACE -> Entrez la surface minimale en m2 :" << endl;
//   cin >> int m2;
//   // map<string, map<Bien,vector<Acheteur>>> mapp=test.get_dico_biens();
//   map<Bien,vector<Acheteur>>::iterator im;
//   for (im=dico_biens[type].begin();im!=dico_biens[type].end();im++){
//     // int biencible = it->first;
//     if ((it->first.get_prix() <= prix) && (it->first.get_m2() <= m2)){
//       it->first.affichage_biens();
//     }
//   }
// }
