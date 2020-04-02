#include <stdio.h>
#include<stdlib.h> 
#include "OUT.h"
#include "IN.h"

void OUT_output( char *PATH ){

    D_expense = D_eating = D_trans_fee = 0; /* initialize the global vars */ 
    
    detail.total_expense = detail.balance = 0; /* initialize value */

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
        caldetail( detail.Ditem, detail.Dcash ); 

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
            caldetail( detail.Ditem, detail.Dcash );

        } /* end while */       

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
void caldetail( char *Ditem, size_t Dcash ){ 
    if( Ditem == "eating" ) 
        D_eating += Dcash; 
    else if( Ditem == "expense" ) 
        D_expense += Dcash; 
    else if( Ditem == "transfee" ) 
        D_trans_fee += Dcash; 
} 
void getdetail( void ){ 
    printf( "\nYour expenditure detail show below:\n" ); 
    printf( "%10s : %5d\n", "eating", D_eating ); 
    printf( "%10s : %5d\n", "expense", D_expense ); 
    printf( "%10s : %5d\n", "transfee", D_trans_fee ); 
    printf( "\n" ); 
} 

/* redirect to txt file */ 
void out_to_file(void){ 

}
