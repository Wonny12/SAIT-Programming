#!/usr/bin/python 

import time
#from pyutmp import UtmpFile

#current_time = time.time()
#login_list = []
#for utmp in UtmpFile():
	#if utmp.ut_user_process and current_time-utmp.ut_time <= 86400:
		#local_time = time.localtime(utmp.ut_time)
		#login_entry = '%d-%02d-%02d %02d:%02d:%02d %s %s %s' % ( \
			#local_time.tm_year, local_time.tm_mon, local_time.tm_mday, \
			#local_time.tm_hour, local_time.tm_min, local_time.tm_sec, \
			#utmp.ut_user, utmp.ut_host, utmp.ut_line) 
		#login_list.append(login_entry)

#login_list.sort(reverse=True)
#for login_entry in login_list:
	#print login_entry 
import datetime
now = datetime.datetime.now()
print now.year, now.month, now.day, now.hour, now.minute, now.second
