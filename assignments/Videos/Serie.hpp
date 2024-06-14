#pragma once
#include <string.h>
#include "Video.hpp"

class Serie: public Video{
    public:
        Serie();
        Serie(std::string, std::string, std::string, int, int, int, int);
        ~Serie();

        int getTemporadas() const;
        void setTemporadas(int);

        int getCapitulos() const;
        void setCapitulos(int);

        void muestraDatos() override;
        
    private:
        int temporadas, capitulos;
};