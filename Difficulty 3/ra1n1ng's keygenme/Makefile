# Makefile by Carlos Zatarain
# 7/21/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

all:
	./keygenme.exe

keygen:
	g++ RKM_Keygen.cpp -o RKMKeygen.exe
	./RKMKeygen.exe
	rm RKMKeygen.exe

Win_keygen:
	g++ RKM_Keygen.cpp -o RKMKeygen.exe
	./RKMKeygen.exe
	del RKMKeygen.exe
