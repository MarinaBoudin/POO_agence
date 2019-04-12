#ifndef PROJECT_LOCAL_H
#define PROJECT_LOCAL_H

#include "Bien.h"
#include "Adresse.h"

class Local : public Bien{
  private:
    int taille_vitrine;
    bool espace_stockage;
  public:
    Local(int _prix, Adresse _adresse, int _m2, int _ref_client, int _ref_catalogue,int _taille_vitrine, bool _espace_stockage);
    int get_taille_vitrine();
    bool get_espace_stockage();
};


#endif //PROJECT_LOCAL_H
