#include <iostream>

#include "Client.h"

using namespace std;

int Client::id_client=0;

Client::Client(){
  nom="";
}

Client::Client(string nom) : nom(nom) {
    cout << "Veuillez rentrer l'adresse de : " << nom << endl;
    adresse.remplir();
    id_client++;
    ref_client=id_client;
}

Client::Client(std::string nom, Adresse _adresse): nom(nom), adresse(_adresse){
    id_client++;
    ref_client=id_client;
}


Client::~Client() {};

int Client::get_ref_client() { return ref_client; }

string Client::getnom() {}

void Client::show() {}
