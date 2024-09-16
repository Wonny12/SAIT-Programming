#!/usr/bin/python 

from immlib import * 

def main(args):
	imm=Debugger()
	#Using the function imm.getAddress (from immlib) 
	address=imm.getAddress("nss3.PR_Write")

	pyhook = firefoxexe() 

	pyhook.add( "%08x" % address, address) 

	return "Firefox hooking is prepared"

class firefoxexe (hook):
	
	def __init__(self):
		
		self.imm=Debugger();

		hook.__init__(self) 

	def execution(self,register):
		#getting address of registers 
		register_address = self.imm.readLong(regs['ESP']+8) 
		#convert to string 	
		str = self.imm.readString(register_address) 

		self.imm.log(" nss3.PR_Write [0x%x] <- %s" (register_address,str)   
		filemanagement = open(self.logfile, "a"); 
		
		filemanagement.write(str) 

		filemanagement.close() 
	

	
