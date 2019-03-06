# CPLC - The Open PLC Development Platform

[1] [Changelog](/CHANGELOG.md) [2] [Testing Reports](/Testing/TESTING.md) [3] [Contributing Guidelines](/CONTRIBUTING.md) [4] [License](/License) 

## Mission

The PLC Project is an open source project aims to create a free, simple, and modular platform for anyone to be able to learn PLC program and develop their own PLC programs on a wide variety of hardware.  


## Goals

+ Creating a readable text based PLC language that aligns with [1] IEC 61131-3 [[Language](#Defining-the-Language)]

+ Creating a C++ based interpreter and compiler for the language [[Interpreter](#Interpreter)] [[Compiler](#Compiler)]

+ Creating tools for running the language Raspberry Pi's and Arduino's [[Raspberry Pi](#Raspberry-Pi-Implimentation)] [[Arduino](#Arduino-Implimentation)]

+ Creating a graphical application for creating PLC programs in the language [[Application](#Application)]

+ Creating a converter compatible with industry PLC file types when Terms and Conditions allow [[Converter](#Converter)]

[1] All information about the IEC-61131-3 is being accessed second hand through *IEC 61131-3: Programming Industrial Automation Systems: Concepts and Programming Languages, Requirements for Programming Systems, Decision-Making Aids* by Karl-Heinz John and Michael Tiegelkamp

## Roadmap

### Defining the Language

To fully define the language I will create a CPLC Standard document that will outline the structure, commands, syntax, behaviors and limitations of the CPLC language. This will apply eventually for all types of PLC programming languages: Instruction list,
Structured Text, Sequential Function Chart (textual), Ladder Diagram, Function Block Diagram, Sequential Function Chart (graphical),  but will initially only define the Ladder Diagram implimentation.

#### Progress ([Not Started] -> [In Progress] -> [Completed] -> [Validated])

```
**[Not Started] Create a CPLC-LD Outline detailing the broad nature of the language according to the IEC 61131-3 standards**

**[Not Started] Define all CPLC-LD tokens to be parsed by the compiler and interpreter**

**[Not Started] Define all CPLC-LD syntactical rules**

**[Not Started] Define a CPLC-LD flow diagram for how programs will compiled and ran**

**[Not Started] Compile all of this information in a CPLC-LD Standards Document**
```

The above will initially be only for the CPLC-LD Ladder Diagram version of the CPLC language, howver time permitting the others may be implimented as well. With the fully defined CPLC-LD language, and interpeter will be created.

### Interpreter

An interpeter is needed to actually be able to run any of the CPLC files. The first version of CPLC-LD interpeter will be written in C++. To be succesful the interpreter will need to succesfully execute the logic of the CPLC-LD file and provide minimal I/O support for verification. There are essentially infinitely many features one could add to an interpreter, however for the first implimentation I will strive to simply include I/O support for console, keyboard/mouse, and perhaps a few peripheral devices such as those on microcontrollers. 

#### Progress [Not Started] -> [In Progress] -> [Completed] -> [Validated]

>+**[Not Started] Create a tokenizer to interpret and push all tokens onto a program stack**
>+**[Not Started] Create a parser to parse the tokens into something similar to an abstract syntax tree**
>+**[Not Started] Create syntax checking tool**
>+**[Not Started] Create a debugging platform**
>+**[Not Started] Create the objects that will represent the different blocks**
>+**[Not Started] Create the objects for the hierarchical structures that will hold the blocks**
>+**[Not Started] Create the wirer that will be used to connect blocks in the syntax tree**
>+**[Not Started] Create the engine that will run the program**
>+**[Not Started] Create the I/O mapping tools**
>+**[Not Started] Create the Interpreter program and all necessary flags and settings**

### Compiler

### Raspberry Pi Implimentation

### Arduino Implimentation

### Application

### Converter




