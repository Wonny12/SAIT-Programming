#!/usr/bin/python 
import struct
import sys

def dump(clist):
	print "\n[%08x]: " % bytecount,
	for x in clist:
		print "%02x" % x,

	line = ""
	for x in clist:
		if x == ord('\n'):
			print " ",
		else:
			line = line + chr(x)
	print line,
			
			


file_name = raw_input("File : ")
f = open(file_name, "rb")
clist = [] 
bytecount = 0
while (1):
    rv = f.read(1)
    if rv=="": break
    bytecount = bytecount + 1
    rv_i = struct.unpack('b',rv)[0]
    clist.append(rv_i)
    if len(clist)==16:
        dump(clist)
        clist = []

dump(clist)
print "\nTotal Length %d (%02x)" % (bytecount, bytecount),

