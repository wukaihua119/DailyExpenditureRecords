CC = gcc
FLAG = -Wall -pedantic 
RM = rm

Accounts: Accounts.o IN.o OUT.o
	$(CC) -o Accounts $(FLAG) Accounts.o IN.o OUT.o 
Accounts.o: Accounts.c IN.h OUT.h
	$(CC) $(FLAG)-c Accounts.c 

IN.o: IN.h IN.c
	$(CC) $(FLAG) -c IN.c 

OUT.o: OUT.h OUT.c
	$(CC) $(FLAG) -c OUT.c

clean:
	$(RM) -rf *.o
