#ifndef PROJECT_LOCAL_H
#define PROJECT_LOCAL_H

#include "Bien.h"
#include "Adresse.h"
#include <iostream>

class Local : public Bien{
  private:
    float taille_vitrine;
    bool espace_stockage;
  public:
    Local(int _prix, int _m2, int _ref_client,float _taille_vitrine, bool _espace_stockage);
    int get_taille_vitrine();
    bool get_espace_stockage();
    void affiche();
    void recherche();
};


#endif //PROJECT_LOCAL_H
