#include <stdio.h>
#include <string.h>

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
   int opc, i,j, dia, mes, year, buscar ;
   int n = 0;
   char nombre[20];
   persona m[12][5];

   for( i = 0; i < 12; i++ ){
   	for( j = 0; j < 5; j++ ){
		m[i][j].mes= -1;
	}
   }
   printf( "Introduzca su opcion" );
   
 do{ 
   opc = menu( );
   switch(opc){
   case 1: printf( "Introduzca el nombre de la persona: " ); scanf( "%s", nombre );
	printf( "\nIntroduzca el mes de nacimiento: " ); scanf( "%d", &mes );
	printf( "\nIntroduzca el dia de nacimiento: " ); scanf( "%d", &dia );
	printf( "\nIntroduzca el ano de nacimiento: " ); scanf( "%d", &year );

	for( j = 0; j<5; j++ ){
	   if( m[mes-1][j].mes == -1 ){
		n = 1;
		strcpy(m[ mes-1 ][j].nom , nombre);
		m[ mes-1 ][j].dia = dia;
		m[ mes-1 ][j].mes = mes;
		m[ mes-1 ][j].year = year;
		
		printf( "Se ingreso el usuario\n" );
		break;
	   }
	
	}
	if( n = 0 ){
		printf( "No se puede ingresar mas gente :(\n" );
			
	}
           
	    break;
   case 2: n = 0;
	   printf("Introduzca su numero de mes ");
	   scanf( "%d", &buscar );
	   for( i = 0; i < 5; i++ ){
		if( m[buscar-1][i].mes != -1 ){
			printf("La fecha de nacimiento de %s es: %d/%d/%d ", m[buscar-1][i].nom,m[buscar-1][i].dia,
				m[buscar-1][i].mes,m[buscar-1][i].year  );
			
			}
		}

	break;

   }
  }while(opc != 0);
   return 0;
} 