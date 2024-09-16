#!/usr/bin/python

import os,sys
import time

file_name = raw_input ("File Name: ")
file_size = os.stat(file_name).st_size
file_inode = os.stat(file_name).st_ino
last_time = (os.stat(file_name).st_mtime)

file_list = [] 
file_list.append(file_name) 

for file_name in file_list:
	print "File Size:", file_size
	print "Inode    :", file_inode
	print "Last Mod :", time.ctime(last_time) 
	
	
