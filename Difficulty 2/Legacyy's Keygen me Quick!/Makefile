# Makefile by Carlos Zatarain
# 7/9/2022

.SILENT: all
.SILENT: keygen
.SILENT: Win_keygen

all:
	./keygenme_1.exe

keygen:
	g++ KMQ_Keygen.cpp -o KMQ_Keygen.exe
	./KMQ_Keygen.exe
	rm KMQ_Keygen.exe

Win_keygen:
	g++ KMQ_Keygen.cpp -o KMQ_Keygen.exe
	./KMQ_Keygen.exe
	del KMQ_Keygen.exe
