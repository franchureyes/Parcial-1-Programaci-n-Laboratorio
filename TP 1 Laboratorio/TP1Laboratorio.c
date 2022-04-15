//Trabajo Práctico Reyes Francisco DIV D 43.670.739

#include <stdlib.h>
#include <stdio.h>
#include "calculos.h"
#include "mostrar.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcion=1;
	int flag=0;
	float kilometrosIngresados=0;
	float precioAerolinea=0;
	float precioLatam=0;
	float tarjetaDebitoAerolinea;
	float tarjetaDebitoLatam;
	float tarjetaCreditoAerolinea;
	float tarjetaCreditoLatam;
	float bitcoinAerolinea;
	float bitcoinLatam;
	float precioUnitarioAerolinea;
	float precioUnitarioLatam;
	float diferenciaPrecios;
	float diferenciaPreciosForzados;
	int kilometrosForzados=7090;
	int precioAerolineaForzado=162965;
	int precioLatamForzado=159339;


	while(opcion!=6)
	{
		printf("1) Ingresar los kilometros \n"
				"2) Ingresar el precio de vuelo \n"
				"3) Calcular todos los costos \n"
				"4) Informar resultados \n"
				"5) Carga forzada de datos \n"
				"6) Salir \n");

		printf("Ingrese una opcion: ");
		scanf("%d", &opcion);

		switch(opcion)
		{
		case 1:
			do
			{
				printf("Ingrese los kilometros (no puede ingresar 0): ");
				fflush(stdin);
				scanf("%f", &kilometrosIngresados);
			}while(kilometrosIngresados<1);
			break;
		case 2:
			while(precioAerolinea<1)
			{
				printf("Ingrese el precio del vuelo en Aerolineas: ");
				fflush(stdin);
				scanf("%f", &precioAerolinea);
			}

			while(precioLatam<1)
			{
				printf("Ingrese el precio del vuelo en Latam: ");
				fflush(stdin);
				scanf("%f", &precioLatam);
			}

			break;
		case 3:
			if(precioAerolinea>0 && precioLatam>0)
			{
			calcularPrecio(precioAerolinea, kilometrosIngresados, &tarjetaDebitoAerolinea, &tarjetaCreditoAerolinea, &bitcoinAerolinea, &precioUnitarioAerolinea, &flag);
			calcularPrecio(precioLatam, kilometrosIngresados, &tarjetaDebitoLatam, &tarjetaCreditoLatam, &bitcoinLatam, &precioUnitarioLatam, &flag);
			diferenciaPrecios = calcularDiferencia(precioAerolinea, precioLatam);
			}
			else
			{
				printf("No se pueden calcular los precios\n");
			}
			break;
		case 4:
			if(flag==0)
			{
				printf("\n\nTodavia no se calcularon los precios\n\n");
			}
			else
			{
				mostrarResultadosAerolineas(kilometrosIngresados, precioAerolinea, tarjetaDebitoAerolinea, tarjetaCreditoAerolinea, bitcoinAerolinea, precioUnitarioAerolinea);
				mostrarResultadosLatam(precioLatam, tarjetaDebitoLatam, tarjetaCreditoLatam, bitcoinLatam, precioUnitarioLatam);
				mostrarResultadoDiferencia(diferenciaPrecios);
			}

			system("pause");
			break;
		case 5:
			calcularPrecio(precioAerolineaForzado, kilometrosForzados, &tarjetaDebitoAerolinea, &tarjetaCreditoAerolinea, &bitcoinAerolinea, &precioUnitarioAerolinea, &flag);
			calcularPrecio(precioLatamForzado, kilometrosForzados, &tarjetaDebitoLatam, &tarjetaCreditoLatam, &bitcoinLatam, &precioUnitarioLatam, &flag);
			diferenciaPreciosForzados = calcularDiferencia(precioAerolineaForzado, precioLatamForzado);

			mostrarResultadosAerolineas(kilometrosForzados, precioAerolineaForzado, tarjetaDebitoAerolinea, tarjetaCreditoAerolinea, bitcoinAerolinea, precioUnitarioAerolinea);
			mostrarResultadosLatam(precioLatamForzado, tarjetaDebitoLatam, tarjetaCreditoLatam, bitcoinLatam, precioUnitarioLatam);
			mostrarResultadoDiferencia(diferenciaPreciosForzados);

			system("pause");
			break;
		case 6:

			printf("\nGracias por utilizar el programa\n");

			break;
		default:

			printf("Por favor, ingrese una opción del 1 al 6\n\n");

			break;

		}

	}

return 0;
}
