//
// Created by Lenni Protte on 15.04.23.
//

#ifndef FLANCK_STATEMENT_H
#define FLANCK_STATEMENT_H

#include <vector>
#include "Token.h"

class Statement
{
public:
    explicit Statement(std::vector<> Token* tokens) : tokens_(const_cast<Token *>(tokens)){}
    std::vector<bool> execute();
private:
    Token* tokens_;
};

std::vector<bool> Statement::execute() {

    return {};
}

#endif //FLANCK_STATEMENT_H
