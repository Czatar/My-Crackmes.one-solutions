# Makefile by Carlos Zatarain
# 7/18/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

all:
	./KidoCrackMe.exe

keygen:
	g++ LKM_Keygen.cpp -o LKMKeygen.exe
	./LKMKeygen.exe
	rm LKMKeygen.exe

Win_keygen:
	g++ LKM_Keygen.cpp -o LKMKeygen.exe
	./LKMKeygen.exe
	del LKMKeygen.exe
