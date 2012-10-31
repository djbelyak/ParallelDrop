CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c99 

OBJS =		ParallelDrop.o

LIBS =		-lm -lrt -lglut 

TARGET =	ParallelDrop

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
