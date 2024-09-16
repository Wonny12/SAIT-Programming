#!/usr/bin/python 

import sys 


while 1: 
	enter = raw_input("Calc:") 
	
	if enter == "exit": 
		sys.exit(0) 

	num1,num2,operation = enter.split(" ")

	if operation == "times": 
		result = float(num1)*float(num2) 
		print float(num1),"x",float(num2), "=", result 

	if operation == "plus": 
		result2 = float(num1)+float(num2)
		print float(num1),"+",float(num2), "=", result2

	if operation == "minus": 
		result3 = float(num1)+float(num2)
		print float(num1),"-",float(num2), "=", result3 
