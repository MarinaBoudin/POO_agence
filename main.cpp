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

void client_vmanuelle() {
    cout << "Combien de fichiers client voulez-vous créer ?" << endl;
    int nb;
    cin >> nb;
    for (int i; i < nb; i++) {
        cout << "Le client n°" << i << " est-il un vendeur (1) ou un acheteur (2) ?" << endl;
        int type;
        cin >> type;
        if (type == 1) {
            //creation client vendeur et ajout dans le dico de agence ??
        } else if (type == 2) {
            //creation client acheteur et ajout dans le dico de agence ??
        } else {
            cout << "Choix invalide." << endl;
        }
    }
}

void client_txt() {

}


void creer_client(Agence mon_agence) {
  cout << "Comment souhaitez-vous entrez le/les nouveaux clients ? \n1 : Manuellement \n2 : Via un fichier txt" << endl;
  int choix;
  cin >> choix;
  if (choix == 1) {
    cout << "Combien de nouveaux clients voulez vous entrer ?"<<endl;
    int nb_client;
    cin >> nb_client;
    for (int k=0;k<nb_client;k++){
      cout << "Quel est le nom du nouveau client n°" << k << " ?" << endl;
      string name;
      cin >> name;
      cout << "Client n°" << k << " : Quel est le type du client ? \n1 : Acheteur\n2 : Vendeur" << endl;
      int type;
      cin >> type;
      if (type==1){
        Acheteur acheteur = Acheteur(name);
        int a= acheteur.get_id();
        cout << "Ref client : " << a << endl;
        mon_agence.ajout_acheteur(acheteur);
      }
      else if (type==2){
        Vendeur vendeur = Vendeur(name);
        mon_agence.ajout_vendeur(vendeur);
        int a= vendeur.get_id();
        cout << "Ref client : " << a << endl;
      }
    }
  }
  if (choix == 2) {
    client_txt();
  }
}

void ajout_appartement(Agence mon_agence,int _prix,int _m2,int ref){
  cout << "Combien y a t-il de pièces ? " << endl;
  int _pieces;
  cin >> _pieces;
  cout << "Quel est l'étage où se trouve l'appartement ?" << endl;
  int _etage;
  cin >> _etage;
  cout << "Y a t-il un garage ? \n1 : Oui\n2:Non"<<endl;
  int _gar;
  cin >> _gar;
  if (_gar==1){
    bool _garage = true;
  }
  else if (_gar==2){
    bool _garage = false;
  }
  cout << "Y a t-il une cave ? \n1 : Oui\n2:Non"<<endl;
  int _ca;
  cin >> _ca;
  if (_ca==1){
    bool _cave = true;
  }
  else if (_ca==2){
    bool _cave = false;
  }
  cout << "Y a t-il une balcon ? \n1 : Oui\n2:Non"<<endl;
  int _ba;
  cin >> _ba;
  if (_ba==1){
    bool _balcon = true;
  }
  else if (_ba==2){
    bool _balcon = false;
  }
  cout << "Combien y a t-il d'appartement dans l'immeuble ?"<<endl;
  int _nb_appart;
  cin >> _nb_appart;
  Appartement nouveau_appartement= Appartement(_prix,_m2,ref,_pieces,_etage,_gar,_ca,_ba,_nb_appart);
  mon_agence.ajout_bien("Appartement",nouveau_appartement);
}

void ajout_local(Agence mon_agence,int _prix,int _m2,int ref){
  cout << "Quelle est la taille de la vitrine ? " << endl;
  int _taille_vitrine;
  cin >> _taille_vitrine;
  cout << "Y a t-il un espace de stockage ? \n1 : Oui\n2:Non"<<endl;
  int _espace;
  cin >> _espace;
  bool _espace_stockage=false;
  if (_espace==1){
    bool _espace_stockage = true;
  }
  Local nouveau_local= Local(_prix,_m2,ref,_taille_vitrine,_espace_stockage);
  mon_agence.ajout_bien("Local",nouveau_local);
}

