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

		printf("1-ALTA VIVIENDA\n"
				"2-MODIFICAR VIVIENDA\n"
				"3-BAJA VIVIENDA\n"
				"4-LISTAR VIVIENDAS\n"
				"5-LISTAR CENSISTAS\n"
				"6-SALIR\n");

		printf("Ingrese una opcion: \n");
		scanf("%d", &opcion);

	return opcion;
}

