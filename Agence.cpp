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

Agence::Agence() {
    cout << "FAILLLLLL" << endl;
    Adresse ben; //Le constructeur par défaut met toutes les valeurs Null ou 0
    //il faut créer l'adresse par la méthode "remplir()"
    cout << "CECI EST UN TEST" << endl;
    Bien test = Bien(2, ben, 1, 65, 98);
//   Acheteur lol = Acheteur("bob");
    // map<Bien,vector<Acheteur>> a;
    // vector<Acheteur> poo;
    // poo.push_back(lol);
    // a[test]=poo;
    // a.insert(make_pair(test,poo));
    dico_biens["Appartement"];
    dico_biens["Maison"];
    dico_biens["Local"];
    dico_biens["Terrain"];
}

std::map<std::string, std::map<Bien, std::vector<Acheteur>>> Agence::get_dico_biens() {
    return dico_biens;
}
