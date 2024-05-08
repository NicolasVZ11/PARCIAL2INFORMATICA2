#include "red.h"

red::red(string* nombre)
{
    Nombre = *nombre;

    Lineas = new linea[1];
    Lineas[0] = linea();

    EndLineas = &(Lineas[0]);
}

string red::GetNombre(void)
{
    return Nombre;
}

void red::SetNombre(string* nombre)
{
    Nombre = *nombre;
}

bool red::ExisteLinea(string* linea)
{
    for(short int i=0; &(Lineas[i])==EndLineas; i++)
    {
        if(Lineas[i].GetNombre() == *linea)
        {
            return true;
        }
    }

    if((*EndLineas).GetNombre() == *linea)
    {
        return true;
    }

    return false;
}

bool red::ExisteEstacion(string* estacion)
{
    for(short int i=0; &(Lineas[i])==EndLineas; i++)
    {
        if(Lineas[i].BuscarEstacion(estacion) == true)
        {
            return true;
        }
    }

    if((*EndLineas).BuscarEstacion(estacion) == true)
    {
        return true;
    }

    return false;
}

bool red::EstacionEnLinea(string* estacion, string* linea)
{
    for(short int i=0; &(Lineas[i])==EndLineas; i++)
    {
        if(Lineas[i].GetNombre() == *linea)
        {
            if(Lineas[i].BuscarEstacion(estacion) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    if((*EndLineas).GetNombre() == *linea)
    {
        if((*EndLineas).BuscarEstacion(estacion) == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool red::EsTransferencia(string* estacion)
{
    for(short int i=0; &(Lineas[i])==EndLineas; i++)
    {
        if(Lineas[i].BuscarEstacion(estacion) == true)
        {
            return Lineas[i].EstacionTransferencia(estacion);
        }
    }

    if((*EndLineas).BuscarEstacion(estacion) == true)
    {
        return (*EndLineas).EstacionTransferencia(estacion);
    }

    return false;
}

bool red::Transferencia(string* linea)
{
    for(short int i=0; &(Lineas[i])==EndLineas; i++)
    {
        if(Lineas[i].GetNombre() == *linea)
        {
            return Lineas[i].TieneTransferencia();
        }
    }

    if((*EndLineas).GetNombre() == *linea)
    {
        return (*EndLineas).TieneTransferencia();
    }

    return false;
}

void red::AddLinea(linea* Linea, estacion* estacionTransferencia) //FALTA HACER QUE LA ESATACIÓN SEA DE TRANFERENCIA EN LAS DEMAS LINEAS.
{
    if(Lineas[0].EsVacio() == true)
    {
        Lineas[0] = *Linea;
        return;
    }

    string Aux = estacionTransferencia->GetNombre();

    for(short int i=0; &(Lineas[i])==EndLineas; i++)
    {
        if(Lineas[i].BuscarEstacion(&Aux) == true)
        {
            Lineas[i].NombreTransferencia(&Aux); //CONVERTIR A TRANSFERENCIA
        }
    }

    if((*EndLineas).BuscarEstacion(&Aux) == true)
    {
        (*EndLineas).NombreTransferencia(&Aux); //CONVERTIR A TRANSFERENCIA
    }

    Aux = "-1";

    if((*EndLineas).EsVacio() == true)
    {
        for(short int i=0; &(Lineas[i])==EndLineas; i++)
        {
            if(i==0)
            {
                if(Lineas[i].EsVacio() == true)
                {
                    Lineas[i] = *Linea;
                    Lineas[i].AddEstacion(estacionTransferencia, &Aux);

                    Aux = (*estacionTransferencia).GetNombre();

                    Lineas[i].NombreTransferencia(&Aux);

                    Transferencias++;

                    break;
                }
            }

            if(Lineas[i+1].EsVacio() == true)
            {
                Lineas[i+1] = *Linea;
                Lineas[i+1].AddEstacion(estacionTransferencia, &Aux);

                Aux = (*estacionTransferencia).GetNombre();

                Lineas[i+1].NombreTransferencia(&Aux);

                Transferencias++;

                break;
            }
        }
    }
    else
    {
        short int contador = 0;
        linea* AuxLineas;

        for(short int i=0; &(Lineas[i])==EndLineas; i++)
        {
            contador++;
        }

        contador++;

        AuxLineas = new linea[contador+1];

        for(short int i=0; i<contador; i++)
        {
            AuxLineas[i] = Lineas[i];
        }

        AuxLineas[contador] = *Linea;
        AuxLineas[contador].AddEstacion(estacionTransferencia, &Aux);

        Aux = (*estacionTransferencia).GetNombre();

        AuxLineas[contador].NombreTransferencia(&Aux);

        Transferencias++;

        delete[] Lineas;
        Lineas = AuxLineas;
        EndLineas = &(AuxLineas[contador]);
    }
}

void red::DelLinea(string* Linea)
{
    for(short int i=0; &(Lineas[i])==EndLineas; i++)
    {
        if(i==0)
        {
            if(Lineas[i].GetNombre() == *Linea)
            {
                Lineas[i].~linea();

                for(short int j=i; &(Lineas[j])==EndLineas; i++)
                {
                    Lineas[j] = Lineas[j+1];
                }

                (*EndLineas).~linea();
                (*EndLineas) = linea();

                break;
            }
        }

        if(Lineas[i+1].GetNombre() == *Linea)
        {
            Lineas[i+1].~linea();

            for(short int j=(i+1); &(Lineas[j])==EndLineas; i++)
            {
                Lineas[j] = Lineas[j+1];
            }

            (*EndLineas).~linea();
            (*EndLineas) = linea();

            break;
        }
    }
}

void red::AgregarEstacion(string* linea, estacion* Estacion, string* estAnt)
{
    for(short int i=0; &(Lineas[i])==EndLineas; i++)
    {
        if(Lineas[i].GetNombre() == *linea)
        {
            Lineas[i].AddEstacion(Estacion, estAnt);
            break;
        }
    }

    if((*EndLineas).GetNombre() == *linea)
    {
        (*EndLineas).AddEstacion(Estacion, estAnt);
    }
}

void red::BorrarEstacion(string* linea, string* estacion)
{
    for(short int i=0; &(Lineas[i])==EndLineas; i++)
    {
        if(Lineas[i].GetNombre() == *linea)
        {
            Lineas[i].DeltEstacion(estacion);
            break;
        }
    }

    if((*EndLineas).GetNombre() == *linea)
    {
        (*EndLineas).DeltEstacion(estacion);
    }
}

short int red::CantidadLineas(void)
{
    short int contador = 0;

    for(short int i=0; &(Lineas[i])==EndLineas; i++)
    {
        if(i==0)
        {
            if(Lineas[i].EsVacio() != false)
            {
                contador++;
            }
        }

        if(Lineas[i+1].EsVacio() != false)
        {
            contador++;
        }
    }

    contador++;

    return contador;
}

int red::CantdadEstLinea(string* Linea)
{
    for(short int i=0; &(Lineas[i])==EndLineas; i++)
    {
        if(Lineas[i].GetNombre() == *Linea)
        {
            return Lineas[i].CuantasEstaciones();
        }
    }

    if((*EndLineas).GetNombre() == *Linea)
    {
        return (*EndLineas).CuantasEstaciones();
    }

    return false;
}

short int red::CantidadEstaciones(void)
{
    short int contador = 0;

    for(short int i=0; &(Lineas[i])==EndLineas; i++)
    {
        if(i==0)
        {
            if(Lineas[i].EsVacio() != false)
            {
                contador += Lineas[i].CuantasEstaciones();
            }
        }

        if(Lineas[i+1].EsVacio() != false)
        {
            contador += Lineas[i].CuantasEstaciones();
        }
    }

    contador -= Transferencias;

    return contador;
}

int red::CalcularTiempo(string* estSalida, string* estDestino)
{
    for(short int i=0; &(Lineas[i])==EndLineas; i++)
    {
        if(Lineas[i].BuscarEstacion(estSalida) == true)
        {
            if(Lineas[i].BuscarEstacion(estDestino) == true)
            {
                return Lineas[i].TmpEntre(estSalida, estDestino);
            }
        }
    }

    if((*EndLineas).BuscarEstacion(estSalida) == true)
    {
        if((*EndLineas).BuscarEstacion(estDestino) == true)
        {
            return (*EndLineas).TmpEntre(estSalida, estDestino);
        }
    }

    return -1;
}

red::~red()
{
    delete[] Lineas;
}