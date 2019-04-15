#ifndef PROJECT_VENDEUR_H
#define PROJECT_VENDEUR_H


#include <string>
#include <vector>
#include "Client.h"
#include "Bien.h"

class Vendeur : public Client {
private:
    std::vector<Bien *> listBiens;
public:
    Vendeur(std::string nom);

    ~Vendeur();

    void show();

    std::string getnom();

    void ajouter_vente(Bien *b);

    void retirer_vente(Bien *b);
};


#endif //PROJECT_VENDEUR_H
