/*
 * inputs.c
 *
 *  Created on: 13 may. 2022
 *      Author: Fran
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"

void rellenarInt(int* variableRecibida, char textoAMostrar[])
{
	printf(textoAMostrar);
	fflush(stdin);
	scanf("%d", variableRecibida);

}

void rellenarFloat(float* variableRecibida, char textoAMostrar[])
{
	printf(textoAMostrar);
	fflush(stdin);
	scanf("%f", variableRecibida);
}

void rellenarArray(char arrayRecibido[], char textoAMostrar[])
{
	printf(textoAMostrar);
	fflush(stdin);
	gets(arrayRecibido);
}
