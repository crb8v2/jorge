CC = gcc
CFLAGS = -g
T1 = Master
T2  = Worker 
O1 =  Master.o 
O2 = Worker.o

all: $(T1) $(T2)

Master: $(O1)
	$(CC) $(CFLAGS) -o Master Master.o

worker: $(O2)
	$(CC) $(FLAGS) -o Worker Worker.o
clean:
	/bin/rm -f *.o $(TARGET)
	/bin/rm -f Master $(TARGET) 
	/bin/rm -f Worker $(TARGET)
