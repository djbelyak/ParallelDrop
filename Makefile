CC=g++
CFLAGS= -fopenmp -O2 -g -Wall -fmessage-length=0  
LDFLAGS= 
SOURCES= OpenGLVizualizator.cpp ParallelDrop.cpp 
LIBS= -lm -lrt -lglut -lGLU

all: 
	$(CC) -c $(CFLAGS) ParallelDrop.cpp
	$(CC) -c $(CFLAGS) OpenGLVizualizator.cpp
	$(CC) -o ParallelDrop ParallelDrop.o OpenGLVizualizator.o $(LIBS)

	
clean:
	rm -rf *.o ParallelDrop