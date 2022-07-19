# Makefile by Carlos Zatarain
# 7/14/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

all:
	./f_crackme.exe

keygen:
	g++ TKFC_Keygen.cpp -o TKFCKeygen.exe
	./TKFCKeygen.exe
	rm TKFCKeygen.exe

Win_keygen:
	g++ TKFC_Keygen.cpp -o TKFCKeygen.exe
	./TKFCKeygen.exe
	del TKFCKeygen.exe
