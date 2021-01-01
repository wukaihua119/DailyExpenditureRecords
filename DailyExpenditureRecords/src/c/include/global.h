#ifndef GLOBAL_H_
#define GLOBAL_H_ 

#include<stdio.h> 

#define OUTPUT output
#define INPUT input 

/* define a struct */
typedef struct{
    size_t date;
    char Ditem[10];
    char Citem[10];
    char ref[10];
    size_t Dcash;
    size_t Ccash;
    size_t total_expense;
    size_t balance;
    size_t T_eating; 
    size_t T_transfee; 
    size_t T_expense; 
}detail;




#endif 

