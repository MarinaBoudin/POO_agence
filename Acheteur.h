#ifndef PROJECT_ACHETEURS_H
#define PROJECT_ACHETEURS_H

#include <map>
#include "Client.h"
#include <map>

class Acheteur : public Client {
private:
    std::map<int, std::pair<std::string, int>> visites;
public:
    Acheteur(std::string nom, int id);

    ~Acheteur();

    void show();

    std::string getnom();

    void Avisiter(int ref_catalogue, int prop, int montant);

    bool operator<(const Acheteur& other);
};


#endif //PROJECT_ACHETEURS_H
