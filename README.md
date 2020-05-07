# <center>DailyExpenditureRecords</center> 
## Introduction 
You need a tool to record daily expenditure and your cash flow if you have the hard time saving money. The DailyExpenditureRecords is born for those who spend their money unnoticeable. 
The DailyExpenditureRecords is an application that record your daily expenditure and track your cash flow in order to make good use of your money and more effeciently. <br> 
<br> 

This application is developed using <br> 
1. Programming language: C 
2. Compiler: GNU GCC 7.5.0 
3. Built tool: GNU Make 4.1 

## Requirements 
1. GNU GCC 
2. Make 

## Features
* Record daily expense.
* Record daily income.
* Uncover and keep track on the detail of cash flow.
* Calculate your total balance and expense automatically.
* Calculate your expense on eat, transportation, and other things. 

## Install  
To use this application, you need to clone this repository. 
```
    $ git clone https://github.com/wukaihua119/DailyExpenditureRecords.git  
``` 
Move to the root directory of this project. Run the command below if you are the first time to execute this application. 
```
    // only compile the souce code. 
    $ make build  
    // or run for unix-like system. 
    $ ./startup.sh 
    // windows 
    $ startup.bat 
```
or 
```
    // not only compile the source code but also execute the binary code to run the application. 
    $ make build_exec 
```

## Start to use 
To Start the application 
```
    $ make exec 
```
You can run command ``` $./Account ``` under Unix-like system or ``` $Account.exe ```under Windows. 

After execute above command you can input your existing filename or just type the new filename to create a new file.  

![start](https://github.com/wukaihua119/DailyExpenditureRecords/blob/master/DailyExpenditureRecords/resource/pics/start.PNG)

Then you are in the main menu. Just choose one. 

![menu](https://github.com/wukaihua119/DailyExpenditureRecords/blob/master/DailyExpenditureRecords/resource/pics/menu.PNG) 

After inputing your records you will see the results. 

![detail](https://github.com/wukaihua119/DailyExpenditureRecords/blob/master/DailyExpenditureRecords/resource/pics/detail.PNG)
