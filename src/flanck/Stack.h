//
// Created by Lenni Protte on 15.04.23.
//

#ifndef FLANCK_STACK_H
#define FLANCK_STACK_H

#include <vector>
#include <string>

class Stack {
public:
    explicit Stack(const std::string &input) {
        push(input);
    }

    void push(const std::string &input);

    void pop(const int &depth);

    std::vector<char> read(int depth);

private:
    std::vector<bool> stack_;
};

void Stack::push(const std::string &input) {
    for (char c: input) stack_.push_back(c == '0');
}

void Stack::pop(const int &depth) {
    stack_.erase(stack_.end() - depth, stack_.end());
}

std::vector<char> Stack::read(int depth) {
    std::vector<char> result;
    result.reserve(depth);
    for (int i = 0; i < depth; i++) {
        result.push_back(stack_[stack_.size() - i] ? '0' : '1');
    }
    return result;
}

#endif //FLANCK_STACK_H