#include <iostream>
#include <ctime>
#include "FunsMenu.h"

void Menu()
{
    short int opcion;
    red* Red =  IniciarRed();

    do
    {
        cout << "Gestion de red metro " << (*Red).GetNombre() << ". Seleccione entre: " <<
            "\n\n 1.Aniadir estacion a una linea." <<
            "\n 2.Eliminar estacion asociada una linea." <<
            "\n 3.Saber cuantas lineas tiene la red." <<
            "\n 4.Saber cuantas estaciones tiene una linea." <<
            "\n 5.Saber si una estacion pertenece a una linea." <<
            "\n 6.Agregar una linea a la red." <<
            "\n 7.Eliminar una linea de la red." <<
            "\n 8.Saber cuantas estaciones tiene la red." <<
            "\n 9.Calcular tiempo entre estaciones" <<
            "\n 10. Salir.\n\n ";

        cin >> opcion;

        switch(opcion)
        {
        case 1:
        {
            AgregarEstLinea(Red);
            break;
        }
        case 2:
        {
            EliminarEstLinea(Red);
            break;
        }
        case 3:
        {
            CantLineas(Red);
            break;
        }
        case 4:
        {
            CantEstLinea(Red);
            break;
        }
        case 5:
        {
            EstLinea(Red);
            break;
        }
        case 6:
        {
            AniadirLinea(Red);
            break;
        }
        case 7:
        {
            EliminarLinea(Red);
            break;
        }
        case 8:
        {
            CantEst(Red);
            break;
        }
        case 9:
        {
            CalTmpLlegada(Red);
            break;
        }
        case 10:
        {
            LimpiarTerminal();
            delete Red;
            break;
        }
        default:
        {
            LimpiarTerminal();
            cout << "\n*** La opcion ingresada es invalida ***\n\n";
        }
        }

    }while(opcion != 10);

    return;
}

void LimpiarTerminal(void)
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

red* IniciarRed()
{
    string Nombre = "Ejemplo";
    red* Red = new red(&Nombre);

    PrimeraLinea(Red);

    return Red;
}

void PrimeraLinea(red* Red)
{
    string Linea, NEstacion;
    int Tiempo = -1;
    linea* NuevaLinea;
    estacion* Estacion;

    cout << "Ingrese el nombre de la primera linea: ";
    getline(cin, Linea);

    if((*Red).ExisteLinea(&Linea) == false)
    {
        cout << "Ingrese el nombre de la primera estacion: ";
        getline(cin, NEstacion);

        NuevaLinea = new linea(&Linea);
        Estacion = new estacion(&Tiempo, &Tiempo, &NEstacion);

        (*Red).AddLinea(NuevaLinea, Estacion);

        delete NuevaLinea;
        delete Estacion;

        LimpiarTerminal();
        cout << "*** Linea " << Linea << " agregada con exito ***\n";

        return;
    }
    else
    {
        LimpiarTerminal();
        cout << "*** La linea " << Linea << " ya existe en la red ***\n";
        return;
    }
}

void AgregarEstLinea(red* Red)
{
    string Linea, Estacion, EstAnt;
    int TiempoAnt, TiempoSig;
    estacion* NuevaEstacion;

    LimpiarTerminal();

    cout << "Agregar estacion a una linea\n\n Ingrese la linea a la que quiere ingresar la estacion: ";
    getline(cin >> ws, Linea);

    if((*Red).ExisteLinea(&Linea) == true)
    {
        cout << " Ingrese el nombre de la nueva estacion: ";
        getline(cin, Estacion);

        if((*Red).EstacionEnLinea(&Estacion, &Linea) == false)
        {
            cout << " Ingrese el nombre de la estacion previa,'-1' si es extremo izquierdo o '1' si es extremo derecho: ";
            getline(cin, EstAnt);

            if(EstAnt == "-1" || EstAnt == "1")
            {
                cout << " Ingrese el tiempo a la estacion conexa: ";

                if(EstAnt == "-1")
                {
                    cin >> TiempoSig;

                    if(TiempoSig <= 0)
                    {
                        LimpiarTerminal();
                        cout << "*** El tiempo ingresado es invalido ***\n";
                        return;
                    }

                    TiempoAnt = -1;
                }
                else
                {
                    cin >> TiempoAnt;

                    if(TiempoAnt <= 0)
                    {
                        LimpiarTerminal();
                        cout << "*** El tiempo ingresado es invalido ***\n";
                        return;
                    }

                    TiempoSig = -1;
                }

                NuevaEstacion = new estacion(&TiempoSig, &TiempoAnt, &Estacion);

                (*Red).AgregarEstacion(&Linea, NuevaEstacion, &EstAnt);

                delete NuevaEstacion;

                LimpiarTerminal();
                cout << "*** Estacion " << Estacion << " agregada con exito en la linea " << Linea << " ***\n";

                return;
            }
            else if((*Red).EstacionEnLinea(&EstAnt, &Linea) == true)
            {
                cout << " Ingrese el tiempo a la estacion anterior: ";
                cin >> TiempoAnt;
                cout << " Ingrese el tiempo a la estacion siguiente: ";
                cin >> TiempoSig;

                if(TiempoAnt <= 0 || TiempoSig <= 0)
                {
                    LimpiarTerminal();
                    cout << "*** Los tiempos ingresados son invalidos ***\n";
                    return;
                }

                NuevaEstacion = new estacion(&TiempoSig, &TiempoAnt, &Estacion);

                (*Red).AgregarEstacion(&Linea, NuevaEstacion, &EstAnt);

                delete NuevaEstacion;

                LimpiarTerminal();
                cout << "*** Estacion " << Estacion << " agregada con exito en la linea " << Linea << " ***\n";

                return;
            }
            else
            {
                LimpiarTerminal();
                cout << "*** La estacion " << EstAnt << " no existe en la linea " << Linea << " ***\n";
                return;
            }
        }
        else
        {
            LimpiarTerminal();
            cout << "*** La estacion " << Estacion << " ya existe en la linea " << Linea << " ***\n";
            return;
        }
    }
    else
    {
        LimpiarTerminal();
        cout << "*** La linea " << Linea << " no existe en la red ***\n";
        return;
    }
}

