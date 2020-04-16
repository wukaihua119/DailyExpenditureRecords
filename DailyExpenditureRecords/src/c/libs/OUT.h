#ifndef OUT_H
#define OUT_H

#include<stdio.h>
#include<string.h> 
#include"IN.h" 

void OUT_output( char * );
int calexpense( size_t cal_expense, size_t cal_Ccash );
int calbalance( size_t cal_Dcash, size_t cal_Ccash,size_t cal_balance );
void caldetail( struct item *detail ); 
void getdetail( struct item *detail ); 
void out_to_file( void ); /* build redirecting output function */ 

#endif
