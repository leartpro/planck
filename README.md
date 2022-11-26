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

Dabei darf ein Wert nie größer als ein Byte sein.
Es können daher nur positive ganze Zahlen von 0 bis 255,
so wie einzelne Zeichen z.B. 'a' dargestellt werden.
Die Zuweisung von größeren Zahlen oder Zeichenketten wirft einen Syntaxfehler.
```
a* = 312 //Fehler
a* = "Hallo" //Fehler
```

Beim Rechnen mit Werten muss erneut beachtet werden,
dass das Rechenergebnis nicht größer als ein Byte sein darf.

```
a* = 2
b* = 'b' // Wert von 98
c* = a* + b* // Wert von 100 
d* = c* + 200 // Fehler, da der Wert der Rechnung (300) größer ist als ein Byte (255)
```
<!--
    01100100 + 11001000 = 01|00101100
    100      +      200 =   |44
-->

Wie dem Beispiel zu entnehmen ist, können Zeichen mit Zahlen verrechnet werden.
Dabei wird der Ascii-Wert, des Zeichen, genommen.

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
Und jede dieser Variablen einen Byte-Wert enthalten kann,
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

Genau das gleiche Prinzip kann auf Zahlen angewendet werden. 
Wenn einer Variable ein Wert zugewiesen wird,
wird dieser Variable ein neuer Pointer zugewiesen.
Dieser zeigt auf eine Variable, welche den zugewiesenen Wert enthält.
Es können des Weiteren wie bei Zeichenketten, Verkettungen erzeugt werden,
sollten die Zahlen zu groß für ein Byte sein.

```
a = 7 // a -> A: {00000111} ->
a = 312 // a -> B: {01111111} -> {10111001} ->
a = "hallo" // a -> D: {01101000} -> {01100001} -> {01101100} -> {01101100} -> {01101111} ->
```

Auch Fließkommazahlen können so erzeugt werden:

```
a = 0.3
b = 0.4
```
## Operatoren

| Operator   | Name                     | Bedeutung                                      |
|------------|--------------------------|------------------------------------------------|
| a          | Initialisierungsoperator | Standard Initialisierung mit einem leeren Byte |
| a << b     |                          |                                                |
| a,b,c << d |                          |                                                |
| a = b      |                          |                                                |
| a <<= b    |                          |                                                |
| a >>       |                          |                                                |
| a <\       |                          |                                                |
| a ?>       |                          |                                                |
| a === b    |                          |                                                |
| a !== b    |                          |                                                |
| a == b     |                          |                                                |
| a != b     |                          |                                                |
| a < b      |                          |                                                |
| a > b      |                          |                                                |
| a <= b     |                          |                                                |
| a >= b     |                          |                                                |
| a + b      |                          |                                                |
| a - b      |                          |                                                |
| a * b      |                          |                                                |
| a / b      |                          |                                                |
| a ~* b     |                          |                                                |
| a ~/ b     |                          |                                                |
| -a         |                          |                                                |
| a +=       |                          |                                                |
| a -= b     |                          |                                                |
| a *= b     |                          |                                                |
| a /= b     |                          |                                                |
| a  ~*= b   |                          |                                                |
| a ~/= b    |                          |                                                |

### Operatoren von Pointern

Rechenoperatoren können von ein bis zwei Pointern den gesamten Wert
von allen folgenden Pointern betrachten,
mit diesem Wert rechnen und in eine neue Kette verteilen.
Der Pointer dieser Kette wird dann zurückgegeben.
Operatoren können niemals die Werte verändern in den Variablen,
sondern nur neue Ketten zurückgegeben.
```
a = 2 // a -> A: {00000010} ->
b = 3 // b -> B: {00000011} -> 
a = a * b * 2 // a -> C: {00001100}
```

Pointer und Werte müssen jedoch immer getrennt bleiben,
auch ihre Operatoren und Literals. <!-- TODO: vielleicht bis auf manche Operatoren -->

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
a << c // an A wird C gehangen, b wird abgehangen
a <\ // von A wird C abgehangen, an A hängt nichts mehr
```

### Vergleichsoperatoren

Konditionale Operatoren bei Pointern
geben immer den Pointer einer neuen Variable zurück,
die 1 für true oder 0 für false enthält.

```
// a -> A, b -> B
a ?> // ob A auf eine andere Variable
a === b // ob a und b den gleichen Pointer enthalten
a == b // ob von A und B aus die beiden Ketten die gleichen Werte enthalten
a > b // ob von A und B aus die beiden Ketten als Zahl betrachtet,
      // die Kette von A einen größeren Wert enthält
```

Konditionale Operatoren bei den Werten von Pointern
geben lediglich die Werte 1 für true und 0 für false.

```
// a -> A, b -> B
a* == b* // ob der Wert von A gleich dem Wert von B entspricht
a* < b* // ob der Wert von A kleiner ist als der von B
```

### Logische Operatoren

Es gibt die standard logischen Operatoren
| (xor), || (or), && (and), ! (not).

Diese können getrennt angewendet werden auf entweder
Ketten oder Werten.

```
a* = 1 + 4 + 16 + 64 // 01010101
a* = !a* // 10101010
a = 312 // a -> A: {01111111} -> {10111001} ->
a = a && 11 // A: {01010000} -> {00000000} -> bzw. 10
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
kann dieser auch als zuweisungsoperator verwendet werden. 

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
Ist der Wert nicht 0 oder der gesamte Wert der Kette des Pointers nicht 0,
wird die Bedingung erfüllt, ansonsten nicht.

### If, elif und else

Ein Beispiel:

```
if a* == 'a' {
     ...
} elif a === b && a == 511 {
     ...
} else {
     ...
}
```

Ohne Klammern, darf auch ein if alleine stehen:
```
if (a << b)* == 'a' a << c
```

## Funktionen
