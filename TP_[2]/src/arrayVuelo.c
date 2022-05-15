/*
 * arrayVuelo.h

 * Author:Teresa Fernandez
 */

#include "arrayVuelo.h"

//funcion que pide datos conrrespecto a el vuelo, pasa a mayusculas los caracteres alfabeticos
eVuelo cargarVuelo()
{
	eVuelo vuelo;
	char id[10];
		printf("Ingrese codigo de vuelo (ej: AR1689):  ");
		fflush(stdin);
		scanf("%s",id);
		strcpy(vuelo.flyCode, strupr(id));
		printf("***Ingrese tipo de pasajero***");
		printf("\n1- Primera clase");
		printf("\n2- Clase ejecutiva");
		printf("\n3- Clase turista  ");
		printf("\nTipo de pasajero:  ");
		scanf("%d",&vuelo.typePassenger);

		printf("***Ingrese estado del vuelo***");
		printf("\n1- Activo");
		printf("\n2- Demorado");
		printf("\n3- Cancelado  ");
		printf("\nEstado de vuelo:  ");
		scanf("%d",&vuelo.statusFlight);


		return vuelo;
}
