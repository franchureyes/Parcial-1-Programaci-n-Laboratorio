/*
 * Viviendas.c
 *
 *  Created on: 20 may. 2022
 *      Author: Fran
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Viviendas.h"
#include "menu.h"
#include "Censistas.h"
#include <ctype.h>
#include "inputs.h"

int inicializarViviendas(Vivienda* lista, int len)
{
	int i;

		for (i = 0; i<len; i++) {
			lista[i].isEmpty = VACIO;
		}

		return 0;
}

int buscarEspacioLibre(Vivienda* lista,int len, int* pIndex)
{

    int todoOk = 0;
    if( lista != NULL && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i<len; i++)
        {
            if(lista[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaVivienda(Vivienda* lista, int len, char calle[], int cantidadPersonas, int cantidadHabitaciones, int tipoVivienda, int legajoCensista, Censista* censistas, int tamCen, int* pNextId)
{
	int todoOk = 0;
	int indice;
	Vivienda nuevaVivienda;


	    if( lista != NULL && pNextId != NULL && len > 0)
	    {
	        system("cls");
	        printf("    *** Alta Vivienda ***\n\n");
	        buscarEspacioLibre(lista, len, &indice);

	        if(indice == -1)
	        {
	            printf("No hay lugar en el sistema\n");
	        }
	        else
	        {
	            nuevaVivienda.idVivienda = *pNextId;

	            utn_getName(calle, "\nIngrese la calle: ", "Error. Ingrese correctamente la calle.\n", 25);
	            utn_getInt(&cantidadPersonas, "Ingrese la cantidad de personas: ", "Error, ingrese correctamente la cantidad de personas:\n", 1, 100);
	            utn_getInt(&cantidadHabitaciones, "Ingrese la cantidad de habitaciones: ", "Error, Ingrese correctamente la cantidad de habitaciones:\n", 0,100);
	            utn_getInt(&tipoVivienda, "Ingrese el tipo de vivienda (1-CASA, 2-DEPARTAMENTO, 3-CASILLA, 4-RANCHO): ", "Error, Ingrese correctamente el tipo de vivienda:\n",1,4);
	            listarCensistas(censistas, tamCen);
	            utn_getInt(&legajoCensista, "Ingrese el legajo del censista: ", "Error, ingrese un legajo valido.\n", 100, 102);

	            strcpy(nuevaVivienda.calle, calle);
	            nuevaVivienda.cantidadPersonas = cantidadPersonas;
	            nuevaVivienda.cantidadHabitaciones = cantidadHabitaciones;
	            nuevaVivienda.tipoVivienda = tipoVivienda;
	            nuevaVivienda.legajoCensista = legajoCensista;

	            nuevaVivienda.isEmpty = 0;

	            lista[indice] = nuevaVivienda;

	            (*pNextId)++;

	            todoOk = 1;
	        }
	    }
	    return todoOk;
	}

int validarVivienda(Vivienda* lista, int len, int id)
{
    int esValido = 0;
    int indice;

    if (buscarVivienda(lista, len, id, &indice) )
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}

int buscarVivienda(Vivienda* lista, int len, int id, int* pIndex)
{
    int todoOk = 0;
    if( lista != NULL && pIndex != NULL && len > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < len; i++)
        {
            if( !lista[i].isEmpty  && lista[i].idVivienda == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int listarViviendas(Vivienda* lista, int len)
{
	int i;
	int todoOk = -1;

		    if(lista!=NULL)
		    {
		        if(len>=0)
		        {
		            for(i=0; i<len; i++ )
		            {
		                if(lista[i].isEmpty == 0)
		                {
		                	ordenarViviendasPorCalle(lista, len);
		                    printf("\nID: %d | CALLE: %s | CANTIDAD DE PERSONAS: %d | CANTIDAD DE HABITACIONES: %d | TIPO DE VIVIENDA: %d | LEGAJO DEL CENSISTA: %d\n", lista[i].idVivienda, lista[i].calle, lista[i].cantidadPersonas, lista[i].cantidadHabitaciones, lista[i].tipoVivienda, lista[i].legajoCensista);
		                }
		            }
		            todoOk=0;
		        }
		    }
		    return todoOk;

}

int modificarVivienda(Vivienda* lista, int len)
{
	int idAUsar;
	int indiceVivienda;
	int opcion;
	int retorno = 0;
	int indice;

	printf("Ingresar el id de la vivienda a modificar");
	fflush(stdin);
	scanf("%d", &idAUsar);

	indiceVivienda = buscarVivienda(lista, len, idAUsar, &indice);

	while(indiceVivienda == -1)
	{
		printf("Error, no se encontro la vivienda\n");
		printf("Ingresar el id de la vivienda a modificar");
		fflush(stdin);
		scanf("%d", &idAUsar);

		indiceVivienda = buscarVivienda(lista, len, idAUsar, &indice);

	}

	do
	{

		printf("1-Modificar calle\n"
			"2-Modificar cantidad de personas\n"
			"3-Modificar cantidad de habitaciones\n"
			"4-Modificar tipo de vivienda\n"
			"5-Salir\n");

			printf("Ingrese una opcion: ");
			scanf("%d", &opcion);

			switch(opcion)
			{
			case 1:
				printf("Ingrese la nueva calle\n");
				fflush(stdin);
				scanf("%s", lista[indiceVivienda].calle);
				retorno = 1;
				break;
			case 2:
				printf("Ingrese la nueva cantidad de personas\n");
				fflush(stdin);
				scanf("%d", &lista[indiceVivienda].cantidadPersonas);
				retorno = 1;
				break;
			case 3:
				printf("Ingrese la nueva cantidad de habitaciones");
				fflush(stdin);
				scanf("%d", &lista[indiceVivienda].cantidadHabitaciones);
				retorno = 1;
				break;
			case 4:
				printf("Ingrese el nuevo tipo de vivienda");
				fflush(stdin);
				scanf("%d", &lista[indiceVivienda].tipoVivienda);
				retorno = 1;
				break;
			case 5:
				printf("Modificacion finalizada\n");
				retorno = 1;
				break;
			}

	}while(opcion!=5);

	return retorno;
}

int borrarVivienda(Vivienda* lista, int len, Censista* censistas, int tamCen, eTipoDeVivienda* tipo, int tamTipo)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if( lista != NULL && len > 0)
    {
    	listarViviendas(lista, len);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if( buscarVivienda(lista, len, id, &indice))
        {

            if(indice == -1)
            {
                printf("No existe una vivienda con id: %d en el sistema\n", id);
            }
            else
            {
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {
                    lista[indice].isEmpty = 1;
                    printf("Baja exitosa!!!\n");
                }
                else
                {
                    printf("Baja cancelada por el usuario\n");
                }

            }

            todoOk = 1;
        }
    }
    return todoOk;
}

int ordenarViviendasPorCalle(Vivienda* lista, int len)
{
	int todoOk = 0;
	    Vivienda auxVivienda;

	    if( lista != NULL && len > 0)
	    {
	        for(int i=0; i < len - 1; i++)
	        {
	            for(int j= i+1; j < len; j++)
	            {
	                if( strcmp(lista[i].calle, lista[j].calle) > 0 )
	                {
	                    auxVivienda = lista[i];
	                    lista[i] = lista[j];
	                    lista[j] = auxVivienda;
	                }
	                if(strcmp(lista[i].calle, lista[j].calle)==0)
	                {
	                	if(lista[i].cantidadPersonas>lista[j].cantidadPersonas)
						{
							auxVivienda = lista[i];
							lista[i] = lista[j];
							lista[j] = auxVivienda;
						}
					}

	            }
	        }
	        todoOk = 1;
	    }
	    return todoOk;
}
