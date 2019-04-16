#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H


#include <string>
#include "Adresse.h"

class Client {
protected:
    std::string nom;
    Adresse adresse;
    static int id_client;
public:
    Client(std::string nom);

    Client(std::string nom, Adresse _adresse);

    ~Client();

    static int get_id();

    virtual std::string getnom() = 0;

    virtual void show() = 0;
};


#endif //PROJECT_CLIENT_H
