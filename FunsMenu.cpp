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
                AgregarEstLinea();
            }
            case 2:
            {
                EliminarEstLinea();
            }
            case 3:
            {
                
            }
            case 4:
            {
                
            }
            case 5:
            {
                
            }
            case 6:
            {
                
            }
            case 7:
            {
                
            }
            case 8:
            {
                
            }
            case 9:
            {
                
            }
            case 10:
            {
                
            }
        }
            
    }while(opcion != 10);
}

void IniciarRed(red* Red)
{
    string Nombre = "Ejemplo"
    Red = new red(&Nombre);
}

void AgregarEstLinea(red* Red)
{
    
}

void EliminarEstLinea(red* Red)
{

}