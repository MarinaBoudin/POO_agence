#ifndef PROJECT_TERRAIN_H
#define PROJECT_TERRAIN_H

#include "Adresse.h"
#include "Bien.h"
#include <iostream>

class Terrain : public Bien{
  private:
    bool constructive;
  public:
    Terrain(int _prix, int _m2, int _ref_client,bool _constructive);
    bool get_constructive();
    void affiche();
};


#endif //PROJECT_TERRAIN_H
