#include<stdio.h>
#include "IN.h"
#include "OUT.h"

int main( void ){

	int choose;
	
	printf( "\"1\" for input and output, \"2\" for outpit.\n" );	
	scanf( "%d", &choose );

	switch( choose ){
		/* Input data and print it out */
		case 1: 
			IN_input( );
			printf( "\n***Your account show below detailly.***\n" );
			OUT_output( );
			break;
		/*print out the account */
		case 2:
			printf( "\n***Your account show below detailly.***\n" );
			OUT_output( );
			break;
		/* run into error */
		default:
			printf( "ERROR\n" );
			break;
	}	

	return 0;
}

