#!/usr/bin/python 
import os,sys 
class LinuxProcList: 
	def proclist(self): 
		dir_list = os.listdir('/proc') 
		pid_list = []
		for x in dir_list:
			if x.isdigit(): 
				pid_list.append(int(x)) 
		return pid_list

	def cmdline(self,pid):
		file_name = "/proc/"+str(pid)+"/cmdline" 
		file_open = open(file_name, "r")  
		file_read = file_open.read() 
		if file_read=="": 
			return None  
		else: 
			return file_read
	
	def get_ppid(self,pid):
		file_name = "/proc/"+str(pid)+"/stat" 
		file_open = open(file_name, "r")
		file_read = file_open.read() 
		word_list = file_read.split() 
		ppid = int(word_list[3]) 
		file_open.close()
		return ppid

	def children(self,param_pid):
		all_pids = self.proclist() 
		cpid_list = []
		for x in all_pids:
			x_ppid = self.get_ppid(x)
			if x_ppid == param_pid:
				cpid_list.append(x) 
		return cpid_list

	def pstree(self): 
		all_pids = self.proclist() 
		for x in all_pids: 
			get_cmd = self.cmdline(x) 
			if get_cmd:
				print x,get_cmd

#main 
x= LinuxProcList()
#my_pid = int(raw_input("Enter pid: ")) 
#print x.proclist() 
#print x.cmdline(my_pid)
#print x.children(my_pid)
print x.pstree() 
