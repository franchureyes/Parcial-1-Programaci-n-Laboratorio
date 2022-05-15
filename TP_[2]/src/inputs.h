/*
 * inputs.h
 *
 *  Created on: 13 may. 2022
 *      Author: Fran
 */

#ifndef INPUTS_H_
#define INPUTS_H_

/// @fn void rellenarInt(int*, char[])
/// @brief Pide datos numericos de tipo entero
/// @param variableRecibida
/// @param textoAMostrar
void rellenarInt(int* variableRecibida, char textoAMostrar[]);


/// @fn void rellenarFloat(float*, char[])
/// @brief Pide datos numericos de tipo flotante
/// @param variableRecibida
/// @param textoAMostrar
void rellenarFloat(float* variableRecibida, char textoAMostrar[]);


/// @fn void rellenarArray(char[], char[])
/// @brief Pide datos de tipo cadena de caracteres
/// @param arrayRecibido
/// @param textoAMostrar
void rellenarArray(char arrayRecibido[], char textoAMostrar[]);




#endif /* INPUTS_H_ */
