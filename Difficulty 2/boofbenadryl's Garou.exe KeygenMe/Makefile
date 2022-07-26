# Makefile by Carlos Zatarain
# 7/26/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

all:
	./garou.exe

keygen:
	g++ BGK_Keygen.cpp -o BGKKeygen.exe
	./BGKKeygen.exe
	rm BGKKeygen.exe

Win_keygen:
	g++ BGK_Keygen.cpp -o BGKKeygen.exe
	./BGKKeygen.exe
	del BGKKeygen.exe
