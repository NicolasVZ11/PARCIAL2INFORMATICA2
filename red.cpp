#include "red.h"

Red::Red(string* nombre)
{
   Nombre = *nombre; 
   Lineas = new Linea[1];
   Lineas[0] = NULL;
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

void Red::AddLinea(Linea* linea, string* estacionTransferencia) //FALTA HACER QUE LA ESATACIÓN SEA DE TRANFERENCIA EN LAS DEMAS LINEAS.
{
    for(short int i=0; Lineas[i]==EndLineas; i++)
    {
        if(Lineas[i].Buscarestacion(estacionTransferencia) == true)
        {
            Lineas[i].hacerTranferencia(estacionTransferencia); //CONVERTIR A TRANSFERENCIA
        }
    }

    if((*EndLineas).Buscarestacion(estacionTransferencia) == true)
    {
         (*EndLineas).hacerTranferencia(estacionTransferencia); //CONVERTIR A TRANSFERENCIA
    }

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
                    Lineas[i] = *linea;
                    Lineas[i].Addestacion(estacionTransferencia, &Extremo, &TmpEst, &TmpEst);
                    Lineas[i].hacerTranferencia(estacionTransferencia);
                    break;
                }
            }
            
            if(Lineas[i+1] == NULL)
            {
                Lineas[i+1] = *linea;
                Lineas[i+1].Addestacion(estacionTransferencia, &Extremo, &TmpEst, &TmpEst);
                Lineas[i+1].hacerTranferencia(estacionTransferencia);
                break;
            }
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
        AuxLineas[contador].Addestacion(estacionTransferencia, &Extremo, &TmpEst, &TmpEst);
        AuxLineas[contador].hacerTranferencia(estacionTransferencia);

        delete[] Lineas;
        Lineas = AuxLineas;
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
                for(short int j=i; Lineas[j]==EndLineas; i++)
                {
                    Lineas[j].~Linea();
                    Lineas[j] = Lineas[j+1];
                }

                *EndLineas = NULL;

                break;
            }
        }

        if(Lineas[i+1].getNombrelinea() == *Linea)
        {
            for(short int j=(i+1); Lineas[j]==EndLineas; i++)
                {
                    Lineas[j].~Linea();
                    Lineas[j] = Lineas[j+1];
                }

                *EndLineas = NULL;

                break;
        }
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

int Red::CalcularTiempo(string* estSalida, string* estDestino)
{
    for(short int i=0; Lineas[i]==EndLineas; i++)
    {
        if(Lineas[i].Buscarestacion(estSalida) == true)
        {
            if(Lineas[i].Buscarestacion(estDestino) == true)
            {
                return Linea[i].TmpEntre(estSalida, estDestino);
            }
        }
    }

    if((*EndLineas).Buscarestacion(estSalida) == true)
    {
        if((*EndLineas).Buscarestacion(estDestino) == true)
        {
            return (*EndLineas).TmpEntre(estSalida, estDestino);
        }
    }

    return -1;
}

Red::~Red()
{
    delete[] Lineas;
}