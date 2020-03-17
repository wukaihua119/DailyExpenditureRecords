#include<stdio.h>
#include "./libs/IN.h"
#include "./libs/OUT.h"

int main( void ){ 

	int choose;
	
    printf("\nThe DailyExpenditure is starting...\n"); 
    printf("\nWelcome to DailyExpenditure...\n"); 
	printf( "\"1\" for input and output, \"2\" for output.\n" );	
	scanf( "%d", &choose );

	switch( choose ){
		/* Input data and print it out */
		case 1: 
			IN_input( );
			printf( "\n\n***Your account show below detailly.***\n" );
			OUT_output( );
			break;
		/*print out the account */
		case 2:
			printf( "\n\n***Your account show below detailly.***\n" );
			OUT_output( );
			break;
		case 3:
			printf( "\n\n***Redirecting output to a file.***\n" );
			out_to_file( );
			break;
		/* run into error */
		default:
			printf( "ERROR\n" );
			break;
	}	

	return 0;
}

