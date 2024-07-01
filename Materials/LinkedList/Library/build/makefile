CC = gcc
SRC = ../src
CFLAGS = -Wall -I ../include
ARV = ../lib
MKR = mkdir 
AR = ar rcs

$(ARV)/liblist.a: $(SRC)/LinkedList.o
	$(MKR) $(ARV)
	$(AR) $@ $<	

$(SRC)/LinkedList.o: $(SRC)/LinkedList.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(ARV)
	rm $(SRC)/*.o



