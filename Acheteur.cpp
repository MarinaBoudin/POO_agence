#include "Acheteur.h"

using namespace std;

Acheteur::Acheteur(string nom) : Client(nom) {}

Acheteur::~Acheteur() {}

string Acheteur::getnom() { return nom; }