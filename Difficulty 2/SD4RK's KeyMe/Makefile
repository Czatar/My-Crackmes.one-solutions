# Makefile by Carlos Zatarain
# 7/25/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

all:
	./CrackMe.exe

keygen:
	g++ SKM_Keygen.cpp -o SKMKeygen.exe
	./SKMKeygen.exe
	rm SKMKeygen.exe

Win_keygen:
	g++ SKM_Keygen.cpp -o SKMKeygen.exe
	./SKMKeygen.exe
	del SKMKeygen.exe
