#include "estacion.h"
#include "linea.h"

estacion::estacion()
{
    Vacio=true;
}
estacion::estacion(int *tiemposig, int *tiempoant, string *nombre) {
    Tiemposiguiente = *tiemposig;
    Tiempoanterior = *tiempoant;
    Nombre = *nombre;
}
void estacion::SetTiempoAnterior(int *tiempoant) {
    Nombre = *tiempoant;
}
void estacion::SetNombre(string *nombre) {
    Nombre = *nombre;
}

void estacion::SetTiempoSiguiente(int *tiemposig) {
    Tiemposiguiente = *tiemposig;
}

void estacion::SetTransferencia(bool *transfe) {
    Transferencia = *transfe;
}

string estacion::GetNombre() {
    return Nombre;
}

int estacion::GetTiempoSiguiente() {
    return Tiemposiguiente;
}

int estacion::GetTiempoAnterior() {
    return Tiempoanterior;
}

bool estacion::GetTransferencia() {
    return Transferencia;
}

string estacion::NombreOriginal()
{
    string NombreOriginal;
    size_t posicionGuion = Nombre.find("-");

    if (posicionGuion != string::npos)
    {
        NombreOriginal=Nombre.substr(0, posicionGuion);
    }
    return NombreOriginal;
}
bool estacion::EsVacio()
{
    if (Vacio == false)
    {
        return false;
    }
    return true;
}

estacion::~estacion() {
    // Destructor de Estacion
}
