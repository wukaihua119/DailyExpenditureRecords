#include<stdio.h>

/* function prototype */
void IN_input( void );
void OUT_output( void );
int calexpense( int cal_expense, int cal_Ccash );
int calbalance( int cal_Dcash, int cal_Ccash, int cal_balance );

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

void OUT_output(void){
    struct item detail;
    detail.total_expense = 0; /* initialize value */
    detail.balance = 0; /* initialize value */

    /* a file pointer */
    FILE *fPtr = fopen( "accountsAugust.dat", "r+");

    if ( fPtr == NULL ){

        /* no files */
        printf("%s\n", "No files.");
    }else {

        /* print the titles */
        printf( "%9s%8s%8s%13s%8s%8s%15s%9s\n", 
                "date", "Ditem", "Citem", "reference", "Dcash", "Ccash", "total_expense", "balance" );

        /* read the contents form file */
        fscanf( fPtr, "%9ld%7s%9s%11s%7d%7d", 
                &detail.date, detail.Ditem, detail.Citem, detail.ref, &detail.Dcash, &detail.Ccash );

        /* calculate total expense and balance */
        detail.total_expense = calexpense( detail.total_expense, detail.Ccash );
        detail.balance = calbalance( detail.Dcash, detail.Ccash, detail.balance );        

        while( !feof( fPtr ) ){

            /* print the value to .dat */
            printf( "%9ld%8s%8s%13s%8d%8d%15d%9d\n", 
                    detail.date, detail.Ditem, detail.Citem, detail.ref, detail.Dcash, detail.Ccash, detail.total_expense, detail.balance );

            /* read the contents form file */
            fscanf( fPtr, "%9ld%7s%9s%11s%7d%7d", 
                    &detail.date, detail.Ditem, detail.Citem, detail.ref, &detail.Dcash, &detail.Ccash );
            
            /* calculate total expense and balance */
            detail.total_expense = calexpense( detail.total_expense, detail.Ccash );
            detail.balance = calbalance( detail.Dcash, detail.Ccash, detail.balance );        

        } /* end while */       

    } /* end if else */

    fclose( fPtr ); /* fclose to close file pointer */

} /* end OUT function */ 


/* calculate total expense */

int calexpense( int cal_expense, int cal_Ccash){

    return cal_expense + cal_Ccash;
}

/* calculate balance */
int calbalance( int cal_Dcash, int cal_Ccash, int cal_balance ){

    return cal_balance + cal_Dcash - cal_Ccash;
}
