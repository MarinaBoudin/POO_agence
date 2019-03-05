#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H


#include <string>
#include "Adresse.h"

class Client {
protected:
    std::string nom;
    Adresse adresse;
public:
    Client(std::string nom);

    ~Client();

    std::string getnom();

    void show();
};


#endif //PROJECT_CLIENT_H
