/*
 * Censistas.h
 *
 *  Created on: 21 may. 2022
 *      Author: Fran
 */

#ifndef CENSISTAS_H_
#define CENSISTAS_H_
typedef struct
{
	int legajoCensista;
	char nombre[25];
	int edad;
	char telefono[10];
	int isEmpty;
}Censista;

int listarCensistas(Censista* censistas, int tamCen, Vivienda* lista, int len);
int ordenarCensista(Censista* censistas, int tamCen);
int validarCensista(Censista* censistas, int tamCen, int id);
int buscarCensista(Censista* censistas, int tamCen, int id, int* pIndex);


#endif /* CENSISTAS_H_ */
