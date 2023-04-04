#include <iostream>
#include <fstream>
#include "Lexer.h"
#include "AST.h"
#include "Parser.h"
#include "Interpreter.h"

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
        const auto code = "x = 3 + 4 * 2\ny = x / 2 - 1";
        Lexer lexer(code);

        // Parser initialisieren
        Parser parser(lexer);

        // AST aufbauen
        AstNode *rootNode = parser.parse();

        // Interpreter initialisieren und Auswertung starten
        Interpreter interpreter;

        // Ergebnis ausgeben
        std::cout << "Result: " << interpreter.interpret(rootNode) << std::endl;

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