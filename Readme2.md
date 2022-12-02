# planck

## INTRODUCTION

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
/* Comment
goes 
here */ 
```

## VARIABLES

A variable always references a planck.
A planck contains a word value (32/64 bit)
and can also link to one other planck or itself.
Multiple variables can reference the same planck.

Before any operations with a variable,
the variable references a unique planck,
with the value 0.
This planck does not link to any other planck.

### VALUE OPERATIONS

To change the value of a planck,
use the assignment operator `=`
on a variable that references the planck in question.

```
a = 10 // gives the planck, that is referenced by a, the value 10
```

A different literal for a value is a char,
which has the value of an ascii character.

```
a = '!' // a has the value of 33, the ascii value of !
```

Values of plancks and value literals can be combined with operators:

```
a = a * 2 // a is doubled
```

Floating point number values can also be defined,
with at least an .0 at the end of the number.

```
a = 28.72345
```

To perform correct floating point arithmetic,
the operators `~+`, `~-`, `~*`, and `~/` are used,
instead of +, -, *, and / for integers.
Using the wrong operators yields unexpected results.

```
// should not be done
a = 1.0 * 2.0 // interpreted as integer: 0, as float: 0.0

a = 1.0 ~* 2.0 // interpreted as integer: 4611686018427387904, as float: 2.0
```

With all the mentioned arithmetic operators and `%` (modulus),
an assignment short form operator can be used. 

```
a += 1 // equivalent to a = a + 1
b ~*= 2.0 // equivalent to b = b ~* 2.0
```

Comparing operators of values in planck either yield the value 0 or 1,
evaluating to true and false respectively.
The operators found in planck are
common in many other programming languages (`==`, `!=`, `>`, `>=`, `<`, `<=`)

Logical and bitwise operators in planck are the same.
The following operators are supported:
`!` (not/negation), `&&` (and), `||` (or), `^` (xor). 

```
b = 0
c = 1
d = 2
b < c && c < d // will yield the value 1
```

### PLANCK AND LINKING OPERATIONS

Until now, we have only discussed how to change the value of a planck,
by a variable that references this planck. 
To change reference of variable to a different planck,
the planck reference assignment operator `&=` can be used.

```
a = 2
b = 3
a &= b // the variables a and b, now both reference the planck with the value 3 
a == b // yields 1
```

Instead of using a variable as to reference a planck,
squared brackets (`[]`) can also surround
a value to create a new planck, with this value.

```
a &= [0] // a now references a new planck with the value 0, that does not link to another planck
a &= [a] // a now references a new planck with the value of a (still 0), that does not link to another planck
```

Another way to create new plancks,
is by using the string literal, enclosed by quotes (`""`).
For each character in the literal a new planck is created,
which links to the next character planck.
The last character does not link to any other plancks.
Using the string literal returns the reference
of the first of the newly created plancks
and therefore has the value of the first character in the string.

```
a = "abc" // a contains a reference to a planck with the value 'a'
```

To get the planck, that a planck is linking to, use the next operator (`>>`).

```
a = "abc" // a contains a reference to a planck with the value 'a'
a &= a >> // a contains a reference to a planck with the value 'b'
```

To assign a variable the reference to the next planck,
of the one that it is currently referencing,
use the next assignment operator `=>>`.

```
a =>> // equivalent to a &= a >>
```

But if this operator is used on a variable, <!-- // TODO: richtig? -->
that references a planck that does not link to another planck.
....

To link a planck to another planck use the link operator `<<`.

```
a << b // a references a planck that links to a planck referenced by b
```
## OPERATORS

| operator | name | description |
|----------|------|-------------|
|          |      |             |

## FLOW CONTROL

### IF-STATEMENTS

```
if <condition> {
    ...
} elif <condition> {
    ...
} else {
    ...
}
```

### LOOPS

```
loop <condition> {
    ...
}
```

### FUNCTIONS

```
#<name> {

}
```

```
#<name>(<params>)
```

#### Parameter-Loop

In a function all parameters can also be accesses through the parameter loop.
A parameter loop is defined by the following syntax:

```
$<name> {
    ...
}
```

The loop iterates each parameter,
which can be accesses with $
or when <name> is specified optionally,
with $<name>.
The access of the parameter is called the parameter identifier.
This parameter access functions as a normal variable.

Example:
``
sum
$param {
    sum += $param
}
``

In the loop the short form $0, $1, etc. can still be used.

Parameter loops can also be nested,
but the parameter identifier should probably be renamed,
as the scope rules still apply for parameter identifier.
If a nested parameter loop has the same parameter identifier,
the parameter identifier will be identical
to the parameter identifier of the outer parameter loop.


### SHORT FORMS

#### IF STATEMENTS

```
[<condition>] ? {
    ...
} : [<condition>] {
    ...
} : {
    ...
}
```

#### LOOPS

```
[<condition>] {
    ...
}
```

## SYSTEM

| keyword | usage | description |
|---------|-------|-------------|
| stdin   |       |             |
| stdout  |       |             |
| stderr  |       |             |
| stdnum  |       |             |
| os      |       |             |

<!--
TODO: sowas wie: 
```kernel32 = os[WIN32API_OPTIONS] >>```
-->

## SCOPES



## REFERENCE MANUAL

| nonterminal | syntax | description |
|-------------|--------|-------------|
|             |        |             |
