#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H


#include <string>
#include "Adresse.h"

class Client {
protected:
    std::string nom;
    Adresse adresse;
    static int id_client;
    int ref_client;
public:
    Client();

    Client(std::string nom);

    ~Client();

    int get_ref_client();

    virtual std::string getnom() = 0;

    virtual void show() = 0;
};


#endif //PROJECT_CLIENT_H
