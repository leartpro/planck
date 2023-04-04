# PLANCK

## INTRODUCTION

Planck is designed
to meet the requirements of algorithmic programming while remaining
as lightweight and low level as possible.
Therefore, the name planck, because a planck unit or length,
is the smallest theoretical length possible in physics.

## USAGE

`
planck <filename> [-option]
`

`
planck "<code>" [-option]
`

### FLAGS

Mögliche flags für `[-option]` sind:

| flag | name   | description                      | usage                |
  |------|--------|----------------------------------|----------------------|
| -d   | debug  | schaltet den debug output an     | `-d`                 |
| -b   | break  | bricht an der gegebenen Zeile ab | `-b <line number>`   |
| -i   | input  | legt den Input fest              | `-i <input source>`  |
| -o   | output | left den Output fest             | `-o <output source>` |

Standardmäßig sind Input und Output die Konsole.

### DEBUG

In Planck kann es unter keinen Umständen zu Laufzeitfehlern kommen.
Da es keine Fehlermeldung gibt,
muss nach ungewünschtem Verhalten geprüft und getestet werden.

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

## CONTAINER

In Planck gibt es nur Container.
Jeder Container kann einen Wert, bis zu einem Byte groß, speichern.
des Weiteren kann jeder Container beliebig mit anderen Containern verbunden werden.

```
a = 1
b = 2
a << b
c = a >> //2
a />
c= a >> //0x00
```

Da es nur Container gibt,
existieren in Planck keine Datentypen und müssen daher auch nicht angegeben werden.
Leere Zuweisungen von Containern sind nicht möglich.
Zuweisungen können in Binär, Hexadezimal oder dezimal erfolgen.

```
a = 0x02
b = 01001100
c = a + b //01001110
d = c ^ b //00000010
e = 230
f = -230
d = e - f //00000000
```

Jeder Container speichert seinen Wert unsigned,
allerdings ist eine Eingabe von negativen Dezimalzahlen dennoch erlaubt.
Die Interpretation und Verwendung ist daher vom Entwickler abhängig.

## OPERATORS

In Planck gibt es keine Schlüsselwörter, dafür aber einen großen Umfang an Operatoren.

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

- nur basic flow control

### CONDITIONS

Innerhalb einer Condition kann ein einziges Byte stehen.
Dieser wird als falsch interpretiert, wenn er null ist, andernfalls als wahr.
Sowohl Vergleichsoperatoren oder Operatoren, welche Wahrheitswerten als Rückgabe haben,
sind ebenfalls in Conditions zugelassen.
Ebenfalls zugelassen sind Rechnungen,
das Ergebnis wird dementsprechend interpretiert.

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

 ```
[<condition>] {
    ; // breaks the loop
}
 ```

### PROCEDURES

Der Name einer Procedure wird immer kleingeschrieben.
Eine Procedure kann beliebig viele Argumente erhalten, 
diese müssen aber vorher definiert werden.
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

Procedures können mit oder ohne Argumenten aufgerufen werden.

Without arguments:
```
<name>
```

With arguments:
```
<name> <arg1>, <arg2>
```
### ROUTINES


#### SUBMIT

- wenn submit, dann lasse gebe submit wert zurück und
  nach Beenden des procedure aufrufers, läuft die methode noch weiter

```
<name> {
    -> <value>
}
```

### RETURN

Gibt mindestens eine value zurück und beendet die Procedure oder die Routine.

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

Ein Struct fasst beliebig viele Attribute.
Der Name eines Structs muss immer großgeschrieben werden.
Der Standartwert ist optional und standardmäßig null.
Ein Struct kann wie folgt definiert werden:

```
<Name> {
    <attribute>: <default value>
    <attribute>: 
    <attribute>: <default value>
}
```

Ein Struct kann wie folgt verwendet werden:

````
a = <Name> <attribute> <attribute>
````

### PARAMETERS

Parameter können entweder über `$<index>` abgefragt werden,
oder über eine parameter loop.

```
params $<name> {
    <statements>
}
```

### SCOPES

Das oberste Scope in planck ist das file scope.
Darunter kommen die procedure scopes und die routine scopes.
Loops und Bedingungen fallen unter das block scope.
Alle Scopes, unter dem file scope, lassen sich an den Blockklammern erkennen.

```
{
    <statements>
}
```

Da es keine `main` oder vergleichbares gibt,
wird der Code von oben nach unten abgearbeitet.
Procedures und Routines müssen definiert sein,
bevor diese verwendet werden können.

## SYSTEM

| operator | name   | description                       | usage           | 
|----------|--------|-----------------------------------|-----------------|
| `<:`     | input  | reads the given input byte wise   | `<variable> <:` |
| `:>`     | output | writes the given output byte wise | `<variable> :>` |

## IMPORT / EXPORT

Es ist nicht möglich Inhalte aus anderen Dateien zu importieren
oder zu anderen Dateien Inhalte zu exportieren.
Daher ist es nicht möglich mehrere `.planck` Dateien miteinander zu verknüpfen.