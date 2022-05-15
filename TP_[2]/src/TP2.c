/*
 ============================================================================
 Name        : trabajo practico 2
 Author      : TERESA FERNANDEZ
 Division    : 1F
 Catedra	 : LABORATORIO I
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "bibliotecaf.h"

#define MAX 2000

int main(void) {

	setbuf(stdout, NULL);

	int opcion;

	Passenger listaPassenger[MAX];//lista de pasajeros

	initPassengers(listaPassenger, MAX);//inicializa-limpia lista

	do
		{

			opcion=menuPrincipal();
			switch(opcion)
			{
			//Alta
				case 1:
					cargarLista(listaPassenger, MAX);
				break;

			//modificar datos
				case 2:
					modificarPasajero(listaPassenger,MAX);
				break;

			//baja
				case 3:
					eliminarPasajero(listaPassenger,MAX);
				break;
			//informar
				case 4:
					menuInforma(listaPassenger,MAX);
				break;
			//carga forzosa
				case 5:
				hardcodearPasajeros(listaPassenger);
				//printPassenger(listaPassenger,MAX);
				break;
		}
		printf("\n");

		}while(opcion!=6);
	return 0;
}
//FIN?
