#!/usr/bin/python 
import struct 

file_name = raw_input("File   : ")

f = open(file_name, "rb")

magic = (f.read(4))

magic_i = struct.unpack('i',magic)[0]

print "Magic  :", hex(magic_i)

fmt = f.read(1)

fmt_i = struct.unpack('b',fmt)[0]

if fmt_i == 1: 
	print "Format : 32-bit"

elif fmt_i == 2:
	print "Format : 64-bit"

endian = f.read(1) 

endian_i = struct.unpack('b',endian)[0] 

if endian_i == 1:
	print "Endian : little"
elif endian_i == 2:
	print "Endian : big"
else:
	print "Endian : unknown"

f.seek(0x12) 

machine = f.read(2)

machine_i = struct.unpack('h',machine)[0]

if machine_i == 0x00:
	print "No specific instruction set" 

elif machine_i == 0x02:
	print "Machine: SPARC"

elif machine_i == 0x03:
	print "Machine: x86"

elif machine_i == 0x08:
	print "Machine: MIPS"

elif machine_i == 0x14:
	print "Machine: PowerPC"

elif machine_i == 0x16:
	print "Machine: S390"

elif machine_i == 0x28:
	print "Machine: ARM"

elif machine_i == 0x2A:
	print "Machine: SuperH"

elif machine_i == 0x32:
	print "Machine: IA-64"

elif machine_i == 0x3E:
	print "Machine: x86-64"

elif machine_i == 0xB7:
	print "Machine: AArch64" 

elif machine_i == 0xF3:
	print "Machine: RISC-V"

else: 
	print "Machine: Unknown"
