.DEFAULT_GOAL := all

OPTION   	 = -std=c++11 -Wno-write-strings -I.
LINK     	 = build/crypto.o build/aes.o build/obsoleteaes.o build/aeskey.o build/aesdata.o build/rsa.o build/rsakey.o build/rsadata.o
CPP      	 = g++
DEL      	 = rm -rf
COPY     	 = cp
MKDIR	 	 = mkdir
EXPORT 		 = export 
BOTAN_OPTION = $(shell botan config cflags)
BOTAN_LINK   = $(shell botan config libs | grep -o "^\S*")

.PHONY: clean aes obsoleteaes aesdata aeskey rsa rsadata rsakey crypto main

clean:
	$(DEL) build
	$(MKDIR) build
aes:
	$(CPP) $(OPTION) ${BOTAN_OPTION} -c aes/aes.cpp -o build/aes.o
obsoleteaes:
	$(CPP) $(OPTION) ${BOTAN_OPTION} -c aes/obsoleteaes.cpp -o build/obsoleteaes.o
aesdata:
	$(CPP) $(OPTION) ${BOTAN_OPTION} -c aes/aesdata.cpp -o build/aesdata.o
aeskey:
	$(CPP) $(OPTION) ${BOTAN_OPTION} -c aes/aeskey.cpp -o build/aeskey.o
rsa:
	$(CPP) $(OPTION) ${BOTAN_OPTION} -c rsa/rsa.cpp -o build/rsa.o
rsadata:
	$(CPP) $(OPTION) ${BOTAN_OPTION} -c rsa/rsadata.cpp -o build/rsadata.o
rsakey:
	$(CPP) $(OPTION) ${BOTAN_OPTION} -c rsa/rsakey.cpp -o build/rsakey.o
crypto:
	$(CPP) $(OPTION) ${BOTAN_OPTION} -c crypto.cpp -o build/crypto.o
test:
	$(CPP) $(OPTION) ${BOTAN_OPTION} test.cpp $(LINK) ${BOTAN_LINK} -o build/test
all: clean aes obsoleteaes aesdata aeskey rsa rsadata rsakey crypto test