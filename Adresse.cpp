#include <iostream>
#include "Adresse.h"

using namespace std;

Adresse::~Adresse() {}

Adresse::Adresse() {
    voie = "N/A";
    nomVoie = "N/A";
    ville = "N/A";
    numero = 0;
    CP = 0;
}

void Adresse::show() {
    cout << numero << " " << voie << " " << nomVoie << " " << CP << " " << ville << endl;
}

void Adresse::remplir() {
    cout << "Numéro de voie : " << endl;
    cin >> numero;
    cout << "Type de voie (rue, cours...): " << endl;
    cin >> voie;
    cout << "Nom de la voie : " << endl;
    cin >> nomVoie;
    cout << "Code Postal : " << endl;
    cin >> CP;
    cout << "Ville : " << endl;
    cin >> ville;
}

Adresse::Adresse(const string &voie, const string &nomVoie, const string &ville, int numero, int CP) : voie(voie),
                                                                                                       nomVoie(nomVoie),
                                                                                                       ville(ville),
                                                                                                       numero(numero),
                                                                                                       CP(CP) {}
