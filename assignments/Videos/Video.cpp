#include "Video.hpp"
#include <iostream>
#include <exception>

//Constructores & Destructor
Video::Video(){
    this->miembros = 0;
    setCalificacion(0);
}

Video::Video(std::string titulo, std::string tipoVideo, std::string genero, int calificacion, int anioLanzamiento){
    this->titulo = titulo;
    this->tipoVideo = tipoVideo;
    this->genero = genero;
    this->calificacion = calificacion;
    this->sumatoriaCal = calificacion;
    this->miembros = 0;
    this->anioLanzamiento = anioLanzamiento;
}

Video::~Video(){}


//Getters & Setters
std::string Video::getTitulo() const{
    return titulo;
} void Video::setTitulo(std::string titulo){
    this->titulo = titulo;
}


std::string Video::getTipoVideo() const{
    return tipoVideo;
}
void Video::setTipoVideo(std::string tipoVideo){
    this->tipoVideo = tipoVideo;
}


std::string Video::getGenero() const{
    return genero;
}
void Video::setGenero(std::string genero){
    this->genero = genero;
}


int Video::getCalificacion() const{
    return calificacion;
}
void Video::setCalificacion(int cal){
    setSumatoriaCal(cal);

    try {
        if (cal < 0) {
            throw std::invalid_argument("La calificación no puede ser menor que 0");
        
        } else if (cal > 100) {
            throw std::invalid_argument("La calificación no puede ser mayor a 100");
        
        } else {
            setMiembros(miembros + 1);
            this->calificacion = getSumatoriaCal() / getMiembros();
        }
        
    } catch (std::invalid_argument &e) {
        std::cerr << e.what();
    }    
}


int Video::getSumatoriaCal() const{
    return sumatoriaCal;
}
void Video::setSumatoriaCal(int cal){
    this->sumatoriaCal = sumatoriaCal + cal;
}


int Video::getAnioLanzamiento() const{
    return anioLanzamiento;
}
void Video::setAnioLanzamiento(int anioLan){
    this->anioLanzamiento = anioLan;
}


int Video::getMiembros() const{
    return miembros;
}
void Video::setMiembros(int miembros){
    this->miembros = miembros;
}


//Overload de Operador
void Video::operator> (const Video& v){
    if(calificacion > v.calificacion){
        std::cout << titulo << " tiene una calificación mayor (" << calificacion << ") que " << v.titulo << " (" << v.calificacion << ")" << std::endl;  
    } else { std::cout << titulo << " NO tiene una calificación mayor (" << calificacion << ") que " << v.titulo << " (" << v.calificacion << ")" << std::endl; }
}

//Metodos
void Video::muestraDatos(){
    std::cout << std::endl << "=====Datos de Video =====" << std::endl;
    std::cout << "Titulo: " << getTitulo() << std::endl;
    std::cout << "Genero: " << getGenero() << std::endl;
    std::cout << "Calificacion: " << getCalificacion() << std::endl;
    std::cout << "Año de lanzamiento: " << getAnioLanzamiento() << std::endl;
    std::cout << "===" << getTipoVideo() << "===" << std::endl;
}

void Video::calificaVideo(int cal){
    setCalificacion(cal);
}