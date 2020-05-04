#include <stdio.h>
#include<stdlib.h> 
#include "OUT.h"

void OUT_output( char *PATH ){

    /* initialize value */
    detail.total_expense = detail.balance = detail.T_expense = 
	    detail.T_transfee = detail.T_eating = 0; 

    FILE *fPtr = fopen( PATH, "r+" ); 

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
        caldetail( &detail ); 

        /* print the value to .dat */
        printf( "%9ld%8s%8s%13s%8ld%8ld%15ld%9ld\n", 
                detail.date, detail.Ditem, detail.Citem, detail.ref, detail.Dcash, detail.Ccash, detail.total_expense, detail.balance );

//      while( !feof( fPtr ) ){ // this condition will causing the problem that the pointer will read the last line twice. 
        while( fscanf( fPtr, "%9zu%7s%9s%11s%7zu%7zu", 
                    &detail.date, detail.Ditem, detail.Citem, detail.ref, &detail.Dcash, &detail.Ccash ) == 6 ){ 

            /* print the value to .dat */
            printf( "%9ld%8s%8s%13s%8ld%8ld%15ld%9ld\n", 
                    detail.date, detail.Ditem, detail.Citem, detail.ref, detail.Dcash, detail.Ccash, detail.total_expense, detail.balance );

            /* read the contents form file */
            //fscanf( fPtr, "%9zu%7s%9s%11s%7zu%7zu", 
            //        &detail.date, detail.Ditem, detail.Citem, detail.ref, &detail.Dcash, &detail.Ccash );
            
            /* calculate total expense and balance */
            detail.total_expense = calexpense( detail.total_expense, detail.Ccash );
            detail.balance = calbalance( detail.Dcash, detail.Ccash, detail.balance );    
            caldetail( &detail ); 

        } /* end while */       

	/* show detail expenditure */ 
	getdetail( &detail ); 

    } /* end if else */

    fclose( fPtr ); 
} /* end OUT function */ 


/* calculate total expense */
int calexpense( size_t cal_expense, size_t cal_Ccash){
    return cal_expense + cal_Ccash;
}

/* calculate balance */
int calbalance( size_t cal_Dcash, size_t cal_Ccash, size_t cal_balance ){
    return cal_balance + cal_Dcash - cal_Ccash;
}

/* calculate the expenditure of that month */ 
void caldetail( struct item *detail ){ 
    if( strcmp( detail->Citem, "eating" ) == 0 )  
        detail->T_eating += detail->Ccash; 
    else if( strcmp( detail->Citem, "expense" ) == 0 ) 
        detail->T_expense += detail->Ccash; 
    else if( strcmp( detail->Citem, "transfee" ) == 0 ) 
        detail->T_transfee += detail->Ccash; 
} 

/* get the expense detail */ 
void getdetail( struct item *detail ){ 
    printf( "\nYour expenditure detail show below:\n" ); 
    printf( "%10s : %5ld\n", "eating", detail->T_eating ); 
    printf( "%10s : %5ld\n", "expense", detail->T_expense ); 
    printf( "%10s : %5ld\n", "transfee", detail->T_transfee ); 
    printf( "\n" ); 
} 

/* redirect to txt file */ 
void out_to_file(void){ 

}
