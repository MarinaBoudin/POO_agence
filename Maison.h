#ifndef PROJECT_MAISON_H
#define PROJECT_MAISON_H

#include "Bien.h"
#include "Adresse.h"
#include <iostream>

class Maison : public Bien {
private:
    int piece;
    bool garage;
    bool jardin;
    bool piscine;
  public:
    Maison(int _prix, int _m2, int _ref_client, int _ref_catalogue,int _piece, bool _garage, bool _jardin, bool _piscine);
    int get_piece();
    bool get_garage();
    bool get_jardin();
    bool get_piscine();
    void affiche();
};


#endif //PROJECT_MAISON_H
