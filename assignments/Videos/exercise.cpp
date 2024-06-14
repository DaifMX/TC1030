#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Pelicula.hpp"
#include "Serie.hpp"

using namespace std;

void fileLoad(vector<Video *> &videos)
{
  string titulo, tipoVideo, genero;
  int calificacion, anioLanzamiento;

  ifstream dataFile("datos.txt");

  while (dataFile >> titulo >> tipoVideo >> genero >> calificacion >> anioLanzamiento)
  {
    if (tipoVideo == "Pelicula")
    {
      string director;
      int duracion;

      dataFile >> director >> duracion;
      videos.push_back(new Pelicula(titulo, tipoVideo, genero, calificacion, anioLanzamiento, director, duracion));
    }
    else
    {
      int temporadas, capitulos;

      dataFile >> temporadas >> capitulos;
      videos.push_back(new Serie(titulo, tipoVideo, genero, calificacion, anioLanzamiento, temporadas, capitulos));
    }
  }
  dataFile.close();
}

int main(void)
{
  vector<Video *> videos;
  fileLoad(videos);

  int menu, cal;

  Pelicula p1("Avengers", "Pelicula", "Superheroes", 0, 2012, "Joss Whedon", 143), test; // Titulo Tipo Genero Cal Año Dtor. Duracion
  Serie s1("Breaking Bad", "Serie", "Substances", 0, 2013, 5, 62);                       // Titulo Tipo Genero Cal Año Temps Eps

  do
  {
    cout << endl
         << "===Menu===" << endl;
    cout << "1) Mostrar por genero" << endl;
    cout << "2) Mostrar por capitulos" << endl;
    cout << "3) Mostrar por calificación" << endl;
    cout << "4) Mostrar videos en la decada del 2010" << endl;
    cout << "5) Calificar video" << endl;
    cout << "6) Cerrar aplicación" << endl;

    cout << "Input: ";
    cin >> menu;
    cout << endl;

    switch (menu)
    {
    case 1:
    {
      string gen;
      cout << endl
           << "Ingrese el genero a filtrar: ";
      cin >> gen;
      cout << endl;

      cout << "===Genero: " << gen << "===" << endl;
      for (const auto &video : videos)
      {
        if (video->getGenero() == gen)
        {
          video->muestraDatos();
        }
      }

      break;
    }

    case 2:
    {
      int numCapitulos;

      cout << "Ingresa un número de capítulos:";
      cin >> numCapitulos;
      cout << "Series con una cantidad de episodios menor a " << numCapitulos << " episodios:" << endl;
      for (const auto &video : videos)
      {
        Serie *serie = dynamic_cast<Serie *>(video);
        if (serie != nullptr && serie->getCapitulos() < numCapitulos)
        {
          serie->muestraDatos();
        }
      }
    }

    case 3:
    {
      int calificacion;
      cout << "Ingresa la calificación:";
      cin >> calificacion;
      cout << "Peliculas con calificacion de " << calificacion << ":" << endl;
      for (const auto &video : videos)
      {
        Pelicula *pelicula = dynamic_cast<Pelicula *>(video);
        if (pelicula != nullptr && pelicula->getCalificacion() >= calificacion)
        {
          pelicula->muestraDatos();
        }
      }
    }
    case 4:
    {
      for (const auto &video : videos)
      {
        Pelicula *pelicula = dynamic_cast<Pelicula *>(video);
        if (pelicula != nullptr && pelicula->getAnioLanzamiento() >= 2010 && pelicula->getAnioLanzamiento() < 2019)
        {
          pelicula->muestraDatos();
        }
      }
    }

    case 5:
      cout << "Ingrese la calificación: ";
      cin >> cal;
      cout << endl;

      p1.calificaVideo(cal);
      break;

    case 6:
      cout << endl
           << "Cerrando aplicación...";
      break;

    default:
      cout << endl
           << "Opción invalida, intente nuevamnete";
    }
  } while (menu != 6);
}