# Makefile by Carlos Zatarain
# 7/13/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

all:
	./ReverseMe.exe

keygen:
	g++ ALSP_Keygen.cpp -o ALSPKeygen.exe
	./ALSPKeygen.exe
	rm ALSPKeygen.exe

Win_keygen:
	g++ ALSP_Keygen.cpp -o ALSPKeygen.exe
	./ALSPKeygen.exe
	del ALSPKeygen.exe
