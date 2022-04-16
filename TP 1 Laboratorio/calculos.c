/*
 * calculos.c
 *
 *  Created on: 8 abr. 2022
 *      Author: Fran
Esta funcion calcula los precios    */

#include <stdio.h>
#include <stdlib.h>

void calcularPrecio(float precio, float kilometros, float* tarjetaDebito, float* tarjetaCredito, float* bitcoin, float* precioUnitario, int* bandera)
{
	float descuentoDebito;
	float aumentoCredito;
	float descuento;
	float interes;
	float valorBitcoin;

	descuentoDebito = 10;
	aumentoCredito = 25;
	valorBitcoin = 4606954.55;
	*bandera = 1;

	descuento = (precio * descuentoDebito) / 100;
	*tarjetaDebito = precio - descuento;
	interes = (precio * aumentoCredito) / 100;
	*tarjetaCredito = precio + interes;

	*bitcoin = precio / valorBitcoin;
	*precioUnitario = precio / kilometros;

}

float calcularDiferencia(float precioA, float precioB)
{
	float resultado;

	if(precioA>precioB)
	{
		resultado = precioA - precioB;
	}
	else
	{
		resultado = precioB - precioA;
	}

	return resultado;
}
