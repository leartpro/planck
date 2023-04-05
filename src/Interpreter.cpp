#include "Interpreter.h"

double Interpreter::interpret(AstNode *root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->type == AstNodeType::NumberLiteral) {
        return root->value;
    } else if (root->type == AstNodeType::Identifier) {
        return variables_[root->identifier];
    }

    double leftValue = interpret(root->left);
    double rightValue = interpret(root->right);

    switch (root->op) {
        case Token::Plus:
            return leftValue + rightValue;
        case Token::Minus:
            return leftValue - rightValue;
        case Token::Multiply:
            return leftValue * rightValue;
        case Token::Divide:
            return leftValue / rightValue;
        default:
            return 0;
    }
}

void Interpreter::setVariable(const std::string &name, double value) {
    variables_[name] = value;
}