#include "Interpreter.h"

double Interpreter::interpret() {


    currentStatement_->execute();


    switch (root->type) {
        case Token::Open:
            return leftValue;
        case Token::Close:
            return leftValue;
        default:
            return 0;
    }
}