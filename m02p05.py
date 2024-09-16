#!/usr/bin/python 
import sys
num1 = input("First Number:")
num2 = input("Second Number:") 
operation = raw_input("Operation:")

if operation == "plus":
	result = float(num1)+float(num2)
	print num1, "+", num2, "=", result

if operation == "minus":
	result2 = float(num1)-float(num2) 
	print num1, "-", num2, "=", result2

if operation == "times":
	result3 = float(num1)*float(num2)
	print num1, "x", num2, "=", result3 

