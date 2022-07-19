# Makefile by Carlos Zatarain
# 7/19/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

all:
	./SerialActivation.exe

keygen:
	g++ MRSA_Keygen.cpp -o MRSAKeygen.exe
	./MRSAKeygen.exe
	rm MRSAKeygen.exe

Win_keygen:
	g++ MRSA_Keygen.cpp -o MRSAKeygen.exe
	./MRSAKeygen.exe
	del MRSAKeygen.exe
