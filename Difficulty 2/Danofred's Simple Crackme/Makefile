# Makefile by Carlos Zatarain
# 7/16/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

all:
	./'simple crackme.exe'

keygen:
	g++ DSC_Keygen.cpp -o DSCKeygen.exe
	./DSCKeygen.exe
	rm DSCKeygen.exe

Win_keygen:
	g++ DSC_Keygen.cpp -o DSCKeygen.exe
	./DSCKeygen.exe
	del DSCKeygen.exe
