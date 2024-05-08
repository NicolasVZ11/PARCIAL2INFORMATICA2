#ifndef RED_H
#define RED_H

#include "linea.h"

class red
{
private:
    string Nombre;
    short int Transferencias = 0;
    linea* Lineas;
    linea* EndLineas;

public:
    red(string* nombre);
    red(void);
    string getNombre(void);
    void SetNombre(string* nombre);
    bool ExisteLinea(string* linea);
    bool ExisteEstacion(string* estacion);
    bool EstacionEnLinea(string* estacion, string* linea);
    bool EsTransferencia(string* estacion);
    bool Transferencia(string* linea);
    void AddLinea(linea* Linea, estacion* estacionTransferencia);
    void DelLinea(string* linea);
    void AgregarEstacion(string* linea, estacion* Estacion, string* estAnt);
    void BorrarEstacion(string* linea, string* estacion);
    short int CantidadLineas(void);
    short int CantidadEstaciones(void);
    int CalcularTiempo(string* estSalida, string* estDestino);
    ~red();
};

#endif // RED_H
