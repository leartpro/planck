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

Because the next operator crashes on a planck,
if that planck does not link,
use the next check operator `?>`,
to check for this case.
It gives the value 0,
if the planck does not link,
or 1 for the opposite case.

```
// a links to b, b does not link
a ?> // 1
b ?> // 0
```

To link two plancks,
the linking operator `<<`
can be used.

```
a << b // links the planck referenced by b, to the planck referenced by a
```

This operation does not return any value
and is therefore comparable to an assignment operation.

To remove a link of a planck to another,
use the unlink operator `\>`.
This operation too, does not return any value.
This operation will however not crash,
if operand planck, does not link to another planck.

```
a << b
a /> // planck referenced by variable a, does not link anymore
```

The linking operator returns the last
planck in the resulting chain created by linking the plancks.
If the resulting chain however is a circle, 


But if this operator is used on a variable, <!-- // TODO: richtig? -->
that references a planck that does not link to another planck.
....

To link a planck to another planck use the link operator `<<`.

```
a << b // a references a planck that links to a planck referenced by b
```

This operation too, does not return anything.

To check if planck references are the same,
use the planck equality operator `===`.
This will return the value 0,
if the references are not the same
and return 1 if they are.

```
b &= c // b and c both reference the same planck, a does not 
b === c // returns 1
a === b // returns 0
```

### VARIABLE REFERENCE VERSUS PLANCK REFERENCE EXPRESSIONS VERSUS VALUE EXPRESSIONS

A variable reference is needed for all planck reference assignments (`&=`).
It cannot be substituted for a planck reference expression,
as the planck reference itself is being assigned.

A planck reference expression can be:
- a variable reference (the variable references a planck)
- the string literal (the string literal creates linked plancks for each character
and returns the reference of the first planck)
- the `[]` operator (creates a new planck with the given value and returns its reference)

It is needed on the left side of value assignments,
such as `=` and `~*=`,
as the value of a referenced planck is changed.

Exclusively planck reference expressions are also needed in
the operands of the operators `<<`, `?>` and `\>`,
as these are planck operations.

A value expression can be the number literals (e.g. `123`)
and the character literals `'a'`.
But reference expressions can also be used
(this also includes variable references),
as instead of the reference of a planck,
the value of this planck is used.

Operations where value expressions are asked for:
- the `[]` operator
- right side of value assignments
- all arithmetic, logical and comparing operators

## OPERATORS

| operator | name | description |
|----------|------|-------------|
|          |      |             |

## FLOW CONTROL

### SCOPE

Different scopes in planck are marked with enclosing
curly braces (`{}`),
in each scope there can be variables only found in this scope
and therefore initialized at the beginning of the scope.
But in a scope, variables of the ancestor scopes
can also be accessed.#

A variable that is supposed to be only found
in a scope, is not allowed to be used in one of its ancestor scopes.
This means that the first depth of a scope where a variable is used,
is where the variable is declared and initialised.

```
// variables a and i are declared and initialised here with 0

a // makes usage of a in this scope clear
{
    // variable b is declared and initialised here with 0
    
    a += 1 // uses a from its ancestor scope
    b *= 2 // makes usage of b in this scope clear
}

{
    // variable b is declared and initialised here with 0,
    // separate from the first definition,
    // this means this variable
    // is completely detached from the 'other' b
    
    b += 3 // makes usage of b in this scope clear
    a += 1 // uses a from its ancestor scope
}
i += 1 // makes usage of i in this scope clear
```

### CONDITIONS

A condition in planck is just a value,
which is read as false, if the value is 0,
or true if the value is anything else.

This is analogue to all comparison
operators and logical operators,
which also return 1 for true and 0 for false.

### EXEC-STATEMENTS

The `exec` statement declares a scope
and executes immediately once.
It can be used to simply create a new scope.

```
exec {
    ...
}
```

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

### LOOP-STATEMENTS

A loop statement executes a scope in a loop,
until the condition is not met anymore.

```
loop <condition> {
    ...
}
```

### PROCEDURE-DECLARATIONS AND CALLS

A procedure name always needs to contain
a `#` in the beginning of its name.
Parameters are not explicitly declared.

```
store #<name> {
    ...
}
```

A procedure is callable in the scope where it was declared.
Declaring two procedures with the same name,
being accessible in the same scope, is not permitted.

A procedure call does not feature any parentheses,
instead all arguments are simply listed with a comma after the name.
A comma after the last parameter is not permitted.
Two commas in a row are not permitted.
If a value expression is given as a parameter,
the `[]` operator will implicitly be used on this value.
All arguments are therefore planck references.

```
#<name> // no arguments
#<name> <arg1>, <arg2> // no arguments
```

A procedure call does not give back any value.

The outermost scope in planck is declared as the `#main` procedure.
It is called with the program location as its first argument,
and the program arguments as the rest arguments.
This means that the `#main`
can be called recursively inside the `#main`.

#### PARAMETER ACCESS

In the procedure the first parameter is referred to as $0,
the second as $1, etc.
Each of the parameters is a variable like any other variable.

To dynamically access all parameters
the parameter loop can be used.
A parameter loop is defined by the following syntax:

```
params $<name> {
    ...
}
```

The loop iterates each parameter,
which can be accesses with `$`
or when <name> is specified optionally,
with `$<name>`.
`<name>` is however not allowed to be a number.
The access of the parameter is called the parameter identifier.
This parameter access functions as a normal variable.

Example:
``
sum
params $p {
    sum += $p
}
``

The parameter identifier acts like `$0` in the first iteration,
`$1` in the second iteration, etc.
This means any operations with the parameter identifier
in the first iteration is the same as an operation with `$0`.

In the loop, the short form `$0`, `$1`, etc. can still be used.

Parameter loops can also be nested,
but the parameter identifier has to be renamed.

### INTERRUPTIONS

An interruption allows all variables
to be read and written to by the system.
This is important for the system variables,
which will be introduced in the next chapter.

Syntax for an interruption:
```
interrupt
```

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
