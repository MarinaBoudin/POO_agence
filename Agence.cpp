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
#include <fstream>
#include <sstream>

using namespace std;

Agence::Agence(){
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

vector<Vendeur> const &Agence::get_vendeurs() const {
  return vendeurs;
}

void Agence::lectureAppart(vector<string> res, Adresse &adresse) {
    bool garage;
    istringstream(res[10]) >> garage;
    bool cave;
    istringstream(res[11]) >> cave;
    bool balcon;
    istringstream(res[12]) >> balcon;
    Appartement a(adresse, stoi(res[6]), stoi(res[7]), stoi(res[14]), stoi(res[8]), stoi(res[9]), garage,
                  cave,
                  balcon, stoi(res[13]));
    ajout_bien("Appartement", &a);
}

void Agence::lectureLocal(vector<string> res, Adresse &adresse) {
    bool stockage;
    istringstream(res[9]) >> stockage;
    Local l(adresse, stoi(res[6]), stoi(res[7]), stoi(res[10]), stof(res[8]), stockage);
    ajout_bien("Local", &l);
}

void Agence::lectureMaison(vector<string> res, Adresse &adresse) {
    bool garage;
    istringstream(res[9]) >> garage;
    bool jardin;
    istringstream(res[10]) >> jardin;
    bool piscine;
    istringstream(res[11]) >> piscine;
    Maison m(adresse, stoi(res[6]), stoi(res[7]), stoi(res[12]), stoi(res[8]), garage, jardin, piscine);
    ajout_bien("Maison", &m);
}

void Agence::lectureTerrain(vector<string> res, Adresse &adresse) {
    bool constructible;
    istringstream(res[8]) >> constructible;
    Terrain t(adresse, stoi(res[6]), stoi(res[7]), stoi(res[9]), constructible);
    ajout_bien("Terrain", &t);
}

void Agence::bien_txt() {
    string const nomFic("C:\\Users\\antoi\\Dropbox\\Master\\M1S2\\POO\\Projet\\POO_agence\\bien.txt");
    ifstream ficBiens(nomFic.c_str());  //ouverture en lecture
    if (ficBiens) {
        string line;
        while (getline(ficBiens, line)) {
            vector<string> res;
            string sousChaine;
            istringstream values(line);
            while (getline(values, sousChaine, ',')) {
                res.push_back(sousChaine);
            }
            Adresse newAdresse(res[2], res[3], res[5], stoi(res[1]), stoi(res[4]));
            string choix;
            cout << "Quel est la référence vendeur pour ce bien ? : (0 si pas de vendeur associé)" << endl;
            newAdresse.show();
            cin >> choix;
            bool ok = false;
            if (choix == "0") { //Cas de création de vendeur
                cout << "Il faut créer le vendeur pour ce bien, entrez son nom : " << endl;
                string nom;
                cin >> nom;
                Vendeur newVendeur = Vendeur(nom);
                ajout_vendeur(newVendeur);
                res.push_back(to_string(newVendeur.get_ref_client()));
                ok = true;
            }
            else if (choix != "0") { //Cas de recherche du vendeur avec l'identifiant communiqué
                for (int i = 0; i < vendeurs.size(); i++) {
                    int reftmp = vendeurs[i].get_ref_client();
                    cout << reftmp << endl;
                    if (stoi(choix) == reftmp) {
                        res.push_back(choix); //si le vendeur existe
                        ok = true;
                        break;
                    }
                }
                if(!ok) {cout << "Pas de vendeur ayant cette référence : " << choix << endl;}
            }
            if (ok) {
                if (res[0] == "a") {
                    lectureAppart(res, newAdresse);
                } else if (res[0] == "l") {
                    lectureLocal(res, newAdresse);
                } else if (res[0] == "m") {
                    lectureMaison(res, newAdresse);
                } else if (res[0] == "t") {
                    lectureTerrain(res, newAdresse);
                } else {
                    cout << "Erreur de lecture du type de bien à l'adresse : " << endl;
                    newAdresse.show();
                    cout << "passage au bien suivant..." << endl;
                }
            }
        }
        ficBiens.close();
    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

void Agence::acheteur_txt() {
    string const nomFic("C:\\Users\\antoi\\Dropbox\\Master\\M1S2\\POO\\Projet\\POO_agence\\acheteur.txt");
    ifstream ficAcheteurs(nomFic.c_str());  // ouverture en lecture
    if (ficAcheteurs) {
        string line;
        while (getline(ficAcheteurs, line)) {
            vector<string> res;
            string sousChaine;
            istringstream values(line);
            while (getline(values, sousChaine, ',')) {
                res.push_back(sousChaine);
            }
            Adresse newAdresse(res[2], res[3], res[5], stoi(res[1]), stoi(res[4]));
            Acheteur a(res[0], newAdresse);
            ajout_acheteur(a);
        }
        ficAcheteurs.close();
    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

void Agence::vendeur_txt() {
    string const nomFic("C:\\Users\\antoi\\Dropbox\\Master\\M1S2\\POO\\Projet\\POO_agence\\vendeur.txt");
    ifstream ficVendeurs(nomFic.c_str());  // ouverture en lecture
    if (ficVendeurs) {
        string line;
        while (getline(ficVendeurs, line)) {
            vector<string> res;
            string sousChaine;
            istringstream values(line);
            while (getline(values, sousChaine, ',')) {
                res.push_back(sousChaine);
            }
            Adresse newAdresse(res[2], res[3], res[5], stoi(res[1]), stoi(res[4]));
            Vendeur v(res[0], newAdresse);
            ajout_vendeur(v);
        }
    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

void Agence::creer_client() {
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
        int a= acheteur.get_ref_client();
        cout << "Ref client : " << a << endl;
        ajout_acheteur(acheteur);
      }
      else if (type==2){
        Vendeur vendeur = Vendeur(name);
        int a= vendeur.get_ref_client();
        cout << "Ref client : " << a << endl;
        ajout_vendeur(vendeur);
      }
    }
  }
  if (choix == 2) {
    cout << "Quel est le type du/des client(s) ? \n1 : Acheteur(s)\n2 : Vendeur(s)" << endl;
    int type;
    cin >> type;
    if (type == 1) {
      acheteur_txt();
    } else if (type == 2) {
      vendeur_txt();
    }
  }
  for(int k=0;k<acheteurs.size();k++){
    acheteurs[k].show();
  }
  for(int k=0;k<vendeurs.size();k++){
    vendeurs[k].show();
  }
}

void Agence::ajout_appartement(Adresse _adresse,int _prix,int _m2,int ref){
  cout << "Combien y a t-il de pièces ? " << endl;
  int _pieces;
  cin >> _pieces;
  cout << "Quel est l'étage où se trouve l'appartement ?" << endl;
  int _etage;
  cin >> _etage;
  cout << "Y a t-il un garage ? \n1 : Oui\n2 : Non"<<endl;
  int _gar;
  cin >> _gar;
  if (_gar==1){
    bool _garage = true;
  }
  else if (_gar==2){
    bool _garage = false;
  }
  cout << "Y a t-il une cave ? \n1 : Oui\n2 : Non"<<endl;
  int _ca;
  cin >> _ca;
  if (_ca==1){
    bool _cave = true;
  }
  else if (_ca==2){
    bool _cave = false;
  }
  cout << "Y a t-il une balcon ? \n1 : Oui\n2 : Non"<<endl;
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
  Appartement* nouveau_appartement= new Appartement(_adresse,_prix,_m2,ref,_pieces,_etage,_gar,_ca,_ba,_nb_appart);
  ajout_bien("Appartement",nouveau_appartement);
}

void Agence::ajout_local(Adresse _adresse,int _prix,int _m2,int ref){
  cout << "Quelle est la taille de la vitrine ? " << endl;
  float _taille_vitrine;
  cin >> _taille_vitrine;
  cout << "Y a t-il un espace de stockage ? \n1 : Oui\n2 : Non"<<endl;
  int _espace;
  cin >> _espace;
  bool _espace_stockage=false;
  if (_espace==1){
    bool _espace_stockage = true;
  }
  Local* nouveau_local= new Local(_adresse,_prix,_m2,ref,_taille_vitrine,_espace_stockage);
  ajout_bien("Local",nouveau_local);
}

void Agence::ajout_maison(Adresse _adresse,int _prix,int _m2,int ref){
  cout << "Combien y a t-il de pièces ? " << endl;
  int _pieces;
  cin >> _pieces;
  cout << "Y a t-il un garage ? \n1 : Oui\n2 : Non"<<endl;
  int _gar;
  cin >> _gar;
  bool _garage=false;
  if (_gar==1){
    _garage = true;
  }
  cout << "Y a t-il un jardin ? \n1 : Oui\n2 : Non"<<endl;
  int _ja;
  cin >> _ja;
  bool _jardin=false;
  if (_ja==1){
    _jardin = true;
  }
  cout << "Y a t-il une piscine ? \n1 : Oui\n2 : Non"<<endl;
  int _pi;
  cin >> _pi;
  bool _piscine=false;
  if (_pi==1){
    _piscine = true;
  }
  Maison* nouveau_maison= new Maison(_adresse,_prix,_m2,ref,_pieces,_garage,_jardin,_piscine);
  ajout_bien("Maison",nouveau_maison);
}

void Agence::ajout_terrain(Adresse _adresse,int _prix,int _m2,int ref){
  cout << "Le terrain est-il constructible ? \n1 : Oui\n2 : Non" << endl;
  int _co;
  cin >> _co;
  bool _constructible=false;
  if (_co==1){
    _constructible = true;
  }
  Terrain* nouveau_terrain= new Terrain(_adresse,_prix,_m2,ref,_constructible);
  ajout_bien("Terrain",nouveau_terrain);
}

void Agence::creer_bien() {
  cout << "Comment souhaitez-vous entrez le/les biens ? \n1 : Manuellement\n2 : Via un fichier txt" << endl;
  int choix;
  cin >> choix;
  if (choix==1){
    cout << "Combien de biens voulez vous ajouter ?" << endl;
    int nb_biens;
    cin >> nb_biens;
    for (int i=0;i<nb_biens;i++){
      cout << "Veuillez donner la référence client vendeur pour le bien ?" << endl;
      int ref;
      cin >> ref;
      int taille = vendeurs.size();
      for (int vendeur=0; vendeur<taille;vendeur++){
        int id=vendeurs[vendeur].get_ref_client();
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
          Adresse _adresse;
          _adresse.remplir();
          if (type==1){
            ajout_appartement(_adresse,_prix,_m2,ref);
          }
          else if (type==2){
            ajout_local(_adresse,_prix,_m2,ref);
          }
          else if (type==3){
            ajout_maison(_adresse,_prix,_m2,ref);
          }
          else if (type==4){
            ajout_terrain(_adresse,_prix,_m2,ref);
          }
        }
      }
    }
  }
  else if (choix == 2) {
    bien_txt();
  }
}



void Agence::ajout_acheteur(Acheteur& a){
  acheteurs.push_back(a);
}

void Agence::ajout_vendeur(Vendeur& v){
  vendeurs.push_back(v);
}

void Agence::ajout_bien(string a, Bien* b){
  dico_biens[a][b];
  int refvendeur = b->get_ref_client();
  for (int i=0;i<vendeurs.size();i++){
    if (vendeurs[i].get_ref_client()==refvendeur){
      vendeurs[i].push_bien(b);
    }
  }
  b->affiche();
}

void Agence::recherche_biens(){
  string typebien = queltype();
  cout << "Choix de filtres de recherche. Tappez 0 si vous ne désirez pas filtrer suivant le paramètre demandé -> " << endl;
  cout << "PRIX -> Entrez le prix maximal du bien que vous désirez acheter :" << endl;
  int choixprix;
  cin >> choixprix;
  cout << "SURFACE -> Entrez la surface minimale en m2 :" << endl;
  int choixm2;
  cin >> choixm2;
  vector<Bien*> vectorfiltre;
  map<Bien*,vector<Acheteur>>::iterator im;
  for (im=dico_biens[typebien].begin();im!=dico_biens[typebien].end();im++){
    Bien* biencible = im->first;
    if (((biencible->get_prix() <= choixprix) || (choixprix==0)) && ((biencible->get_m2() >= choixm2) || (choixm2==0))){
      vectorfiltre.push_back(biencible);
    }
  }
  for (int i=0; i<vectorfiltre.size();i++){
        Bien* a = vectorfiltre[i];
        a->recherche();
    }
}

void Agence::proposition_achat(){
  string typebien = queltype();
  cout << "Quelle est la référence catalogue du bien souhaité ?" << endl;
  int refbien;
  cin >> refbien;
  cout << "Quelle est la référence du client ACHETEUR ?" << endl;
  int refacheteur;
  cin >> refacheteur;
  cout << "La visite du bien (ref " << refbien << ") a été ajouté. Voulez-vous faire une proposition ? (1 : oui, 2 : non)" << endl;
  int prop;
  cin >> prop;
  int prixpropo;
  if (prop == 1) {
      cout << "Quel prix proposez-vous pour ce bien ?" << endl;
      cin >> prixpropo;
  } else {prop = 0; prixpropo = 0;}
  Acheteur acheteurcible;
  for (int i=0; i<acheteurs.size();i++){
    if ((acheteurs[i].get_ref_client())==refacheteur){
      acheteurcible = acheteurs[i];
    }
  }
  Bien* bien;
  acheteurcible.Avisiter(refbien,prop,prixpropo);
  map<Bien*,vector<Acheteur>>::iterator im;
  for (im=dico_biens[typebien].begin();im!=dico_biens[typebien].end();im++){
    bien = im->first;
    if (bien->get_ref_catalogue() == refbien){
      dico_biens[typebien][bien].push_back(acheteurcible);
    }
  }
}

void Agence::contrats(){
  cout << "Quelle est la référence du client vendeur ?" << endl;
  int refv;
  cin >> refv;
  string typebien = queltype();
  cout << "Quelle est la référence catalogue du bien souhaité ?" << endl;
  int refb;
  cin >> refb;
  Vendeur tmp;
  for (int i=0; i<vendeurs.size();i++){
    if (vendeurs[i].get_ref_client()==refv){
      tmp = vendeurs[i];
    }
  }
  Bien* tmpb;
  vector<Bien*> listBiens = tmp.get_listBiens();
  for (int j=0;j<listBiens.size();j++){
    if (listBiens[j]->get_ref_catalogue()==refb){
      tmpb = listBiens[j];
    }
  }
  vector<Acheteur> listacheteurs = dico_biens[typebien][tmpb];
  cout << "Liste des propositions pour ce bien (avec référence client acheteur) :" << endl;
  for (int k=0;k<listacheteurs.size(); k++){
    map<int, pair<int, int>> visites = listacheteurs[k].get_visites();
    map<int, pair<int, int>>::iterator im;
    for (im=visites.begin();im!=visites.end();im++){
      int refc = im->first;
      if (refc == refb){
        pair<int, int> propo = im->second;
        if (propo.first==1){
          int prix = propo.second;
          listacheteurs[k].show();
          cout << "Prix proposé : " << prix << "\n######" << endl;
        }
      }
    }
  }
  cout << "Retenez-vous une des propositions de vente ? Oui(1) ou Non(2)" << endl;
  int choix;
  cin >> choix;
  int choixa;
  if (choix==1){
    cout << "Entrez l'ID du client acheteur souhaité :" << endl;
    cin >> choixa;
    tmp.retirer_vente(tmpb);
    for (int k=0;k<listacheteurs.size(); k++){
      map<int, pair<int, int>> visites = listacheteurs[k].get_visites();
      map<int, pair<int, int>>::iterator im;
      for (im=visites.begin();im!=visites.end();im++){
        int refc = im->first;
        if (refc == refb){
          visites.erase(refc);
        }
      }
    }
    dico_biens[typebien].erase(tmpb);
  }
}

string Agence::queltype(){
  cout << "Quel type de bien est-ce ? Appartemment(1), Local(2), Maison(3) ou Terrain(4)" << endl;
  string typebien;
  int typeb;
  cin >> typeb;
  switch (typeb) {
    case 1:
      typebien="Appartement";
      break;
    case 2:
      typebien="Local";
      break;
    case 3:
      typebien="Maison";
      break;
    case 4:
      typebien="Terrain";
      break;
    default :
      cout << "Choix non reconnu." << endl;
      break;
  }
  return typebien;
}

void Agence::deleteagence(){
  vector<string> types{"Appartement","Local","Maison","Terrain"};
  for (int k=0;k<types.size();k++){
    int size = dico_biens[types[k]].size();
    cout << size << endl;
    if (size!=0){
      map<Bien*, vector<Acheteur>>::iterator im;
      if (im!=dico_biens[types[k]].end()){
        delete im->first;
        // dico_biens[types[k]].erase(im);
      }
    }
  }
}
