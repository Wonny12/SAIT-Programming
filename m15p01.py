import win32con^M
import win32api^M
import win32security^M
^M
import wmi^M
import sys^M
import os^M
^M
^M
def log_to_file(message):^M
    fd = open("process_monitor_log.csv", "ab")^M
    fd.write("%s\r\n" % message)^M
    fd.close()^M
^M
    return^M
^M
# create a log file header^M
^M
log_to_file("Time,User,Executable,CommandLine,PID,ParentPID,Privileges")^M
^M
# instantiate the WMI interface^M
c = wmi.WMI()^M
^M
# create our process monitor^M
process_watcher = c.Win32_Process.watch_for("creation")^M
^M
^M
while True:^M
    try:^M
        new_process = process_watcher()^M
^M
        proc_owner  = new_process.GetOwner()^M
        proc_owner  = "%s\\%s" % (proc_owner[0],proc_owner[2])^M
        create_date = new_process.CreationDate^M
        executable  = new_process.ExecutablePath^M
        cmdline     = new_process.CommandLine^M
        pid         = new_process.ProcessId^M
        parent_pid  = new_process.ParentProcessId^M
^M
        privileges  = "N/A"^M
^M
        process_log_message = "%s, %s, %s,%s,%s,%s,%s\r\n" % (create_date, proc_owner, executable, cmdline, pid, parent_pid,privileges)^M
  = "N/A"^M
^M
        process_log_message = "%s, %s, %s,%s,%s,%s,%s\r\n" % (create_date, proc_owner, executable, cmdline, pid, parent_pid,privileges)^M
^M
        print process_log_message^M
^M
        log_to_file(process_log_message)^M
^M
    except:^M
        pass^M
~                        
