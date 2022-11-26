# planck

## die Idee von planck

Planck ist darauf ausgelegt,
den Ansprüchen der algorithmischen Programmierung gerecht zu werden
und dabei möglichst lightweight zu bleiben.
Daher auch der Name planck, denn eine Planck-Einheit beziehungsweise Länge,
ist in der Physik die kleinste theoretische Länge, die möglich ist.

## Kommentare

```
// Zeilenkommentar

/*
 * Reihenkommentar
 *
*/
```

## Daten, Variablen und Werte

### Werte

```
a* // Wert von a
```

Einem Wert können entweder Zahlen oder Zeichen übergeben werden.

```
a* = 7
b* = 'p'
```

Dabei darf ein Wert nie größer als ein 64Bit sein.
Es können daher ganze Zahlen und Fließkommazahlen,
so wie einzelne Zeichen z.B. 'a' dargestellt werden.
Die Zuweisung von größeren Zahlen oder von Zeichenketten wirft einen Syntaxfehler.
Sollte die Zuweisung einer zu großen Zahl innerhalb der Laufzeit passieren (z.B. durch eine Rechenoperation),
wird ein Laufzeitfehler geworfen.
Die Größe eines Wertes passt sich dabei dynamisch im Memory bis maximal 64Bit an.

```
a* = 2^65 //Fehler
a* = "Hallo" //Fehler
```

```
a* = 2 //Wert von 2
b* = 'b' // Wert von 98
c* = a* + b* // Wert von 100 
d* = c* + 200 // Wert von 300
```

Wie dem Beispiel zu entnehmen ist, können Zeichen mit Zahlen verrechnet werden.
Dabei wird der Ascii-Wert des Zeichens betrachtet.

Der Wertebereich von Fließkommazahlen liegt zwischen -2^53Bit und +2^53Bit.
Die maximale Anzahl an Nachkommastellen beträgt dabei 17.
```
a* = 304.2389457
```

### Pointer

Die Variable a ist ein Pointer auf eine Variable,
die einen Wert (hier den von a*) enthält.
Dabei kann die Variable b hier ebenfalls auf eine Variable verweisen.

```
a* // Wert von a
a // Pointer von a
a << b // a zeigt auf b, beziehungsweise wird b an a angehängt
```

Wenn a auf eine Variable zeigt und b auf a gesetzt wird,
zeigt b ebenfalls auf diese Variable.
Wenn der Wert dieser Variable anhand der Referenz in b (mit b*) geändert wird,
enthält a* den gleichen Wert (hier 'a').

```
a
b = a
b* = 'a' // a* == b* 
```

Da diese Variablen Ketten bilden können (z.B. A -> B -> C -> D).
Und jede dieser Variablen einen bis zu 64Bit großen Wert enthalten kann,
können Zeichenketten gebildet werden.
Im folgenden Beispiel wird die Zeichenkette "abc" von a aus gebildet.

```
a* = 'a' // der Pointer a von a* zeigt auf eine Variable A
b* = 'b' // der Pointer b von b* zeigt auf eine Variable B
c* = 'c' // ...
a << b // B wird an A angehängt
b << c // C wird an B angehängt
```

Die Kurzschreibweise lautet aber:

```
a = "abc"
```

Der Pointer den a dabei vorher besaß,
wird also verworfen und durch einen neuen Pointer ersetzt.


## Operatoren

### Operatoren von Pointern

Pointer und Werte müssen,
genauso wie ihre Operatoren und Literals,
getrennt behandelt werden.
<!-- TO-DO: vielleicht bis auf manche Operatoren -->

```
a* = a + b // Geht nicht, da das Ergebnis von zwei Pointern,
           // ein Pointer ist.
a * a* // Geht nicht, da es nur Operatoren zwischen zwei Pointern
       // und zwischen zwei nicht Pointern gibt.
a = 'a' // Geht nicht, da 'a' ein Wert ist
        // und keinen Pointer zurückgibt, richtig wäre "a"
a* = "a" // Geht nicht, da "a" einen Pointer zurückgibt
         // und man aber a* einen Wert zuweise muss
```

Um dem zu entgehen, kann mit {```WERT```} ein Wert in eine neue Variable eingesetzt werden,
der Pointer dieser Variablen kann dann zurückgegeben werden.

```
// a -> A, b -> B
a = {b*} // a wird einem Pointer zugewiesen,
         // der auf eine neue Variable zeigt,
         // die den gegebenen Wert enthält
         // (in diesem Fall, der Wert von B)
a = {b* + 12 + 'b'} // erweitertes Beispiel
```

