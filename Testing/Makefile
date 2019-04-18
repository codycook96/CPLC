CC = g++
#CFLAGS = -c -Wall -std=c++11
CFLAGS = -g -Wall -std=c++11
CXXFLAGS = -g -Wall -std=c++11

#==========DIRECTORIES==========#
#Test Directory
TEST_DIR = Tests

#Build Directory
BUILD_DIR = $(TEST_DIR)/Build

#Program Source Directories
SOURCE_DIR = ../Source
APPLICATION_DIR = $(SOURCE_DIR)/Application
ASSEMBLER_DIR = $(SOURCE_DIR)/Assembler
DATABASE_DIR = $(SOURCE_DIR)/Database
ENGINE_DIR = $(SOURCE_DIR)/Engine
LANGUAGE_DIR = $(SOURCE_DIR)/Language
UTILITY_DIR = $(SOURCE_DIR)/Utility

#Testing Directories
TEST_APPLICATION_DIR = $(TEST_DIR)/Application
TEST_ASSEMBLER_DIR = $(TEST_DIR)/Assembler
TEST_DATABASE_DIR = $(TEST_DIR)/Database
TEST_ENGINE_DIR = $(TEST_DIR)/Engine
TEST_LANGUAGE_DIR = $(TEST_DIR)/Language
TEST_UTILITY_DIR = $(TEST_DIR)/Utility

#============INCLUDE============#
#Test Include
TEST_INC = -I$(TEST_DIR)

#Project Include
APPLICATION_INC = -I$(APPLICATION_DIR)
ASSEMBLER_INC = -I$(ASSEMBLER_DIR)
DATABASE_INC = -I$(DATABASE_DIR)
ENGINE_INC = -I$(ENGINE_DIR)
LANGUAGE_INC = -I$(LANGUAGE_DIR)
UTILITY_INC = -I$(UTILITY_DIR)
SOURCE_INC = $(APPLICATION_INC) $(ASSEMBLER_INC) $(DATABASE_INC) $(ENGINE_INC) $(LANGUAGE_INC) $(UTILITY_INC)

#All Include
ALL_INC = $(TEST_INC) $(SOURCE_INC)


#============OBJECTS============#
#Test Objects
TEST_OBJ = $(BUILD_DIR)/Test.o $(BUILD_DIR)/TestBench.o

#Program Objects
APPLICATION_OBJ =
ASSEMBLER_OBJ = $(BUILD_DIR)/Assembler.o $(BUILD_DIR)/Parser.o $(BUILD_DIR)/Lexer.o $(BUILD_DIR)/Linter.o
DATABASE_OBJ = $(BUILD_DIR)/Database.o $(BUILD_DIR)/Types.o $(BUILD_DIR)/Datum.o
ENGINE_OBJ = $(BUILD_DIR)/Engine.o $(BUILD_DIR)/Logger.o
LANGUAGE_OBJ = 
UTILITY_OBJ = $(BUILD_DIR)/Exception.o

#Object Colletions
SOURCE_OBJ = $(APPLICATION_OBJ) $(ASSEMBLER_OBJ) $(DATABASE_OBJ) $(ENGINE_OBJ) $(LANGUAGE_OBJ) $(UTILITY_OBJ)
ALL_OBJ =  $(TEST_OBJ) $(SOURCE_OBJ)

#Build Target
TARGET = Test


#=============RULES=============#
all: $(TARGET)

$(TARGET): $(ALL_OBJ)
	$(CC) $(CFLAGS) $(ALL_OBJ) $(ALL_INC) -o $@

#Test Rules
$(BUILD_DIR)/Test.o: $(TEST_DIR)/Test.cpp
	$(CC) $(CFLAGS) $(TEST_INC) -c $(TEST_DIR)/Test.cpp -o $(BUILD_DIR)/Test.o

$(BUILD_DIR)/TestBench.o: $(TEST_DIR)/TestBench.cpp $(TEST_DIR)/TestBench.h
	$(CC) $(CFLAGS) $(TEST_INC) -c $(TEST_DIR)/TestBench.cpp -o $(BUILD_DIR)/TestBench.o

#Application Rules

#Assembler Rules
$(BUILD_DIR)/Assembler.o: $(ASSEMBLER_DIR)/Assembler.cpp $(ASSEMBLER_DIR)/Assembler.h
	$(CC) $(CFLAGS) $(ASSEMBLER_INC) -c $(ASSEMBLER_DIR)/Assembler.cpp -o $(BUILD_DIR)/Assembler.o

$(BUILD_DIR)/Parser.o: $(ASSEMBLER_DIR)/Parser.cpp $(ASSEMBLER_DIR)/Parser.h
	$(CC) $(CFLAGS) $(ASSEMBLER_INC) -c $(ASSEMBLER_DIR)/Parser.cpp -o $(BUILD_DIR)/Parser.o

$(BUILD_DIR)/Lexer.o: $(ASSEMBLER_DIR)/Lexer.cpp $(ASSEMBLER_DIR)/Lexer.h
	$(CC) $(CFLAGS) $(ASSEMBLER_INC) -c $(ASSEMBLER_DIR)/Lexer.cpp -o $(BUILD_DIR)/Lexer.o

$(BUILD_DIR)/Linter.o: $(ASSEMBLER_DIR)/Linter.cpp $(ASSEMBLER_DIR)/Linter.h
	$(CC) $(CFLAGS) $(ASSEMBLER_INC) -c $(ASSEMBLER_DIR)/Linter.cpp -o $(BUILD_DIR)/Linter.o

#Database Rules
$(BUILD_DIR)/Database.o: $(DATABASE_DIR)/Database.cpp $(DATABASE_DIR)/Database.h
	$(CC) $(CFLAGS) $(DATABASE_INC) $(UTILITY_INC) -c $(DATABASE_DIR)/Database.cpp -o $(BUILD_DIR)/Database.o

$(BUILD_DIR)/Types.o: $(DATABASE_DIR)/Types.cpp $(DATABASE_DIR)/Types.h
	$(CC) $(CFLAGS) $(DATABASE_INC) -c $(DATABASE_DIR)/Types.cpp -o $(BUILD_DIR)/Types.o

$(BUILD_DIR)/Datum.o: $(DATABASE_DIR)/Datum.cpp $(DATABASE_DIR)/Datum.h
	$(CC) $(CFLAGS) $(DATABASE_INC) -c $(DATABASE_DIR)/Datum.cpp -o $(BUILD_DIR)/Datum.o

#Engine Rules
$(BUILD_DIR)/Engine.o: $(ENGINE_DIR)/Engine.cpp $(ENGINE_DIR)/Engine.h
	$(CC) $(CFLAGS) $(ENGINE_INC) -c $(ENGINE_DIR)/Engine.cpp -o $(BUILD_DIR)/Engine.o

$(BUILD_DIR)/Logger.o: $(ENGINE_DIR)/Logger.cpp $(ENGINE_DIR)/Logger.h
	$(CC) $(CFLAGS) $(ENGINE_INC) -c $(ENGINE_DIR)/Logger.cpp -o $(BUILD_DIR)/Logger.o

#Language Rules

#Utility Rules
$(BUILD_DIR)/Exception.o: $(UTILITY_DIR)/Exception.cpp $(UTILITY_DIR)/Exception.h
	$(CC) $(CFLAGS) $(UTILITY_INC) -c $(UTILITY_DIR)/Exception.cpp -o $(BUILD_DIR)/Exception.o

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
	-rm -f $(BUILD_DIR)*.o
	-rm -f $(TARGET)