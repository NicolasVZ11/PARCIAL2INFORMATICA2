#ifndef RED_H
#define RED_H

#include <string>
#include "Linea.h"

using namespace std;

class Red
{
private:
    string Nombre;
    Linea* Lineas;
    Linea* EndLineas;

public:
    Red(string* nombre);
    string GetNombre(void);
    void SetNombre(string nombre);
    bool ExisteLinea(string* linea);
    bool ExisteEstacion(string* estacion);
    void AddLinea(Linea* linea, string* estacionTransferencia);
    void DelLinea(string* linea);
    short int CuantasLineas(void);
    int CalcularTiempo(string* lineaSalida, string* lineaDestino);
    ~Red();
};

#endif // RED_H
