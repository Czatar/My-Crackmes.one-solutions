# Makefile by Carlos Zatarain
# 7/8/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

all:
	./Untitled3.exe

keygen:
	g++ DM_Keygen.cpp -o DM_Keygen.exe
	./DM_Keygen.exe
	rm DM_Keygen.exe

Win_keygen:
	g++ DM_Keygen.cpp -o DM_Keygen.exe
	./DM_Keygen.exe
	del DM_Keygen.exe
