#!/usr/bin/python 

def pascal(row,col): #recursive function pascal(row,col) calculating row and col  
	if (col == 0):  #conditions Jan gave us as tips :) 
		return 1
	elif (row == col): #same
		return 1 
	else:
		return pascal(row-1,col) + pascal(row-1,col-1) #same

def main(rows): #main function to print pascal
	for counter1 in range(0,rows):
		for white_space in range(0,rows - counter1): #two for loops inorder to print the white space
			print " ",

		for counter2 in range(0,counter1+1):
			print pascal(counter1,counter2),
			print " ",


		print '\n',

main(10)
