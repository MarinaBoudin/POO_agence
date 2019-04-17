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
  // map<Appartement*, vector<Acheteur>> a;
  // // map<Maison, vector<Acheteur>> b;
  // // map<Local, vector<Acheteur>> c;
  // // map<Terrain, vector<Acheteur>> d;
  dico_biens["Appartement"];
  dico_biens["Maison"];
  dico_biens["Local"];
  dico_biens["Terrain"];
}

map<string, map<Bien*, vector<Acheteur>>> Agence::get_dico_biens() {
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
  // int taille_a = acheteurs.size();
  //   cout << taille_a << endl;
  //   for (int k =0;k<taille_a;k++){
  //     acheteurs[k].show();
  //   }
}

void Agence::ajout_vendeur(Vendeur& v){
  vendeurs.push_back(v);
}

void Agence::ajout_bien(string a, Bien* b){
  dico_biens[a][b];
  b->affiche();
  int ref = b->get_ref_catalogue();
  cout << "La ref catalogue est "<<ref<<endl;
}

void Agence::recherche_biens(){
  cout << "Recherchez vous un appartement(1), une maison(2), un local (3) ou un terrain(4) ?";
  int nb;
  cin >> nb;
  cout << "Choix de filtres de recherche. Tappez 0 si vous ne désirez pas filtrer suivant le paramètre demandé -> " << endl;
  cout << "PRIX -> Entrez le prix maximal du bien que vous désirez acheter :" << endl;
  int choixprix;
  cin >> choixprix;
  cout << "SURFACE -> Entrez la surface minimale en m2 :" << endl;
  int choixm2;
  cin >> choixm2;
  string type;
  if (nb==1){type="Appartement";}
  else if (nb==2){type="Maison";}
  else if (nb==3){type="Local";}
  else if (nb==4){type="Terrain";}
  else {cout << "Choix non reconnu." << endl;}
  vector<Bien*> vectorfiltre;
  map<Bien*,vector<Acheteur>>::iterator im;
  for (im=dico_biens[type].begin();im!=dico_biens[type].end();im++){
    Bien* biencible = im->first;
    if (((biencible->get_prix() <= choixprix) || (choixprix==0)) && ((biencible->get_m2() <= choixm2) || (choixm2==0))){
      vectorfiltre.push_back(biencible);
    }
  }
  for (int i=0; i<vectorfiltre.size();i++){
        Bien* a = vectorfiltre[i];
        a->recherche();
    }
}

void Agence::proposition_achat(){
  cout << " Pour quel type de bien souhaitez-vous faire une proposition d'achat ? Appartement(1), maison(2), local(3) ou terrain(4)." << endl;
  int type;
  cin >> type;
  string typebien;
  if (type==1){typebien="Appartement";}
  else if (type==2){typebien=="Maison";}
  else if (type==3){typebien=="Local";}
  else if (type==4){typebien=="Terrain";}
  cout << "Quelle-est la référence catalogue du bien souhaité ?" << endl;
  int refbien;
  cin >> refbien;
  cout << "Quelle-est la référence du client ACHETEUR ?" << endl;
  int refacheteur;
  cin >> refacheteur;
  cout << "Quel prix proposez-vous pour ce bien ?" << endl;
  int prixpropo;
  cin >> prixpropo;
  Acheteur acheteurcible;
  for (int i=0; i<acheteurs.size();i++){
    if ((acheteurs[i].get_ref_client())==refacheteur){
      acheteurcible = acheteurs[i];
    }
  }
  Bien* biencible;
  acheteurcible.Avisiter(refbien,1,prixpropo);
  map<Bien*,vector<Acheteur>>::iterator im;
  for (im=dico_biens[typebien].begin();im!=dico_biens[typebien].end();im++){
    // CETTE BOUCLE DE FONCTIONNE PAS, POURQUOIIIIIIIII
    cout << "MDRRRRRRRRRRR" << endl;
    Bien* biencible = im->first;
    if (biencible->get_ref_catalogue() == refbien){
      vector <Acheteur> offre = dico_biens[typebien][biencible];
      offre.push_back(acheteurcible);
    }
  }
  //test d'affichage
  vector<Acheteur> test;
  test = dico_biens[typebien][biencible];
  for (int i=0; i<test.size();i++){
    acheteurs[i].show();
    acheteurs[i].affiche_visites(refbien);
  }
  //
}
