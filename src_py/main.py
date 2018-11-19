#!/usr/bin/python3.5  


# Define functions 

def Input( ):
	record_input = []
	while True:
		records = input( ">> " )
		if records:
			record_input.append( records ) 
		else:
			break
	
	# Write the records into files 
	fwrite = open( "recordsData.dat", "a+" )
	for keyin in record_input:
		fwrite.write( keyin+"\n" )
	
	fwrite.close()

def Output( ):
	fread = open( "recordsData.dat", 'r+' ) # == open().read() == loop of readline() 
	fstdout = open( "Accounts.txt", 'w+' )
	fstdout.write( "%9s %7s %9s %11s %7s %7s %15s %9s\n" %( "Date", "Ditem", "Citem", "Reference", "Dcash", "Ccash", "total_expense", "balance" ) )

	totalexpense = 0
	balance = 0

	while True:
		stdout_lines = [ lines.rstrip().split(' ') for lines in fread ]
	#	print( fread )
	#	print( stdout_lines )
		if stdout_lines:
			for read_ in stdout_lines:
					totalexpense += int( read_[5] )
					balance += int( read_[4] ) - int( read_[5] )
					print( 	"%9s %7s %9s %11s %7s %7s %15s %9s" %( read_[0], read_[1], read_[2], read_[3], read_[4], read_[5], totalexpense, balance ),
							file = fstdout )
				#print( read_ )
		else:
			break

# Program Start 
while True:
	print( "1 for input, 2 for output, 3 for end program." )
	try:
		choice = int( input( ">>? " ) )
		if choice == 1:
			print( "Input the Date, Ditem, Citem, reference, Dcash, Ccash\n", "Enter to end input." )
			Input()
		elif choice == 2:	
			print( "Output\n" )
			Output()
		elif choice == 3:
			break	
		else:	
			print( " Error choice! " )
	except ValueError:
		print( " Error type of choice!! " )
	

