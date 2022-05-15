/*
 * bibliotecaf.c
 *  Author:Teresa Fernandez
 */

#include "bibliotecaf.h"
#define LEN_HARCODEO 5

int id=111;
//genera un ID
int generarId(int codigo)
{

	codigo++;
	return codigo;
}

//pide y retorna un id
int buscarId()
{
	int index;
	printf("\nCodigo de pasajero a buscar: ");
	scanf("%d", &index);
	return index;
}

//valida que un numero flotante sea mayor a 0
float validarImporte(float operando)
{
	while(operando<0){
		printf("por favor, ingrese un importe valido...\n");
		printf("precio: ");
		scanf("%f", &operando);
	}
	return operando;
}

//valida que un espacio especifico este ocupado
int validarEspacio(Passenger lista[], int tam, int index)
{
	int i;

	for( i=0; i<tam; i++ ){
		if(lista[i].isEmpty == OCUPADO && lista[i].idPasajero==index ){
			return OCUPADO;
		}
	}

	return -1;
}
//valida que un espacio especifico este ocupado y corresponda a un pasajero para retornar su posicion en la lista
int validarEspacioPosicion(Passenger lista[], int tam, int index)
{
	int i;

	for( i=0; i<tam; i++ ){
		if(lista[i].isEmpty == OCUPADO && lista[i].idPasajero==index ){
			return i;
		}
	}

	return -1;
}

//valida que un espacio de la lista este libre y retorna su indice
int validarEspacioLibre(Passenger lista[], int tam)
{
	int i;

	for( i=0; i<tam; i++ ){
		if(lista[i].isEmpty == LIBRE){
			return i;
		}
	}

	return -1;
}

//valida que por lo menos uno de los estados de la lista este cargado para luego operar
int validarEstadoOcupado(Passenger lista[], int tam)
{
	int i;
	if(lista != NULL && tam >0){
		for( i=0; i<tam; i++ ){
			if(lista[i].isEmpty==OCUPADO){
				return OCUPADO;
				}
			}
		}
	return LIBRE;
}

//harcodeo de lista forzada
void hardcodearPasajeros(Passenger lista[])
{
	int i;
	char nombre[][51]= {"SAKURA","SHAORAN","MAI","TOMOYO","TOUYA"};
	char apellido[][51]={"KINOMOTO","LEE","LEE","DAIDOUSHI","KINOMOTO"};
	float precio[]= {250,320,150,600,250};
	char codVuelo[][10]={"AR1234","AR1234","BR4567","CH4789","FR4862"};
	int tipoPas[]={3,3,1,1,2};
	int estado[]={1,1,2,3,1};

	for(i=0; i<LEN_HARCODEO; i++)
	{
		id=generarId(id);
		lista[i].idPasajero=id;
		strcpy(lista[i].name, nombre[i]);
		strcpy(lista[i].lastName, apellido [i]);
		lista[i].price = precio[i];
		strcpy(lista[i].vuelo.flyCode, codVuelo[i]);
		lista[i].vuelo.typePassenger=tipoPas[i];
		lista[i].vuelo.statusFlight=estado[i];

		lista[i].isEmpty = OCUPADO;
	}

	printPassenger(lista,LEN_HARCODEO);

}
//menu principal en el main
int menuPrincipal()
{

	int opcion;
	printf("****Administrar pasajero****");
	printf("\n\n1. Alta de pasajero");
	printf("\n2. Modificar datos de pasajero ");
	printf("\n3. Baja de pasajero ");
	printf("\n4. Informar");
	printf("\n5. Forzar lista");
	printf("\n6. Salir");
	printf("\n\nOpcion: ");
	scanf("%d", &opcion);

	return opcion;
}


