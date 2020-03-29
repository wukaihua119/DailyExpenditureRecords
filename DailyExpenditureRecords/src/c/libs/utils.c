#include "utils.h" 

FILE *CreateNewDataSheet( void ){ 
    FILE *FILEPTR; 
    char PATH[500] = "./databases/"; 
    char FILENAME[30]; 

    printf( "Input your new data sheet name. >> " ); 
    scanf( "%s", FILENAME ); 
    strcat( PATH, FILENAME ); 

    return fopen( PATH, 'w' ); ; 
}

FILE *OpenExistingDataSheet( void ){ 
    FILE *FILEPTR; 
    char PATH[500] = "./databases/"; 
    char FILENAME[30]; 

    printf( "Input the name of your exsiting data sheet. >> " ); 
    scanf( "%s", FILENAME ); 
    strcat( PATH, FILENAME ); 

return fopen( PATH, "r+" ); 

}