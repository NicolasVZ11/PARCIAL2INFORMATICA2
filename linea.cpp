#include "linea.h"
#include "estacion.h"

linea::linea()
{
    Linea = nullptr;
    fin = nullptr;
    Vacio=true;
}

linea::linea(string *nombre)
{
    Nombre = *nombre;
    Linea = new estacion[2];
    Linea[0] = estacion();
    Linea[1] = estacion();
    fin=&Linea[1];
}

string linea::GetNombre() {
    return Nombre;
}

estacion linea::GetFin() {
    return *fin;
}


void linea::SetNombre(string *nombre)
{
    Nombre = *nombre;
}

void linea::SetFin(estacion *nuevadireccion)
{
    fin = nuevadireccion;
}

void linea::NombreTransferencia(string* nombre)
{
    estacion *puntero = Linea; // Inicializa el puntero al principio del arreglo
    string nuevonombre;
    bool transferencia=true;

    while (puntero != fin) {
        if (puntero->GetNombre() == *nombre)
        {                                                       // Compara el nombre de la estación actual con el nombre buscado
            nuevonombre= puntero->GetNombre();
            nuevonombre+="-";
            nuevonombre+=Nombre;
            puntero->SetNombre(&nuevonombre);
            puntero->SetTransferencia(&transferencia);
        }
        puntero += 1;                                            // Avanza al siguiente elemento del arreglo
    }

    if (puntero->GetNombre() == *nombre)
    {                                                       // Compara el nombre de la estación actual con el nombre buscado
        nuevonombre= puntero->GetNombre();
        nuevonombre+="-";
        nuevonombre+=Nombre;
        puntero->SetNombre(&nuevonombre);
        puntero->SetTransferencia(&transferencia);
    }
}

bool linea::TieneTransferencia()
{
    estacion *puntero = Linea; // Inicializa el puntero al principio del arreglo

    while (puntero != fin) {
        if (puntero->GetTransferencia()) { // Verifica si la estación actual tiene transferencia
            return true; // Si una estación tiene transferencia, retorna verdadero
        }
        puntero +=1; // Avanza al siguiente elemento del arreglo
    }

    if (puntero->GetTransferencia()) { // Verifica si la estación actual tiene transferencia
        return true; // Si una estación tiene transferencia, retorna verdadero
    }
    return false; // Si ninguna estación tiene transferencia, retorna falso
}

bool linea::BuscarEstacion(string *nombreEstacion)
{
    estacion *puntero = Linea; // Inicializa el puntero al principio del arreglo

    while (puntero != fin)
    {
        if (puntero->GetNombre() == *nombreEstacion) { // Compara el nombre de la estación actual con el nombre buscado
            return true; // Si encuentra la estación, retorna verdadero
        }
        puntero += 1; // Avanza al siguiente elemento del arreglo
    }

    if (puntero->GetNombre() == *nombreEstacion) { // Compara el nombre de la estación actual con el nombre buscado
        return true; // Si encuentra la estación, retorna verdadero
    }
    return false; // Si no encuentra la estación, retorna falso
}

int linea::CuantasEstaciones()
{
    estacion *puntero = Linea; // Inicializa el puntero al principio del arreglo
    int contador = 0;

    while (puntero != fin ) {
        if(puntero->EsVacio()== false)
        {
            ++contador;
        }
        puntero += 1;
    }

    if(puntero->EsVacio()== false)
    {
        ++contador;
    }

    return contador;
}

void linea::DeltEstacion(string *nombre, int* tiempo)
{
    estacion* puntero=Linea;
    while(puntero != fin)
    {
        if(puntero->GetNombre() == *nombre)
        {
            (puntero+1)->SetTiempoAnterior(tiempo);
            (puntero-1)->SetTiempoSiguiente(tiempo);
            MoverIzquierda(puntero,fin);
        }
        puntero += 1;
    }
    if(puntero->GetNombre() == *nombre)
    {
        (puntero+1)->SetTiempoAnterior(tiempo);
        (puntero-1)->SetTiempoSiguiente(tiempo);
        MoverIzquierda(puntero,fin);
    }
}
void linea::MoverIzquierda(estacion* inicio, estacion* fin)
{
    // Mover los elementos una posición hacia la izquierda
    estacion* ptr = inicio;
    for (; ptr < fin; ++ptr)
    {
        *(ptr) = *(ptr + 1);
    }
    ptr->~estacion();
    *ptr=estacion();
}

void linea::MoverDerecha(estacion* inicio, estacion* fin)

{
    // Mover los elementos una posición hacia la derecha
    for (estacion* ptr = fin; ptr > inicio; --ptr) {
        *(ptr) = *(ptr - 1);
    }
}

