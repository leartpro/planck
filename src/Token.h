#ifndef PLANCK_TOKEN_H
#define PLANCK_TOKEN_H
enum class Token {
    Invalid,
    Eof,
    Plus,
    Minus,
    Multiply,
    Divide,
    Number,
    Identifier // new token for identifiers
};
#endif //PLANCK_TOKEN_H
