CC = g++
#CFLAGS = -c -Wall -std=c++11
CFLAGS = -g -Wall -std=c++11
CXXFLAGS = -g -Wall -std=c++11

#==========DIRECTORIES==========#
#Test Directory
TEST_DIR = Tests

#Build Directory
BUILD_DIR = Build

#Program Source Directories
SOURCE_DIR = ../Source
APPLICATION_DIR = $(SOURCE_DIR)/Application
ASSEMBLER_DIR = $(SOURCE_DIR)/Assembler
DATABASE_DIR = $(SOURCE_DIR)/Database
ENGINE_DIR = $(SOURCE_DIR)/Engine
LANGUAGE_DIR = $(SOURCE_DIR)/Language
UTILITY_DIR = $(SOURCE_DIR)/Utility

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
ALL_INC = $(TEST_INC) $(SOURCE_INC) -I.


#============OBJECTS============#
#Test Objects
TEST_SRC = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ = $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEST_SRC))

#Program Objects
APPLICATION_OBJ =
ASSEMBLER_OBJ = $(BUILD_DIR)/Assembler.o $(BUILD_DIR)/Parser.o $(BUILD_DIR)/Lexer.o $(BUILD_DIR)/Linter.o
DATABASE_OBJ = $(BUILD_DIR)/Database.o $(BUILD_DIR)/Types.o $(BUILD_DIR)/Datum.o
ENGINE_OBJ = $(BUILD_DIR)/Engine.o $(BUILD_DIR)/Logger.o
LANGUAGE_OBJ = 
UTILITY_OBJ = $(BUILD_DIR)/Exception.o

#Object Colletions
SOURCE_OBJ = $(APPLICATION_OBJ) $(ASSEMBLER_OBJ) $(DATABASE_OBJ) $(ENGINE_OBJ) $(LANGUAGE_OBJ) $(UTILITY_OBJ)
ALL_OBJ =  $(TEST_OBJ) $(SOURCE_OBJ) $(BUILD_DIR)/TestBench.o $(BUILD_DIR)/Test.o #$(TEST_DIR)/TestList.o

#Build Target
TARGET = Test


#=============RULES=============#
all: $(TARGET)

$(TARGET): $(ALL_OBJ)
	$(CC) $(CFLAGS) $(ALL_OBJ) $(ALL_INC) -o $@

#Tester Rules
$(BUILD_DIR)/Test.o: Test.cpp
	$(CC) $(CFLAGS) $(ALL_INC) -c Test.cpp -o $(BUILD_DIR)/Test.o

$(BUILD_DIR)/TestBench.o: TestBench.cpp TestBench.h
	$(CC) $(CFLAGS) $(ALL_INC) -c TestBench.cpp -o $(BUILD_DIR)/TestBench.o

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp $(SOURCE_OBJ) $(BUILD_DIR)/TestBench.o
	$(CC) $(CFLAGS) $(ALL_INC) -c $< -o $@ 


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

clean:
	#-rm -f *.o
	-rm -f $(BUILD_DIR)/*.o
	-rm -f $(TEST_DIR)/*.o
	-rm -f $(TARGET) 