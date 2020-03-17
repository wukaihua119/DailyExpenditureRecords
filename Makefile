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
exec:  
	cd $(CODE_PATH) && ./Accounts 

build_and_exec: build clean 
	cd $(CODE_PATH) && ./Accounts 

build:  Accounts 
	echo 'Compile the source code...' 
	cd $(CODE_PATH)  
	echo 'Done...' 

Accounts: Accounts.o IN.o OUT.o
	cd $(CODE_PATH) && $(CC) -o Accounts $(FLAG) Accounts.o ./libs/IN.o ./libs/OUT.o 

Accounts.o: $(CODE_PATH)Accounts.c $(LIBS_CODE_PATH)IN.h $(LIBS_CODE_PATH)OUT.h
	cd $(CODE_PATH) && $(CC) $(FLAG) -c Accounts.c 

IN.o: $(LIBS_CODE_PATH)IN.h $(LIBS_CODE_PATH)IN.c 
	cd $(LIBS_CODE_PATH) && $(CC) $(FLAG) -c IN.c 

OUT.o: $(LIBS_CODE_PATH)OUT.h $(LIBS_CODE_PATH)OUT.c
	cd $(LIBS_CODE_PATH) && $(CC) $(FLAG) -c OUT.c

clean:
	echo 'Cleaning code...' 
	$(RM) -rf $(CODE_PATH)*.o &&  $(RM) -rf $(LIBS_CODE_PATH)*.o
	echo 'Done...' 
