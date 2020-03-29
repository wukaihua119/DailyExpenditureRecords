#include<stdio.h>
#include "./libs/IN.h"
#include "./libs/OUT.h"
#include "./libs/utils.h"

void main_page( FILE *FILEPTR ); 
void sub_page( FILE *FILEPTR, int choose ); 

int main( void ){ 

int choose;
FILE *FILEPTR; 

   printf("\nThe DailyExpenditure is starting...\n"); 
   printf("\nWelcome to DailyExpenditure...\n\n"); 
   
   main_page( FILEPTR ); 
   printf( "\"1\" for input and output, \"2\" for output, \"3\" for return to last menu, \"0\" for end.\n" );	
   scanf( "%d", choose ); 
   sub_page( FILEPTR, choose ); 
   
   printf( "\n\n\"1\" for input and output, \"2\" for output, \"3\" for return to last menu, \"0\" for end.\n" );	
   scanf( "%d", choose ); 
   
   while( choose != 0 ){ 
        if( choose == 3 ){ 
            main_page( FILEPTR ); 
        }else if( choose == 1 || choose == 2 ){ 
            sub_page( FILEPTR, choose ); 
        } 
        printf( "\n\n\"1\" for input and output, \"2\" for output, \"3\" for return to last menu, \"0\" for end.\n" );
        scanf( "%d", choose ); 
    }

    fclose( FILEPTR ); 

    return 0;
}

void main_page( FILE *FILEPTR ){ 

    char create_or_not; 
    printf( "%s", "Do you want to create a new data sheet? Y/N >> " ); 
    scanf( "%c", &create_or_not ); 

    if( create_or_not == 'y' || create_or_not == 'Y'){ 
        FILEPTR = CreateNewDataSheet(); 
    }else{ 
        FILEPTR = OpenExistingDataSheet(); 
    } 
} 

void sub_page( FILE *FILEPTR, int choose ){ 

    if( FILEPTR != NULL ){ 

        switch( choose ){
            /* Input data and print it out */
            case 1: 
                IN_input( FILEPTR );
                printf( "\n\n***Your account show below detailly.***\n" );
                OUT_output( FILEPTR );
            break;
            /*print out the account */
            case 2:
                printf( "\n\n***Your account show below detailly.***\n" );
                OUT_output( FILEPTR );
                break;
            case 3: 
                printf( "\n\n***Return to the last menu.***\n" );
                main_page( FILEPTR );
                break;
            /* 
            case 4:
                printf( "\n\n***Redirecting output to a file.***\n" );
                out_to_file( FILEPTR );
                break;
            */ 
            /* run into error */
            default:
                printf( "ERROR\n" );
                break;
        }	

    }else 
        printf( "Data sheet cannot be opened or created.\n" );  


}
