/*
 * ArrayPassenger.c
 *  teresa fernandez
 */
#include "bibliotecaf.h"
#include "ArrayPassenger.h"

//contador de cantidad de pasajeros
int	contadorPasajero=0;

//inicializa la lista de pasajeros
int initPassengers(Passenger array[], int len)
{
	int i;

	if(array !=NULL){
		if (len >LIBRE) {
			for (i = LIBRE; i < len; i++) {
				array[i].isEmpty=LIBRE;
			}
		}
	}
	return -1;

}

//agrega a lista un pasajero
int addPassenger(Passenger array[], int len)
{
	int index;

	index=validarEspacioLibre(array, len);

		if(index>=0 && index <= len){
		   array[index] = cargarPasajero();
		   contadorPasajero++;
		   return LIBRE;
		}
		else{
			printf("\n*******************************************************************************\n");
			printf("***La lista esta llena***");
			printf("\n*******************************************************************************\n");
		}
	return -1;

}

//busca un pasajero y reorna su index
int FindPassengerById(Passenger lista[],int len,int id)
{
    if(lista != NULL && len>0){
		for(int i=0; i<len; i++){
		   if(lista[i].idPasajero==id && lista[i].isEmpty == OCUPADO){
			   return id;
			   break;
		   }
		}
	}
    return -1;
}

//elimina de manera logica un pasajero
int removePassenger(Passenger lista[],int len,int id)
{
	int i;
	char confirmar;
			for( i=0; i<len; i++ ){
				if( lista[i].idPasajero == id){
					 mostrarUnPasajero(lista, i);
					printf( "\nConfirma borrar pasajero? (S/N):" );
					fflush(stdin);
					scanf("%c", &confirmar);
					confirmar = toupper( confirmar );
					if( confirmar == 'S' ){
						lista[i].isEmpty = -1;
						contadorPasajero--;
						printf("\n*******************************************************************************\n");
						printf("\n****el pasajero ha sido borrado!****\n");
						printf("\n*******************************************************************************\n");
						break;
					}else{
						printf("\n*******************************************************************************\n");
						printf("****el pasajero no ha sido borrado!****");
						printf("\n*******************************************************************************\n");
						break;
					}
				}else{
					printf("\n*******************************************************************************\n");
					printf("\n****el pasajero no existe****\n");
					printf("\n*******************************************************************************\n");
					break;
				}

			}


		return -1;
}

//muestra una lista de pasajeros
int printPassenger(Passenger lista[],int len)
{
	int i;
	printf("\n************************************************************************************\n");
    printf("COD.PASAJERO   NOMBRE     APELLIDO    IMPORTE    COD.VUELO     T.PASAJERO   EST.VUELO \n");
    for(i=0; i<len; i++)
       {

    		if(lista[i].isEmpty==OCUPADO){
    			printf("%5d%16s%12s%12.2f%12s%12d%12d\n",
													   lista[i].idPasajero,
													   lista[i].name,
													   lista[i].lastName,
													   lista[i].price ,
													   lista[i].vuelo.flyCode,
													   lista[i].vuelo.typePassenger,
													   lista[i].vuelo.statusFlight);
    		}

       }
	printf("\n***********************************************************************************\n");
	return 0;
}



// ordena lista de manera ascendente-desendente por apellido y en su defecto tipo de pasajero
int sortPassenger(Passenger lista[],int len, int orden)
{
	int i,j;
	Passenger listaAux;

	if(orden==1){
		for(i=0;i<len-1;i++){
			for( j=i+1;j<len;j++){
				if(strcmp(lista[i].lastName,lista[j].lastName)>0){
					listaAux=lista[i];
					lista[i]=lista[j];
					lista[j]=listaAux;

				}
				else{

					if(strcmp(lista[i].lastName,lista[j].lastName)==0){
						if(lista[i].vuelo.typePassenger<lista[j].vuelo.typePassenger){
							listaAux=lista[i];
							lista[i]=lista[j];
							lista[j]=listaAux;
						}
					}
				}
			}
		}
	}
	else{
		for(i=0;i<len-1;i++){
			for( j=i+1;j<len;j++){
				if(strcmp(lista[i].lastName,lista[j].lastName)< 0){

					listaAux=lista[i];
					lista[i]=lista[j];
					lista[j]=listaAux;

				}
				else{

					if(strcmp(lista[i].lastName,lista[j].lastName)==0){
						if(lista[i].vuelo.typePassenger>lista[j].vuelo.typePassenger){

							listaAux=lista[i];
							lista[i]=lista[j];
							lista[j]=listaAux;
						}
					}
				}
			}
		}
	}
	printPassenger(lista,len);
	return 0;
}


//ordena la lista por codigo de vuelo y en su defecto por estado de vuelo ACTIVO
int sortPassengerByCode(Passenger lista[],int len, int orden)
{
	int i,j;
	Passenger listaAuxDos;

	if(orden==1){
		for(i=0;i<len-1;i++){
			for( j=i+1;j<len;j++){
				if(strcmp(lista[i].vuelo.flyCode,lista[i].vuelo.flyCode)> 0){

					listaAuxDos=lista[i];
					lista[i]=lista[j];
					lista[j]=listaAuxDos;

		}
		else{

				if(strcmp(lista[i].vuelo.flyCode,lista[i].vuelo.flyCode)== 0){
						if(lista[i].vuelo.statusFlight==1){
							listaAuxDos=lista[i];
								lista[i]=lista[j];
								lista[j]=listaAuxDos;
							}
						}
					}
				}
			}
		}
		else{
			for(i=0;i<len-1;i++){
				for( j=i+1;j<len;j++){
					if(strcmp(lista[i].vuelo.flyCode,lista[i].vuelo.flyCode)< 0){

						listaAuxDos=lista[i];
						lista[i]=lista[j];
						lista[j]=listaAuxDos;

				}
				else{

					if(strcmp(lista[i].vuelo.flyCode,lista[i].vuelo.flyCode)== 0){
						if(lista[i].vuelo.statusFlight==1){
							listaAuxDos=lista[i];
							lista[i]=lista[j];
							lista[j]=listaAuxDos;
						}
					}
				}
			}
		}
	}
	printPassenger(lista,len);

	return 0;
}


