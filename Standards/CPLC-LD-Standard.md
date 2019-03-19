# CPLC-LD Standard 

*Defining how to use the CPLC Ladder Diagram Language*

---

## Contents

+ [**Outline**](#Outline)

+ [**Elements**](#Elements)

  + [**Delimiters**](#Delimiters)
  
  + [**Blocks**](#Blocks)
  
    + [**Logical Blocks**](#Logical-Blocks)
    
    + [**Coil Blocks**](#Coil-Blocks)
    
    + [**Function Blocks**](#Function-Blocks)
    
    + [**Comment Blocks**](#Comment-Blocks)
    
    + [**User-Defined Blocks**](#User-Defined-Blocks)
  
  + [**Keywords**](#Keywords)
  
  + [**Literals**](#Literals)

+ [**Syntax**](#Syntax)

+ [**Flow**](#Flow)

## Outline

The CPLC-LD is the Ladder Diagram version of the CPLC Language. The language is designed so that a CPLC-LD file in text appears as a Ladder Diagram. It will be implimented this way so that it is possible to design and run a ladder program without the use of a graphical editor.

The various contacts, coals, and other objects will be easily recognizable to users of other Ladder Diagram languages. CPLC-LD will include all of the objects described in the IEC 61131-3 as well as allow for user defined objects. User defined objects will be easily to make: if the form is not already taken by another standard object, users may define how their object will look (keyword and shape) as well, the various inputs and outputs, as well as the logical function of the block. The predefined objects that come standard with the language will be created in much the same way that a user would create their own objects.

The syntax will be robust and flexible where whitespace and connector elements can be used to align and make blocks more easily readable. The syntax will strive to maximize readability within the medium of text while still conforming to expectations of ladder diagram languages 

The language ultimately we be implimented so that newcomers to the field as well as experienced PLC programmers will be able to use it effectively without need for a graphical editor.

## Elements

The elements are the building blocks of the language. They make up every character and combination of characters that can meanifully be used in the langueage. They are separated into: 

+ **Delimiters**: special characters that are used to separate and distinguish other data. 

+ **Blocks**: the set of all blocks that can be created with the allowed block shapes.

+ **Keywords**:  the set of all meaningful combinations of characters and words that may make up data types and more.

+ **Literals**: characters or words to be interpreted as literal data values such as an integer number.

### Delimiters

```-```
**Rung**: The dash is to be used as a wire or rung of the ladder program. A section of rung is needed both to distinguish different logical elements that exist on a rung and to separate blocks with a certain amount of space so they are more easily readable.

```|```
**Rail** The pipe symbol may be used as a part of the vertical rails on either side of the ladder program. While this might be useful to help visualize the rail particularly when separating rows, it is by all meants not necessary. Rungs may be right on top of each other using only the rail or up and down connectors without needing a rail, and they may also simply be separated by empty lines.

```+```
**Rail Connector** The plus symbol is to be used as a rail connector. This symbol will mark both the beginning and ending of each rail depending on whether it is on the left (beginning) or right (end). Rungs may exist without this symbol, but they will not recieve the intial "high/on" value that all rungs connected to the rail are given. Rungs without this connecter will need up or down connectors to be active.

```\```
**Down Connector**: The backslash is to be used as a down connector, indicating that at the point in the rung that it appears, there should be a connection to the rung below it. It is to be paired sequentially to a matching up connector from the rung below it. I.E. the third down connector to appear (from left to right) on a rung will be taken as a directly wired connection the the third up connector from the rung below. Similarly to parenthesis in other languages, all up and down connectors must have pairs. Connectors will logically output the OR of the two connecting wires.

```/```
**Up Connector**: The forwardlash is to be used as a up connector, indicating that at the point in the rung that it appears, there should be a connection to the rung above it. It is to be paired sequentially to a matching down connector from the rung above it. I.E. the third up connector to appear (from left to right) on a rung will be taken as a directly wired connection the the third down connector from the rung above. Similarly to parenthesis in other languages, all up and down connectors must have pairs. Connectors will logically output the OR of the two connecting wires.

```[ ... ]( ... , ... )```
**Logical Block**: A pair of square brackets with a following pair of parenthesis represent a logical block. The square brackets contain any information distinguishing the function of the block, contact, arithemtic, timer, etc. The pair of parenthesis are where arguents to the block are passed such as tag names, arguments, etc. The block reads from an enable-in, EN, (rung input) and writes to an enable-out, ENO, (rung output).

```( ... )( ... , ... )```
**Coil Block**: A pair of parenthesis followed by another pair of parenthesis represent a coil block. The first pair of parenthis contain any information distinguishing the function of the coil. The second pair of parenthesis are where arguments to the coil, such as tag name, are passed. The block reads from an enable-in, EN, (rung input) and writes to an enable-out, ENO (rung output).

```< ... >( ... , ... )```
**Function Block**: A less-than and greater-than symbol followed by a pair of parenthesis represent a function block. The less-than and greater-than sign contain any information distinguishing the function block. the pair of parenthsis are where arguments to the function block, such as function block to call or return condition, are passed. The block reads from an enable-in, EN, (rung input) and writes to an enable-out, ENO (rung output).

```# ... #```
**Comment Block**: A pair of pound symbolsmay be used as a comment block. All normal tect to appear within the brackets will not be compiled or executed on and left simply as a comment. This may be used to write an inline comment where code continues after the comment or as a multiline comment.

### Blocks

#### Logical Blocks

```[ ]( gate )``` <br/>
**Normally Open Contact**: a single space in a logcal block indicates a normally open contact. The normally open contact takes a single parameter: a boolean switch tag that controls the switching function of the contact. When the switch tag is high and the enable-in is high, the enable-out becomes high, and when gate is low the enable-out is always low.

```[/]( gate )``` <br/>
**Normally Closed Contact**: a forward slash in a logical block indicates a normally closed contact. The normally closed contact takes a single parameter: a boolean switch tag that controls the switching function of the contact. When gate is low and the enable-in is high, the enable-out becomes high, and when gate is high the enable-out is always low.

```[P]( gate )``` <br/>
**Positive Edge Contact**: a capital or lowercase "P" in a logical block indicates a positive edge detecting contact. The positive edge contact takes a single parameter: a boolean gate tag that controls the switching of the contact. When gate has become high in the last cycle of operation and the enable-in is high, then the enable-out becomes high. After one cycle, the enable-out becomes low and will remain low until the tag transitions to high after being low again.

```[N]( gate )``` <br/>
**Negative Edge Contact**: a capital or lowercase "N" in a logical block indicates a negative edge detecting contact. The positive edge contact takes a single parameter: a boolean gate tag that controls the swithcing of the contact. When gate has become low in the last cycle of operation and the enable-in is high, then the enable-out becomes high. After one cycle, the enable out becomes low and will remain low until the tag transitions to low after being high again.

```[NOT]``` <br/>
**Inverter**: a capital or lowercase "NOT" in a logical block indicates an inverter. The inverter takes no parameters. When enable-in becomes high, enable-out becomes low and when enable-in becomes low, enable-out becomes high.

```[TYP]( outputY, inputA)``` <br/>
**Type Converter**: a capital or lowercase "TYP" in a logical block indicates a type converter. The type converter takes two parameters: the first being a tag of one type to be written to and the second being being a tag of a another type containing the value to be converted and written. Enable-in is passed directly to enable-out and the value is only written to the output if enable-in is high.

```[MOV]( outputY, inputA )``` <br/>
```[SET]( outputY, inputA )``` <br/>
**Move/Set**: a capital or lowercase "MOV" or "SET" in a logical block indicates a move/set block. The move/set block takes two parameters: the first being the tag being written to and the second being the tag or literal containing the value to be written. Enable-in is passed directly to enable-out and the value is only written to the output if enable-in is high. <br/>*Y = A*

```[ADD]( outputY, inputA, inputB, ... )``` <br/>
**Addition**: a capital or lowercase "ADD" in a logical block indates an addition block. The addition block takes at least three parameters: the first being the tag where the final sum will be written to and the second and all thereafter being the tags or literals that will be added together to produce a sum. Enable-in is passed directly to enable-out and the value is only written to the output if enable-in is high. <br/>*Y = A + B + C ...*

```[SUB]( outputY, inputA, inputB, ... )``` <br/>
**Subtraction**: a capital or lowercase "SUB" in a logical block indates a subtraction block. The subtraction block takes at least three parameters: the first being the tag where the final difference will be written, the second being the tag or literal to be subtracted from, and the third and all thereafter being the tags or literals that will subtract. Enable-in is passed directly to enable-out and the value is only written to the output if enable-in is high. <br/>*Y = A - B - C ...*

```[MUL]( outputY, inputA, inputB, ... )``` <br/>
**Multiplication**: a capital or lowercase "MUL" in a logical block indates a multiplication block. The multiplication block takes at least three parameters: the first being the tag where the final product will be written to and the second and thereafter being the tags or literals that will be multiplied together to produce the product. Enable-in is passed directly to enable-out and the value is only written to the output if enable-in is high. <br/>*Y = A x B x C ...*

```[DIV]( outputY, inputA, inputB, ... )``` <br/>
**Division**: a capital or lowercase "DIV" in a logical block indates a division block. The division block takes at least three parameters: the first being the tag where the final product will be written to, the second being the dividend, and the third and all thereafter being the tags or literals that will be divide the dividend to produce the quotient. Enable-in is passed directly to enable-out and the value is only written to the output if enable-in is high. <br/>*Y = A / B / C ...*

```[EXP]( outputY, inputA, inputB, ... )``` <br/>
**Exponentiation**: a capital or lowercase "EXP" in a logical block indates a exponentiation block. The exponentiation block takes at least three parameters: the first being the tag where the final product will be written to, the second being a tag or literal for the base, and the third being a tag or literal for the power that the base will be raised to produce the final product. For more than three parameters, every latter parameter is taken to be a successive power to the previous parameter. Enable-in is passed directly to enable-out and the value is only written to the output if enable-in is high. <br/>*Y = A ^ B ^ C ...*

```[MOD]( outputY, inputA, inputB )``` <br/>
**Modulo**: a capital or lowercase "MOD" in a logical block indates a modulo block. The modulo block takes three parameters: the first being the tag where the remainder will be written to, the second being the tag or literal for the dividend, and the third being the tag or literal for the modulus. Enable-in is passed directly to enable-out and the value is only written to the output if enable-in is high. <br/>*Y = A mod B*

```[NOT]( outputY, intputA )``` <br/>
**Bitwise Invert**: a capital or lowercase "NOT" in a logical block indicates a bitwise invert. The bitwise invert block takes two parameters: the first being a tag where the inverted value will be stored and the second being a tag or literal that will have each bit inverted. Enable-in is passed directly to enable-out and the value is only written to the output if enable-in is high.

```[AND]( outputY, intputA, inputB, ... )``` <br/>
**Bitwise And**: a capital or lowercase "AND" in a logical block indicates a bitwise and. The bitwise and block takes three or more parameters: the first being a tag where the final value will be stored and all of the following being tags or literals that will have each respective bit AND'ed for the output. Enable-in is passed directly to enable-out and the value is only written to the output if enable-in is high.

```[OR]( outputY, intputA, inputB, ... )``` <br/>
**Bitwise Or**: a capital or lowercase "OR" in a logical block indicates a bitwise or. The bitwise or block takes three or more parameters: the first being a tag where the final value will be stored and all of the following being tags or literals that will have each respective bit OR'ed for the output. Enable-in is passed directly to enable-out and the value is only written to the output if enable-in is high.

```[XOR]( outputY, intputA, inputB )``` <br/>
**Bitwise Exclusive Or**: a capital or lowercase "XOR" in a logical block indicates a bitwise exclusive or. The bitwise exclusive or block takes three or more parameters: the first being a tag where the final value will be stored and all of the following being tags or literals that will have each respective bit XOR'ed for the output. Enable-in is passed directly to enable-out and the value is only written to the output if enable-in is high.\

```[SHL]( outputY, intputA, inputB )``` <br/>
**Bitwise Shift Left**: a capital or lowercase "SHL" in a logical block indicates a bitwise shift left. The bitwise shift left block takes three or more parameters: the first being a tag where the final value will be stored, the second being a tag or literal with the value to be shifted and the third being a tag or value for the number of left shifts of the second value to take place. Enable-in is passed directly to enable-out and the value is only written to the output if enable-in is high.

```[SHR]( outputY, intputA, inputB )``` <br/>
**Bitwise Shift Right**: a capital or lowercase "SHR" in a logical block indicates a bitwise shift right. The bitwise shift right block takes three or more parameters: the first being a tag where the final value will be stored, the second being a tag or literal with the value to be shifted and the third being a tag or value for the number of right shifts of the second value to take place. Enable-in is passed directly to enable-out and the value is only written to the output if enable-in is high.

```[ROL]( outputY, intputA, inputB )``` <br/>
**Bitwise Rotate Left**: a capital or lowercase "ROL" in a logical block indicates a bitwise rotate left. The bitwise rotate left block takes three or more parameters: the first being a tag where the final value will be stored, the second being a tag or literal with the value to be rotated and the third being a tag or value for the number of left rotates of the second value to take place. Enable-in is passed directly to enable-out and the value is only written to the output if enable-in is high.

```[ROR]( outputY, intputA, inputB )``` <br/>
**Bitwise Rotate Right**: a capital or lowercase "ROR" in a logical block indicates a bitwise rotate right. The bitwise rotate right block takes three or more parameters: the first being a tag where the final value will be stored, the second being a tag or literal with the value to be rotated and the third being a tag or value for the number of right rotates of the second value to take place. Enable-in is passed directly to enable-out and the value is only written to the output if enable-in is high.

```[$MyBlock]( ... )``` <br/>
**User-Defined Logical Block**: a dollar sign followed by any series of capital or lowercase letters or numbers (first character must be a letter) in a logical block indicates a user-defined logical block. The user-defined logical block takes in as many parameters as is specified in its definition. The block may read an enable-in signal, write an enable-out signal, read and write to any read-write enabled tags that it is passed as parameters, and access the internal system timer and certain other I/O facilities. The block may introduce new tags as well as keep certain variables private and internal. For more information, see [User-Defined Blocks](#User-Defined-Blocks).

#### Coil Blocks

```( )( set )```
**Output Coil**: a space in a coil block indicates an output coil. The output coil takes a single parameter: a boolean set tag that is controlled by enable-in. When enable-in becomes high, both set tag and enable-out become high, when enable-in becomes low, both tag and enable-out become low.

```(S)( set )```
**Set Coil**: a capital or lowercase "S" in the coil block indicates a set coil. The set coil takes a single parameter: a boolean set tag that is controlled by the enable-in. When the enable-in becomes high, both the set tag and enable-out become high and both stay high until the reset coil using the same tag becomes high. 

```(R)( set )```
**Reset Coil**: a capital or lowercase "R" in a coil block indicates a reset coil. The reset coil takes a single parameter: a boolean set tag that is controlled by the enable-in. When the enable-in becomes high, both the set tag and enable-out become high and any set tag coils with the same tag name are reset to low.

```(M)( set )```
**Retentative Memory Coil**: a capital or lowercase "M" in a coil block indicates a retentative memory coil. The retentative memory coil takes a single parameter: a boolean set tag that is controlled by enable-in. When enable-in becomes high, both set tag and enable-out become high, when enable-in becomes low, both tag and enable-out become low. The coil retains its value even if the program is reset. This block requires the ability to write to a file and may not be realizable on some machines.

```(SM)( set )```
**Set Retentative Memory Coil**: a capital or lowercase "SM" in a coil block indicates a set retentative memory coil. The set retentative memory coil takes a single parameter: a boolean set tag that is controlled by the enable-in. When the enable-in becomes high, both the set tag and enable-out become high and both stay high until the reset coil using the same tag name becomes high. The coil retains its value even if the program is reset. This block requires the ability to write to a file and may not be realizable on some machines.

```(RM)( set )```
**Reset Retentative Memory Coil**: a capital or lowercase "RM" in a coil block indicates a reset retentative memory coil. The reset retentative memory coil takes a single parameter: a boolean set tag that is controlled by the enable-in. When the enable-in becomes high, both the set tag and enable-out become high and any set tag coils with the same tag name are reset to low.  The coil retains its value even if the program is reset. This block requires the ability to write to a file and may not be realizable on some machines.

```($MyBlock)( ... )```
**User-Defined Coil Block**: a dollar sign followed by any series of capital or lowercase letters or numbers (first character must be a letter) in a coil block indicates a user-defined coil block. The user-defined coil block takes in as many parameters as is specified in its definition. The block may read an enable-in signal, write an enable-out signal, read and write to any read-write enabled tags that it is passed as parameters, and access the internal system timer and certain other I/O facilities. The block may introduce new tags as well as keep certain variables private and internal. For more information, see [User-Defined Blocks](#User-Defined-Blocks).

#### Function Blocks

```<LBL>( label )```
**Label**: a capital or lowercase "LBL" in a function block indicates an jump label. The label takes a single parameter: a label name. When a the enable-in on a conditional or unconditional jump with the same label becomes high, the program immediately starts executing at the rung with that label, skipping the rungs that would normally be reached before it. If there are multiple labels of the same name defined, the closest one after the called jump.

```<JMP>( label )```
**Jump**: a capital or lowercase "JMP" in a function block indicates an jump. The jump takes a single parameter: a label name. When enable-in becomes high the program will stop executing the current rung and jump to the closest label of the same name.

```<FUN>( name )```
**Function**: a capital or lowercase "FUN" in a function block indicates a function. The function takes a single parameter: a name for the function. When any running program in the workspace reaches a functional call of the same name, the program stops and begins to run at the function. The function is designed to be used with function calls and returns.

```<CALL>( name )```
**Function Call**: a capital or lowercase "CALL" in a function block indicates a function call. The function call takes one parameter: a name for the function. When enable-in becomes high, as long as there is a function with the same name on some program in the workspace, the execution stops and begins to run at the function. The function is designed to be used with function calls and returns.

```<RET>```
**Return**: a capital or lowercase "RET" in a function block indicates a return. The return takes no parameters. When enable-in becomes high the program will stop executing and return to the calling program at the point that the current function was called. If there was no calling program and a return is reached then program execution simple stops.

```<END>```
**End**: a capital or lowercase "END" in a function block indicates an end. The end takes no parameters. When enable-in becomes high the program will stop execution completety and terminate.

```<$MyBlock>( ... )```
**User-Defined Function Block**: a dollar sign followed by any series of capital or lowercase letters or numbers (first character must be a letter) in a function block indicates a user-defined function block. The user-defined function block takes in as many parameters as is specified in its definition. The block may read an enable-in signal, write an enable-out signal, create labels, jump to any labels within the diagram, create functions, call any functions in the worspace, return from a program, end a program, and access the internal system timer and certain other I/O facilities. The block may introduce new tags as well as keep certain variables private and internal. For more information, see [User-Defined Blocks](#User-Defined-Blocks).

#### Comment Blocks

```# Comment #```
**Comment Block**: a pair of pound symbols make up a comment block. Any text that appears between the two pound symbols will not be executed on and enable sigals pass as if the comment were a rung. Comments can span multiple lines and cannot be nested (i.e. any pound symbol will escape the comment started by any other pound symbol). Comments can then can be wrapped around rungs or certain parts of a rung to prevent them from being executed.

#### User-Defined Blocks

### Keywords

### Literals

## Syntax

## Flow
