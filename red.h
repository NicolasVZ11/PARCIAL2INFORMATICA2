#ifndef RED_H
#define RED_H

#include <string>
#include "Linea.h"
#include "Estacion.h"

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
    bool EstacionEnLinea(string* estacion, string* linea);
    bool EsTransferencia(string* estacion);
    bool Transferencia(string* linea);
    void AddLinea(Linea* linea, string* estacionTransferencia);
    void DelLinea(string* linea);
    void AgregarEstacion(string* linea, Estacion* estacion);
    void BorrarEstacion(string* linea, string* estacion);
    short int CuantasLineas(void);
    short int CuantasEstaciones(void);
    int CalcularTiempo(string* estSalida, string* estDestino);
    ~Red();
};

#endif // RED_H
