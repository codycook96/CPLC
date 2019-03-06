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

####Progress

[ ] 1. Create a CPLC-LD Outline detailing the broad nature of the language according to the IEC 61131-3 standards

[ ] 2. Define all CPLC-LD tokens to be parsed by the compiler and interpreter

[ ] 3. Define all CPLC-LD syntactical rules

[ ] 4. Define a CPLC-LD flow diagram for how programs will compiled and ran

[ ] 5. Compile all of this information in a CPLC-LD Standards Document

### Interpreter

### Compiler

### Raspberry Pi Implimentation

### Arduino Implimentation

### Application

### Converter



--
