# Makefile by Carlos Zatarain
# 7/17/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

all:
	./Second_Program.exe

keygen:
	g++ SSP_Keygen.cpp -o SSPKeygen.exe
	./SSPKeygen.exe
	rm SSPKeygen.exe

Win_keygen:
	g++ SSP_Keygen.cpp -o SSPKeygen.exe
	./SSPKeygen.exe
	del SSPKeygen.exe
