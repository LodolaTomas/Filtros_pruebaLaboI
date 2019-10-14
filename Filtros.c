#include "Filtros.h"


float filtro_ContratoMayorPromedio(eElenco* listE,int lenElenco)
{
    float totalSalario;
    int totalElencos;
    float promedioSalario;

    totalSalario = filtro_SalarioAcumuladoElenco(listE, lenElenco);
    totalElencos=filtro_CantidadDeElencos(listE,lenElenco);
    promedioSalario = totalSalario / totalElencos;

    printf("\nEl salario promedio es: %.2f\n", promedioSalario);

    return promedioSalario;
}

float filtro_SalarioAcumuladoElenco(eElenco* listE,int lenElenco)
{
    float retorno=0;
    int i;

    for(i=0; i<lenElenco; i++)
    {
        if(listE[i].estado==OCUPADO)
        {
            retorno+=listE[i].valorContrato;
        }
    }
    return retorno;
}

int filtro_CantidadDeElencos(eElenco* listE,int lenElenco)
{
    int retorno=0;
    int i;

    for(i=0; i<lenElenco; i++)
    {
        if(listE[i].estado==OCUPADO)
        {
            retorno++;
        }
    }

    return retorno;
}

int filtro_CantidadDeActores(eActor* listA,int lenActores)
{
    int retorno=0;
    int i;

    for(i=0; i<lenActores; i++)
    {
        if(listA[i].estado==OCUPADO)
        {
            retorno++;
        }
    }

    return retorno;
}

void filtro_ElencoSuperaPromedio(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG,int promContrato)
{
    int i;
    eActor auxActor;
    ePelicula auxPelicula;
    eGenero auxGenero;

    printf("Los Elencos que lo superan el Contrato promedio son: \n\n");
    printf("\n%30s %20s %25s %20s\n","Pelicula","Genero","Nombre y Apellido","Valor Contrato");
    for (i=0; i<lenElenco; i++)
    {
        if (listE[i].valorContrato > promContrato && listE[i].estado == OCUPADO)
        {
            auxActor=actor_ObtenerActor(listaA,lenA,listE[i].codigoDeActor);
            auxPelicula=pelicula_ObtenerPelicula(listP,lenP,listE[i].codigoDePelicula);
            auxGenero=genero_ObtenerGenero(listG,lenG,auxPelicula.idGenero);
            elenco_MostrarUnElenco(listE[i],auxActor,auxPelicula,auxGenero);
        }
    }
}
/*********************************************************************************************************************************/
void filtro_OrenarPorGenero(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG)
{
    int i,j;
    eActor auxActor;
    ePelicula auxPelicula;
    eGenero auxGenero;

    for(i=0; i<lenG; i++)
    {
        printf("***********************************************************************************************************\n");
        printf("%50s\n",listG[i].descripcion);
        printf("***********************************************************************************************************\n");
        for(j=0; j<lenElenco; j++)
        {
            if(listE[j].estado==OCUPADO)
            {
                auxPelicula=pelicula_ObtenerPelicula(listP,lenP,listE[j].codigoDePelicula);
                auxGenero=genero_ObtenerGenero(listG,lenG,auxPelicula.idGenero);
                if(listG[i].id==auxPelicula.idGenero)
                {

                    auxActor=actor_ObtenerActor(listaA,lenA,listE[j].codigoDeActor);
                    elenco_MostrarUnElenco(listE[j],auxActor,auxPelicula,auxGenero);
                }
            }
        }
    }

}

void filtro_MenorGenero(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG)
{
    int cantGenero[]= {0,0,0,0}; //{"Accion","Terror","Romance","Suspenso"}
    int i;
    int flag=0;
    int minimo;
    int idMinimo;

    filtro_CantidadGenero(listE,lenElenco,listP,lenP,listG,lenG,cantGenero);
    for(i=0; i<lenG; i++)
    {
        if(flag==0 || minimo > cantGenero[i])
        {
            minimo=cantGenero[i];
            flag=1;
        }
    }
    printf("***********************************************************************************************************\n");
    printf("\n%30s\n","MINIMO");

    for(i=0; i<lenG; i++)
    {
        if(minimo==cantGenero[i])
        {
            idMinimo=listG[i].id;
            printf("%30s\n",listG[i].descripcion);
            //filtro_MostrarGenero(listE,lenElenco,listaA,lenA,listP,lenP,listG,lenG,idMinimo);
        }
    }
    printf("***********************************************************************************************************\n");
}

void filtro_CantidadGenero(eElenco* listE,int lenElenco,ePelicula* listP,int lenP,eGenero* listG,int lenG,int* cantGeneros)
{
    int i,j;
    ePelicula auxPelicula;

    for(i=0; i<lenG; i++)
    {
        for(j=0; j<lenElenco; j++)
        {
            if(listE[j].estado==OCUPADO)
            {
                auxPelicula=pelicula_ObtenerPelicula(listP,lenP,listE[j].codigoDePelicula);
                if(listG[i].id==auxPelicula.idGenero)
                {
                    cantGeneros[i]+=1;
                }
            }
        }
    }

}
void filtro_MayorGenero(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG)
{
    int cantGenero[]= {0,0,0,0};
    int i;
    int flag=0;
    int maximo;
    int idMAximo;

    filtro_CantidadGenero(listE,lenElenco,listP,lenP,listG,lenG,cantGenero);
    for(i=0; i<lenG; i++)
    {
        if(flag==0 || maximo < cantGenero[i])
        {
            maximo=cantGenero[i];
            flag=1;
        }
    }
    printf("***********************************************************************************************************\n");
    printf("\n%30s\n","MAXIMO");

    for(i=0; i<lenG; i++)
    {
        if(maximo==cantGenero[i])
        {
            idMAximo=listG[i].id;
            printf("%30s\n",listG[i].descripcion);
            //filtro_MostrarGenero(listE,lenElenco,listaA,lenA,listP,lenP,listG,lenG,idMAximo);
        }
    }
    printf("***********************************************************************************************************\n");
}
void filtro_MostrarGenero(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG,int Mmo)
{
    int i;
    ePelicula auxPelicula;
    eActor auxActor;
    eGenero auxGenero;

    for(i=0; i<lenElenco; i++)
    {
        if(listE[i].estado==OCUPADO)
        {
            auxPelicula=pelicula_ObtenerPelicula(listP,lenP,listE[i].codigoDePelicula);
            if(auxPelicula.idGenero==Mmo)
            {
                auxActor=actor_ObtenerActor(listaA,lenA,listE[i].codigoDeActor);
                auxGenero=genero_ObtenerGenero(listG,lenG,auxPelicula.idGenero);
                elenco_MostrarUnElenco(listE[i],auxActor,auxPelicula,auxGenero);
            }
        }
    }
}
