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
The dash is to be used as a wire or rung of the ladder program. Though it is not necessary to have a dash between objects to have them "connect" it is useful in separating different blocks and making the diagram more readable.

```\```
The backslash is to be used as a down connector, indicating that at the point in the rung that it appears, there should be a connection to the rung below it. It is to be paired sequentially to a matching up connector from the rung below it. I.E. the third down connector to appear (from left to right) on a rung will be taken as a directly wired connection the the third up connector from the rung below. Similarly to parenthesis in other languages, all up and down connectors must have pairs.

```/```
The forwardlash is to be used as a up connector, indicating that at the point in the rung that it appears, there should be a connection to the rung above it. It is to be paired sequentially to a matching down connector from the rung above it. I.E. the third up connector to appear (from left to right) on a rung will be taken as a directly wired connection the the third down connector from the rung above. Similarly to parenthesis in other languages, all up and down connectors must have pairs.

### Keywords

### Literals

## Syntax

## Flow
