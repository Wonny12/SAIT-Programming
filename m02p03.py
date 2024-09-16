#!/usr/bin/python 
import keyword

wordlist = keyword.kwlist

counter1 = 0 

for counter1 in range(len(wordlist)): 
	print wordlist[counter1] 

counter2 = 30 

for line in range(len(wordlist)): 
	print wordlist[counter2] 
	counter2 -= 1

