#include "Pelicula.hpp"
#include <string.h>
#include <iostream>

Pelicula::Pelicula(){}

Pelicula::Pelicula(std::string titulo, std::string tipoVideo, std::string genero, int cal, int anio, std::string director, int duracion): Video(titulo, tipoVideo, genero, cal, anio){
    this->director = director;
    this->duracion = duracion;
}

Pelicula::~Pelicula(){};

//Setters & Getters
std::string Pelicula::getDirector() const {
    return director;
}
void Pelicula::setDirector(std::string director){
    this->director = director;
}

int Pelicula::getDuracion() const{
    return duracion;
}
void Pelicula::setDuracion(int duracion){
    this->duracion = duracion;
}

void Pelicula::muestraDatos(){
    Video::muestraDatos();
    std::cout << "Director: " << getDirector() << std::endl;
    std::cout << "Duracion: " << getDuracion() << std::endl;
}