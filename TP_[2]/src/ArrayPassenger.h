/*
 * ArrayPassenger.h
 *  Author: Teresa Fernandez
 */

#ifndef PROTF_H_
#define PROTF_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1

#include "arrayVuelo.h"

typedef struct
{
	int idPasajero;
	char name[51];
	char lastName[51];
	float price;
	int isEmpty;
	eVuelo vuelo;

}Passenger;

/**
 * @brief inicializa en estado libre(0) toda la lista de pasajeros
 *
 * @param array lista Passenger a inicializarpara luego ser cargada con datos de pasajeros
 * @param len tamaño de la lista
 * @return -1 error
 */
int initPassengers(Passenger array[], int len);
/**
 * @brief recibe un indice-espacio libre,si existiera, de validarEspacioLibre()...luego valida que este este entre el rango de tamaño de la lista,
 *si el indice recivido el -1 da por entendido que la lista ya esta cargada en su totalidad. Suma un contador de pasajeros.
 * @param array recibe una lista Passenger que sera cargada
 * @param len tamaño de la lista
 * @return -1 error 0 si las validaciones fueron correctas
 */
int addPassenger(Passenger array[], int len);

/**
 * @brief valida un id recibido, busca que exista y que este cargado
 *
 * @param lista lista Passenger para recorrer y comprobar que el id recibido pertenece a esa lista
 * @param len tamaño de la lista
 * @param id dato que hay que buscar entre los id de los Pasajeros
 * @return retorna el id validado como existente o -1 en caso de error
 */
int FindPassengerById(Passenger lista[],int len,int id);

/**
 * @brief recibe un id el cual busca para generar una eliminacion logica de un pasajero, si este es encontrado, muestra los datos y pide condfirmar la eliminacion
 *
 * @param lista lista Passenger para recorrer y comprobar que el id recibido pertenece a esa lista
 * @param len tamaño de la lista
 * @param id dato que hay que buscar entre los id de los Pasajeros
 * @return -1 error
 */
int removePassenger(Passenger lista[],int len,int id);

/**
 * @brief muestra lista de pasajeros cargados
 *
 * @param lista lista lista Passenger para recorrer
 * @param len tamaño de la lista
 * @return
 */
int printPassenger(Passenger lista[],int len);

/**
 * @brief  ordena lista de manera ascendente-desendente, segun eleccion dada,por apellido y en su defecto tipo de pasajero.
 * luego muestra la lista ordenada de la manera deseada.
 * @param lista lista lista Passenger para recorrer
 * @param len tamaño de la lista
 * @param orden eleccion del usuario
 * @return
 */
int sortPassenger(Passenger lista[],int len,int orden);
/**
 * @brief ordena lista de manera ascendente-desendente, segun eleccion dada,por codigo de vuelo y en su defecto estado de vuelo '1-ACTIVO'.
 * luego muestra la lista ordenada de la manera deseada.
 * @param lista lista lista Passenger para recorrer
 * @param len tamaño de la lista
 * @param orden orden eleccion del usuario
 * @return
 */
int sortPassengerByCode(Passenger lista[],int len,int orden);

#endif /* PROTF_H_ */
