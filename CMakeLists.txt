cmake_minimum_required(VERSION 3.13)
project(CLion_TD3_4)

set(CMAKE_CXX_STANDARD 14)

add_executable(POO_agence main.cpp Acheteur.cpp Acheteur.h Agence.cpp Agence.h Appartement.cpp Appartement.h Biens.cpp Biens.h Client.cpp Client.h Local.cpp Local.h Maison.cpp Maison.h Terrain.cpp Terrain.h Vendeur.cpp Vendeur.h)