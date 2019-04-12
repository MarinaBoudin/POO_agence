cc=g++
main:Acheteur.o Adresse.o Agence.o Appartement.o Bien.o Client.o Local.o main.o Maison.o Terrain.o Vendeur.o
	$(cc) Acheteur.o Adresse.o Agence.o Appartement.o Bien.o Client.o Local.o main.o Maison.o Terrain.o Vendeur.o -o main
Adresse.o: Adresse.cpp Adresse.h
	$(cc) -c Adresse.cpp
Bien.o: Bien.cpp Bien.h Adresse.h
	$(cc) -c Bien.cpp
Appartement.o: Appartement.cpp Appartement.h Adresse.h Bien.h
	$(cc) -c Appartement.cpp
Maison.o: Maison.cpp Maison.h Adresse.h Bien.h
	$(cc) -c Maison.cpp
Local.o: Local.cpp Local.h Adresse.h Bien.h
	$(cc) -c Local.cpp
Terrain.o: Terrain.cpp Terrain.h Adresse.h Bien.h
	$(cc) -c Terrain.cpp
Client.o: Client.cpp Client.h
	$(cc) -c Client.cpp
Acheteur.o: Acheteur.cpp Acheteur.h Client.h
	$(cc) -c Acheteur.cpp
Vendeur.o: Vendeur.cpp Vendeur.h Client.h
	$(cc) -c Vendeur.cpp
Agence.o: Agence.cpp Agence.h Bien.h Appartement.h Adresse.h Maison.h Local.h Terrain.h Client.h Acheteur.h Vendeur.h
	$(cc) -c Agence.cpp
main.o: main.cpp Agence.h Bien.h Appartement.h Adresse.h Maison.h Local.h Terrain.h Client.h Acheteur.h Vendeur.h
	$(cc) -c main.cpp
