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
    Vendeur();

    Vendeur(std::string nom);

    Vendeur(std::string nom, Adresse _adresse);

    ~Vendeur();

    void show();

    std::vector<Bien*> get_listBiens();

    std::string getnom();

    void retirer_vente(Bien *b);

    void push_bien(Bien* b);

};


#endif //PROJECT_VENDEUR_H