void EliminarEstLinea(red* Red)
{
    string Linea, Estacion;
    int Tiempo;

    LimpiarTerminal();

    cout << "Eliminar una estacion de una linea\n\n Ingrese la linea sobre la que se encuentra la estacion: ";
    getline(cin >> ws, Linea);

    if((*Red).ExisteLinea(&Linea) == true)
    {
        cout << " Ingrese el nombre de la estacion que desea eliminar: ";
        getline(cin, Estacion);

        if((*Red).EstacionEnLinea(&Estacion, &Linea) == true)
        {
            cout << " Ingrese el tiempo entre las estaciones conexas: ";
            cin >> Tiempo;

            if(Tiempo > 0)
            {
                if((*Red).EsTransferencia(&Estacion) == false)
                {
                    (*Red).BorrarEstacion(&Linea, &Estacion, &Tiempo);

                    LimpiarTerminal();
                    cout << "*** Estacion " << Estacion << " eliminada con exito de la linea " << Linea << " ***\n";

                    return;
                }
                else
                {
                    LimpiarTerminal();
                    cout << "*** No se puede elimiar la estacion " << Estacion << " porque es de transferencia ***\n";
                    return;
                }
            }
            else
            {
                LimpiarTerminal();
                cout << "*** El tiempo ingresado es invalido ***\n";
                return;
            }
        }
        else
        {
            LimpiarTerminal();
            cout << "*** La estacion " << Estacion << " no existe en la linea " << Linea << " ***\n";
            return;
        }
    }
    else
    {
        LimpiarTerminal();
        cout << "*** La linea " << Linea << " no existe en la red ***\n";
        return;
    }
}

void CantLineas(red*Red)
{
    char aux;

    LimpiarTerminal();

    cout << "*** La red tiene " << (*Red).CantidadLineas() << " lineas ***\n";
    cin >> aux;

    LimpiarTerminal();

    return;
}

void CantEstLinea(red* Red)
{
    string Linea;

    LimpiarTerminal();

    cout << "Saber cuantas estaciones tiene una linea\n\n Ingrese el nombre de la linea: ";
    getline(cin >> ws, Linea);

    if((*Red).ExisteLinea(&Linea) == true)
    {
        cout << "\n*** Hay " << (*Red).CantdadEstLinea(&Linea) << " estaciones en la linea " << Linea << " ***\n";
        cin >> Linea;
        LimpiarTerminal();
        return;
    }
    else
    {
        LimpiarTerminal();
        cout << "*** La linea " << Linea << " no existe en la red ***\n";
        return;
    }
}

void EstLinea(red* Red)
{
    string Linea, Estacion;

    LimpiarTerminal();

    cout << "Saber si una estacion pertenece a una linea\n\n Ingrese el nombre de la estacion: ";
    getline(cin >> ws, Estacion);

    if((*Red).ExisteEstacion(&Estacion) == true)
    {
        cout << " Ingrese el nombre de la linea: ";
        getline(cin, Linea);

        if((*Red).EstacionEnLinea(&Estacion, &Linea) == true)
        {
            cout << "\n***La estacion " << Estacion << " si pertenece a la linea " << Linea << " ***\n";
            cin >> Linea;

        }
        else
        {
            cout << "\n***La estacion " << Estacion << " no pertenece a la linea " << Linea << " ***\n";
            cin >> Linea ;
        }

        LimpiarTerminal();
        return;
    }
    else
    {
        LimpiarTerminal();
        cout << "*** La estacion " << Estacion << " no existe en la red ***\n";
        return;
    }
}

