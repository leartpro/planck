# PLANCK

TODO: Pointer & Referenzen

## INTRODUCTION

Planck is designed
to meet the requirements of algorithmic programming while remaining 
as lightweight and low level as possible.
Therefore, the name planck, because a planck unit or length,
is the smallest theoretical length possible in physics.

## USAGE

```
planck <filename> [-option]
```
```
planck "<code>" [-option]
```

### FLAGS

- hier mögliche flags für [-option]

### DEBUG

in der Laufzeit können keine Fehler, sondern nur fehlerhaftes/ungewolltes Verhalten auftreten.

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

- Zuweisungen nur für hexadezimale zahlen odr binäre zahlen bis zu einem byte
- interpretation(positiv/negativ) ist dem entwickler überlassen (feature :D)
```
a = 0x02
b = 01001100
c = a + b //01001110
d = c ^ b //00000010
```

## LINKING OPERATIONS

- container können beliebig verlinkt und end linkt werden
- -hier noch paar beispiele

## OPERATORS

- hier noch allgemeine beschreibung der operatoren

| operator             | precedence | operator name                    | description                                 |
|----------------------|------------|----------------------------------|---------------------------------------------|
| `a * b`, `a / b`     | 10         | multiplication / division        | multiplication / division operations        |
| `a % b`              | 10         | modulo                           | modulo operations                           |
| `a + b`, `a - b`     | 9          | addition, subtraction            | addition / subtraction operations           |
| `a < b`, `a > b`     | 7          | is-less, is-greater              | greater / less comparisons                  |
| `a <= b`, `a >= b`   | 7          | smaller/greater or equals        | greater-equals / less-equals comparisons    |
| `a == b`, `a != b`   | 6          | equals, not equals               | equals / not-equals comparisons             |
| `a & b`              | 5          | and                              | binary 'and' operations                     |
| `a &#124; b`         | 4          | or                               | binary 'or' operations                      |    
| `a ^ b`              | 4          | xor                              | binary 'xor' operations                     | 
| `a && b`             | 5          | and                              | logical 'and' comparisons                   |
| `a &#124;&#124; b`   | 4          | or                               | logical 'or' comparisons                    |    
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

In planck gibt es die gängigen Flow-Controls.

### CONDITIONS

Innerhalb einer Condition kann ein einziges Byte stehen. 
Dieser wird als falsch interpretiert, wenn er null ist, andernfalls als wahr.
Sowohl Vergleichsoperatoren oder Operatoren, welcheWahrheitswerten als Rückgabe haben,
sind ebenfalls in Conditions zugelassen.

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

#### BREAK

 ```
[<condition>] {
    ; // breaks the loop
}
 ```

### PROCEDURES

Der Name einer Procedure wird immer kleingeschrieben.

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

```
<name> {
    -> <value>
}
```

#### RETURN

Gibt mindestens eine value zurück und beendet die Procedure.

```
<name> {
    <- <value>
}
```

### STRUCTS

Ein Struct fasst beliebig viele Attribute.
Der Name eines Structs muss immer großgeschrieben werden.

#### DECLARATIONS

Der Standartwert ist optional und standardmäßig null.

```
struct <Name> {
    <attribute>: <default value>
    <attribute>: 
    <attribute>: <default value>
}
```

#### USAGES

````
a = <Name> <attribute> <attribute>
````


### PARAMETERS

Parameter können entweder über `$<index>` abgefragt werden, 
oder über eine Parameter-Loop, bez. Procedure.

```
params $<name> {
    ...
}
```

## ROUTINES

Routines sind wie Procedures, nur Nebenläufig.
Diese können über Channels miteinander Kommunizieren.
Dadurch wird nebenläufige Programmierung in planck ermöglicht.

### SUBMIT

- wenn submit, dann lasse gebe submit wert zurück und
  lasse routine aber weiter laufen
- (ka ob das geht)

### CHANNELS

- wie in golang nur planck syntax halt


## SCOPES

Der Code wird von oben nach unten ausgeführt, da es keine main o.ä. gibt.
Das oberste Scope ist das File-Scope, da es weder Import, noch Export von anderen Dateien gibt.
Darunter kommen die Procedure und Routine Scopes.
Die untersten Scopes stellen die Block Scopes dar.

Ein Scope lässt sich grundsätzlich (abgesehen vom File-Scope) an den Block-Klammern erkennen.

```
{
    ...
}
```

## SYSTEM

| keyword | usage | description |
|---------|-------|-------------|
| in      |       |             |
| out     |       |             |