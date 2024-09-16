import m06attach

debugger = m06attach.debugger() 

pid = raw_input ("Enter the PID of the prcoess to attach to: ") 

debugger.attach(int(pid)) 

debugger.detach() 
