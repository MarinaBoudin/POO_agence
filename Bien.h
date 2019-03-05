#ifndef PROJECT_BIEN_H
#define PROJECT_BIEN_H


#include <string>
#include "Adresse.h"

class Bien {
  private:
    int prix;
    Adresse adresse;
    int m2;
    int ref_client;
    int ref_catalogue;
};


#endif //PROJECT_BIEN_H