void AniadirLinea(red* Red)
{
    string Linea, EstacionTrans;
    int Tiempo = -1;
    linea* NuevaLinea;
    estacion* EstacionT;

    LimpiarTerminal();

    cout << "Agregar una linea a la red\n\n Ingrese el nombre de la nueva linea: ";
    getline(cin >> ws, Linea);

    if((*Red).ExisteLinea(&Linea) == false)
    {
        cout << " Ingrese la estacion con la que se hara transferencia: ";
        getline(cin, EstacionTrans);

        if((*Red).ExisteEstacion(&EstacionTrans) == true)
        {
            NuevaLinea = new linea(&Linea);
            EstacionT = new estacion(&Tiempo, &Tiempo, &EstacionTrans);

            (*Red).AddLinea(NuevaLinea, EstacionT);

            delete NuevaLinea;
            delete EstacionT;

            LimpiarTerminal();
            cout << "*** Linea " << Linea << " agregada con exito ***\n";

            return;
        }
        else
        {
            LimpiarTerminal();
            cout << "*** No se puede agregar la linea debido a que la estacion " << EstacionTrans << " no existe en la red ***\n";
            return;
        }
    }
    else
    {
        LimpiarTerminal();
        cout << "*** La linea " << Linea << " ya existe en la red ***\n";
        return;
    }
}

void EliminarLinea(red* Red)
{
    string Linea;

    LimpiarTerminal();

    cout << "Eliminar una linea a la red\n\n Ingrese el nombre de la nueva linea: ";
    getline(cin >> ws, Linea);

    if((*Red).ExisteLinea(&Linea) == true)
    {
        if((*Red).Transferencia(&Linea) == false)
        {
            (*Red).DelLinea(&Linea);
            return;
        }
        else
        {
            LimpiarTerminal();
            cout << "*** La linea " << Linea << " no se puede eliminar debido a que contiene transferencias ***\n";
            return;
        }
    }
    else
    {
        LimpiarTerminal();
        cout << "*** La linea " << Linea << " no existe en la red ***\n";
        return;
    }
}

void CantEst(red* Red)
{
    char aux;

    LimpiarTerminal();

    cout << "*** La red tiene " << (*Red).CantidadEstaciones() << " estaciones ***\n";
    cin >> aux;

    LimpiarTerminal();

    return;
}

void CalTmpLlegada(red* Red)
{
    string EstacionSalida, EstacionLlegada;

    LimpiarTerminal();

    cout << "Calcular tiempo entre dos estaciones \n\n Ingrese el nombre de la estacion de salida: ";
    getline(cin >> ws, EstacionSalida);

    if((*Red).ExisteEstacion(&EstacionSalida) == true)
    {
        cout << " Ingrese el nombre de la estacion de llegada: ";
        getline(cin, EstacionLlegada);

        if((*Red).ExisteEstacion(&EstacionLlegada) == true)
        {

            if((*Red).CalcularTiempo(&EstacionSalida, &EstacionLlegada) != -1)
            {
                LimpiarTerminal();
                cout << " Tiempo de salida de la estacion " << EstacionSalida << ": ";
                SumarTiempo(0);
                cout << "\n Tiempo de llegada estimado a la estacion " << EstacionLlegada << ": ";
                SumarTiempo((*Red).CalcularTiempo(&EstacionSalida, &EstacionLlegada));
                cout << "\n\n";

                cin >> EstacionSalida;

                LimpiarTerminal();

                return;
            }
            else
            {
                LimpiarTerminal();
                cout << "*** No se puede calcular debido a que las estaciones no pertenecen a la misma linea ***\n";

                return;
            }
        }
        else
        {
            LimpiarTerminal();
            cout << "*** La estacion " << EstacionLlegada << " no existe en la red ***\n";
            return;
        }
    }
    else
    {
        LimpiarTerminal();
        cout << "*** La estacion " << EstacionSalida << " no existe en la red ***\n";
        return;
    }
}

void SumarTiempo(int Adicional)
{
    time_t now = time(0);
    tm* TiempoActual = localtime(&now);

    TiempoActual->tm_min += Adicional;

    if (TiempoActual->tm_min >= 60) {
        TiempoActual->tm_min -= 60;
        TiempoActual->tm_hour++;
    }

    if (TiempoActual->tm_hour >= 24) {
        TiempoActual->tm_hour -= 24;
    }

    now = mktime(TiempoActual);

    cout << TiempoActual->tm_hour << ":" << TiempoActual->tm_min << ":" << TiempoActual->tm_sec;

    return;
}
