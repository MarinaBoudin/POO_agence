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
    std::map<std::string, std::map<Bien*,std::vector<Acheteur>>> dico_biens;
    std::vector<Acheteur> acheteurs;
    std::vector<Vendeur> vendeurs;
  public:
    Agence();
    std::map<std::string, std::map<Bien*,std::vector<Acheteur>>> get_dico_biens();
    const std::vector<Acheteur> & get_acheteurs() const;
    std::vector<Vendeur> get_vendeurs();
    void ajout_acheteur(Acheteur& a);
    void ajout_vendeur(Vendeur& v);
    void ajout_bien(std::string a, Bien* b);
    void recherche_biens();
    void proposition_achat();
};


#endif //POO_AGENCE_AGENCE_H
