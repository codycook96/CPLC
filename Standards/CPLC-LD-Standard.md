# CPLC-LD Standard 

*Defining how to use the CPLC Ladder Diagram Language*

---

## Contents

+ [**Outline**](#Outline)

+ [**Elements**](#Elements)

  + [**Delimiters**](#Delimiters)
  
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

+ **Keywords**:  the set of all meaningful combinations of characters and words that may make up data types, function names and more.

+ **Literals**: characters or words to be interpreted as literal data values such as an integer number.

### Delimiters

```-```
**Eung**: The dash is to be used as a wire or rung of the ladder program. Though it is not necessary to have a dash between objects to have them "connect" it is useful in separating different blocks and making the diagram more readable. Many dashes are intended to be used as wirign, or a form of "whitespace", between objects.

```|```
**Rail** The pipe symbol may be used as a part of the vertical rails on either side of the ladder program. While this might be useful to help visualize the rail particularly when separating rows, it is by all meants not necessary. Rungs may be right on top of each other using only the rail or up and down connectors without needing a rail, and they may also simply be separated by empty lines.

```+```
**Rail Connector** The plus symbol is to be used as a rail connector. This symbol will mark both the beginning and ending of each rail depending on whether it is on the left (beginning) or right (end). Rungs may exist without this symbol, but they will not recieve the intial "high/on" value that all rungs connected to the rail are given. Rungs without this connecter will need up or down connectors to be active.

```\```
**Down Connector**: The backslash is to be used as a down connector, indicating that at the point in the rung that it appears, there should be a connection to the rung below it. It is to be paired sequentially to a matching up connector from the rung below it. I.E. the third down connector to appear (from left to right) on a rung will be taken as a directly wired connection the the third up connector from the rung below. Similarly to parenthesis in other languages, all up and down connectors must have pairs.

```/```
**Up Connector**: The forwardlash is to be used as a up connector, indicating that at the point in the rung that it appears, there should be a connection to the rung above it. It is to be paired sequentially to a matching down connector from the rung above it. I.E. the third up connector to appear (from left to right) on a rung will be taken as a directly wired connection the the third down connector from the rung above. Similarly to parenthesis in other languages, all up and down connectors must have pairs.

```#```
**Single Line Comment**: The pound symbol is to be used for comments single line comments. All normal text to appear after the symbol to the end of the line will not be compiled or executed on and left simply as a comment.

```#{ ... }```
**Block Comment**: A pound symbol with brackets may be used as a comment block. All normal tect to appear within the brackets will not be compiled or executed on and left simply as a comment. This may be used to write an inline comment where code continues after the comment or as a multiline comment.





### Keywords

### Literals

## Syntax

## Flow
