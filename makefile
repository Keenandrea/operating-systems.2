CC = gcc
CFLAGS = -g
TARGET = logParse
OBJS = main.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
clean:
	rm -f *.o $(TARGET)