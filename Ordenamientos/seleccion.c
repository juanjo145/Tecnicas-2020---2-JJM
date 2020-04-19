#include <stdio.h>
#include <string.h>

void seleccion(int arr[], int tam){
	int i, j, p,temp;
	
	for( i = 0; i<tam-1;i++ ){
		p = i;
		for( j = p ; j< tam-1;j++ );
			if(arr[j]<arr[p])
				p = j;
		temp = arr[i];
		arr[i]=arr[p];
		arr[p] = temp;
	}
}
void printArray(int A[], int size){
	int i;
	for (i=0; i < size; i++)
	printf("%d ", A[i]);
}


int main(){
	int arr[] = {85, 24, 63, 45, 17, 31, 96, 50,4};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	printf("El arreglo que yo le doy es: ");
	printArray(arr, arr_size);
	seleccion(arr, arr_size);
	printf("\nEl arreglo ordenado es: ");
	printArray(arr, arr_size);
	return 0;
}
