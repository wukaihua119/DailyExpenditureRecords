#include "utils.h" 

char *getFileName( void ){ 

    printf( "%s", "\n**********************************************\n"); 
    system( show_databases ); 

    char PATH[500] = "./databases/"; 
    char FILENAME[30]; 
    char *target; 
    printf( "%s", "\n**********************************************\n"); 
    printf( "%s", "Please enter your file name with extension >> " ); 
    scanf( "%s", FILENAME ); 
    strcat( PATH, FILENAME ); 
    target = malloc( sizeof( PATH ) ); 
    strcpy( target, PATH ); 
    return target; 
} 

void Options( char *PATH, int choose ){ 

    if( PATH != NULL ){ 

        switch( choose ){
            /* Input data and print it out */
            case 1: 
                IN_input( PATH );
                printf( "%s", "\n**********************************************\n"); 
                printf( "\***Your account show below detailly.***\n" );
                OUT_output( PATH );
            break;
            /*print out the account */
            case 2:
                printf( "%s", "\n**********************************************\n"); 
                printf( "***Your account show below detailly.***\n" );
                OUT_output( PATH );
                break;
            case 4: 
                printf( "%s", "\n**********************************************\n"); 
                printf( " detail expenditure of this month shows below.\n\n" ); 
                getdetail(); 
                break; 
            /* run into error */
            default:
                printf( "ERROR\n" );
                break;
        }	

    }else 
        printf( "Data sheet cannot be opened or created.\n" );  

}

