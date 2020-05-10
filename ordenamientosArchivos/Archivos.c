#include "Archivos.h"

void imprimirArchivo( int * arr, int s, FILE *f ){
	int i;
	fprintf( f,"Los datos organizados por el algoritmo son: " );
	for (i=0; i < s; i++){
		fprintf(f, "%d ", arr[i]);
	}
	fprintf( f,"\n" );
}

void seleccion(int * arr, int s,FILE * f){
	int i, j, p,temp;
	time_t inicio,fin;
	inicio = time(NULL);
	printf( "Inicio: %f", time );
	for( i = 0; i<s-1;i++ ){
		p = i;
		for( j = p ; j< s-1;j++ ){
			if(arr[j]<arr[p])
				p = j;
		}
		temp = arr[i];
		arr[i]=arr[p];
		arr[p] = temp;
	}


	fin = time(NULL);
	fprintf(f, "\nEl tiempo que se en seleccion fue de: %f ", difftime(fin,inicio) );
}

void merge(int * arr, int l, int m, int r, FILE *f){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
		for (j = 0; j < n2; j++)
			R[j] = arr[m + 1+ j];
			i = 0;
			j = 0;
			k = l;
			while (i < n1 && j < n2){
			if (L[i] <= R[j]){
			arr[k] = L[i];
			i++;
			}
			else{
			arr[k] = R[j];
			j++;
			}
			k++;
			}
			while (i < n1){
			arr[k] = L[i];
			i++;
			k++;
			}
			while (j < n2){
			arr[k] = R[j];
			j++;
			k++;
			}
}

void mergeSort(int * arr, int l, int r, FILE *f){
	time_t inicio,fin;
	inicio = time(NULL);
	printf( "Inicio: %f", time );
	if (l < r){
		int m = l+(r-l)/2;
		mergeSort(arr, l, m,f);
		mergeSort(arr, m+1, r,f);
		merge(arr, l, m, r);
	}
	printf("Arreglo ordenado\n");
	fin = time(NULL);
	fprintf(f, "\nEl tiempo que se tomo en merge fue de: %f ", difftime(fin,inicio) );
}

void datos( int * arr, int s ){
	int i;
	for( i=0; i < s; i++ ){
		arr[i] = rand(); 
	}
}

 void insert_sort(int * v, int size, FILE *f){
 	int i, j, temp;
 	time_t inicio,fin;
	inicio = time(NULL);
	printf( "Inicio: %f", time );
	 for(i=0; i<size; i++){
 		temp=v[i];
 		j=i-1;
 		while(j>=0 && v[j] >temp){
 			v[j+1] = v[j];
 			j--;
 		}

 		v[j+1] = temp;
	}
	printf("Arreglo ordenado\n");
	fin = time(NULL);
	fprintf(f, "\nEl tiempo que se tomo en sort fue de: %f ", difftime(fin,inicio) );
}

void mejorado( int * arr, int size, FILE *f){
	int i, j, p,temp;
	time_t inicio,fin;
	inicio = time(NULL);
	printf( "Inicio: %f", time );
	for( i=0; i<size;i++  ){
		for( j=0; j<size; j++ ){
			if (arr[i]<arr[j]){

			}
			else{
				for( i = 0; i<size-1;i++ ){
					p = i;
					for( j = p ; j< size-1;j++ ){
						if(arr[j]<arr[p])
							p = j;
						}
					temp = arr[i];
					arr[i]=arr[p];
					arr[p] = temp;
				}
			}
		}
	}

	printf("Arreglo ordenado\n");
	fin = time(NULL);
	fprintf(f, "\nEl tiempo que se tomo en el mejorado fue de: %f ", difftime(fin,inicio) );
}