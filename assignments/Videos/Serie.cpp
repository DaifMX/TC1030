#include "Serie.hpp"
#include <string.h>
#include <iostream>

Serie::Serie(){}

Serie::Serie(std::string titulo, std::string tipoVideo, std::string genero, int cal, int anio, int temps, int caps): Video(titulo, tipoVideo, genero, cal, anio){
    this->temporadas = temps;
    this->capitulos = caps;
}

Serie::~Serie(){}

//Setters & Getters
int Serie::getTemporadas() const {
    return temporadas;
}
void Serie::setTemporadas(int temporadas){
    this->temporadas = temporadas;
}

int Serie::getCapitulos() const{
    return capitulos;
}
void Serie::setCapitulos(int capitulos){
    this->capitulos = capitulos;
}

void Serie::muestraDatos(){
    Video::muestraDatos();
    std::cout << "Temporadas: " << getTemporadas() << std::endl;
    std::cout << "Capitulos: " << getCapitulos() << std::endl;
}