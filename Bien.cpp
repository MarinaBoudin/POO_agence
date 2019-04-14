#include "Bien.h"
#include "Adresse.h"
#include <string>

using namespace std;

Bien::Bien(int _prix, Adresse _adresse, int _m2, int _ref_client, int _ref_catalogue) {
    prix = _prix;
    adresse = _adresse;
    m2 = _m2;
    ref_client = _ref_client;
    ref_catalogue = _ref_catalogue;
}

int Bien::get_prix() {
    return prix;
}

Adresse Bien::get_adresse() {
    return adresse;
}

int Bien::get_m2() {
    return m2;
}

int Bien::get_ref_client() {
    return ref_client;
}

int Bien::get_ref_catalogue() {
    return ref_catalogue;
}
// bool Bien::operator<(const Bien &b){
//   if (prix<b.get_prix()){
//     return true;
//   }
//   else{
//     return false;
//   }
// }
