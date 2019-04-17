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

vector<Vendeur> const &Agence::get_vendeurs() const {
  return vendeurs;
}

void Agence::lectureAppart(vector<string> res, Adresse &adresse) {
    bool garage;
    istringstream(res[11]) >> garage;
    bool cave;
    istringstream(res[12]) >> cave;
    bool balcon;
    istringstream(res[13]) >> balcon;
    Appartement a(adresse, stoi(res[6]), stoi(res[7]), stoi(res[8]), stoi(res[9]), stoi(res[10]), garage,
                  cave,
                  balcon, stoi(res[14]));
    ajout_bien("Appartement", &a);
}

void Agence::lectureLocal(vector<string> res, Adresse &adresse) {
    bool stockage;
    istringstream(res[10]) >> stockage;
    Local l(adresse, stoi(res[6]), stoi(res[7]), stoi(res[8]), stof(res[9]), stockage);
    ajout_bien("Local", &l);
}

void Agence::lectureMaison(vector<string> res, Adresse &adresse) {
    bool garage;
    istringstream(res[10]) >> garage;
    bool jardin;
    istringstream(res[11]) >> jardin;
    bool piscine;
    istringstream(res[12]) >> piscine;
    Maison m(adresse, stoi(res[6]), stoi(res[7]), stoi(res[8]), stoi(res[9]), garage, jardin, piscine);
    ajout_bien("Maison", &m);
}

void Agence::lectureTerrain(vector<string> res, Adresse &adresse) {
    bool constructible;
    istringstream(res[9]) >> constructible;
    Terrain t(adresse, stoi(res[6]), stoi(res[7]), stoi(res[8]), constructible);
    ajout_bien("Terrain", &t);
}

void Agence::bien_txt() {
    string const nomFic("bien.txt");
    ifstream ficBiens(nomFic.c_str());  // ouverture en lecture
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
            //1:Appartement, 2:Local, 3:Maison, 4:Terrain
            switch (stoi(res[0])) {
                case 1 :
                    lectureAppart(res, newAdresse);
                    break;
                case 2 :
                    lectureLocal(res, newAdresse);
                    break;
                case 3 :
                    lectureMaison(res, newAdresse);
                    break;
                case 4 :
                    lectureTerrain(res, newAdresse);
                    break;
                default:
                    cout << "Erreur de lecture de l'indice du fichier" << endl;
                    break;
            }


        }
        ficBiens.close();
    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

void Agence::acheteur_txt() {
    string const nomFic("acheteur.txt");
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
    string const nomFic("vendeur.txt");
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
            v.show();
        }
        ficVendeurs.close();
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

void Agence::ajout_appartement(int _prix,int _m2,int ref){
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
  Appartement* nouveau_appartement= new Appartement(_prix,_m2,ref,_pieces,_etage,_gar,_ca,_ba,_nb_appart);
  ajout_bien("Appartement",nouveau_appartement);
  nouveau_appartement->affiche();
}

void Agence::ajout_local(int _prix,int _m2,int ref){
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
  Local* nouveau_local= new Local(_prix,_m2,ref,_taille_vitrine,_espace_stockage);
  ajout_bien("Local",nouveau_local);
}

void Agence::ajout_maison(int _prix,int _m2,int ref){
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
  Maison* nouveau_maison= new Maison(_prix,_m2,ref,_pieces,_garage,_jardin,_piscine);
  ajout_bien("Maison",nouveau_maison);
}

void Agence::ajout_terrain(int _prix,int _m2,int ref){
  cout << "Le terrain est-il constructible ? \n1 : Oui\n2 : Non" << endl;
  int _co;
  cin >> _co;
  bool _constructible=false;
  if (_co==1){
    _constructible = true;
  }
  Terrain* nouveau_terrain= new Terrain(_prix,_m2,ref,_constructible);
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
      cout << "Veuillez donner la référence client pour le bien ?" << endl;
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
          if (type==1){
            ajout_appartement(_prix,_m2,ref);
          }
          else if (type==2){
            ajout_local(_prix,_m2,ref);
          }
          else if (type==3){
            ajout_maison(_prix,_m2,ref);
          }
          else if (type==4){
            ajout_terrain(_prix,_m2,ref);
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
