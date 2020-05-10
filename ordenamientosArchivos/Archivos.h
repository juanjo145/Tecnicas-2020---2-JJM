#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void seleccion( int * arr, int size, FILE * f);

void datos( int * arr,int s );

void mergeSort(int * arr, int l, int r,FILE *f);

void merge(int * arr, int l, int m, int r);

void insert_sort(int * v, int size, FILE *f);

void mejorado( int * arr, int size,FILE *f);

void imprimirArchivo( int * arr, int s, FILE *f );