/*
 * bibliotecaf.h
 * Author: Teresa Fernandez
 */

#ifndef BIBLIOTECAF_H_
#define BIBLIOTECAF_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "arrayVuelo.h"

/**
 * @brief genera un codigo id de cada pasajero, sea en forma predeterminada o cargada por el usuario
 *
 * @param codigo
 * @return
 */
int generarId(int codigo);
/**
 * @brief pide el ingreso de un Id
 *
 * @return id solicitado
 */
int buscarId();
/**
 * @brief valida que el importe ingresado como flotante sea mayor a 0
 *
 * @param operando numero flotante para ser evaluado
 * @return
 */
float validarImporte(float operando);

/**
 * @brief valida un espacio, que este este ocupado y que el id pasado corresponda a un pasajero
 *
 * @param lista recibe una lista Passenger
 * @param tam tamaño de la lista
 * @param index id a validar
 * @return ocupado= 1 o -1 error
 */
int validarEspacio(Passenger lista[], int tam,int index);

/**
 * @brief   valida un espacio, que este este ocupado y que el id pasado corresponda a un pasajero
 *
 * @param lista recibe una lista Passenger
 * @param tam tamaño de la lista
 * @param index id a validar
 * @return la posicion de el id validado o -1 error
 */
int validarEspacioPosicion(Passenger lista[], int tam, int index);
/**
 * @brief busca un espacio libre y retorna su posicion en la lista
 *
 * @param lista recibe una lista Passenger
 * @param tam tamaño de la lista
 * @return la posicion de el id validado o -1 error
 */
int validarEspacioLibre(Passenger lista[], int tam);

/**
 * @brief valida que haya un espacio ocupado
 *
 * @param lista recibe una lista Passenger
 * @param tam tamaño de la lista
 * @return ocupado=1 o libre=0
 */
int validarEstadoOcupado(Passenger lista[], int tam);

/**
 * @brief se realiza una carga forzosa de la lista pasajeros
 *
 * @param lista recibe la lista Passenger a cargar de manera predeterminada
 */
void hardcodearPasajeros(Passenger lista[]);

/**
 * @brief menu de inicio
 *
 * @return
 */
int menuPrincipal();

/**
 * @brief solicita al usuario la carga de datos por cada pasajero y guarda en una variable pasajero  para luego ser validados y cargados a una lista Passanger
 *
 * @return variable pasajero
 */
Passenger cargarPasajero();

/**
 * @brief valida el retorno de addPassenger para confirmar la continuidad de la carga en la lista
 *
 * @param lista recibe una lista Passenger
 * @param tam tamaño de la lista
 * @return
 */
int cargarLista(Passenger lista[], int tam);

/**
 * @brief muestra por pantalla un pasajero seleccionado,
 *
 * @param lista recibe una lista Passenger
 * @param len tamaño de la lista
 */
void mostrarUnPasajero(Passenger lista[],int len);

/**
 * @brief menu donde se encuentran las opciones a modificar de los datos de un pasajero,sera pedido un id, este validado y luego entrara o no al menu.
 *
 * @param lista recibe una lista Passenger
 * @param len tamaño de la lista
 */
void modificarPasajero(Passenger lista[],int len);
/**
 * @brief llama a las funciones correspondiente para realizar la eliminacion de una pasajero
 *
 * @param lista recibe una lista Passenger
 * @param len tamaño de la lista
 * @return -1
 */
int eliminarPasajero(Passenger lista[], int len);

/**
 * @brief funcion generica para imprimir una operacion que retorne un numero flotate
 *
 * @param mensaje mensaje de interacion con el usuario
 * @param operacion numero flotante para a ser mostrado
 */
void imprimeCuentas(char mensaje[],float operacion);

/**
 * @brief realiza la operacion para saber el importe total de los pasajeros cargados en la lista
 *
 * @param lista recibe una lista Passenger
 * @param len tamaño de la lista
 * @return el resultado de la operacion en numero flotante para luego ser impreso
 */
float importeTotal(Passenger lista[], int len);

/**
  * @brief realiza la operacion para saber el promedio de los importes de los pasajeros cargados en la lista
 *
 * @param lista recibe una lista Passenger
 * @param len tamaño de la lista
 * @return el resultado de la operacion en numero flotante para luego ser impreso
 */
float importePromedio(Passenger lista[], int len);

/**
 * @brief realiza la operacion de contar cuantos pasajeros cargados superan el importe promedio, se imprime la cantidad
 *
 * @param lista recibe una lista Passenger
 * @param len tamaño de la lista
 * @return
 */
int PasajerosMasPromedio(Passenger lista[],int len);

/**
 * @brief menu donde se encuentran las opciones a informar sobre la lista Passenger, este valida la carga de pasajeros y se pued einformar solo si almenos un pasajero fue cargado
 *
 * @param lista recibe una lista Passenger
 * @param len tamaño de la lista
 */
void menuInforma(Passenger lista[],int len);

#endif /* BIBLIOTECAF_H_ */
