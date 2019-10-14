#include <stdio.h>
#include <stdlib.h>
#include "Filtros.h"

#define MAX_ACTOR 25
#define MAX_PELI 13
#define MAX_GENE 4
#define MAX_ELENCO 20

int main()
{
    int opcion;
    int idPeliculas=0;
    int idActores=0;
    eActor listaDeActores[MAX_ACTOR];
    ePelicula listaDePeliculas[MAX_PELI];
    eGenero listaDeGenero[MAX_GENE];
    eElenco listaDeElenco[MAX_ELENCO];
    elenco_InicializarElenco(listaDeElenco,MAX_ELENCO);
    elenco_HardcodeElenco(listaDeElenco,10);//OPCIONAL
    genero_hardCodear(listaDeGenero,MAX_GENE);
    pelicula_HardCodeoPeliculas(listaDePeliculas,MAX_PELI,&idPeliculas);
    actor_InicializarActores(listaDeActores,MAX_ACTOR);
    actor_HardCodearActores(listaDeActores,20,&idActores);//OPCIONAL
    do
    {
        getValidInt("1- Promedio de los contrados y las peliculas que ganan mas del promedio\n2- Genero\n3- Actores \n4- Pelicula\n5- Salir\nElija una Opcion: ","Error, solo numeros",1,5,&opcion);
        switch(opcion)
        {
        case 1:
            borrar();
            //elenco_MostarElencos(listaDeElenco,MAX_ELENCO,listaDeActores,MAX_ACTOR,listaDePeliculas,MAX_PELI,listaDeGenero,MAX_GENE);
            //promedio=filtro_ContratoMayorPromedio(listaDeElenco,MAX_ELENCO);
            //filtro_ElencoSuperaPromedio(listaDeElenco,MAX_ELENCO,listaDeActores,MAX_ACTOR,listaDePeliculas,MAX_PELI,listaDeGenero,MAX_GENE,promedio);
            pausa();
            break;
        case 2:
            borrar();
            //filtro_OrenarPorGenero(listaDeElenco,MAX_ELENCO,listaDeActores,MAX_ACTOR,listaDePeliculas,MAX_PELI,listaDeGenero,MAX_GENE);
            //filtro_MenorGenero(listaDeElenco,MAX_ELENCO,listaDeActores,MAX_ACTOR,listaDePeliculas,MAX_PELI,listaDeGenero,MAX_GENE);
            //filtro_MayorGenero(listaDeElenco,MAX_ELENCO,listaDeActores,MAX_ACTOR,listaDePeliculas,MAX_PELI,listaDeGenero,MAX_GENE);
            pausa();
            break;
        case 3:
            borrar();

            pausa();
            break;
        case 4:
            borrar();
            pausa();
            break;
        case 5:

            break;
        }
        borrar();
    }
    while(opcion!=5);
    return 0;
}
