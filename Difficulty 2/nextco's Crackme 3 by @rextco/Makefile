# Makefile by Carlos Zatarain
# 7/29/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

# Usage: "make PASS=(generated password)"
all:
	./crackme-3.exe $(PASS)

keygen:
	g++ NC3R_Keygen.cpp -o NC3RKeygen.exe
	./NC3RKeygen.exe
	rm NC3RKeygen.exe

Win_keygen:
	g++ NC3R_Keygen.cpp -o NC3RKeygen.exe
	./NC3RKeygen.exe
	del NC3RKeygen.exe
