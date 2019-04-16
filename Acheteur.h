#ifndef PROJECT_ACHETEURS_H
#define PROJECT_ACHETEURS_H

#include <map>
#include "Client.h"
#include <map>

class Acheteur : public Client {
private:
    std::map<int, std::pair<std::string, int>> visites;
public:
    Acheteur(std::string nom);

    Acheteur(std::string nom, Adresse _adresse);

    ~Acheteur();

    void show();

    std::string getnom();

    void Avisiter(int ref_catalogue, int prop, int montant);

    void retirerVisite(int ref_catalogue);

    bool operator<(const Acheteur& other);
};


#endif //PROJECT_ACHETEURS_H
