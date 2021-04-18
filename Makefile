# Use gcc to compile this source files.
CC = gcc
# Complier flag.
FLAG = -Wall -pedantic 
# Delete object files.
RM = rm
ERASE = erase
# Path 
LIBS_CODE_PATH=./DailyExpenditureRecords/src/c/libs/
CODE_PATH=./DailyExpenditureRecords/src/c/

.PHONY: clean cleanWin exec build_and_exec build

# Combine object files to form a binary execuatable file as Accounts
exec:  
	./Accounts 

build_and_exec: build clean 
	./Accounts 

build:  Accounts clean 
	@echo 'Compile the source code...' 
	@echo 'Done...' 

Accounts: Accounts.o utils.o IN.o OUT.o  
	$(CC) -o Accounts $(FLAG) Accounts.o utils.o IN.o OUT.o  

Accounts.o: $(CODE_PATH)Accounts.c $(LIBS_CODE_PATH)IN.h $(LIBS_CODE_PATH)OUT.h
	$(CC) $(FLAG) -c $(CODE_PATH)Accounts.c 

utils.o: $(LIBS_CODE_PATH)utils.h $(LIBS_CODE_PATH)utils.c 
	$(CC) $(FLAG) -c $(LIBS_CODE_PATH)utils.c 

IN.o: $(LIBS_CODE_PATH)IN.h $(LIBS_CODE_PATH)IN.c 
	$(CC) $(FLAG) -c $(LIBS_CODE_PATH)IN.c 

OUT.o: $(LIBS_CODE_PATH)OUT.h $(LIBS_CODE_PATH)OUT.c
	$(CC) $(FLAG) -c $(LIBS_CODE_PATH)OUT.c

clean:
	@echo 'Cleaning code...' 
	$(RM) -rf *.o 
	@echo 'Done...' 

cleanWin:
	@echo 'Cleaning code...' 
	$(ERASE) *.o 
	@echo 'Done...' 
