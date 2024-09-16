#!/usr/bin/python 

import sys 

num1 = sys.argv[1] 

num2 = sys.argv[2] 

operation = sys.argv[3] 

if operation == "plus": 
	result = float(num1)+float(num2) 
if operation == "minus": 
	result2 = float(num1)-float(num2) 
if operation == "times": 
	result3 = float(num1)*float(num2) 

if operation == "plus": 
	print num1, "+", num2, "=", result 
if operation == "minus": 
	print num1, "-", num2, "=", result2 
if operation == "times": 
	print num1, "x", num2, "=", result3
