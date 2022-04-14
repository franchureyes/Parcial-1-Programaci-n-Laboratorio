/*
 * mostrar.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Fran
 */
#include <stdio.h>
#include <stdlib.h>

/*Esta función muestra los distintos resultados obtenidos*/

void mostrarResultadosAerolineas(float kilometros, float precioAerolinea, float tarjetaDebitoAerolinea, float tarjetaCreditoAerolinea, float bitcoinAerolinea, float precioUnitarioAerolinea)
{
	printf("\nKMs ingresados: %.2f", kilometros);
	printf("\nPrecio Aerolineas: $ %.2f\n\n", precioAerolinea);
	printf("A)Precio con tarjeta de debito: $ %.2f\n", tarjetaDebitoAerolinea);
	printf("B)Precion con tarjeta de credito: $ %.2f\n", tarjetaCreditoAerolinea);
	printf("C)Precio pagando con bitcoin: BTC %f\n", bitcoinAerolinea);
	printf("D)Mostrar precio unitario: $ %.2f\n", precioUnitarioAerolinea);
}

void mostrarResultadosLatam(float precioLatam, float tarjetaDebitoLatam, float tarjetaCreditoLatam, float bitcoinLatam, float precioUnitarioLatam)
{
	printf("\nPrecio Latam: $ %.2f\n\n", precioLatam);
	printf("A)Precio con tarjeta de debito: $ %.2f\n", tarjetaDebitoLatam);
	printf("B)Precion con tarjeta de credito: $ %.2f\n", tarjetaCreditoLatam);
	printf("C)Precio pagando con bitcoin: BTC %f\n", bitcoinLatam);
	printf("D)Mostrar precio unitario: $ %.2f\n\n", precioUnitarioLatam);
}

void mostrarResultadoDiferencia(float diferenciaPrecios)
{
	printf("La diferencia entre los precios es: $ %.2f\n", diferenciaPrecios);
}
