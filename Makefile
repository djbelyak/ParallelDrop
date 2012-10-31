CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		ParallelDrop.o

LIBS =

TARGET =	ParallelDrop

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
