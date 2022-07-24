# Makefile by Carlos Zatarain
# 7/24/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

all:
	./crackme.exe

keygen:
	g++ MCD2_Keygen.cpp -o MCD2Keygen.exe
	./MCD2Keygen.exe
	rm MCD2Keygen.exe

Win_keygen:
	g++ MCD2_Keygen.cpp -o MCD2Keygen.exe
	./MCD2Keygen.exe
	del MCD2Keygen.exe
