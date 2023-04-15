# PLANCK

## INTRODUCTION

Planck is designed
to meet the requirements of algorithmic programming while remaining
as lightweight and low level as possible.
Therefore, the name planck, because a planck unit or length,
is the smallest theoretical length possible in physics.

## FLANCK

TODO ...

## USAGE

`planck <filename> [-option]`

### FLAGS

Possible flags for `[-option]` are:

| flag | name   | description                  | usage                |
  |------|--------|------------------------------|----------------------|
| -d   | debug  | switches the debug output on | `-d`                 |
| -b   | break  | breaks at the given line     | `-b <line number>`   |

By default, Input and Output are the console.

### DEBUG

In Planck, runtime errors cannot occur under any circumstances.
Since there is no error message must be checked and tested for undesired behavior.

## COMMENTS

Singe line comment:

`
// Comment goes here
`

Multiline comment:

```
/* 
 * Comment
 * goes here 
 */ 
```

## IMPORT / EXPORT

```
# <filename>.planck
# <filename>.flanck
```

## CONTAINER

In Planck there are only containers.
Each container can store a value up to one byte in size.
Furthermore, each container can be arbitrarily connected to other containers.

```
a = 1
b = 2
a << b
c = a >> //2
a />
c= a >> //0x00
```

Since there are only containers,
there are no data types in Planck, and therefore they do not have to be specified.
Empty assignments of containers are not possible.
Assignments can be made in binary, hexadecimal or decimal.

```
a = 0x02
b = 01001100
c = a + b //01001110
d = c ^ b //00000010
e = 230
f = -230
d = e - f //00000000
```

Each container stores its value unsigned,
however an input of negative decimal numbers is nevertheless permitted.
The interpretation and usage is therefore dependent on the developer.

## OPERATORS

There are no keywords in Planck, but there is a large set of operators.

| operator             | precedence | operator name                    | description                                 |
|----------------------|------------|----------------------------------|---------------------------------------------|
| `a * b`, `a / b`     | 10         | multiplication / division        | multiplication / division operations        |
| `a % b`              | 10         | modulo                           | modulo operations                           |
| `a + b`, `a - b`     | 9          | addition, subtraction            | addition / subtraction operations           |
| `a < b`, `a > b`     | 7          | is-less, is-greater              | greater / less comparisons                  |
| `a <= b`, `a >= b`   | 7          | smaller/greater or equals        | greater-equals / less-equals comparisons    |
| `a == b`, `a != b`   | 6          | equals, not equals               | equals / not-equals comparisons             |
| `a & b`              | 5          | and                              | binary 'and' operations                     |
| `a \| ; b`           | 4          | or                               | binary 'or' operations                      |    
| `a ^ b`              | 4          | xor                              | binary 'xor' operations                     | 
| `a <<: b`            | 4          | left shift                       | binary right shift operations               | 
| `a :>> b`            | 4          | right shift                      | binary left shift operations                | 
| `a && b`             | 5          | and                              | logical 'and' comparisons                   |
| `a \|\| b`           | 4          | or                               | logical 'or' comparisons                    |    
| `a ?>`               |            | has-next                         | if current pointer from 'a' exist           |
| `a === b`, `a !== b` |            | strict equals, strict not equals |                                             |
| `a << b`             | 8          | link                             | links two variables, first points to second |
| `-a`                 |            | negate                           | negates a value                             |
| `!a`                 |            | not                              | conditional not                             |
| `~a`                 |            | not                              | binary not operations                       |
| `a >>`               |            | next                             | returns the next container a links to       |
| `a <\ `              |            | unlink                           | unlinks the container a currently links to  |
| `a =>>`              |            | assigment to next                | a is now strict equals to b                 |
| `a = b`              |            | assigment                        | a is now equals to b                        |
| `-> a`               |            | submit                           | submits a value                             |
| `<- a`               |            | return                           | returns a value                             |
| `;`                  |            | break                            | breaks a loop                               |

## FLOW CONTROL

In planck there are the common flow controls.
### CONDITIONS

Within a condition there can be a single byte.
This is interpreted as false if it is zero, otherwise as true.
Both comparison operators or operators which have truth values as return,
are also allowed in conditions.
Calculations are also allowed,
the result is interpreted accordingly.

### IF STATEMENTS

```
[<condition>] ? { //If
    ...
} : [<condition>] { //Else If
    ...
} : { //Else
    ...
}
```

### LOOP STATEMENTS

```
[<condition>] { //while
    ...
}
```

```
{ //do
    ...
} [<condition>] //while
```

 ```
[<condition>] { //while
    ; // breaks the loop
}
 ```

### PROCEDURES

The name of a procedure is always lowercase.
A procedure can have any number of arguments,
but they must be defined beforehand.
```
<name> {
    ...
}
```

```
<name> <arg1> {
    ...
}
```

```
<name> <arg1>, <arg2> {
    ...
}
```

```
<name> <arg1>, $<arg2> {
    ...
}
```

Procedures can be called with or without arguments.

Without arguments:
```
<name>
```

With arguments:
```
<name> <arg1>, <arg2>
```
### ROUTINES

Routines are like procedures, only concurrent.
They are light and performant threads,
which can communicate with each other via channels.
This enables concurrent programming in planck.

#### SUBMIT

Via submit `<value> -> _<channel>` can be sent to a channel.
This allows the synchronization of routines without explicit locks or condition variables.

#### CHANNEL

The code within a channel is executed as soon as a value is sent to it.
```
_<name> {
    ...
}
```

### RETURN

Returns at least one value and terminates the procedure, loop or routine.
```
  ...
    <- <value>
  ...
```

```
  ...
    <- <value> <value>
  ...
```

### STRUCTS

A struct can contain any number of attributes.
The name of a struct must always be capitalized.
The default value is optional and null by default.
A struct can be defined as follows:

```
<Name> {
    <attribute>: <default value>
    <attribute>: 
    <attribute>: <default value>
}
```

A Struct can be used as follows:

````
a = <Name> <attribute> <attribute>
````

### PARAMETERS

Parameters can be queried either via `$<index>`,
or via a parameter loop, i.e. procedure.

```
params $<name> {
    ...
}
```

### SCOPES

The top scope in planck is the file scope.
Below that are the procedure scopes and the routine scopes.
Loops and conditions fall under the block scope.
All scopes below the file scope can be recognized by the block brackets.

```
{
    ...
}
```

Since there is no `main` or comparable,
the code is processed from top to bottom.
Procedures and routines must be defined
before they can be used.

## IMPORT / EXPORT

It is not possible to import content from other files
or to export content to other files.
Therefore, it is not possible to link several `.planck` files together.