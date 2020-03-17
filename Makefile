# Use gcc to compile this source files.
CC = gcc
# Complier flag.
FLAG = -Wall -pedantic 
# Delete object files.
RM = rm
# Path 
LIBS_CODE_PATH=./DailyExpenditureRecords/src/c/libs/
CODE_PATH=./DailyExpenditureRecords/src/c/

# Combine object files to form a binary execuatable file as Accounts
run: clean 
	cd ./DailyExpenditureRecords/src/c/ && ./Accounts 

build: Accounts 

Accounts: Accounts.o IN.o OUT.o
	$(CC) -o Accounts $(FLAG) Accounts.o IN.o OUT.o 

Accounts.o: Accounts.c IN.h OUT.h
	$(CC) $(FLAG)-c $(CODE_PATH)Accounts.c 

IN.o: IN.h IN.c
	$(CC) $(FLAG) -c $(LIBS_CODE_PATH)IN.c 

OUT.o: OUT.h OUT.c
	$(CC) $(FLAG) -c $(LIBS_CODE_PATH)OUT.c

clean:
	$(RM) -rf *.o
