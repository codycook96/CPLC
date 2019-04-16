CC = g++
#CFLAGS = -c -Wall -std=c++11
CFLAGS = -g -Wall -std=c++11
CXXFLAGS = -g -Wall -std=c++11

TEST = Tests/
BUILD = $(TEST)Build/
SOURCE = ../Source/
INCLUDE = -I$(SOURCE) -I$(TEST)

#SOURCES = $(TEST)Test.cpp $(TEST)TestBench.cpp $(SOURCE)Data.cpp $(SOURCE)Type.cpp  $(SOURCE)Database.cpp

OBJTEST = $(BUILD)Test.o $(BUILD)TestBench.o
OBJSOURCE = $(BUILD)Data.o $(BUILD)Type.o $(BUILD)Database.o
OBJALL =  $(OBJTEST) $(OBJSOURCE)

TARGET = Test

all: $(TARGET)

$(TARGET): $(OBJALL)
	$(CC) $(CFLAGS) $(OBJALL) $(INCLUDE) -o $@

$(BUILD)Test.o: $(TEST)Test.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $(TEST)Test.cpp -o $(BUILD)Test.o

$(BUILD)TestBench.o: $(TEST)TestBench.cpp $(TEST)TestBench.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $(TEST)TestBench.cpp -o $(BUILD)TestBench.o

$(BUILD)Data.o: $(SOURCE)Data.cpp $(SOURCE)Data.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SOURCE)Data.cpp -o $(BUILD)Data.o

$(BUILD)Type.o: $(SOURCE)Type.cpp $(SOURCE)Type.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SOURCE)Type.cpp -o $(BUILD)Type.o

$(BUILD)Database.o: $(SOURCE)Database.cpp $(SOURCE)Database.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SOURCE)Database.cpp -o $(BUILD)Database.o


####### Implicit rules
#all: $(SOURCES) $(TARGET)

#.SUFFIXES: .o .c .cpp .cc .cxx .C

#$(TARGET): $(OBJECTS)
#	$(CXX) $(OBJECTS) $(CXXFLAGS) $(INCLUDE) -o $@

#.cpp.o:
#	$(CXX) -c $(CXXFLAGS) $(INCLUDE) -o "$@" "$<"

#.cc.o:
#	$(CXX) -c $(CXXFLAGS) $(INCLUDE) -o "$@" "$<"

#.cxx.o:
#	$(CXX) -c $(CXXFLAGS) $(INCLUDE) -o "$@" "$<"

#.C.o:
#	$(CXX) -c $(CXXFLAGS) $(INCLUDE) -o "$@" "$<"

#.c.o:
#	$(CC) -c $(CFLAGS) $(INCLUDE) -o "$@" "$<"

clean:
	#-rm -f *.o
	-rm -f $(BUILD)*.o
	-rm -f $(TARGET)