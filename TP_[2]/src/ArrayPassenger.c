/*
 * ArrayPassenger.c
 *
 *  Created on: 12 may. 2022
 *      Author: Fran
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"



int initPassengers(Passenger *list, int len) {
	int i = 0;

	for (; i < len; i++) {
		list[i].isEmpty = VACIO;
	}

	return 0;
}



int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[])
{
	int i = 0;
		for (; i < len; i++)
		{
			if (list[i].isEmpty == VACIO)
			{
				list[i].isEmpty = 0;
				list[i].id = id;
				list[i].price = price;
				list[i].typePassenger = typePassenger;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				strcpy(list[i].flycode, flycode);

				printf("El id del pasajero es %d\n", id);

				i = len + 1;
			}
		}
    return 0;
}


int findPassengerById(Passenger *list, int len, int id)
{
	int i;
	int posicionADevolver = -1;

	for (i = 0; i < len; i++) {
		if (list[i].id == id) {
			posicionADevolver = i;
			i = len + 1;
		}
	}

	return posicionADevolver;
}

int printPassenger(Passenger* list, int length)
{
int i;
int todoOk = -1;

	    if(list!=NULL)
	    {
	        if(length>=0)
	        {
	            for(i=0; i<length; i++ )
	            {
	                if(list[i].isEmpty == 0)
	                {
	                    printf("\nID: %d | NOMBRE: %s | APELLIDO: %s | PRECIO: %.2f | CODIGO DE VUELO: %s | TIPO DE PASAJERO: %d\n", list[i].id, list[i].name, list[i].lastName, list[i].price, list[i].flycode, list[i].typePassenger);
	                }
	            }
	            todoOk=0;
	        }
	    }
	    return todoOk;

}

int modificarPasajero(Passenger* list, int len)
{
	int idAUsar;
	int indicePasajero;
	int opcion;
	int retorno = 0;

	printf("Ingresar el id de la persona a modificar");
	fflush(stdin);
	scanf("%d", &idAUsar);

	indicePasajero = findPassengerById(list, len, idAUsar);

	while(indicePasajero == -1)
	{
		printf("Error, no se encontro el pasajero\n");
		printf("Ingresar el id de la persona a modificar");
		fflush(stdin);
		scanf("%d", &idAUsar);

		indicePasajero = findPassengerById(list, len, idAUsar);

	}

	do
	{

		printf("1-Modificar nombre\n"
			"2-Modificar apellido\n"
			"3-Modificar precio\n"
			"4-Modificar tipo de pasajero\n"
			"5-Modificar codigo de vuelo\n"
			"6-Salir\n");

			printf("Ingrese una opcion: ");
			scanf("%d", &opcion);

			switch(opcion)
			{
			case 1:
				printf("Ingrese el nuevo nombre\n");
				fflush(stdin);
				scanf("%s", list[indicePasajero].name);
				retorno = 1;
				break;
			case 2:
				printf("Ingrese el nuevo apellido\n");
				fflush(stdin);
				scanf("%s", list[indicePasajero].lastName);
				retorno = 1;
				break;
			case 3:
				printf("Ingrese el nuevo precio");
				fflush(stdin);
				scanf("%f", &list[indicePasajero].price);
				retorno = 1;
				break;
			case 4:
				printf("Ingrese el nuevo tipo de pasajero");
				fflush(stdin);
				scanf("%d", &list[indicePasajero].typePassenger);
				retorno = 1;
				break;
			case 5:
				printf("Modificar el codigo de vuelo");
				fflush(stdin);
				scanf("%s", list[indicePasajero].flycode);
				retorno = 1;
				break;
			case 6:
				printf("Modificacion finalizada\n");
				retorno = 1;
				break;
			}

	}while(opcion!=6);

	return retorno;
}

int removePassenger(Passenger* list, int len, int id)
{
	int retorno = -1;
	if(list != NULL)
	{
		if(len >= 0)
		{
			list[id].isEmpty = VACIO;
			retorno = 0;
		}
	}
	return retorno;
}
