# planck
### die Idee von planck
Planck ist darauf ausgelegt, den Ansprüchen der algorithmischen Programmierung gerecht zu werden
und dabei möglichst lightweight zu bleiben.
Daher auch der Name, denn eine Planck-Einheit beziehungsweise länge,
ist in der physik die kleinste theoretische länge die möglich ist.
### Daten
In planck gibt es Pointer und Werte. Dabei hat jeder Wert einen Pointer.
Die Schreibweise ist wie folgt:

#### Werte
```
a* // Wert von a
```

Einem Wert können entweder Zahlen oder Zeichen übergeben werden

```
a* = 7
b* = 'p'
```

Dabei kann ein Wert nie größer als ein byte werden.
Es können also nur positive ganze Zahlen von 0 bis 255
und einzelne Zeichen z.B. 'a' dargestellt werden.

```
a* = 312 //Fehler
a* = "Hallo" //Fehler
```

Man kann mit Werten auch rechen,
doch dabei muss erneut beachtet werden,
dass ein Wert nie größer als ein Byte sein darf.

```
a* = 2
b* = 'b' // Wert von 98
c* = a* + b* // Wert von 100 
d* = c* + 200 // Wert von 44, wegen overflow
```
<!--
    01100100 + 11001000 = 01|00101100
    100      +      200 =   |44
-->

#### Pointer

Die Variable a ist ein Pointer auf eine Variable,
die einen Wert (hier den von a*) enthält. 
Die Variable b kann hier ebenfalls auf eine Variable verweisen. 

```
a* // Wert von a
a // Pointer von a
a << b // a zeigt auf b, bzw. b wird an a angehangen
```

Wenn a auf eine Variable zeigt und b auf a gesetzt wird, zeigt b ebenfalls auf diese Variable.
Wenn der Wert dieser Variable anhand der Referenz in b (mit b*) geändert wird,
enthält a* den gleichen Wert (hier 'a').

```
a
b = a
b* = 'a' // a* == b* 
```

Da zum Beispiel die Variable A zu B und 

```
a = 7 // a -> {00000111} ->
a = 312 // a -> {01111111} -> {10111001} ->
a = 'h' // a -> {01101000}
a = "hallo" // a -> {01101000} -> {01100001} -> {01101100} -> {01101100} -> {01101111} ->
```

Hier wird, sollte ein byte für die Zuweisung nicht ausreichen, ein weiterer byte angehängt.


- was ist ein pointer
- was ist der Wert eines pointers

### Rechenoperatoren
#### für Pointer
#### für Werte
- fließkommazahlen
- rechnen mit werten
- rechnen mit pointer

### keywords / default pointer 
- 

### Control flow
- 