Verändernde Operatoren/Operationen für Pointer am Beispiel a -> A, b -> B, c -> C:

```
a << b // An A wird B angehängt,
       // die letzte Variable in der Kette von B wird zurückgegeben,
       // so dass Ketten wie a << "asdf" << 34 << b erzeugt werden können
a >> // Der Pointer von B wird zurückgegeben,
     // wenn A auf nichts zeigen würde,
     // ergäbe das einen Fehler
a << c // an A wird C gehängt, b wird abgehangen
a <\ // von A wird C abgehangen an A hängt nichts mehr
```

### Vergleichsoperatoren

Konditionale Operatoren bei Pointern
geben immer den Wert zero oder eins zurück.

```
a -> A, b -> B
a ?> // ob A auf eine andere Variable zeigt
a === b // ob a und b den gleichen Pointer enthalten
```

Konditionale Operatoren bei den Werten von Pointern
geben lediglich die Werte eins für true und zero für false.

```
// a -> A, b -> B
a* == b* // ob der Wert von A gleich dem Wert von B entspricht
a* < b* // ob der Wert von A kleiner ist als der von B
```

### Logische Operatoren

Es gibt die standard logischen Operatoren
| (xor), || (or), && (and), ! (not).

Diese können auf Werte angewendet werden und geben einen anderen Wert zurück.

```
a* = 1 + 4 + 16 + 64 // 01010101
a* = !a* // 10101010
```

### Zuweisungsoperatoren

Alle Rechenoperatoren, Vergleichsoperatoren und logische Operatoren
mit zwei Operanten, dürfen immer auch als Zuweisungsoperatoren
verwendet werden, mit einem zusätzlichen '=' am Ende des Operators.

```
a* &&= 234 // a* = a* && 234
```

Da der verändernde Operator '<<'
den Pointer der hintersten Variable in der Kette des zweiten Operanden zurückgibt,
kann dieser auch als Zuweisungsoperator verwendet werden.

```
// a -> A
a <<= "abc" // hängt {'a'} -> {'b'} -> {'c'} hinten an A,
            // nun hat a den Pointer der neu
            // erzeugten Variable mit dem Wert 'c'
```

Es gibt außerdem den Operator '=>>'. Ein Beispiel:

```
a -> A: {} -> B ->
a =>> // a zeigt nun auf die nächste Variable, also hier B
```

Eine volle Liste an Operatoren befindet sich am Ende. <!-- TODO: Am Ende-->

### System Variablen

Bestimmte Variablen Namen sind bereits reserviert und können nur mit bestimmten Operatoren verwendet werden.
"stdout" und "stderr" sind Ausgabe und Fehlerausgabe und können nur mit dem Operator '<<=' verwendet werden,
um etwas auszugeben.

"stdin" darf nur mit den Operatoren '?>' und '=>>' verwendet werden um zu überprüfen,
ob weitere Zeichen eingegangen und dann zum nächsten Zeichen zu springen.
Mit "stdin*" darf außerdem das aktuelle Zeichen gelesen werden.

Auf "stdout", "stderr" und "stdin" darf nicht verwiesen werden.

### Weitere reservierte Variablennamen

Alle Schlüsselworte von planck dürfen nicht als Variablenname verwendet werden.

## Control flow

### Bedingung

Als Bedingung darf ein Wert oder ein Pointer verwendet werden.
Ist der Wert nicht zero, wird die Bedingung erfüllt, ansonsten nicht.

Beispiel für eine erfüllende Bedingung: 10100000

Eine nicht erfüllende Bedingung: 00000000

### If, elif und else

Ein Beispiel:

```
if a* == 'a' {
     ...
} elif a === b && a* == 511 {
     ...
} else {
     ...
}
```

Ohne Klammern, darf auch ein if alleine stehen:

```
if (a << b)* == 'a': a << c
```

### Schleifen

```
loop <Bedingung> {
<Statements>
}


loop a* > 0 {
...
} 

```

## Funktionen
{
asdf*

{
i

}

{
i
asdf
}
}


loop {
a //a = {0}

}

- Function Syntax:
```
add: {
$0* + $1*
}
```
- gibt ken scope
- -expression scope, block scope, function scope, file scope, module scope, global scope
- Parameter-Loop
  - gibt es in functions für die parameter
  - gibt es außerhalb der functions für klassenargumente
  - 
```

add: {
$0* + $1*
}

<name>: {

parameterloop {
parameterloop {
}
}
$
...
submit
...
return
}
}
```

