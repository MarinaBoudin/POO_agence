#ifndef CLION_TD3_4_ADRESSE_H
#define CLION_TD3_4_ADRESSE_H

#include <string>

class Adresse {
private:
    std::string voie;
    std::string nomVoie;
    std::string ville;
    int numero = 0;
    int CP = 0;

public:
    Adresse();

    void show();

    void remplir();
};


#endif //CLION_TD3_4_ADRESSE_H
