#ifndef PROJECT_VENDEUR_H
#define PROJECT_VENDEUR_H


#include <string>
#include "Client.h"

class Vendeur : public Client {
private:
    //TODO : créer une liste de références vers la liste des biens en vente
public:
    Vendeur(std::string nom);

    ~Vendeur();

    void show();

    std::string getnom();
};


#endif //PROJECT_VENDEUR_H
