#include "red.h"

Red::Red(string* nombre)
{
   Nombre = *nombre; 
   Lineas = new linea[1];
   EndLineas = Lineas[0];
}

string Red::GetNombre(void)
{
    return Nombre;
}

void Red::SetNombre(string* nombre)
{
    Nombre = *nombre; 
}

void Red::AddLinea(string* nuevaLinea, string* lineaAnt)
{
    
}

void Red::DelLinea(string* Linea)
{

}

int Red::CuantasLineas(void)
{

}

int Red::CalcularTiempo(string* lineaSalida, string* lineaDestino)
{

}

Red::~Red()
{

}