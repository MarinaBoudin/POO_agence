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
public:
    Bien(int _prix, Adresse _adresse, int _m2, int _ref_client, int _ref_catalogue);

    int get_prix();

    Adresse get_adresse();

    int get_m2();

    int get_ref_client();

    int get_ref_catalogue();

    bool operator<(const Bien &b) const {
        return (prix < b.prix);
    }
};


#endif //PROJECT_BIEN_H
