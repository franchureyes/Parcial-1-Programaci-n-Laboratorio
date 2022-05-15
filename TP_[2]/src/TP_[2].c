/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Reyes Francisco Nicolás
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "ArrayPassenger.h"
#include "inputs.h"
#include "utn.h"
#define LEN 2000
#define MAX	3

int main(void) {

	    setbuf(stdout, NULL);
		char salir = 'n';
		int idAux = 0;
		char nameAux[51];
		char lastNameAux[51];
		float priceAux;
		char flycodeAux[10];
		int typePassengerAux;
		int indiceAEliminar;

		Passenger pasajeros[LEN];


	    initPassengers(pasajeros, LEN);

	do{
		switch(menuPrincipal())
		{
		case 1:

			idAux ++;

			rellenarArray(nameAux, "\nIngrese el nombre del pasajero:");

			rellenarArray(lastNameAux, "\nIngrese el apellido del pasajero:");

			rellenarFloat(&priceAux, "\nIngrese el precio del vuelo (no puede ser menor a 0):");

			rellenarArray(flycodeAux, "\nIngrese el codigo de vuelo:");

			rellenarInt(&typePassengerAux, "\nIngrese el tipo de pasajero (1 turista, 2 ejecutivo):");


			addPassenger(pasajeros, LEN, idAux, nameAux, lastNameAux, priceAux, typePassengerAux, flycodeAux);
			break;
		case 2:
			modificarPasajero(pasajeros, LEN);
			break;
		case 3:
			printf("Ingrese el ID del pasajero que desea dar de baja: ");
			fflush(stdin);
			scanf("%d", &idAux);
			indiceAEliminar = findPassengerById(pasajeros, LEN, idAux);
			if (indiceAEliminar > -1)
			{
				if(removePassenger(pasajeros, LEN, indiceAEliminar) == 0)
				{
				printf("\nSe ha dado de baja con exito al pasajero.\n");
				}
				else
				{
				printf("\nHubo un error al intentar dar de baja al pasajero.\n");
				}
			}
			else
			{
				printf("\nEl ID ingresado no coincide con ningún pasajero de la lista.\n\n");
			}
			break;
		case 4:
			printPassenger(pasajeros, LEN);
			break;
		case 5:
			printf("¿Desea salir? (s o n)");
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
	}while(salir != 's');

	return EXIT_SUCCESS;
}
