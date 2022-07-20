# Makefile by Carlos Zatarain
# 7/20/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

all:
	./'keygenMe - 01.exe'

keygen:
	g++ DKM1_Keygen.cpp -o DKM1Keygen.exe
	./DKM1Keygen.exe
	rm DKM1Keygen.exe

Win_keygen:
	g++ DKM1_Keygen.cpp -o DKM1Keygen.exe
	./DKM1Keygen.exe
	del DKM1Keygen.exe
