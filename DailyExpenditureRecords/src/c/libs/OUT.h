#include<stdio.h>

#ifndef OUT_H
#define OUT_H

int D_eating; 
int D_expense; 
int D_moto; 

void OUT_output( char * );
int calexpense( size_t cal_expense, size_t cal_Ccash );
int calbalance( size_t cal_Dcash, size_t cal_Ccash,size_t cal_balance );
void caldetail( void ); 
void out_to_file( void ); /* build redirecting output function */ 

#endif
