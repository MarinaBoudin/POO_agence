#ifndef PROJECT_TERRAIN_H
#define PROJECT_TERRAIN_H

#include "Adresse.h"
#include "Bien.h"
#include <iostream>

class Terrain : public Bien{
  private:
    bool constructive;
  public:
    Terrain(int _prix, Adresse _adresse, int _m2, int _ref_client, int _ref_catalogue,bool _constructive);
    bool get_constructive();
    void affiche();
};


#endif //PROJECT_TERRAIN_H