//pide datos de pasajeros para luego retornarlos como variable de estructura.Pasa a mayusculas los caracteres alfabeticos
Passenger cargarPasajero()
{
	Passenger pasajero;
	char nombre[51];
	char apellido[51];
	float precio;

		printf("**Cargar datos del pasajero***\n");
		id=generarId(id);
		pasajero.idPasajero=id;
		printf("Ingrese nombre: ");
		fflush(stdin);
		scanf("%[^\n]",nombre);
		strcpy(pasajero.name, strupr(nombre));
		printf("Ingrese apellido: ");
		fflush(stdin);
		scanf("%[^\n]",apellido);
		strcpy(pasajero.lastName, strupr(apellido));
		//pasajero.lastName=strupr(apellido);
		printf("Ingrese precio del vuelo: ");
		scanf("%f",&precio);
		precio=validarImporte(precio);
		pasajero.price=precio;

		pasajero.vuelo=cargarVuelo();

		pasajero.isEmpty=OCUPADO;

		return pasajero;
}

//recibe de a un pasajero y lo agrega a una lista
int cargarLista(Passenger lista[], int tam)
{
	char confirmar;
	int agregar;

	do{
		agregar=addPassenger(lista, tam);
		if(agregar==LIBRE){
			printf("\nagregar otro pasajero? S/N:");
			fflush(stdin);
			scanf("%c", &confirmar);
			confirmar=toupper(confirmar);
		}
		else{
			confirmar='N';
		}

	}while(confirmar=='S');

	return -1;
}

//muestra un pasajero en especifico
void mostrarUnPasajero(Passenger lista[],int len)
{

	printf("\n************************************************************************************\n");
	printf("COD.PASAJERO   NOMBRE     APELLIDO    IMPORTE    COD.VUELO     T.PASAJERO   EST.VUELO \n");
	printf("%5d%16s%12s%12.2f%12s%12d%12d\n",
											   lista[len].idPasajero,
											   lista[len].name,
											   lista[len].lastName,
											   lista[len].price,
											   lista[len].vuelo.flyCode,
											   lista[len].vuelo.typePassenger,
											   lista[len].vuelo.statusFlight);
	printf("\n***********************************************************************************\n");

}


//modifica los datos de un pasajero
void modificarPasajero(Passenger lista[],int len)
{
	int opcion;
	int index;
	int rtn;
	index=buscarId();
	index=FindPassengerById(lista,len,index);
	rtn=validarEspacio(lista,len,index);

	if(rtn==OCUPADO){
		do
		{
			printf("\n**Modificar datos**");
			printf("\n\n1. Nombre");
			printf("\n2. Apellido");
			printf("\n3. Importe");
			printf("\n4. Tipo de pasajero");
			printf("\n5. Codigo de vuelo");
			printf("\n6. Salir");
			printf("\n\nOpcion");
			scanf("%d", &opcion);

			switch(opcion)
			{
				case 1:
					printf("Nombre: ");
					fflush(stdin);
					scanf("%[^\n]", lista[index].name);
				break;
				case 2:
					printf("Apellido: ");
					fflush(stdin);
					scanf("%[^\n]", lista[index].lastName);
				break;
				case 3:
					printf("Importe: ");
					scanf("%f", &lista[index].price);
					break;
				case 4:
					printf("Tipo de pasajero: ");
					scanf("%d", &lista[index].vuelo.typePassenger);
				break;
				case 5:
					printf("Codigo de vuelo: ");
					scanf("%c", lista[index].vuelo.flyCode);
				break;
				case 6:
					printf("Saliendo de la modificacion");
					break;
				default:
					printf("la opcion ingresada no existe...");
			}

		}while(opcion!=6);
	}
	else{
		printf("\n*******************************************************************************\n");
		printf("**no hay pasajero para informar**");
		printf("\n*******************************************************************************\n");
	}


}

//elimina de manera logica un pasajero
int eliminarPasajero(Passenger lista[], int len)
{
	int index;
	index=buscarId();
	index= FindPassengerById(lista,len,index);
	removePassenger(lista,len,index);
	return -1;
}



