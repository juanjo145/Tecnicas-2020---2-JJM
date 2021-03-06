#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include "iostream"
#include <stdexcept>
using namespace std;


typedef enum tipoLocal{
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

//Funcion de ordenamiento tipo seleccion
void seleccion( int *arr, int s );

//Funcion de ordenamiento tipo mergeSort
void mergeSort(int * arr, int l, int r);

void merge(int * arr, int l, int m, int r);

//Funcion de ordenamiento tipo inrseccion
void insert_sort(int * v, int size);

//Funcion de quick sort
void quicksort( int *arr, int n );

void quick( int *arr, int limizq, int limder );

//Funcion para agregar archivo binario 
void escribir( local_t ** centroComercial, int fil, int col );
#endif /* FUNCIONESCC_H_ */