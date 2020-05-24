#include "centroC.h"

/* Funcion de ejemplo que imprimiria la informacion de un local */
void mostrarLocal(local_t ** centroComercial,int fil, int col, int numPiso, int numLocalxPiso ) {
	//Se valida si el numero ingresado esta en el rango	
	if(numPiso<= fil && numLocalxPiso <= col  ){
	//Se valida si la tienda esta abierta 
	   if( centroComercial[numPiso][numLocalxPiso].disp == 1 ){
		printf("\nNombre local : %s\n", centroComercial[numPiso][numLocalxPiso].nombreLocal);
		printf("Numero local : %d \n", centroComercial[numPiso][numLocalxPiso].numLocalxPiso);
		printf("ID del local : %d \n", centroComercial[numPiso][numLocalxPiso].idLocal);
		printf("El local tiene %d empelados trabajando \n", centroComercial[numPiso][numLocalxPiso].empleados);
	   }
	   else{
	  	printf( "La tienda esta cerrada no se puede mostrar \n" );
	   }	 
	}
}

void mostrarLocalesAbiertos(local_t ** centroComercial,int fil,int col){
	int i, j;
	for( i = 0; i < fil; i++ ){
      	    for( j = 0; j < col; j++ ){
		if( centroComercial[i][j].disp == 1 ){
			printf("\nNombre local : %s\n", centroComercial[i][j].nombreLocal);
		}
	    }
   	}

}

local_t ** reservaDinamica( int fil, int col ){
	int i;
	//Memoria filas
	local_t ** centroComercial = malloc( fil * sizeof(local_t*) );
	if( centroComercial != NULL ){
	//Memoria columnas
	   for( i = 0; i < fil; i++ ){
		centroComercial[i] = malloc( col * sizeof(local_t) );
		if( centroComercial[i] == NULL ){
			printf( "Error en reservado de memoria \n" ); break;
		}
		//Indicador de reserva de memoria
		printf("Cargando...\n"); 
	   }
	} else{
	     printf( "Error en reservado de memoria \n" );
	}
	return centroComercial;
}
void inicializarMatriz( local_t ** centroComercial, int fil, int col ){
	int i, j;
	for( i = 0; i < fil; i++ ){
      	    for( j = 0; j < col; j++ ){
		centroComercial[i][j].disp = 0;
		printf( "%d", centroComercial[i][j].disp );
	    }
   	}
	return ;
}

void ingresarLocal( local_t ** centroComercial){
	int piso,local,num,opc;
	local_t localNuevo;
	   printf( "Ingrese el piso en el que desea poner su local: ");
	   scanf( "%d", &piso );
	   printf( "Ingrese el numero de local: " );
	   scanf( "%d", &local );
	   //Aqui se verifica si el local indicado esta vacio
	   if( centroComercial[piso-1][local-1].disp == 0 ){ 
		printf( "Digite el nombre del local: " );
		scanf( "%s", localNuevo.nombreLocal );
		localNuevo.pisoLocal = piso;
		localNuevo.numLocalxPiso = local; 
		//Numero al azar para el id
		localNuevo.idLocal = rand();
		printf("El id de el local sera %d \n", localNuevo.idLocal );
		//Se cambia el estado del local a ocupado
		printf( "Oprima 1 para ponerlo como un local de ropa\n" );
		printf( "Oprima 2 para ponerlo como un local de comida\n" );
		scanf( "%d", &opc );
		printf( "Digite la cantidad de empleados que va a tener el local: \n" );
		scanf( "%d", &localNuevo.empleados );
		if( opc == 1){
			localNuevo.tipo = ROPA;
		}
		if( opc == 2 ){
			localNuevo.tipo = COMIDA;
		}
	 	localNuevo.disp = 1;
		centroComercial[piso-1][local-1] = localNuevo;
	    }
}


void cambiarLocal(local_t ** centroComercial, int piso, int local){
	int opc;
	local_t localCambio;
	if( centroComercial[piso][local].disp == 1 ){
		printf( "Oprima 1 para cambiar todo lo del local\n" );
		printf( "Oprima 2 para cambiar el id\n" );
		printf( "Oprima 3 para cambiar el nombre\n" );
		scanf( "%d", &opc );
		if( opc == 1){
			cerrarLocal( centroComercial,piso,local );
			ingresarLocal( centroComercial );
		}
		if( opc == 2 ){
			printf( "Introduzca el nuevo id: " );
			scanf("%d", &centroComercial[piso][local].idLocal);
		}
		if( opc == 3 ){
			printf("Introduzca el nombre nuevo ");
			scanf( "%s", centroComercial[piso][local].nombreLocal );
		}
	}
	else{
	   printf( "Local cerrado\n" );
	}
}

void cerrarLocal(local_t ** centroComercial, int piso, int local ){
	local_t localBorrado;
	//se valida si la tienda ya esta abierta
	if( centroComercial[piso][local].disp == 1 ){
		strcpy( localBorrado.nombreLocal,"");
		localBorrado.pisoLocal = 0 ;
		localBorrado.numLocalxPiso = 0;
		localBorrado.idLocal = 0;
		localBorrado.disp = 0;
		centroComercial[piso][local] = localBorrado;
	}
}

int arregloPiso( local_t ** centroComercial,int piso ,int col, int *arr ){
	int j;
	for( j = 0; j<col; j++ ){
		arr[j] = centroComercial[piso][j].empleados;
		printf("%d",arr[j]);
	
	}
	return *arr;


}