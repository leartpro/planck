# PLANCK

## INTRODUCTION

Planck is designed
to meet the requirements of algorithmic programming while remaining 
as lightweight and low level as possible.
Therefore, the name planck, because a Planck unit or length,
is the smallest theoretical length possible in physics.

## USAGE

```
planck <filename> [-option]
```
```
planck "<code>" [-option]
```

## COMMENTS

Singe line comment:
```
// Comment goes here
```

Multiline comment:
```
/* 
 * Comment
 * goes here 
 */ 
```

## VARIABLES

- gibt nur Container
- alle Container sind ein Byte groß
- Container können beliebig miteinander verknüpft werden
- gibt keine Datentypen
- keine leeren Zuweisungen

## VALUE OPERATIONS

```
a = 0x02
b = 01001100
c = a + b //01001110
d = c ^ b //00000010
```

## LINKING OPERATIONS

- container können beliebig verlinkt und end linkt werden

## OPERATORS

| operator             | precedence | operator name                    | description                                         |
|----------------------|------------|----------------------------------|-----------------------------------------------------|
| `a * b`, `a / b`     | 10         | multiplication / division        | multiplication for only full numbers                |
| `a % b`              | 10         | modulo                           |                                                     |
| `a + b`, `a - b`     | 9          | addition, subtraction            | addition for numbers                                |
| `a < b`, `a > b`     | 7          | is-less, is-greater              |                                                     |
| `a <= b`, `a >= b`   | 7          | smaller/greater or equals        |                                                     |
| `a == b`, `a != b`   | 6          | equals, not equals               |                                                     |
| `a && b`             | 5          | and                              |                                                     |
| `a &#124;&#124; b`   | 4          | or                               |                                                     |    
| `a ^ b`              | 4          | xor                              |                                                     | 
| `a ?>`               |            | is-next                          |                                                     |
| `a === b`, `a !== b` |            | strict equals, strict not equals |                                                     |
| `a << b`             | 8          | link                             | link A to B, return the last pointer of the B chain |
| `-a*`                |            | negate                           |                                                     |
| `!a*`                |            | not                              |                                                     |
| `a >>`               |            | next                             |                                                     |
| `a <\ `              |            | unlink                           |                                                     |
| `a =>>`              |            | assigment to next                | a is now pointing to B                              |


## FLOW CONTROL

### CONDITIONS

- ein byte kann als false gelesen werden, wenn dieser 0 ist
- ein byte der nicht 0 ist, ist true
- auf bedingungen mit operatoren sind zugelassen

### IF STATEMENTS

```
[<condition>] ? {
    ...
} : [<condition>] {
    ...
} : {
    ...
}
```

### LOOP STATEMENTS

```
[<condition>] {
    ...
}
```

### PROCEDURES

- name wird immer kleingeschrieben

#### DECLARATIONS

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

#### CALLS

Without arguments
```
<name>
```

With arguments
```
<name> <arg1>, <arg2>
```

### STRUCTS

- Name wird immer großgeschrieben

#### DECLARATIONS

```
struct <Name> {
    ...
}
```

### USAGES


### PARAMETERS

```
params $<name> {
    ...
}
```

### SCOPES

#### EXEC-STATEMENTS

```
exec {
    ...
}
```

## SYSTEM

| keyword | usage | description |
|---------|-------|-------------|
| in      |       |             |
| out     |       |             |
| err     |       |             |
| os      |       |             |

todo: import/export