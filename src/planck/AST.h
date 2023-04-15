#ifndef PLANCK_AST_H
#define PLANCK_AST_H

#include <string>
#include "Token.h"

using namespace std;

enum class AstNodeType {
    Invalid,
    NumberLiteral,
    BinaryOperation,
    Identifier
};

struct AstNode {
    AstNodeType type;

    // NumberLiteral node
    double value;

    // BinaryOperation node
    AstNode* left;
    AstNode* right;
    Token op;

    // Identifier node
    string identifier;

    AstNode() : type(AstNodeType::Invalid), value(0), left(nullptr), right(nullptr), op(Token::Invalid) {}
};
#endif //PLANCK_AST_H
