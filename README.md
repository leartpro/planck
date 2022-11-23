# planck
### die Idee von planck
Planck ist darauf ausgelegt, den Ansprüchen der algorithmischen Programmierung gerecht zu werden
und dabei möglichst lightweight zu bleiben.
Daher auch der Name, denn eine planck einheit  beziehungsweise länge,
ist in der physik die kleinste theorestische länge die möglich ist .
### Daten
In planck gibt es pointer und werte. Dabei hat jeder wert einen pointer.
Die Schreibweise ist wie folgt:
``
a* //Wert
``

``
a //Pointer
``

Einem Wert können entweder Zahlen oder Zeichen übergeben werden

``
a* = 7
b* = 'p'
``

Dabei kann ein Wert nie größer als ein byte werden.
Es können also nur positive Zahlen vvon 0 bis 255 und einzelne Zeichen z.B. 'a' dargestellt werden.

``
a* = 312 //Fehler
a* = "Hallo" //Fehler
``

Anders ist es bei Pointern.

``
a = 7 // a -> {00000111} ->
``

``
a = 312 // a -> {01111111} -> {10111001} ->
``

``
a = 'h' // a -> {01101000}
``

``
a = "hallo" // a -> {01101000} -> {01100001} -> {01101100} -> {01101100} -> {01101111} ->
``

Hier wird, sollte ein byte für die Zuweisung nicht ausreichen, ein weiterer byte angehängt.


- was ist ein pointer
- was ist der Wert eines pointers

### Rechenoperatoren
#### für Pointer
#### für Werte
- fließkommatarzahlen
- rechnen mit werten
- rechnen mit pointern

### keywords / default pointer 
- 

### Control flow
- 
