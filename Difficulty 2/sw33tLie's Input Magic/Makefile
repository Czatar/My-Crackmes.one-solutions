# Makefile by Carlos Zatarain
# 7/28/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

all:
	./'Input Magic.exe'

keygen:
	g++ SIM_Keygen.cpp -o SIMKeygen.exe
	./SIMKeygen.exe
	rm SIMKeygen.exe

Win_keygen:
	g++ SIM_Keygen.cpp -o SIMKeygen.exe
	./SIMKeygen.exe
	del SIMKeygen.exe
