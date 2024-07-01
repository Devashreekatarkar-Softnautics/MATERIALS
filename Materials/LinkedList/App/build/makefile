CC=gcc
MKR=mkdir
SRC_DIR= ../src/*.c
SRC= ../src
DEST= ../bin
IN= -I  ../../Library/include
LIB = -L ../../Library/lib -llist
$(DEST)/app: $(SRC)/app.o
	$(MKR) $(DEST)
	$(CC) $^ $(LIB) -o $@ 

$(SRC)/app.o: $(SRC_DIR) 
	$(CC) -c $^ $(IN) -o $@ 
 
clean: 
	rm -rf $(DEST)
	rm $(SRC)/*.o

	
