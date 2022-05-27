/*
 * Viviendas.h
 *
 *  Created on: 20 may. 2022
 *      Author: Fran
 */

#ifndef VIVIENDAS_H_
#define VIVIENDAS_H_
#define VACIO -1
#include "Censistas.h"

typedef struct
{
	int idVivienda;
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
	int isEmpty;
}Vivienda;

/*typedef struct
{
	int legajoCensista;
	char nombre[25];
	int edad;
	char telefono[10];
	int isEmpty;
}Censista;*/

typedef struct
{
	int tipoVivienda;
	char descripcion[15];
}eTipoDeVivienda;

/// @brief Inicializa los espacios del array en vacío para que se puedan utilizar
///
/// @param lista
/// @param len
/// @return 0 si no hubo error
int inicializarViviendas(Vivienda* lista, int len);

/// @brief Busca espacio libre para poder dar el alta posteriormente
///
/// @param lista
/// @param len
/// @param pIndex
/// @return 0 si no hubo error, 1 si el espacio no esta vacío
int buscarEspacioLibre(Vivienda* lista, int len, int* pIndex);

/// @brief Realiza el alta de la vivienda pidiéndole al usuario que llene los campos e incrementa el ID automáticamente
///
/// @param lista
/// @param len
/// @param calle
/// @param cantidadPersonas
/// @param cantidadHabitaciones
/// @param tipoVivienda
/// @param legajoCensista
/// @param censistas
/// @param tamCen
/// @param pNextId
/// @return 1 si se logro dar el alta, 0 si no se realizó
int altaVivienda(Vivienda* lista, int len, char calle[], int cantidadPersonas, int cantidadHabitaciones, int tipoVivienda, int legajoCensista, Censista* censistas, int tamCen, int* pNextId);

/// @brief Permite la modificación de algún campo de la vivienda que elija el usuario que ya fue cargada
///
/// @param lista
/// @param len
/// @return 1 si se realizó la modificación, 0 si no se hizo
int modificarVivienda(Vivienda* lista, int len);

/// @brief Muestra las viviendas que han sido dadas de alta
///
/// @param lista
/// @param len
/// @return 0 si se mostraron bien, -1 si no se pudo
int listarViviendas(Vivienda* lista, int len);

/// @brief Permite buscar una vivienda por su id para su modificación o su eliminación
///
/// @param lista
/// @param len
/// @param id
/// @param pIndex
/// @return 1 si se encontró una vivienda, 0 si no
int buscarVivienda(Vivienda* lista, int len, int id, int* pIndex);

/// @brief Permite eliminar una vivienda cargada buscándola por su id
///
/// @param lista
/// @param len
/// @param censistas
/// @param tamCen
/// @param tipo
/// @param tamTipo
/// @return 1 si se pudo realizar la eliminación, 0 si no
int borrarVivienda(Vivienda* lista, int len, Censista* censistas, int tamCen, eTipoDeVivienda* tipo, int tamTipo);

/// @brief Permite ordenar las viviendas mostradas por su calle en orden alfabético
///
/// @param lista
/// @param len
/// @return 1 si se pudo ordenar, 0 si no
int ordenarViviendasPorCalle(Vivienda* lista, int len);

/// @brief Permite validar si la vivienda existe o no
///
/// @param lista
/// @param len
/// @param id
/// @return 1 si es válida, 0 si no
int validarVivienda(Vivienda* lista, int len, int id);




#endif /* VIVIENDAS_H_ */