## Import

```
#import<List>

imports <<= "import.planck" :-(
```

## Reference Manual

| nonterminal      | syntax                                                                                         | description                                                 |
|------------------|------------------------------------------------------------------------------------------------|-------------------------------------------------------------|
| *Statement*      | *EmptyStatement*<br/>*Expression*<br/>*Assignment*<br/>*ControlFlow*<br/>*FunctionDeclaration* | The planck language exclusively consists *Statement*s       |
| *EmptyStatement* |                                                                                                | An empty line consisting of only whitespace and/or comments |

### PointerReference and ValueReference



| nonterminal        | syntax                            | description                                                                                     | Example |
|--------------------|-----------------------------------|-------------------------------------------------------------------------------------------------|---------|
| *PointerReference* | Regex: **(?![0-9])[a-zA-Z_0-9]+** | Variable reference of the pointer.                                                              | `a`     |
| *ValueReference*   | *PointerReference*`*`             | The Value of a Variable, no whitespace is allowed in between the *PointerReference* and the `*` | `a*`    |

### Expression

| nonterminal                 | syntax                                    | description    |
|-----------------------------|-------------------------------------------|----------------|
| *Expression*                | *PointerExpression*<br/>*ValueExpression* | any Expression |

#### PointerExpression

| nonterminal                   | syntax                                                                                                                          | description                               |
|-------------------------------|---------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------|
| *PointerExpression*           | *PointerReference*<br/> `{`*ValueExpression* `}`<br/> `(` *PointerExpression* `)`<br/> *PointerOperation* <br/> *StringLiteral* | An expression with the value of a pointer |
| *PointerOperation*            | *TwoOperandsPointerOperation*  <br/> *PostfixPointerOperation*                                                                  |                                           |
| *TwoOperandsPointerOperation* | *PointerExpression* *TwoOperandsPointerOperator* *PointerExpression*<br/>                                                       |                                           |
| *PostfixPointerOperation*     | *PointerExpression* *PostfixPointerOperator*                                                                                    |                                           |

#### TwoOperandsPointerOperator

a -> A, b -> B

| Operator | precedence | operator name                    | description                                         |
|----------|------------|----------------------------------|-----------------------------------------------------|
| `a << b` | 8          | link                             | link A to B, return the last pointer of the B chain |


#### PostfixPointerOperator

| Operator | Name    | Bedeutung                                      |
|----------|---------|------------------------------------------------|
| `a >>`   | next    |                                                |
| `a <\ `  | unlink  |                                                |

#### StringLiteral

Ein String literal wird mit einem " angefangen und terminiert. 

Ausnahmen:

| Zeichen | Name                        | Darstellung im Quellcode |
|---------|-----------------------------|--------------------------|
| \       | Backslash                   | `"\\"`                   |
| '       | Einzelnes Anführungszeichen | `"\""`                   |
|         | ANSI Escape                 | `"\e"`                   |
|         | Zeilenumbruch               | `"\n"`                   |

#### ValueExpression
| nonterminal            | syntax                                                                                                                                                      | description                                                 |
|------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------|
| *ValueExpression*      | *ValueReference* <br/> *ValueOperation* <br/> *ValuePrefixOperation* <br/> `(` *ValueExpression* `)`<br/> *ConditionalPointerOperator* <br/> *ValueLiteral* |                                                             |
| *ValueOperation*       | *ValueExpression* *ValueOperator* *ValueExpression*                                                                                                         |                                                             |
| *ValuePrefixOperation* | *ValuePrefix* *ValueExpression*                                                                                                                             | Between prefix and the expression, no whitespace is allowed |
| *ValueLiteral*         | *Character* <br/> *Number* <br/> *FloatingPointNumber* <br/> *HexUnsignedNumber*                                                                            |                                                             |


#### ConditionalPointerOperator

| Operator             | Name                             | Bedeutung |
|----------------------|----------------------------------|-----------|
| `a ?>`               | is-next                          |           |
| `a === b`, `a !== b` | strict equals, strict not equals |           |

#### Character

Ein Char, den man einen Wert zuweisen kann, wird als `'[<char>]'` geschrieben,
wobei char für den konkreten char steht.
Ein char kann dabei jedes Ascii Zeichen sein.

Ausnahmen:

