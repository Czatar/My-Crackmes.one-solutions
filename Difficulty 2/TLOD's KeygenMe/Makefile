# Makefile by Carlos Zatarain
# 7/22/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

all:
	./KeygenMe.exe

keygen:
	g++ TKM_Keygen.cpp -o TKMKeygen.exe
	./TKMKeygen.exe
	rm TKMKeygen.exe

Win_keygen:
	g++ TKM_Keygen.cpp -o TKMKeygen.exe
	./TKMKeygen.exe
	del TKMKeygen.exe
