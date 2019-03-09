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
    
    + [**Jump Blocks**](#Jump-Blocks)
    
    + [**Comment Blocks**](#Comment-Blocks)
  
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

+ **Blocks**: the set of all blocks that can be created with the allowed block delimiter shapes.

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
**Down Connector**: The backslash is to be used as a down connector, indicating that at the point in the rung that it appears, there should be a connection to the rung below it. It is to be paired sequentially to a matching up connector from the rung below it. I.E. the third down connector to appear (from left to right) on a rung will be taken as a directly wired connection the the third up connector from the rung below. Similarly to parenthesis in other languages, all up and down connectors must have pairs.

```/```
**Up Connector**: The forwardlash is to be used as a up connector, indicating that at the point in the rung that it appears, there should be a connection to the rung above it. It is to be paired sequentially to a matching down connector from the rung above it. I.E. the third up connector to appear (from left to right) on a rung will be taken as a directly wired connection the the third down connector from the rung above. Similarly to parenthesis in other languages, all up and down connectors must have pairs.

```[ ... ]( ... , ... )```
**Logical Block**: A pair of square brackets with a following pair of parenthesis represent a logical block. The square brackets contain any information distinguishing the function of the block, contact, arithemtic, timer, etc. The pair of parenthesis are where arguents to the block are passed such as tag names, arguments, etc. The block reads from an enable in, EN, (rung input) and writes to an enable out, ENO, (rung output).

```( ... )( ... , ... )```
**Coil Block**: A pair of parenthesis followed by another pair of parenthesis represent a coil block. The first pair of parenthis contain any information distinguishing the function of the coil. The second pair of parenthesis are where arguments to the coil, such as tag name, are passed. The block reads from an enable in, EN, (rung input) and writes to an enable out, ENO (rung output).

```< ... >( ... , ... )```
**Function Block**: A less-than and greater-than symbol followed by a pair of parenthesis represent a function block. The less-than and greater-than sign contain any information distinguishing the function block. the pair of parenthsis are where arguments to the function block, such as function block to call or return condition, are passed. The block reads from an enable in, EN, (rung input) and writes to an enable out, ENO (rung output).

```> ... >( ... , ...)```
**Jump Block**: A pair of two greater-than symbols followed by a pair of parenthesis represent a jump block. The two greater-than symbols contain any information distinguishing the jump block. The pair of parenthesis are where arguments to the jump block, such as location and condition, are passed. The block reads from an enable in, EN, (rung input) and writes to an enable out, ENO (rung output).

```#{ ... }```
**Comment Block**: A pound symbol with brackets may be used as a comment block. All normal tect to appear within the brackets will not be compiled or executed on and left simply as a comment. This may be used to write an inline comment where code continues after the comment or as a multiline comment.

### Blocks

#### Logical Blocks

```[ ]( tag )```
**Normally Open Contact**: a single space in the logcal block indicates a normally open contact. The normally open contact takes a single parameter: a tag which controls the switching function of the contact: when the tag is logical high and the enable in, EN, is also logical high then the enable out, ENO, becomes high and when the tag is low the enable out, ENO, is always low.

```[/]( tag )```
**Normally Closed Contact**: a forward slash in the logical block indicates a normally closed contact. The normally closed contact takes a single parameter: a tag which controls the switching function of the contact: when the tag is logical low and the enable in, EN, is logical high then the enable out, ENO, becomes high and if the tag is logical high the enable out is always low.

```[P]( tag )```
**Positive Edge Contact**: a capital or lowercase 'p' in the logical block indicates a positive edge detecting contact. The positive edge contact takes a single parameter of a tag which controls the switching of the contact: when the tag has become high in the last cycle of operation and the enable in, EN, is high then the enable out, ENO, becomes true. After one cycle, the enable out, ENO, is set to false and will remain false until the tag transitions to high after being low again.

```[N]( tag )```
**Negative Edge Contact**: a capital or lowercase 'n' in the logical block indicates a negative edge detecting contact. The positive edge contact takes a single parameter of a tag which controls the swithcing of the contact: when the tag has become low in the last cycle of operation and the enable in, EN, is high then the enable out, ENO, becomes true. After one cycle the enable out, ENO, is set to false and will remain false until the tag transitions to low after being high again.

#### Coil Blocks

```( )( tag )```
**Output Coil**: a space in the coil block indicates an output coil. The output coil takes a single parameter of a tag which is controlled by the enable in, EN: when the enable in, EN, becomes high, both the tag and enable out, ENO, become high, when the enable becomes low, both tag and enable out, ENO, become low.

#### Function Blocks

#### Jump Blocks

#### Comment Blocks

### Keywords

### Literals

## Syntax

## Flow
