/*
 * Censistas.c
 *
 *  Created on: 21 may. 2022
 *      Author: Fran
 */

#include <stdio.h>
#include <stdlib.h>
#include "Censistas.h"
#include "Viviendas.h"
#include <string.h>

int listarCensistas(Censista* censistas, int tamCen, Vivienda* lista, int len)
{
int i;
int todoOk = -1;

	    if(censistas!=NULL)
	    {
	        if(tamCen>=0)
	        {
	            for(i=0; i<tamCen; i++ )
	            {
	                if(censistas[i].isEmpty == 0)
	                {
	                	ordenarCensista(censistas, tamCen);
	                    printf("\nLEGAJO CENSISTA: %d | NOMBRE: %s | EDAD: %d | TELEFONO: %s | Id Vivienda: %d | Tipo vivienda: %d\n", censistas[i].legajoCensista, censistas[i].nombre, censistas[i].edad, censistas[i].telefono, lista[i].idVivienda, lista[i].tipoVivienda);
	                }
	            }
	            todoOk=0;
	        }
	    }
	    return todoOk;

}

int ordenarCensista(Censista* censistas, int tamCen)
{
    int todoOk = 0;
    Censista auxCensista;

    if( censistas != NULL && tamCen > 0)
    {
        for(int i=0; i < tamCen - 1; i++)
        {
            for(int j= i+1; j < tamCen; j++)
            {
                if( strcmp(censistas[i].nombre, censistas[j].nombre) > 0 )
                {
                    auxCensista = censistas[i];
                    censistas[i] = censistas[j];
                    censistas[j] = auxCensista;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;

}

int buscarCensista(Censista* censistas, int tamCen, int id, int* pIndex)
{
    int todoOk = 0;
    if( censistas != NULL && pIndex != NULL && tamCen > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tamCen; i++)
        {
            if(censistas[i].legajoCensista == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int validarCensista(Censista* censistas, int tamCen, int id)
{
 int esValido = 0;
 int indice;

 if (buscarCensista(censistas, tamCen, id, &indice)){
    if(indice != -1){
        esValido = 1;
    }
 }
 return esValido;
}


