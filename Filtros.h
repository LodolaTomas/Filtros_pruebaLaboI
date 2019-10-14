#include <stdio.h>
#include <stdlib.h>
#include "elenco.h"

float filtro_ContratoMayorPromedio(eElenco* listE,int lenElenco);
float filtro_SalarioAcumuladoElenco(eElenco* listE,int lenElenco);
int filtro_CantidadDeElencos(eElenco* listE,int lenElenco);
int filtro_CantidadDeActores(eActor* listA,int lenActores);
void filtro_ElencoSuperaPromedio(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG,int promContrato);
/*********************************************************************************************************************************/
void filtro_OrenarPorGenero(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG);
void filtro_CantidadGenero(eElenco* listE,int lenElenco,ePelicula* listP,int lenP,eGenero* listG,int lenG,int* cantGeneros);
void filtro_MenorGenero(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG);
void filtro_MayorGenero(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG);
void filtro_MostrarGenero(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG,int Mmo);
