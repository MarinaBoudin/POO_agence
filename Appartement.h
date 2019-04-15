#ifndef PROJECT_APPARTEMENT_H
#define PROJECT_APPARTEMENT_H

#include "Adresse.h"
#include "Bien.h"
#include <iostream>

class Appartement : public Bien {
private:
    int pieces;
    int etage;
    bool garage;
    bool cave;
    bool balcon;
    int nb_appart;
<<<<<<< HEAD
  public:
    Appartement(int _prix, int _m2, int _ref_client, int _ref_catalogue,int _pieces,int _etage,bool _garage,bool _cave,bool _balcon,int _nb_appart);
=======
public:
    Appartement(int _prix, Adresse _adresse, int _m2, int _ref_client, int _ref_catalogue, int _pieces, int _etage,
                bool _garage,
                bool _cave, bool _balcon, int _nb_appart);
>>>>>>> 476bc1e02c9a16c713257f7f43fe8d51c747817c
    int get_pieces();
    int get_etage();
    bool get_garage();
    bool get_cave();
    bool get_balcon();
    int get_nb_appart();
    void affiche();
};


#endif //PROJECT_APPARTEMENT_H
