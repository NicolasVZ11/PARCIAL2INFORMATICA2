#ifndef RED_H
#define RED_H

#include <string>
#include "linea"

using namespace std;

class Red
{
private:
    string Nombre;
    linea* Lineas;
    linea* EndLineas;

public:
    Red(string* nombre);
    string GetNombre(void);
    void SetNombre(string nombre);
    void AddLinea(string* nuevaLinea, string* lineaAnt);
    void DelLinea(string* Linea);
    int CuantasLineas(void);
    int CalcularTiempo(string* lineaSalida, string* lineaDestino);
    ~Red();
};

#endif // RED_H
