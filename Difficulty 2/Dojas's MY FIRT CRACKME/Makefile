# Makefile by Carlos Zatarain
# 7/7/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

all:
	./prograsmaisje.exe

keygen:
	g++ DMFC_Keygen.cpp -o DFKeygen.exe
	./DFKeygen.exe
	rm DFKeygen.exe

Win_keygen:
	g++ DMFC_Keygen.cpp -o DFKeygen.exe
	./DFKeygen.exe
	del DFKeygen.exe
