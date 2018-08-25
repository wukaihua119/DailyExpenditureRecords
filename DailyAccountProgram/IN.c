#include <stdio.h>
#include "IN.h"

/* define a struct */
struct item{
	long date;
	char Ditem[20];
	char Citem[20];
	char ref[20];
	int Dcash;
	int Ccash;
    int total_expense;
    int balance;
};



void IN_input( void ){

    struct item detail;

	FILE *fPtr = fopen( "accountsAugust.dat", "a+"); /*File name should change by yourself.*/

 	if (  fPtr  == NULL ) {
        printf( "No File.\n" );
   	} else {
        printf( "Enter the date, Ditem, Citem, reference, Dcash, Ccash\n" );
        printf( "Enter EOF to end input.\n" );
        printf( "// " );

        /* input value to var */
        scanf( "%ld%s%s%s%d%d", 
        	&(detail.date), detail.Ditem, detail.Citem, detail.ref, &(detail.Dcash), &(detail.Ccash) );

        /* write account, name and balance into file with fprintf */
        while ( !feof( stdin ) ) { 
            fprintf( fPtr, "%9ld%7s%9s%11s%7d%7d\n", 
            	detail.date, detail.Ditem, detail.Citem, detail.ref, detail.Dcash, detail.Ccash );
            printf( "// " );
			scanf( "%ld%s%s%s%d%d", 
        		&(detail.date), detail.Ditem, detail.Citem, detail.ref, &(detail.Dcash), &(detail.Ccash) );
        } /* end while */

        fclose( fPtr ); /* fclose closes file */

	}
}

