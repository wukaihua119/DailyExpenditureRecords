#include<stdio.h>
#define ACCOUNT_NAME "accountSEP18.dat"

#ifndef IN_H
#define IN_H

/* define a struct */
struct item{
	size_t date;
	char Ditem[20];
	char Citem[20];
	char ref[20];
	size_t Dcash;
	size_t Ccash;
    size_t total_expense;
    size_t balance;
};

struct item detail;

/* function prototype */
void IN_input( void );
/* Function IN to input the daily accounts*/


#endif
