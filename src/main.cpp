#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

    string programText;

    ifstream is(argv[2]);
    if (is) {
        while (!is.eof()) {
            char c;
            is.get(c);
            programText += c;
        }
    } else {
        cerr << "Could not open file " << argv[2] << endl;
        return 1;
    }

    try {
        // Lexer initialisieren
        Lexer lexer(code);

        // Parser initialisieren
        Parser parser(lexer);

        // AST aufbauen
        AstNode* rootNode = parser.parse();

        // Interpreter initialisieren und Auswertung starten
        Interpreter interpreter;
        interpreter.visit(rootNode);

        // Ergebnis ausgeben
        std::cout << "Result: " << interpreter.getResult() << std::endl;

        // AST freigeben
        delete rootNode;
    }
    catch (exception &e) {
        cerr << e.what() << endl;
    }
    catch (...) {
        cerr << "Unexpected error" << endl;
    }
    return 0;
}