| Zeichen | Name                        | Darstellung im Quellcode |
|:--------|-----------------------------|--------------------------|
| \       | Backslash                   | `'\\'`                   |
| '       | Einzelnes Anführungszeichen | `'\''`                   |
|         | ANSI Escape                 | `'\e'`                   |
|         | Zeilenumbruch               | `'\n'`                   |
|         | Leerzeichen                 | `' '`                    |

#### HexUnsignedNumber

Unsigned integer as a 64bit hexadecimal number, with prefix 0x.

#### Number

Integer numbers and negative integer numbers are from -9223372036854775808 to 9223372036854775807.

#### FloatingPointNumber

A floating point number is written in the format of always having at least one decimal place.
Otherwise, the literal is interpreted as an integer number.

#### ValueOperator

Regex eines Variablen Wertes: `WERT = ` <!--TO-DO: testen -->

| operator           | precedence | operator name                       | description                                 |
|--------------------|------------|-------------------------------------|---------------------------------------------|
| `a * b`            | 10         | multiplication                      | multiplication for only full numbers        |
| `a / b`            | 10         | division                            | division for only full numbers              |
| `a % b`            | 10         | modulo                              |                                             |
| `a ~* b`           | 10         | multiply for fixed point numbers    | multiplication for only fixed point numbers |
| `a ~/ b`           | 10         | divide for fixed point numbers      | division for only fixed point numbers       |
| `a + b`, `a - b`   | 9          | addition, subtraction               | addition for numbers                        |
| `a ~+ b`, `a ~- b` | 9          | floating point addition/subtraction | addition for numbers                        |
| `a < b`, `a > b`   | 7          | is-less, is-greater                 |                                             |
| `a <= b`, `a >= b` | 7          | smaller/greater or equals           |                                             |
| `a == b`, `a != b` | 6          | equals, not equals                  |                                             |
| `a && b`           | 5          | and                                 |                                             |
| `a &#124;&#124; b` | 4          | or                                  |                                             |    
| `a ^ b`            | 4          | xor                                 |                                             | 

#### ValuePrefix

| Operator | operator name | Bedeutung |
|----------|---------------|-----------|
| `-a*`    | negate        |           |
| `!a*`    | not           |           |

### Assignment


| nonterminal  | syntax                                      | description |
|--------------|---------------------------------------------|-------------|
| *Assignment* | *ValueAssignment* <br/> *PointerAssignment* |             |

#### ValueAssignment

| nonterminal       | syntax                                                       | description |
|-------------------|--------------------------------------------------------------|-------------|
| *ValueAssignment* | *ValueReference* *ValueAssignmentOperator* *ValueExpression* |             |

#### ValueAssignmentOperator

| Operator | operator name | Bedeutung |
|----------|---------------|-----------|
| `=`      | assigment     |           |

#### PointerAssignment

| nonterminal         | syntax                                                                                                                   | description |
|---------------------|--------------------------------------------------------------------------------------------------------------------------|-------------|
| *PointerAssignment* | *PointerReference* *PointerAssignmentOperator* *PointerExpression*<br/>*PointerReference* *PointerSelfAssigmentOperator* |             |

#### PointerAssignmentOperator

| Operator  | operator name                               | Bedeutung |
|-----------|---------------------------------------------|-----------|
| `a = b`   | assigment                                   |           |
| `a <<= b` | link and assigment to last of complete link |           |

#### PointerSelfAssigmentOperator

| Operator  | operator name     | Bedeutung |
|-----------|-------------------|-----------|
| `a =>>`   | assigment to next |           |

#### Nummern

Ein Wert kann bei ganzen Zahlen von -2^64 bis 2^64 - 1 gehen.
Bei Fließkommazahlen von -2^53 bis 2^53 mit 17 Nachkommastellen.

#### Zeichen


### Pointer

Regex einer Variable: `[a-zA-Z_]+`

### Reservierte Pointer

| Name   | Bedeutung                                                         | Erlaubte operationen                                                                                                                      |
|--------|-------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------|
| stdout | Etwas in die Konsole ausgeben (stdout)                            | `<<=` etwas an stdout anhängen und damit ausgeben                                                                                         |
| stderr | Etwas in die Konsole ausgeben (stderr)                            | `<<=` etwas an stderr anhängen und damit ausgeben                                                                                         |
| stdin  | Überprüfen ob ein char eingegeben wurde und lese dann diesen char | `?>` überprüfen ob ein neuer char eingegangen ist <br/> `=>>` zum nächsten char gehen <br/> `stdin*` (nur lesen) lesen des nächsten chars |
| os     | Programm beenden                                                  | `os* = [code]` das Program beenden mit dem gegebenen code                                                                                 | 


