#include<stdio.h>
#include "./libs/IN.h"
#include "./libs/OUT.h"
#include "./libs/utils.h"


int main( void ){ 

    int choose;
    char *PATH; 

    printf("\nThe DailyExpenditure is starting...\n"); 
    printf("\n\nWelcome to DailyExpenditure...\n\n\n\n"); 
    
    PATH = getFileName(); 
    printf( "\n\n\"1\" to input and output,\n\"2\" to output,\n\"3\" to show detail expenditure,\n\"4\" to open or recreate new file,\n\"0\" to end.\n" ); 
    scanf( "%d", &choose ); 
   
    while( choose != 0 ){ 
        if( choose == 4 ) 
            PATH = getFileName(); 
        else 
            Options( PATH, choose ); 
         
        printf( "\n\n\"1\" to input and output,\n\"2\" to output,\n\"3\" to show detail expenditure,\n\"4\" to open or recreate new file,\n\"0\" to end.\n" ); 
        scanf( "%d", &choose ); 
    }
    
    printf( "Bye!\n" ); 
    free( PATH ); 
    return 0;
}


