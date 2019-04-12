#ifndef PROJECT_ACHETEURS_H
#define PROJECT_ACHETEURS_H


#include <map>
#include "Client.h"

class Acheteur : public Client {
private:
    //TODO : créer une liste de références vers les biens déjà visités, l'offre et le prix si offre il y a
public:
    Acheteur(std::string nom);

    ~Acheteur();

    std::string getnom();
};


#endif //PROJECT_ACHETEURS_H
