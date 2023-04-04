#ifndef PLANCK_AST_H
#define PLANCK_AST_H

#include <string>
#include "Token.h"

enum class AstNodeType {
    Invalid,
    NumberLiteral,
    BinaryOperation,
    Identifier // new node type for identifiers
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
    std::string identifier; // new field for identifier nodes

    AstNode() : type(AstNodeType::Invalid), value(0), left(nullptr), right(nullptr), op(Token::Invalid) {}
};
#endif //PLANCK_AST_H
