#ifndef LINEA_H
#define LINEA_H
#include "estacion.h"
using namespace std;

class linea
{
private:
    string Nombre;
    estacion *Linea;
    estacion *fin;
    bool Vacio=false;
public:
    linea(string* nombre);
    string GetNombre();
    estacion GetFin();
    void SetVacioLinea();
    void SetNombre(string* nombre);
    void SetFin(estacion* nuevadireccion);
    void SetNombreTransferencia(string* nombre);
    bool TieneTransferencia();
    bool BuscarEstacion(string* nombreEstacion);
    int CuantasEstaciones();
    void DeltEstacion(string*nombre);
    void AddEstacion(estacion* NuevaEstacion, string* estacionante);
    void MoverDerecha(estacion* inicio, estacion* fin);
    bool EstacionTransferencia(string* nombre);
    bool EsVacio();
    int TmpEntre(string* estSalida, string* estDestino);
    ~linea();
};
#endif // LINEA_H
