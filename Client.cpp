#include <iostream>

#include "Client.h"

using namespace std;

Client::Client(string nom) : nom(nom) {
    adresse = Adresse();
}

Client::~Client() {};

string Client::getnom() { return nom; }

void Client::show() {
    cout << nom << " habite au " << endl;
    adresse.show();
}