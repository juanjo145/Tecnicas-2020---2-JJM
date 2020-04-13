#include "FuncionesCC.h"
#include <stdio.h>

int menu(){
   int opc;
	printf( "\n MENU \n" );
	printf( "  1 IGRESAR UN NUEVO LOCAL \n" );
	printf( "  2  MOSTRAR LA INFORMACION DE UN LOCAL POR SU UBICACION\n" );
	printf( "  3 Cambiar un local \n" );
	printf( "  4 Eliminar un local \n" );
	printf( "  5 MOSTRAR LOCALES ABIERTOS\n");
	printf( "  0 SALIR \n" );
	scanf( "%d", &opc );

 
   return opc;
}

int main(){
   int opc, fil, col, n = 0,tipo;
   int piso,local,numPiso, numLocalxPiso;
   local_t ** centroComercial;

   printf("Cual es el numero de pisos que necesita ?\n");
   scanf("%d", &fil);
   printf("Cual es el numero de locales por piso que necesita ?\n");
   scanf("%d", &col);
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
				mostrarLocal( centroComercial,fil, col,numPiso,numLocalxPiso);	
			        break;
			
			case 3: printf( "En que piso quiere cambiar el local?: " );
			        scanf( "%d", &piso );
				printf( "\nCual es el numero del local que  quiere cambiar?: " );
				scanf( "%d", &local );
				cambiarLocal(centroComercial, piso, local);
				
				break;

			case 4: printf( "En que piso quiere buscar?: " );
			        scanf( "%d", &piso );
				printf( "\nCual es el numero del local que  quiere cerrarr?: " );
				scanf( "%d", &local );
				cerrarLocal( centroComercial,piso,local);
				break;
			case 5: mostrarLocalesAbiertos( centroComercial, fil, col);
				break; 

		}
   }
   while( opc != 0 );
  	return 0;
}
