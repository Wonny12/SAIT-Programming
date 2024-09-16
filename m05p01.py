#!/usr/bin/python 

from ctypes import *
import os
import sys 

my_pid = os.getpid() 
file_name = "/proc/"+str(my_pid)+"/stat" 

f = open(file_name, 'r') 
fp = f.read() 
word_list = fp.split() 

test = cdll.LoadLibrary("libprintproc.so") 

test.printproc((word_list[2][0]),int(word_list[3]),int(word_list[7]),int(word_list[25]),int(word_list[27]),int(word_list[28]),int(word_list[29]))


