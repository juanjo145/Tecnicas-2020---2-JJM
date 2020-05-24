#include "centroC.h"
#include <stdio.h>

int menu(){
   int opc;
	printf( "\n MENU \n" );
	printf( "  1 IGRESAR UN NUEVO LOCAL \n" );
	printf( "  2  MOSTRAR LA INFORMACION DE UN LOCAL POR SU UBICACION\n" );
	printf( "  3 Cambiar un local \n" );
	printf( "  4 Eliminar un local \n" );
	printf( "  5 MOSTRAR LOCALES ABIERTOS\n");
	printf( "  6 Ordenar los locales de cualquier piso\n" );
	printf( "  0 SALIR \n" );
	scanf( "%d", &opc );


   return opc;
}

int main(){
   int opc, fil, col, n = 0,tipo,opcion;
   int piso,local,numPiso, numLocalxPiso;
   local_t ** centroComercial;
   printf("Cual es el numero de pisos que necesita ?\n");
   scanf("%d", &fil);
   printf("Cual es el numero de locales por piso que necesita ?\n");
   scanf("%d", &col);
   int arr[col];
   //Se hace su reserva dinamica
   centroComercial = reservaDinamica( fil, col );
   if( centroComercial != NULL ){
	//Se inicializa
	inicializarMatriz( centroComercial, fil, col );
   }

   do{
      opc = menu();
		switch(opc){   
			case 1: ingresarLocal( centroComercial);	
				break;

			case 2: printf( "En que piso quiere buscar?: " );
				scanf( "%d", &numPiso );
				printf( "Cual es el numero del local que  quiere buscar?: " );
				scanf( "%d", &numLocalxPiso );
				numPiso= numPiso-1;
				numLocalxPiso = numLocalxPiso - 1;
				mostrarLocal( centroComercial,fil, col,numPiso,numLocalxPiso);	
			        break;

			case 3: printf( "En que piso quiere cambiar el local?: " );
			        scanf( "%d", &piso );
				printf( "\nCual es el numero del local que  quiere cambiar?: " );
				scanf( "%d", &local );
				piso = piso -1;
				local = local -1;
				cambiarLocal(centroComercial, piso, local);

				break;

			case 4: printf( "En que piso quiere buscar?: " );
			        scanf( "%d", &piso );
					printf( "\nCual es el numero del local que  quiere cerrarr?: " );
					scanf( "%d", &local );
					piso = piso -1;
					local = local -1;
					cerrarLocal( centroComercial,piso,local);
				break;
			case 5: mostrarLocalesAbiertos( centroComercial, fil, col);
				break; 
			case 6: printf( "Que piso quiere ordenar: " );
			        scanf( "%d", &piso );
					piso = piso -1;
					arregloPiso( centroComercial, piso, col, arr  );
					printf( "%d", arr[0] );
					printf( "Por cual metodo lo vas a ordenar ?" );
					printf( "Oprima 1 para ordenarlo por selection \n" );
					printf( "Oprima 2 para ordenarlo por mergesort\n" );
					printf( "Oprima 3 para ordebnarlo por inserccion\n" );
					printf( "Oprima 3 para ordenarlo por quick sort\n" );
					scanf( "%d", &opcion );
					if( opcion==1 ){
					
					}
		}
   }
   while( opc != 0 );
  	return 0;
}