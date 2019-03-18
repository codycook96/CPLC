# Contributing to CPLC

## Thank You!

Thank you for considering to contribute to CPLC. With your help, this project can help educate and make PLC technology more accessible.

[1] [Source](https://github.com/codycook96/CPLC/master/CONTRIBUTING.md) [2] [Documentation](https://github.com/codycook96/CPLC/master/) [3] [Website (TBD)](https://github.com/codycook96/CPLC/master/CONTRIBUTING.md) 

## Preface.

This is project intended to be a basic platform on which anyone can learn, write, and execute PLC programs without needing proprietary software packages or expensive hardware PLC's. This project is intented to be robust, modular, and fast. However, I am a novice developer and my attention unfortunately cannot be dedicated fully to this project. I welcome all contributions and aim to integrate useful contributions as much as I am able, all that I ask is that expectations are managed. For the time being, I will be simply taking suggestions and selectively implimenting them myself.

---

## Contributions

+ [Security Report](#Security-Report) 

+ [Bug Report](#Bug-Report) 

+ [Code Improvement](#Code-Improvement) 

+ [Documentation Improvement](#Documentation-Improvement) 

+ [Feature Suggestion](#Feature-Suggestion)

---

### Security Report

If you find a security vulnerability, *do NOT open an issue*. Email ProjectCPLC@gmail.com with all the relevant details instead. This is crucial in maintaining the security of users as well as the trust of the project as a safe learning tool. 

If you think you may have found a vulnerability but are unsure, remember the C.I.A. anacronysm:

+ Can I jeopardize **confidential** information? E.g. revealing a users password.

+ Can I jeopardize the **integrity** of information? E.g. changing a users password.<br/>

+ Can I jeopardize the **accessibility** of information? E.g. prevent users from loggin in.

Though this platform will likely never contain a user system these examples allow you to visualize what different security vulnerabilities may look like.

If think you may have found a vulnerability and wish to test it, I suggest using a virtual machine, such as a Linux VirtualBox, and not running the exploit on your personal machine.

---

### Bug Report

When reporting a bug, for your convenience I recomend usng this template:

**C++ Version**: *C++98, C++11, C++14,  etc*<br/>
**Compiler**: *GNU, MinGQ, Cygwin, etc*<br/>
**Operating System and Version**: *Windows 7, Windows 10, Ubuntu 16, Ubuntu 14, MacOS Mojave, etc*<br/>
**What did you do**: *compiled program, ran ladder file, etc*<br/>
**What did you expect to see**: *succesful compilation, output abc high, etc*<br/>
**What did you actually see**: *compiler error x, output abc low, etc*<br/>
**Problem Code (if applicable)**: *char buff[4] = "overflow me"; *<br/>
**Comments**: *Your code sucks*<br/>

Copy this for your bug report:</br>
```
C++ Version:
Compiler:
Operating System and Version:
What did you do:
What did you expect to see:
What did you actually see:
Problem Code:
Comments:
```

---

### Code Improvement

When proposing a code improvement, for your convenience I recomend usng this template:

**File Name**: *Test.cpp, Block.h*<br/>
**Object (if applicable)**: *Block*<br/>
**Function (if applicable)**: *Block() constructor*<br/>
**Original Code**: *Block(bool* _tag, bool* _wireIn): tag(_tag), wireIn(_wireIn), wireOut(false){};*<br/>
**Suggested Revision**: *Move function definitions to cpp file*<br/>
**Reason for Revision**: *Because I like it that way*<br/>
**Comments**: *Your coding sucks*<br/>

Copy this for your documentation improvement:<br/>
```
File Name:
Object (if applicable):
Function (if applicable):
Original Code:
Suggested Revision:
Reason for Revision:
Comments:
```

---

### Documentation Improvement

When proposing a documentation improvement, for your convenience I recomend usng this template:

**Document Name**: *README, Guide, etc*<br/>
**Section (if applicable)**: *1. Purpose: B) Use Cases*<br/>
**Original Text (if applicable)**: *This is a text.*<br/>
**Suggested Revision**: *This is some text, swap section B with section A*<br/>
**Reason for Revision**: *This is basic grammar.*<br/>
**Comments**: *Your writing sucks*<br/>

Copy this for your documentation improvement:<br/>
```
Document Name:
Section:
Original Text:
Suggested Revision:
Reason for Revision:
Comments:
```

---

### Feature Suggestion

When proposing a feature suggestion, for your convenience I recommned using this template:

**Feature**: *GUI Application, File Converter, etc*<br/>
**Description**: *A graphical user application to write ladder files*<br/>
**Need**: *It would help users who arent familiar with shell*<br/>
**Comments**: *Your program sucks... but I want to make it better*<br/>

Copy this for your feature suggestion:<br/>
```
Feature:
Description:
Need:
Comments:
```
