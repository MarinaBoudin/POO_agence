#include <iostream>

#include "Client.h"

using namespace std;

Client::Client(string nom) : nom(nom) {
    cout << "Veuillez rentrer l'adresse de : " << nom << endl;
    adresse.remplir();
}

Client::~Client() {};

int Client::get_id() { return id_client; }

string Client::getnom() {}

void Client::show() {}