void ajout_maison(Agence mon_agence,int _prix,int _m2,int ref){
  cout << "Combien y a t-il de pièces ? " << endl;
  int _pieces;
  cin >> _pieces;
  cout << "Y a t-il un garage ? \n1 : Oui\n2:Non"<<endl;
  int _gar;
  cin >> _gar;
  bool _garage=false;
  if (_gar==1){
    _garage = true;
  }
  cout << "Y a t-il un jardin ? \n1 : Oui\n2:Non"<<endl;
  int _ja;
  cin >> _ja;
  bool _jardin=false;
  if (_ja==1){
    _jardin = true;
  }
  cout << "Y a t-il une piscine ? \n1 : Oui\n2:Non"<<endl;
  int _pi;
  cin >> _pi;
  bool _piscine=false;
  if (_pi==1){
    _piscine = true;
  }
  Maison nouveau_maison= Maison(_prix,_m2,ref,_pieces,_garage,_jardin,_piscine);
  mon_agence.ajout_bien("Maison",nouveau_maison);
}

void ajout_terrain(Agence mon_agence,int _prix,int _m2,int ref){
  cout << "Le terrain est-il constructible ? " << endl;
  int _co;
  cin >> _co;
  bool _constructible=false;
  if (_co==1){
    _constructible = true;
  }
  Terrain nouveau_terrain= Terrain(_prix,_m2,ref,_constructible);
  mon_agence.ajout_bien("Terrain",nouveau_terrain);
}

void creer_bien(Agence mon_agence) {
  cout << "Comment souhaitez-vous entrez le/les biens ? \n1 : Manuellement\n2 : Via un fichier txt" << endl;
  int choix;
  cin >> choix;
  if (choix==1){
    cout << "Combien de biens voulez vous ajouter ?" << endl;
    int nb_biens;
    cin >> nb_biens;
    for (int i=0;i<nb_biens;i++){
      cout << "Veuillez donner la référence client pour le bien ?" << endl;
      int ref;
      cin >> ref;
      vector<Vendeur> vendeurs = mon_agence.get_vendeurs();
      int taille = vendeurs.size();
      for (int vendeur=0; vendeur<taille;vendeur++){
        int id=vendeurs[vendeur].get_id();
        cout << "id : " << id << endl;
        if (id==ref){
          cout << "Quel type de bien voulez-vous ajouter ?\n1 : Appartement \n2 : Local\n3 : Maison\n4 : Terrain"<<endl;
          int type;
          cin >> type;
          cout << "Quel est le prix du bien ?" <<endl;
          int _prix;
          cin >> _prix;
          cout << "Combien y a t-il de mêtres carré ? " << endl;
          int _m2;
          cin >> _m2;
          if (type==1){
            ajout_appartement(mon_agence,_prix,_m2,ref);
          }
          else if (type==2){
            ajout_local(mon_agence,_prix,_m2,ref);
          }
          else if (type==3){
            ajout_maison(mon_agence,_prix,_m2,ref);
          }
          else if (type==4){
            ajout_terrain(mon_agence,_prix,_m2,ref);
          }
        }
      }
    }
  }
}

void proposition_achat() {

}

void affichage_biens() {

}

void contrats() {

}

void menu_print() { //creer une liste avec les propositions de menu
    cout << "1- Créer un ou plusieurs client(s) acheteur(s) et/ou vendeur(s)." << endl;
    cout << "2- Enregistrement d'un bien." << endl;
    cout << "3- Enregistrement d'une proposition d'achat à un client." << endl;
    cout << "4- Afficher tous les biens existants avec des paramètres spécifiques." << endl;
    cout << "5- Gérer les contrats de vente." << endl;
    cout << "0- Quitter le gestionnaire." << endl;
}

int main() {
    Agence mon_agence;
    // map<string, map<Bien,vector<Acheteur>>> mapp=mon_agence.get_dico_biens();
    // map<string, map<Bien,vector<Acheteur>>>::iterator im;
    // for (im=mapp.begin();im!=mapp.end();im++){
    //   cout << im->first << endl;
    // }
    bool run=true;
    while (run){
      menu_print();
      int choix;
      cin >> choix;
      switch (choix) {
          case 1 :
              creer_client(mon_agence);
              break;
          case 2 :
              creer_bien(mon_agence);
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
              return run = false;
              break;
          default :
              cout << "Choix invalide." << endl;
              break;
      }
    }
    return 0;
};
