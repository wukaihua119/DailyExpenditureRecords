#ifndef UTILS_H_ 
#define UTILS_H_ 

#include <stdio.h> 
#include <string.h> 

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
FILE *CreateNewDataSheet(void); 
FILE *OpenExistingDataSheet(void); 

#endif 
