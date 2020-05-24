#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum tipoLocal{
	ROPA, COMIDA
}tipo;
//Local 
typedef struct local_t{
	char nombreLocal[35];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;//Columnas
	int disp; //Disponibilidad del local
	int tipo; //Tipo de local
	int empleados;
} local_t;

//Memoria dinamica
local_t ** reservaDinamica( int fil, int col );

//Inicializar matriz
void inicializarMatriz( local_t ** centroComercial,int fil, int col );

//Agregar un local
void ingresarLocal( local_t ** centroComercial);

//Eliminar un local
void cerrarLocal(local_t ** centroComercial, int piso, int local);

//Cambiar cualquier dato
void cambiarLocal(local_t ** centroComercial, int piso, int local);

/*Agregar las funciones que necesite para satisfacer los requerimientos */
void mostrarLocal(local_t ** centroComercial,int fil, int col, int numPiso, int numLocalxPiso);

//Mostrar el nombre por id

void mostrarLocalesAbiertos(local_t ** centroComercial,int fil,int col);

//Pone todos los locales del piso en un arreglo de enteros y lo arregla segun el metodo

int arregloPiso( local_t ** centroComercial, int piso, int col, int *arr );


#endif /* FUNCIONESCC_H_ */