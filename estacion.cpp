#include "estacion.h"

estacion::estacion() {
    Vacio = true;
}

estacion::estacion(int *tiemposig, int *tiempoant, string *nombre) {
    Tiemposiguiente = *tiemposig;
    Tiempoanterior = *tiempoant;
    Nombre = *nombre;
    Vacio = false;
}

void estacion::SetTiempoAnterior(int *tiempoant) {
    Tiempoanterior = *tiempoant;
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

string estacion::NombreOriginal() {
    size_t posicionGuion = Nombre.find("-");
    if (posicionGuion != string::npos) {
        return Nombre.substr(0, posicionGuion);
    }
    return Nombre; // Si no se encuentra un guion, simplemente devolvemos el nombre original
}

bool estacion::EsVacio() {
    return Vacio; // Devolvemos directamente el valor de Vacio
}

estacion::~estacion() {
    // Destructor de estacion
}