//muestra los resultados de las diferentes operaciones
void imprimeCuentas(char mensaje[],float operacion)
{
	printf("\n*********************************************************************************\n");
	printf(mensaje, operacion);
	printf("\n*********************************************************************************\n");
}

//calcula el importe total
float importeTotal(Passenger lista[], int len)
{
	float total;
	int i;

	total=0;

		for(i=0; i<len;i++){

			total+= lista[i].price;
		}
	return total;
}

//clacula el importe promedio
float importePromedio(Passenger lista[], int len)
{
	float acumuladorImp;
	int contador;
	float promedio;
	int i;

	acumuladorImp=0;
	contador=0;

	for(i=0; i<len;i++){

		if(lista[i].isEmpty==OCUPADO){

			acumuladorImp+= lista[i].price;
			contador++;
		}
	}

	promedio=acumuladorImp/contador;
	return promedio;
}

//calcula la cantidad de superan el promedio de los importes
int PasajerosMasPromedio(Passenger lista[],int len)
{
	int i;
	int operando;
	int contadorCaros=0;
	operando=importePromedio(lista,len);
	for(i=0; i<len; i++){

		if(lista[i].isEmpty==OCUPADO && lista[i].price>operando){

			contadorCaros++;
		}
	}
	printf("\n******************************************************************************\n");
	printf("La cantidad de pasajeros que superan el promedio en importes son: %d", contadorCaros);
	printf("\n******************************************************************************\n");
	return contadorCaros;
}


//menu informa
void menuInforma(Passenger lista[],int len)
{
	int opcion;
	int orden;
	int index;
	float operacion;
	int rtn;
	rtn=validarEstadoOcupado(lista,len);
	if(rtn==1){
		do{
				printf("\n****INFORMAR****");
				printf("\n\n1. Mostrar Lista");
				printf("\n2. Mostrar un pasajero");
				printf("\n3. Total de importes");
				printf("\n4. Promedio de importes");
				printf("\n5. Cantidad de pasajeros que superen el promedio");
				printf("\n6. Lista de pasajeros por codigo de vuelo y estado ACTIVO");
				printf("\n7. Lista de pasajeros por apellido y tipo de pasajero");
				printf("\n8. Salir");
				printf("\n\nOpcion: ");
				scanf("%d", &opcion);

			switch(opcion)
			{
					case 1:
						printPassenger(lista,len);
					break;
					case 2:
						index=buscarId();//pide un id pasajero lo retorna
						index=validarEspacioPosicion(lista,len,index);//toma ese codigo de pasajero y retorna su hubicacion en la lista
						mostrarUnPasajero(lista,index);//muestra el pasajero seleccionado
					break;
					case 3:
						operacion=importeTotal(lista,len);
						imprimeCuentas("El total del Importe es: %2.f ",operacion);
					break;
					case 4:
						operacion=importePromedio(lista,len);
						imprimeCuentas("El de los Importes es: %2.f",operacion);
					break;
					case 5:
						PasajerosMasPromedio(lista,len);
					break;
					case 6:
						printf("\n elija orden:\n1-ASENTENTE\n2-DESENDENTE");
						printf("\nopcion: ");
						scanf("%d",&orden);
						sortPassengerByCode(lista,len,orden);
					break;
					case 7:
						printf("\n elija orden:\n1-ASENTENTE\n2-DESENDENTE");
						printf("\nopcion: ");
						scanf("%d",&orden);
						sortPassenger(lista,len,orden);
					break;
					case 8:
						printf("\n****Saliendo de informes****\n");
						printf("\n*******************************************************************************\n");
					break;
					default:
						printf( "\n****la opcion ingresada no existe...****\n");
			}

		}while(opcion!=8);
		printf("\n");
	}
	else{
		printf("\n*******************************************************************************\n");
		printf("**no hay listas para informar**");
		printf("\n*******************************************************************************\n");
	}

}
