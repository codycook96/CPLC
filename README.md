# CPLC 

*An Open PLC Development Platform*

[1] [Changelog](/CHANGELOG.md) [2] [Testing Reports](/Testing/TESTING.md) [3] [Contributing Guidelines](/CONTRIBUTING.md) [4] [License](/License) 

---

## Mission

The CPLC Project is an open source project aims to create a free, simple, and modular platform for anyone to be able to learn PLC program and develop their own PLC programs on a wide variety of hardware.  


## Goals

+ Creating a readable text based PLC language that aligns with IEC 61131-3 [1] [[Language](#Defining-the-Language)]

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


+ **[Not Started] Create a CPLC-LD Outline detailing the nature of the language (according to IEC 61131-3 standards)**

+ **[Not Started] Define all CPLC-LD tokens to be parsed by the compiler and interpreter**

+ **[Not Started] Define all CPLC-LD syntactical rules**

+ **[Not Started] Define a CPLC-LD flow diagram for how programs will compiled and ran**

+ **[Not Started] Compile all of this information in a CPLC-LD Standards Document**


The above will initially be only for the CPLC-LD Ladder Diagram version of the CPLC language, howver time permitting the others may be implimented as well. With the fully defined CPLC-LD language, and interpeter will be created.

### Interpreter

An interpeter is needed to actually be able to run any of the CPLC files. The first version of CPLC-LD interpeter will be written in C++. To be succesful the interpreter will need to succesfully execute the logic of the CPLC-LD file and provide minimal I/O support for verification. There are essentially infinitely many features one could add to an interpreter, however for the first implimentation I will strive to simply include I/O support for console, keyboard/mouse, and perhaps a few peripheral devices such as those on microcontrollers. 

#### Progress [Not Started] -> [In Progress] -> [Completed] -> [Validated]

+ **[Not Started] Create a tokenizer to interpret and push all tokens onto a program stack**

+ **[Not Started] Create a parser to parse the tokens into something similar to an abstract syntax tree**

+ **[Not Started] Create syntax checking tool**

+ **[Not Started] Create a debugging platform**

+ **[Not Started] Create the objects that will represent the different blocks**

+ **[Not Started] Create the objects for the hierarchical structures that will hold the blocks**

+ **[Not Started] Create the wirer that will be used to connect blocks in the syntax tree**

+ **[Not Started] Create the engine that will run the program**

+ **[Not Started] Create the I/O mapping tools**

+ **[Not Started] Create the Interpreter program and all necessary flags and settings**

As other versions of the CPLC language may defined in the future so may the interpreter be expanded to include them.

### Compiler

The compiler will follow directly from the interpreter. Initially the compiler will just be a "transpiler", converting the CPLC file to a C++ file which can then in tern be compiled by a standard C++ compiler. This transpiler will suffice temporarily to allow for hardware implimentations of the code. After hardware implimentations have been tested, I plan to create an actual compiler using [LLVM](https://llvm.org/). No attempt will be made to write a full compiler from the ground up.

#### Progress [Not Started] -> [In Progress] -> [Completed] -> [Validated]

+ **[Not Started] Adapt the tokenizer, parser, syntax and debugging tools for compiling**

+ **[Not Started] Create a scribe to write the C++ file**

+ **[Not Started] Adapt the wirer to write to the C++ file**

Sometime later...

+ **[Not Started] Write a compiler using LLVM**

For most itial implimentations and validation the transpiler should suffice.

### Raspberry Pi Implimentation

Raspberry Pi's are one of the most ubiquitous mini computers, particularly in the education and hacking worlds. Because of its wide support, minimal cost, and I/O capabilities I believe it would be an ideal device to bring CPLC support to. As the Pi already compiles and runs C++ this will likely come down to mapping the GPIO outputs to I/O's within the program. Initially I will likely require 3rd party libraries such as [WiringPi](http://wiringpi.com/) to get full use of the GPIO. 

#### Progress [Not Started] -> [In Progress] -> [Completed] -> [Validated]

+ **[Not Started] Add Pi GPIo support to the interpreter**

+ **[Not Started] Add Pi GPIO support to the compiler**

### Arduino Implimentation

Arduno's are similarly one of the most ubiquitous microcontrollers. It also has wide support, minimal cost (particularly for 3rd part clones), and I/O capabilities so it too would be an ideal device to bring CPLC support to. It will likely come down to simply mapping the GPIO outputs the I/O's within the program and may require libraries. Because the arudino is a microcontroller, it cannot run the interpreter and must use the compiler.


#### Progress [Not Started] -> [In Progress] -> [Completed] -> [Validated]

+ **[Not Started] Add Arduino GPIO support to the compiler**

### Application

A graphical user application is a part of the broad goal of CPLC in making PLC programming more accessible, however it will not be defined until the language is working and validated on hardware devices.

### Converter

Similar to the graphical user application the file converters will not be explored until the CPLC is working and validated on hardware devices, as well as verified as legal within the Terms and Conditions of each file type as specified by their owners.




