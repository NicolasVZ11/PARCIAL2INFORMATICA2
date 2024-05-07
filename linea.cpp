#include "linea.h"
#include "estacion.h"

linea::linea(string *nombre) {
    Nombre = *nombre;
    Linea = new estacion[2];
    fin = &Linea[1];
}
string linea::GetNombre() {
    return Nombre;
}
estacion linea::GetFin(){
    return *fin;
}

void linea::SetVacioLinea()
{
    Vacio=true;
}

void linea::SetNombre(string *nombre)
{
    Nombre = *nombre;
}

void linea::SetFin(estacion *nuevadireccion)
{
    fin = nuevadireccion;
}

void linea::SetNombreTransferencia(string* nombre){
    estacion *puntero = Linea; // Inicializa el puntero al principio del arreglo
    string nuevonombre;
    bool transferencia=true;
    while (puntero != nullptr) {
        if (puntero->GetNombre() == *nombre) { // Compara el nombre de la estación actual con el nombre buscado
            nuevonombre= puntero->GetNombre();
            nuevonombre+="-";
            nuevonombre+=Linea->GetNombre();
            puntero->SetNombre(&nuevonombre);
            puntero->SetTransferencia(&transferencia);
            break;
        }
        puntero += 1; // Avanza al siguiente elemento del arreglo
    }

}
bool linea::TieneTransferencia()
{
    estacion *puntero = Linea; // Inicializa el puntero al principio del arreglo
    while (puntero != nullptr) {
        if (puntero->GetTransferencia()) { // Verifica si la estación actual tiene transferencia
            return true; // Si una estación tiene transferencia, retorna verdadero
        }
        puntero +=1; // Avanza al siguiente elemento del arreglo
    }
    return false; // Si ninguna estación tiene transferencia, retorna falso
}

bool linea::BuscarEstacion( string *nombreEstacion)
{
    estacion *puntero = Linea; // Inicializa el puntero al principio del arreglo
    while (puntero != nullptr) {
        if (puntero->GetNombre() == *nombreEstacion) { // Compara el nombre de la estación actual con el nombre buscado
            return true; // Si encuentra la estación, retorna verdadero
        }
        puntero += 1; // Avanza al siguiente elemento del arreglo
    }
    return false; // Si no encuentra la estación, retorna falso
}

int linea::CuantasEstaciones()
{
    estacion **puntero = &Linea; // Inicializa el puntero al principio del arreglo
    int contador = 0;
    while (*puntero != nullptr) {
        ++contador;
        puntero += 1;
    }
    return contador;
}

void linea::DeltEstacion(string *nombre) {
    for (int short i=0;i < CuantasEstaciones();i++)
    {
        if(Linea[i].GetNombre() == *nombre)
        {
            if(Linea[i+1].EsVacio() == true)
            {
                Linea[i].~estacion();
                Linea[i]=estacion();
            }
            else
            {
                Linea[i].~estacion();
                Linea[i]=estacion();
                for (estacion* p = Linea + 1; p <= &Linea[CuantasEstaciones()-1]; ++p)
                {
                    *(p - 1) = *p;
                }
                Linea[CuantasEstaciones()-1].~estacion();
                Linea[CuantasEstaciones()-1]=estacion();
            }
        }
    }
}

void linea::AddEstacion(estacion* nuevaEstacion, string *estacionante) {
    int espaciosvacios = 0;
    int Tiemposiguiente, Tiempoanterior;

    // Verificar si el arreglo de estaciones está vacío
    if (Linea == nullptr)
    {
        Linea = nuevaEstacion; // Si está vacío, asigna la nueva estación como la primera de la línea
    }
    else
    {
        estacion **puntero = &Linea; // Inicializa el puntero al principio del arreglo
        while (*puntero != fin) {
            if((*puntero)->EsVacio()== true)
            {
            espaciosvacios+=1;
            }
            puntero += 1;
        }
        if (espaciosvacios != 0)
        {

        }
        else
        {
            short int contador = 0;
            estacion* AuxEstaciones;

            for(short int i=0; &Linea[i]!= fin; i++)
            {
                contador++;
            }
            contador++;
            AuxEstaciones = new estacion[contador+2];
            for(short int i=0; i<contador; i++)
            {
                AuxEstaciones[i] = Linea[i];
            }
            delete[] Linea;
            Linea= AuxEstaciones;
            fin=&(AuxEstaciones[contador]);
        }

        if (*estacionante == "-1")
        {
            MoverDerecha(Linea,fin);
            Linea[0]=*nuevaEstacion;
            Tiempoanterior=Linea[0].GetTiempoSiguiente();
            Linea[1].SetTiempoAnterior(&Tiempoanterior);
        }

        else if (*estacionante == "1")
        {
            for (int short i=0 ; i < CuantasEstaciones(); i++)
            {
                if(Linea[i].EsVacio()== true)
                {
                    Linea[i]=*nuevaEstacion;
                    Tiempoanterior=nuevaEstacion->GetTiempoAnterior();
                    Linea[i-1].SetTiempoSiguiente(&Tiempoanterior);
                    break;
                }
            }
        }

        else
        {
            for (int short i=0 ; i < CuantasEstaciones(); i++)
            {
                if(Linea[i].GetNombre() == *estacionante)
                {
                    Tiemposiguiente=nuevaEstacion->GetTiempoSiguiente();
                    Tiempoanterior=nuevaEstacion->GetTiempoAnterior();
                    MoverDerecha(&Linea[i+1],fin);
                    Linea[i+1]=*nuevaEstacion;
                    Linea[i].SetTiempoSiguiente(&Tiempoanterior);
                    Linea[i+2].SetTiempoAnterior(&Tiemposiguiente);
                }
            }
        }

    }
}

void linea::MoverDerecha(estacion* inicio, estacion* fin) {
    // Mover los elementos una posición hacia la derecha
    for (estacion* ptr = fin; ptr > inicio; --ptr) {
        *(ptr) = *(ptr - 1);
    }
}

bool linea::EsVacio()
{
    if (Vacio == false)
    {
        return false;
    }
    return true;
}

bool linea::EstacionTransferencia(string* nombre)
{
    estacion *puntero = Linea; // Inicializa el puntero al principio del arreglo
    while (puntero != nullptr) {
        if (puntero->GetNombre() == *nombre) { // Compara el nombre de la estación actual con el nombre buscado
            if(puntero->GetTransferencia() == true)
            {
                return true; // Si es transferencia retorna verdadero
            }
            else
            {
                return false; // Si no es tranferencia retorna falso
            }
        }
        puntero += 1; // Avanza al siguiente elemento del arreglo
    }
}

int linea::TmpEntre(string* estSalida, string* estDestino){
    estacion *puntero = Linea; // Inicializa el puntero al principio del arreglo
    int cuenta=0;
    while (puntero != nullptr)
    {
        if (puntero->GetNombre() == *estSalida) { // Compara el nombre de la estación actual con el nombre buscado
            cuenta += puntero->GetTiempoSiguiente();
        }
        if(puntero->GetNombre() == *estDestino){
            cuenta += puntero->GetTiempoAnterior();
        }
        else{
            cuenta += puntero->GetTiempoSiguiente();
        }
        puntero += 1; // Avanza al siguiente elemento del arreglo
    }
    return cuenta;
}
linea::~linea() {
    // Destructor de linea
    // Aquí puedes liberar la memoria asignada a los nodos de la línea
}


