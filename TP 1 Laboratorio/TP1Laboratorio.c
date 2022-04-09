//Trabajo Práctico Reyes Francisco DIV D 43.670.739

#include <stdlib.h>
#include <stdio.h>
#include "calculos.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcion=1;
	int kilometrosIngresados;
	int precioVuelo;
	char aerolineaIngresada;

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
			printf("Ingrese los kilometros: ");
			scanf("%d", &kilometrosIngresados);
			break;
		case 2:
			printf("Ingrese el precio del vuelo: ");
			scanf("%d", &precioVuelo);
			printf("Ingrese la aerolinea (y = Aerolineas, z = Latam): \n");
			scanf("%c", &aerolineaIngresada);
			break;
		case 3:
			break;

		}
	}



return 0;
}


