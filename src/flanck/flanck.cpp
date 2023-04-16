#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>

using namespace std;

struct Statement {
    Statement(vector<vector<bool>> condition, vector<vector<bool>> output) {
        this->condition = std::move(condition);
        this->output = std::move(output);
    }

    vector<vector<bool> > condition;
    vector<vector<bool> > output;
};

void executeStatement(const Statement &statement, vector<vector<bool>> &stacks) {
    for (int stack_index = 0; stack_index < statement.condition.size(); stack_index++) {
        for (int stack_position = 0; stack_position < statement.condition[stack_index].size(); stack_position++) {
            //TODO: EXC_BAD_ACCESS (code=1, address=0x8)
            // this = {const std::vector<bool> *} NULL

            /*
             * This error happens because stacks does not contain anything
             */
            if (statement.condition[stack_index][stack_position] !=
                stacks[stack_index][stacks[stack_index].size() - stack_position]) {
                return;
            }
        }
    }
    for (int stack_index = 0; stack_index < statement.output.size(); stack_index++) {
        stacks[stack_index].insert(stacks[stack_index].end(),
                                   statement.output[stack_index].begin(),
                                   statement.output[stack_index].end()
        );
    }
}

int main(int argc, char *argv[]) {

    if (argc > 2) {
        cerr << "Unexpected arguments " << endl;
        return 1;
    }
    ifstream is(argv[1]);
    if (!is) {
        cerr << "Could not open file " << argv[1] << endl;
        return 1;
    }

    is.seekg(0, ifstream::end);
    size_t fileSize = is.tellg();
    is.seekg(0, ifstream::beg);
    char programText[fileSize + 1];
    size_t index = 0;
    char c;
    while (is.get(c)) {
        programText[index++] = c;
    }
    programText[index] = '\0';

    //TODO: remove debug println
    cout << programText << endl << static_cast <const void *> (programText) << endl;

    try {
        vector<Statement> programStack;
        vector<vector<bool> > stacks;
        int position = 0;
        while (position < ::strlen(programText)) {
            vector<vector<bool> > read;
            bool valueAllowed = false;
            while (programText[position] != ':' && position < ::strlen(programText)) {
                switch (programText[position]) {
                    case '[':
                        valueAllowed = true;
                        break;
                    case ']':
                        valueAllowed = false;
                        break;
                    case '0':
                    case '1':
                        if (!valueAllowed) {
                            cerr << "Syntax error " << endl;
                            return -1;
                        }
                        vector<bool> stack;
                        while (position < ::strlen(programText)  &&
                               (programText[position] == '0' || programText[position] == '1')) {
                            stack.push_back(programText[position] == '0');
                            ++position;
                        }
                        read.push_back(stack);
                        valueAllowed = false;
                        break;
                }
                position++;
            }
            position++;
            vector<vector<bool> > write;
            while (programText[position] != '\n' && position < ::strlen(programText)) {
                switch (programText[position]) {
                    case '[':
                        valueAllowed = true;
                        break;
                    case ']':
                        valueAllowed = false;
                        break;
                    case '0':
                    case '1':
                        if (!valueAllowed) {
                            cerr << "Syntax error " << endl;
                            return 1;
                        }
                        vector<bool> stack;
                        while (position < ::strlen(programText) &&
                               (programText[position] == '0' || programText[position] == '1')) {
                            stack.push_back(programText[position] == '0');
                            ++position;
                        }
                        write.push_back(stack);
                        valueAllowed = false;
                        break;
                }
                position++;
            }
            programStack.emplace_back(read, write);
            position++;
        }
        //works until here (debugging shows noting suspicious)
        //TODO: execute until nothing in 'stacks' changes
        for (const Statement &statement: programStack) {
            executeStatement(statement, stacks);
        }
        string binaryOutput;
        for (auto &&e: stacks[1]) binaryOutput.push_back(e ? '0' : '1');
        stringstream sstream(binaryOutput);
        string asciiOutput;
        while (sstream.good()) {
            bitset<8> bits;
            sstream >> bits;
            char ch = char(bits.to_ulong());
            asciiOutput += ch;
        }
        cout << asciiOutput << endl;
    }
    catch (exception &e) {
        cerr << e.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "Unexpected error" << endl;
        return 1;
    }
    return 0;
}