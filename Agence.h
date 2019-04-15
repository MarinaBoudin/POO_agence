#ifndef POO_AGENCE_AGENCE_H
#define POO_AGENCE_AGENCE_H

#include "Bien.h"
#include "Appartement.h"
#include "Maison.h"
#include "Local.h"
#include "Terrain.h"
#include "Client.h"
#include "Acheteur.h"
#include "Vendeur.h"

#include <iostream>
#include <map>
#include <vector>

class Agence {
  private:
    std::map<std::string, std::map<Bien,std::vector<Acheteur*>>> dico_biens;
    std::vector<Acheteur> acheteurs;
    std::vector<Vendeur> vendeurs;
  public:
    Agence();
    std::map<std::string, std::map<Bien,std::vector<Acheteur*>>> get_dico_biens();
    std::vector<Acheteur> acheteurs get_acheteurs();
    std::vector<Vendeur> vendeurs get_vendeurs();
    void ajout_acheteur(Acheteur a);
    void ajout_vendeur(Vendeur v);
    void ajout_bien(int a, Bien b);
    void recherche_biens();
};


#endif //POO_AGENCE_AGENCE_H
