#ifndef UTILS_H_ 
#define UTILS_H_ 

#include <stdio.h> 
#include <string.h> 

#define show_databases "#!/bin/bash \n echo 'Here are the existing databases...'\n ls ./databases" 

/* define a struct */
struct item{
    size_t date;
    char Ditem[10];
    char Citem[10];
    char ref[10];
    size_t Dcash;
    size_t Ccash;
    size_t total_expense;
    size_t balance;
};

struct item detail;

/* function prototype */ 
char *getFileName( void ); 
void Options( char *PATH, int choose );  
char *CreateNewDataSheet(void); 
char *OpenExistingDataSheet(void); 

#endif 
