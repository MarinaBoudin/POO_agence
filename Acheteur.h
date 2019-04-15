#ifndef PROJECT_ACHETEURS_H
#define PROJECT_ACHETEURS_H

#include <map>
#include "Client.h"
#include <map>

class Acheteur : public Client {
private:
    //TODO : créer une liste de références vers les biens déjà visités, l'offre et le prix si offre il y a
    std::map<std::string,std::pair<std::string,int>> visites;
public:
    Acheteur(std::string nom);

    ~Acheteur();

    void show();

    std::string getnom();

    void Avisiter(std::string nomBien, int prop, int montant);

    bool operator<(const Acheteur& other);
};


#endif //PROJECT_ACHETEURS_H
