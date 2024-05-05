#include "red.h"

Red::Red(string* nombre, short int* cantLineas)
{
   Nombre = *nombre; 
   Lineas = new Linea[*cantLineas];
   EndLineas = Lineas[*cantLineas-1];
}

string Red::GetNombre(void)
{
    return Nombre;
}

void Red::SetNombre(string* nombre)
{
    Nombre = *nombre; 
}

bool Red::ExisteLinea(strng* linea)
{

    for(short int i=0; Lineas[i]==EndLineas; i++)
    {

        if(Lineas[i].getNombrelinea == *linea)
        {
            return true;
        }
    }

    if((*EndLineas).getNombrelinea == *linea)
    {
        return true;
    }

    return false;
}

bool Red::ExisteEstacion(string* estacion)
{
    for(short int i=0; Lineas[i]==EndLineas; i++)
    {
        if(Lineas[i].Buscarestacion(estacion) == true)
        {
            return true;
        }
    }

    if((*EndLineas).Buscarestacion(estacion) == true)
    {
        return true;
    }

    return false;
}

void Red::AddLinea(Linea* linea, string* estacionTransferencia)
{
    string Extremo = "-1";
    short int TmpEst = -1;

    if(*EndLineas == NULL)
    {
        for(short int i=0; Lineas[i]==EndLineas; i++)
        {
            if(i==0)
            {
                if(Lineas[i] == NULL)
                {
                    Lineas[i] = linea;
                    Lineas[i].Addestacion(estacionTransferencia, &Extremo, &TmpEst, &TmpEst);
                }
            }
            
            if(Lineas[i+1] == NULL)
            {
                Lineas[i+1] = linea;
                Lineas[i+1].Addestacion(estacionTransferencia, &Extremo, &TmpEst, &TmpEst);
            }
        }

        if((*EndLineas) == NULL)
        {
            EndLineas = linea;
            (*EndLineas).Addestacion(estacionTransferencia, &Extremo, &TmpEst, &TmpEst);
        }
    }
    else
    {
        short int contador = 0;
        Linea* AuxLineas;

        for(short int i=0; Lineas[i]==EndLineas; i++)
        {
            contador++;
        }

        contador++;

        AuxLineas = new Linea[contador+1];

        for(short int i=0; i<contador; i++)
        {
            AuxLineas[i] = Lineas[i];
        }

        AuxLineas[contador] = *linea;

        EdnLineas = &(AuxLineas[contador]);
    }
}

void Red::DelLinea(string* Linea)
{
    short int aux;

    for(short int i=0; Lineas[i]==EndLineas; i++)
    {
        if(i==0)
        {
            if(Lineas[i].getNombrelinea() == *Linea)
            {
                Aux = i;
                break;
            }
        }

        if(Lineas[i+1].getNombrelinea() == *Linea)
        {
            Aux = i+1;
            break;
        }
    }

    for(short int i=Aux; Lineas[i]==EndLineas; i++)
    {

    }
}

short int Red::CuantasLineas(void)
{
    short int contador = 0;

    for(short int i=0; Lineas[i]==EndLineas; i++)
    {
        
        if(i==0)
        {
            if(Lineas[i] != NULL)
            {
                contador++;
            }
        }

        if(Lineas[i+1] != NULL)
        {
            contador++;
        }
    }

    contador++;

    return contador;
}

int Red::CalcularTiempo(string* lineaSalida, string* lineaDestino)
{

}

Red::~Red()
{

}