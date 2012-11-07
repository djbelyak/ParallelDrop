CC=g++
CFLAGS= -fopenmp -O2 -g -Wall -fmessage-length=0 
LDFLAGS= -lm -lrt -lglut -lglut -lGLU
SOURCES= OpenGLVizualizator.cpp ParallelDrop.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ParallelDrop

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
