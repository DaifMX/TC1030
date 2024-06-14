#pragma once
#include <string.h>
#include "Video.hpp"

class Pelicula: public Video{
    public:
        Pelicula();
        Pelicula(std::string, std::string, std::string, int, int, std::string, int);
        ~Pelicula();

        std::string getDirector() const;
        void setDirector(std::string);

        int getDuracion() const;
        void setDuracion(int);

        void muestraDatos() override;

    private:
        std::string director;
        int duracion;
};