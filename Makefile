CC=g++
CFLAGS= -fopenmp -O2 -g -Wall -fmessage-length=0 -fpermissive
LDFLAGS= 
SOURCES= OpenGLVizualizator.cpp ParallelDrop.cpp Greed.cpp
LIBS= -lm -lrt -lglut -lGLU -lgomp

all: 
	$(CC) -c $(CFLAGS) ParallelDrop.cpp
	$(CC) -c $(CFLAGS) OpenGLVizualizator.cpp
	$(CC) -c $(CFLAGS) Greed.cpp
	$(CC) -o ParallelDrop ParallelDrop.o OpenGLVizualizator.o Greed.o $(LIBS)

	
clean:
	rm -rf *.o ParallelDrop