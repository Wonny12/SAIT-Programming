#!/usr/bin/python 

import socket 
import os,sys 

fp = open("/proc/meminfo", "r") 

eachlines = fp.readline(27).split() 

memory = (int(eachlines[1])/1024) 

print "Hostname:", (socket.gethostname()),",", "Memory: ",memory, " MB"  
