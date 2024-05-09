#ifndef FUNSMENU_H
#define FUNSMENU_H

#include "red.h"

void Menu(void);
void LimpiarTerminal(void);
red* IniciarRed();
void PrimeraLinea(red* Red);
void AgregarEstLinea(red* Red);
void EliminarEstLinea(red* Red);
void CantLineas(red*Red);
void CantEstLinea(red* Red);
void EstLinea(red* Red);
void AniadirLinea(red* Red);
void EliminarLinea(red* Red);
void CantEst(red* Red);
void CalTmpLlegada(red* Red);
void SumarTiempo(int Adicional);

#endif // FUNSMENU_H