#include "Client.h"
#include "Acheteur.h"
#include "Vendeur.h"
#include "Adresse.h"
#include "Bien.h"
#include "Appartement.h"
#include "Maison.h"
#include "Terrain.h"
#include "Local.h"
#include "Agence.h"

#include <iostream>

using namespace std;

void menu_print(){ //creer une liste avec les propositions de menu
  cout << "1- Créer un ou plusieurs client(s) acheteur(s) et/ou vendeur(s)." << endl;
  cout << "2- Enregistrement d'un bien." << endl;
  cout << "3- Enregistrement d'une proposition d'achat à un client." << endl;
  cout << "4- Afficher tous les biens existants avec des paramètres spécifiques." << endl;
  cout << "5- Gérer les contrats de vente." << endl;
  cout << "0- Quitter le gestionnaire." << endl;
}

void client_vmanuelle(){
  cout << "Combien de fichiers client voulez-vous créer ?" << endl;
  int nb;
  cin >> nb;
  for (int i; i < nb; i++){
    cout << "Le client n°" << i << " est-il un vendeur (1) ou un acheteur (2) ?" << endl;
    int type;
    cin >> type;
    if (type == 1){
      //creation client vendeur et ajout dans le dico de agence ??
    }
    else if (type == 2){
      //creation client acheteur et ajout dans le dico de agence ??
    }
    else {
      cout << "Choix invalide." << endl;
    }
  }
}

void client_txt(){

}

void creer_client(){
  cout << "Souhaitez-vous rentrer manuellement les nouveaux clients (1) ou en utilisant un fichier txt (2) ?" << endl;
  int choix;
  cin >> choix;
  if (choix == 1){
    client_vmanuelle();
  }
  if (choix == 2){
    client_txt();
  }
}

void creer_bien(){

}

void proposition_achat(){

}

void affichage_biens(){

}

void contrats(){

}

bool menu_switch(bool run){
  menu_print();
  int choix;
  cin >> choix;
  switch (choix){
    case 1 :
    creer_client();
    break;
    case 2 :
    creer_bien();
    break;
    case 3 :
    proposition_achat();
    break;
    case 4 :
    affichage_biens();
    break;
    case 5 :
    contrats();
    break;
    case 0 :
    return run=false;
    break;
    default :
    cout << "Choix invalide." << endl;
  }
}

int main() {
    Agence test;
    map<string, map<Bien,vector<Acheteur>>>::iterator im;
    for (im=test.get_dico_biens().begin();im!=test.get_dico_biens().end();im++){
      cout << im->first << endl;
    }   // Vendeur bob = Vendeur("Bob");
    // bob.show();
    // cout << "Bienvenue dans le gestionnaire d'agence. Que souhaitez-vous faire ?" << endl;
    // bool run=true;
    // while (run){
    //   run = menu_switch(run);
    // }
    return 0;
};
