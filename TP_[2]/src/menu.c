/*
 * menu.c
 *
 *  Created on: 9 may. 2022
 *      Author: Fran
 */

#include <stdio.h>
#include <stdlib.h>

int menuPrincipal()
{
	int opcion = 1;

		printf("1-ALTA\n"
				"2-MODIFICAR\n"
				"3-BAJA\n"
				"4-INFORMAR\n"
				"5-SALIR\n");

		printf("Ingrese una opcion: ");
		scanf("%d", &opcion);

	return opcion;
}
