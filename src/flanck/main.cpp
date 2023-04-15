#include <iostream>
#include <fstream>
#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include "Statement.h"

using namespace std;

int main(int argc, char *argv[]) {

    ifstream is(argv[2]);
    if (!is) {
        cerr << "Could not open file " << argv[2] << endl;
        return 1;
    }

    is.seekg(0, ifstream::end);
    size_t fileSize = is.tellg();
    is.seekg(0, ifstream::beg);
    char programText[fileSize + 1];
    size_t i = 0;
    char c;
    while (is.get(c)) {
        programText[i++] = c;
    }
    programText[i] = '\0';

    //TODO: remove debug prints
    cout << programText << endl << static_cast <const void *> (programText) << endl;

    try {
        Lexer lexer(programText);
        Parser parser(lexer);
        Interpreter interpreter(parser);
        cout << "Result: " << interpreter.interpret() << endl;
    }
    catch (exception &e) {
        cerr << e.what() << endl;
    }
    catch (...) {
        cerr << "Unexpected error" << endl;
    }
    return 0;
}