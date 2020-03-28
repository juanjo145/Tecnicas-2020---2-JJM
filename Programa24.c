#include <stdio.h>


typedef struct persona{
   char nom[ 20 ];   
   int mes,dia,year;
   
}persona;

int menu(){
   int opc;
	printf( "\n MENU \n" );
	printf( " 1 INGRESAR USUARIO \n" );
	printf( "2 NUMERO DE MES\n" );
	printf( "0 SALIR \n" );
	scanf( "%d", &opc );

 
   return opc;
}





int main(){
   int opc, i,j ;

   persona m[12][5], dia, mes, nombre, year;



   printf( "Introduzca su opcion" );
   
 do{ 

   opc = menu( );
   switch(opc){
   
   case 1: 
	   
	
           
	    break;

   }
  }while(opc != 0);
   return 0;
} 