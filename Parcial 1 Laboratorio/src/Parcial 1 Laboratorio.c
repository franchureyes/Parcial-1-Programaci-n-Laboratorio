/*
 ============================================================================
 Name        : Parcial.c
 Author      : Reyes Francisco Nicolás
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "Viviendas.h"
#include "inputs.h"
#include "Censistas.h"
#define LEN 3
#define TAMCEN 3
#define TAMTIPOVIVIENDA 4

int main(void) {
	setbuf(stdout, NULL);
	int proximoId = 20000;
	int flagOpcion = 0;
	char salir = 'n';
	char calle[25];
	int cantidadPersonas=0;
	int cantidadHabitaciones=0;
	int tipoVivienda=0;
	int legajoCensista=0;

	Vivienda lista[LEN];
	Censista censistas[TAMCEN]=
	{
		{100, "Ana", 34, "1203-2345"},
		{101, "Juan", 24, "4301-54678"},
		{102, "Sol", 47, "5902-37487"}
	};

	eTipoDeVivienda TipoDeViviendaCensada[TAMTIPOVIVIENDA] =  	{{1, "Casa"},
																{2, "Departamento"},
																{3, "Casilla"},
																{4, "Rancho"}};

	inicializarViviendas(lista, LEN);

	do
	{
		switch(menuPrincipal())
		{
		case 1:
			if(altaVivienda(lista, LEN, calle, cantidadPersonas, cantidadHabitaciones, tipoVivienda, legajoCensista, censistas, TAMCEN, &proximoId))
			{
			   printf("***Vivienda cargada con exito***\n");
			}
			else
			{
			   printf("No se pudo cargar la vivienda\n");
			}
			flagOpcion = 1;
		break;
		case 2:
			if(flagOpcion == 1)
			{
				modificarVivienda(lista, LEN);
			}
			else
			{
				printf("No se ingreso ninguna vivienda\n");
			}

			break;
		case 3:
			if(flagOpcion==1)
			{
				borrarVivienda(lista, LEN, censistas, TAMCEN, TipoDeViviendaCensada, TAMTIPOVIVIENDA);
			}
			else
			{
				printf("No se ingreso ninguna vivienda\n");
			}
			break;
		case 4:
			if(flagOpcion==1)
			{
				listarViviendas(lista, LEN);
			}
			else
			{
				printf("No se ingreso ninguna vivienda\n");
			}
			break;
		case 5:
			listarCensistas(censistas, TAMCEN);
			break;
		case 6:
				printf("Desea salir? (s o n)");
				fflush(stdin);
				scanf("%c", &salir);

				while((salir!='s' && salir!='S') && (salir!='n' && salir!='N'))
				{
					printf("Error, letra invalida (responda s o n)\n");
					fflush(stdin);
					scanf("%c",&salir);
				}

			break;

		}
	}while(salir!='s');



	return EXIT_SUCCESS;
}
