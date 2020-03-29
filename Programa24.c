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
	printf( "3 IMPRIMIR TODOS LOS CUMPLES !\n" );
	printf( "0 SALIR \n" );
	scanf( "%d", &opc );

 
   return opc;
}



void imprimir(persona m[12][5], int i,int j){
	if( i == 11 ){
		printf("Impresa :)");	   	  
	}
	else{
		if( j == 4 ){
			j = 0; i++;
		}
		if( m[i][j].mes != -1 )
		printf("La fecha de nacimiento de %s es: %d/%d/%d\n ", m[i][j].nom,m[i][j].dia,
			m[i][j].mes,m[i][j].year  );
		j++;
		imprimir(m,i,j);

	}

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
   case 2: n = 0; printf("Introduzca su numero de mes ");
	   scanf( "%d", &buscar );
	   for( i = 0; i < 5; i++ ){
		if( m[buscar-1][i].mes != -1 ){
			printf("La fecha de nacimiento de %s es: %d/%d/%d\n ", m[buscar-1][i].nom,m[buscar-1][i].dia,
				m[buscar-1][i].mes,m[buscar-1][i].year  );
			
			}
		}

	

	break;

   case 3: printf("Ahora vera todas las fechas\n");
	  i = 0; j=0;
	   imprimir(m,i,j);
		


	break;

   }
  }while(opc != 0);
   return 0;
} 