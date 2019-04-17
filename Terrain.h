#ifndef PROJECT_TERRAIN_H
#define PROJECT_TERRAIN_H

#include "Adresse.h"
#include "Bien.h"
#include <iostream>

class Terrain : public Bien{
  private:
    bool constructible;
  public:
    Terrain(Adresse _adresse, int _prix, int _m2, int _ref_client, bool _constructible);
    bool get_constructible();
    void affiche();
    void recherche();
};


#endif //PROJECT_TERRAIN_H
