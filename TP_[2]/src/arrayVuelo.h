/*
 * arrayVuelo.h
 *  teresa fernandez
 */

#ifndef ARRAYVUELO_H_
#define ARRAYVUELO_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
	char flyCode[10];
	int typePassenger;
	int statusFlight;

}eVuelo;

/**
 * @brief pide los datos referidos a los vuelos par luego ser usados en la carga de pasajeros
 *
 * @return variable evuelo
 */
eVuelo cargarVuelo();
#endif /* ARRAYVUELO_H_ */
