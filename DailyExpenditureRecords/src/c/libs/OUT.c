#include <stdio.h>
#include<stdlib.h> 
#include "OUT.h"
#include "IN.h"

void OUT_output( FILE *fPtr ){
    detail.total_expense = 0; /* initialize value */
    detail.balance = 0; /* initialize value */

    if ( fPtr == NULL ){

        /* no files */
        printf("%s\n", "No files.");
    }else {

        /* print the titles */
        printf( "%9s%8s%8s%13s%8s%8s%15s%9s\n", 
                "date", "Ditem", "Citem", "reference", "Dcash", "Ccash", "total_expense", "balance" );

        /* read the contents form file */
        fscanf( fPtr, "%9zu%7s%9s%11s%7zu%7zu", 
                &detail.date, detail.Ditem, detail.Citem, detail.ref, &detail.Dcash, &detail.Ccash );

        /* calculate total expense and balance */
        detail.total_expense = calexpense( detail.total_expense, detail.Ccash );
        detail.balance = calbalance( detail.Dcash, detail.Ccash, detail.balance );        

        while( !feof( fPtr ) ){

            /* print the value to .dat */
            printf( "%9ld%8s%8s%13s%8ld%8ld%15ld%9ld\n", 
                    detail.date, detail.Ditem, detail.Citem, detail.ref, detail.Dcash, detail.Ccash, detail.total_expense, detail.balance );

            /* read the contents form file */
            fscanf( fPtr, "%9zu%7s%9s%11s%7zu%7zu", 
                    &detail.date, detail.Ditem, detail.Citem, detail.ref, &detail.Dcash, &detail.Ccash );
            
            /* calculate total expense and balance */
            detail.total_expense = calexpense( detail.total_expense, detail.Ccash );
            detail.balance = calbalance( detail.Dcash, detail.Ccash, detail.balance );        

        } /* end while */       

    } /* end if else */

    fclose( fPtr ); /* fclose to close file pointer */

} /* end OUT function */ 


/* calculate total expense */
int calexpense( size_t cal_expense, size_t cal_Ccash){

    return cal_expense + cal_Ccash;
}

/* calculate balance */
int calbalance( size_t cal_Dcash, size_t cal_Ccash, size_t cal_balance ){

    return cal_balance + cal_Dcash - cal_Ccash;
}

/* redirect to txt file */ 
void out_to_file(void){ 

}
