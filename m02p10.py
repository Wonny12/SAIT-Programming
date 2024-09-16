#!/usr/bin/python 
def pascal(row):
	next_row = [1]
	for cell in range(1,len(row)):
		next_row.append(row[cell-1]+row[cell])
	next_row.append(1)
	return next_row

row = [1]
while 1:
	line = ""
	for lines in row:
		line += str(lines) + " "
	if len(line) >= 80:
		break
	for i in range(0, (80-len(line))/2):
		print "",
	print line 
	row = pascal(row)
