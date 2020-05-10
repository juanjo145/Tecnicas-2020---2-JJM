#include "Archivos.h"
#include <stdio.h>

int menu(){
	int opc;
	printf("\n=========================\n");
	printf( "Menu\n" );
	printf( "1 Introducir datos\n" );
	printf( "2 Selection\n" );
	printf( "3 Inserccion\n" );
	printf( "4 Mejorado\n" );
	printf( "5 Merge sort\n" );
	printf( "6 Imprimir\n" );
	printf( "7 Salir\n " );
	printf("========================\n");
	scanf( "%d", &opc );
	return opc;
}


int main(){
	FILE *f;
	int opc,i,s;
	int * arr = malloc( 100001 * sizeof(int) ) ;
	time_t inicio,fin;
	f = fopen( "Resultados(100000).txt", "a+" );
	fprintf( f,"Documento de pruebas" );
	do{
		opc = menu();
			switch(opc){

				case 1: printf( "Introduzca cuantos elementos quiere organizar: " );
						//scanf( "%d",&s );
						s =100000 ;
						datos(arr,s);
						break;

				case 2: seleccion(arr,s,f);
					break;

				case 3: insert_sort( arr, s,f );
						break;

				case 4: mejorado( arr,s,f );
						break;

				case 5: inicio = time(NULL);
						printf( "Inicio: %f", time );
						mergeSort(arr,0,s-1);
						fin = time(NULL);
						fprintf(f, "\nEl tiempo que se tomo en merge fue de: %f ", difftime(fin,inicio) );
						break;

				case 6: printf( "\nLos elementos del arreglo son: " );
						for (i=0; i < s; i++){
							printf("%d ", arr[i]);
						}
						imprimirArchivo( arr, s,f );

						break;
			}
	} while(opc != 7);
	fclose( f );
	free( arr );
	return 0;
}