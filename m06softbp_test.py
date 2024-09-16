import m06events 
from my_debugger_defines import *

debugger = m06events.debugger()

pid = raw_input("Enter the PID of the process to attach to: ")

debugger.attach(int(pid))

printf = debugger.func_resolve("msvcrt.dll","printf")
print "Address of printf: 0x%08x" % printf_address

debugger.bp_set(printf_address) 

debugger.run()
