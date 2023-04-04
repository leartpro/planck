#include <iostream>
#include <fstream>

#include "lexer/lexer.h"

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


    lexer::Lexer lexer(programText);

    try {
        // Try to parse as program
    }
    catch (exception &e) {
        cerr << e.what() << endl;
    }
    catch (...) {
        cerr << "Unexpected error" << endl;
    }
    return 0;
}