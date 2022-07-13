# Makefile by Carlos Zatarain
# 7/12/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

all:
	./oldsofts_keygenme_2.exe

keygen:
	g++ WOK2_Keygen.cpp -o OK2Keygen.exe
	./OK2Keygen.exe
	rm OK2Keygen.exe

Win_keygen:
	g++ WOK2_Keygen.cpp -o OK2Keygen.exe
	./OK2Keygen.exe
	del OK2Keygen.exe
