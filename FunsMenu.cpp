#include <iostream>
#include "FunsMenu.h"

void Menu()
{
    short int opcion;
    red* Red;

    IniciarRed(Red);

    do
    {
        cout << "Gestion de red metro " << (*Red).GetNombre() << ". Seleccione entre: " <<
            "\n\n 1.Añadir estacion a una linea." <<
            "\n 2.Eliminar estacion asociada una linea." <<
            "\n 3.Saber cuantas lineas tiene la red." <<
            "\n 4.Saber cuantas estaciones tiene una linea." <<
            "\n 5.Saber si una estacion pertenece a una linea." <<
            "\n 6.Agregar una linea a la red." <<
            "\n 7.Eliminar una linea de la red." <<
            "\n 8.Saber cuantas estaciones tiene la red." <<
            "\n 9.Calcular tiempo entre estaciones" <<
            "\n 10. Salir.";

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
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                break;
            }
            case 7:
            {
                break;
            }
            case 8:
            {
                break;
            }
            case 9:
            {
                break;
            }
            case 10:
            {
                break;
            }
            default:
            {
            LimpiarTerminal();
            cout << "\n*** La opcion ingresada es invalida ***\n\n";
            }
        }
            
    }while(opcion != 10);
}

void LimpiarTerminal(void)
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void IniciarRed(red* Red)
{
    string Nombre = "Ejemplo"
    Red = new red(&Nombre);

}

void AgregarEstLinea(red* Red)
{
    string linea, estacion, estAnt;
    int tiempoAnt, tiempoSig;
    estacion* NuevaEstacion;

    LimpiarTerminal();

    cout << "Agregar estacion a una linea\n\n Ingrese la linea a la que quiere ingresar la estacion: ";
    getline(cin, linea);

    if((*Red).ExisteLinea() == true)
    {
        cout << " Ingrese el nombre de la nueva estacion: ";
        getline(cin, estacion);

        if((*Red).EstacionEnLinea(&estacion, &linea) == false)
        {
            cout << " Ingrese el nombre de la estacion previa,'-1' si es extremo izquierdo o '1' si es extremo derecho: ";
            getline(cin, estAnt);

            if(estAnt !="-1" || estAnt != "1")
            {
                cout << " Ingrese el tiempo a la estacion conexa: ";
                
                if(estAnt == "-1")
                {
                    cin << tiempoSig;
                    tiempoAnt = -1;
                }
                else
                {
                    cin << tiempoAnt;;
                    tiempoSig = -1;
                }

                NuevaEstacion = new estacion(&tiempoSig, &tiempoAnt, &estacion);

                (*Red).AgregarEstacion(&linea, &NuevaEstacion, &estAnt);

                return;
            }
            else if((*Red).EstacionEnLinea(&estAnt, &linea) == true)
            {
                cout << " Ingrese el tiempo a la estacion anterior: ";
                cin >> tiempoAnt;
                cout << " Ingrese el tiempo a la estacion siguiente: ";
                cin >> tiempoSig;

                NuevaEstacion = new estacion(&tiempoAnt, &tiempoSig, &estacion);

                (*Red).AgregarEstacion(&linea, &NuevaEstacion, &estAnt);

                LimpiarTerminal();
                cout << "*** Estacion " << estacion << " agregada con exito en la linea" << linea << " ***\n";

                return;
            }
            else
            {
                LimpiarTerminal();
                cout << "*** La estacion " << estAnt << " no existe en la linea " << linea << " ***\n";
                return;
            }
        }
        else
        {
            LimpiarTerminal();
            cout << "*** La estacion " << estacion << " ya existe en la linea " << linea << " ***\n";
            return;
        }
    }
    else
    {
        LimpiarTerminal();
        cout << "*** La linea " << linea << " no existe en la red ***\n";
        return;
    }
}

void EliminarEstLinea(red* Red)
{
    string linea, estacion;
    
    cout << "Eliminar una estacion de una linea\n\n Ingrese la linea sobre la que se encuentra la estacion: ";
    getline(cin, linea);

    if((*Red).ExisteLinea() == true)
    {
        cout << " Ingrese el nombre de la estacion que desea eliminar: ";
        getline(cin, linea);
    
        if((*Red).EstacionEnLinea(&estacion) == true)
        {
            if((*Red).EsTransferencia(&estacion) == false)
            {
                BorrarEstacion(&linea, &estacion);

                LimpiarTerminal();
                cout << "*** Estacion " << estacion << " eliminada con exito de la linea" << linea << " ***\n";
                
                return;
            }
            else
            {
                LimpiarTerminal();
                cout << "*** No se puede elimiar la estacion " << estacion << " porque es de transferencia ***\n";
                return;
            }
        }
        else
        {
            LimpiarTerminal();
            cout << "*** La estacion " << estacion << " no existe en la linea " << linea << " ***\n";
            return;
        }
    }
    else
    {
        LimpiarTerminal();
        cout << "*** La linea " << linea << " no existe en la red ***\n";
        return;
    }
}