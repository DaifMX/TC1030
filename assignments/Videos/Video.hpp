#pragma once
#include <string>

class Video
{
    public:
        Video();
        Video(std::string,std::string, std::string, int, int);
        ~Video();

        //Getters & Setters
        std::string getTitulo() const;
        void setTitulo(std::string);

        std::string getTipoVideo() const;
        void setTipoVideo(std::string);

        std::string getGenero() const;
        void setGenero(std::string);

        int getCalificacion() const;
        void setCalificacion(int);

        int getSumatoriaCal() const;
        void setSumatoriaCal(int);

        int getAnioLanzamiento() const;
        void setAnioLanzamiento(int);

        int getMiembros() const;
        void setMiembros(int);

        //Overload de Operador
        void operator> (const Video&);

        //Metodos
        virtual void muestraDatos() = 0; //Polimorfismo y Clase Abstracta
        void calificaVideo(int);

    private:
        std::string titulo, tipoVideo, genero;
        int calificacion, sumatoriaCal, anioLanzamiento, miembros;
};