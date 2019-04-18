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
#include <fstream>
#include <sstream>

using namespace std;

void menu_print() {
    cout << "1- Créer un ou plusieurs client(s) acheteur(s) et/ou vendeur(s)." << endl;
    cout << "2- Enregistrement d'un bien." << endl;
    cout << "3- Enregistrement d'une visite et possibilité de créer une proposition d'achat." << endl;
    cout << "4- Afficher tous les biens existants avec des paramètres spécifiques." << endl;
    cout << "5- Gérer les contrats de vente." << endl;
    cout << "0- Quitter le gestionnaire." << endl;
}

int main() {
    Agence mon_agence;
    bool run=true;
    while (run){
      menu_print();
      int choix;
      cin >> choix;
      switch (choix) {
          case 1 :
              mon_agence.creer_client();
              break;
          case 2 :
              mon_agence.creer_bien();
              break;
          case 3 :
              mon_agence.proposition_achat();
              break;
          case 4 :
              mon_agence.recherche_biens();
              break;
          case 5 :
              mon_agence.contrats();
              break;
          case 0 :
              mon_agence.deleteagence();
              return run = false;
              break;
          default :
              cout << "Choix invalide." << endl;
              break;
      }
    }
    return 0;
};
