#ifndef PROJECT_BIEN_H
#define PROJECT_BIEN_H


#include <string>
#include "Adresse.h"
#include <iostream>

class Bien {
private:
    int prix;
    Adresse adresse;
    int m2;
    int ref_client;
    static int id_bien;
    int ref_catalogue;
  public:
    Bien(int _prix, int _m2, int _ref_client);
    int get_prix();
    Adresse get_adresse();
    int get_m2();
    int get_ref_client();
    int get_ref_catalogue();
    virtual void affiche();
    virtual void recherche();
    // virtual void recherche_maison();
    // virtual void recherche_terrain();
    // virtual void recherche_local();
    bool operator<(const Bien &b) const {
        return (prix < b.prix);
    }
};


#endif //PROJECT_BIEN_H
