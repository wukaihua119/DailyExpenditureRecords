#include <stdio.h>
#include "IN.h"


void IN_input( FILE *fPtr ){

    printf( "Enter the date, Ditem, Citem, reference, Dcash, Ccash\n" );
    printf( "Enter EOF to end input.\n" );
    printf( "// " );

    /* input value to var */
    scanf( "%zu%s%s%s%zu%zu", 
    	&(detail.date), detail.Ditem, detail.Citem, detail.ref, &(detail.Dcash), &(detail.Ccash) );

    /* write account, name and balance into file with fprintf */
    while ( !feof( stdin ) ) { 
        fprintf( fPtr, "%9ld%7s%9s%11s%7ld%7ld\n", 
        	detail.date, detail.Ditem, detail.Citem, detail.ref, detail.Dcash, detail.Ccash );
        printf( "// " );
			s( "%zu%s%s%s%zu%zu", 
    		&(detail.date), detail.Ditem, detail.Citem, detail.ref, &(detail.Dcash), &(detail.Ccash) );
    } /* end while */

}