void linea::AddEstacion(estacion* nuevaEstacion, string* estacionante) {
    int espaciosvacios = 0;
    int Tiemposiguiente, Tiempoanterior;

    // Verificar si el arreglo de estaciones está vacío
    if (Linea->EsVacio() == true)
    {
        Linea[0] = *nuevaEstacion; // Si está vacío, asigna la nueva estación como la primera de la línea

    }
    else
    {
        estacion* puntero =Linea; // Inicializa el puntero al principio del arreglo apuntando al primer elemento de arreglo
        while (puntero != fin) {
            if(puntero->EsVacio()== true)
            {
                espaciosvacios+=1;
            }
            puntero += 1;
        }
        if(puntero->EsVacio()== true)
        {
            espaciosvacios+=1;
        }
        if (espaciosvacios != 0)
        {

        }
        else
        {
            int contador = CuantasEstaciones();
            estacion* AuxEstaciones = new estacion[contador + 2];
            for (int i = 0; i < contador; ++i) {
                AuxEstaciones[i] = Linea[i];
            }
            AuxEstaciones[contador+1]=estacion();
            AuxEstaciones[contador]=estacion();
            delete[] Linea;
            Linea = AuxEstaciones;
            fin = &AuxEstaciones[contador+1];
        }

        if (*estacionante == "-1")
        {
            MoverDerecha(Linea, fin);
            Linea[0] = *nuevaEstacion;
            Tiempoanterior = Linea[0].GetTiempoSiguiente();
            Linea[1].SetTiempoAnterior(&Tiempoanterior);
        }

        else if (*estacionante == "1")
        {
            for (int i = 0; i <= CuantasEstaciones(); ++i)
            {
                if (Linea[i].EsVacio() == true)
                {
                    Linea[i] = *nuevaEstacion;
                    Tiempoanterior = nuevaEstacion->GetTiempoAnterior();
                    Linea[i - 1].SetTiempoSiguiente(&Tiempoanterior);
                    break;
                }
            }
        }

        else
        {
            for (int i = 0; i < CuantasEstaciones(); ++i)
            {
                if (Linea[i].GetNombre() == *estacionante)
                {
                    Tiemposiguiente = nuevaEstacion->GetTiempoSiguiente();
                    Tiempoanterior = nuevaEstacion->GetTiempoAnterior();
                    MoverDerecha(&Linea[i+1], fin);
                    Linea[i+1] = *nuevaEstacion;
                    Linea[i].SetTiempoSiguiente(&Tiempoanterior);
                    if(Linea[i+2].EsVacio() == false)
                    {
                        Linea[i+2].SetTiempoAnterior(&Tiemposiguiente);
                    }
                }
            }
        }

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
    while (puntero->EsVacio() == false) {
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
    if (puntero->GetNombre() == *nombre) {           // Compara el nombre de la estación actual con el nombre buscado
        if(puntero->GetTransferencia() == true)
        {
            return true;                        // Si es transferencia retorna verdadero
        }
        else
        {
            return false;                           // Si no es tranferencia retorna falso
        }
    }

    return false;
}

int linea::TmpEntre(string* estSalida, string* estDestino){
    int cuenta=0;

    for(int i=0; i<CuantasEstaciones();i++)
    {
        if ( Linea[i].GetNombre()== *estSalida)
        {                                                                                   // Compara el nombre de la estación actual con el nombre buscado

            cuenta += Linea[i].GetTiempoSiguiente();

            for (int j=1;Linea[i+j].GetNombre()!=*estDestino;j++)
            {
                cuenta += Linea[i+j].GetTiempoSiguiente();
                if (Linea[i+j+1].GetNombre()== *estDestino)                                 //se crea un bluce para identificar la final y de ahi ya sale todo
                {
                    return cuenta;
                }

            }
            return cuenta;
        }
        else if (Linea[i].GetNombre()== *estDestino)
        {                                                                                   // Compara el nombre de la estación actual con el nombre buscado

            cuenta += Linea[i].GetTiempoSiguiente();

            for (int j=1;Linea[i+j].GetNombre()!=*estSalida;j++)
            {
                cuenta += Linea[i+j].GetTiempoSiguiente();

                if (Linea[i+j+1].GetNombre()== *estSalida)                                 //se crea un bluce para identificar la final y de ahi ya sale todo
                {
                    return cuenta;
                }
            }
            return cuenta;
        }
    }
    return cuenta;
}

linea::~linea() {
    // Destructor de linea
    // Aquí puedes liberar la memoria asignada a los nodos de la línea
}