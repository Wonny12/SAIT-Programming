#!/usr/bin/python

def print_user_line(username):
	if username=="None":
		print "+----------------------+----------------------+"
		return 
	fp = open("/etc/passwd", "r");
	home_directory = ""
	for line in fp:
		new_line = line.split(":")
		if username==new_line[0]:
			home_directory = new_line[5]
			break
	fp.close
	if home_directory!="":
		print "|",
		print "%-20s" % username, 
		print "|",
		print "%-20s" % home_directory,
		print "|"
	return 


fp = open("/etc/passwd", "r");
print_user_line("None")
for line in fp:
	new_line = line.split(":")
	print_user_line(new_line[0])
fp.close
print_user_line("None") 

