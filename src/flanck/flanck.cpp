#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>

using namespace std;

/**
 * Jedes Statement setzt sich aus seinen Conditions und seinem Instructions zusammen
 */
struct Statement {
    Statement(vector<vector<bool>> condition, vector<vector<bool>> instructions) {
        this->condition = std::move(condition);
        this->instructions = std::move(instructions);
    }

    vector<vector<bool> > condition;
    vector<vector<bool> > instructions;
};

/**
 * Führt das Statement aus, indem die Conditions geprüft werden und bei Richtigkeit die Instructions ausgeführt werden
 * @param statement eine referenz auf das aktuelle statement
 * @param stacks eine referenz aller stacks
 * @return true wenn sich etwas auf den stacks verändert hat
 */
bool executeStatement(const Statement &statement, vector<vector<bool>> &stacks) {
    for (int stack_index = 0; stack_index < statement.condition.size(); stack_index++) {
        if (stacks.size() < stack_index + 1) stacks.emplace_back();
        if (stacks[stack_index].empty() && !statement.condition.empty()) return false;
        for (int stack_position = int(statement.condition[stack_index].size()); stack_position > 0; stack_position--) {
            if (statement.condition[stack_index][stack_position] !=
                stacks[stack_index][stacks[stack_index].size() - stack_position - 1]) {
                return false;
            }
        }
    }
    bool hasChanged = false;
    //TODO: legt nicht die gesamte introduction auf den keller
    for (int stack_index = 0; stack_index < statement.instructions.size(); stack_index++) {
        if (stacks.size() < stack_index + 1) stacks.emplace_back();
        for (int stack_position = int(statement.instructions[stack_index].size()); stack_position > 0; stack_position--) {
            stacks[stack_index].push_back(statement.instructions[stack_index][stack_position]);
            hasChanged = true;
        }
    }
    return hasChanged;
}

/**
 *
 * @param argc darf nicht größer als zwei sein
 * @param argv die .flanck Datei und optional einen Input in der Form: 010|00|1111 (keller durch '|' getrennt)
 * @return 0 wenn es zu keinem Fehler gekommen ist
 */
int main(int argc, char *argv[]) {
    //if size of arguments is correct
    if (argc > 3) {
        cerr << "Unexpected arguments " << endl;
        return 1;
    }
    //if file exists
    ifstream is(argv[1]);
    if (!is) {
        cerr << "Could not open file " << argv[1] << endl;
        return 1;
    }
    //read file
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
    //initialize stacks
    vector<vector<bool> > stacks;
    if (argc == 3) {
        for (int i = 0; i < ::strlen(argv[2]); i++) {
            vector<bool> stack;
            while (argv[2][i] != '|' && i < ::strlen(argv[2])) {
                stack.push_back(argv[2][i] == '0');
                i++;
            }
            stacks.push_back(stack);
        }
    }
    //initialize program stack / lexing+parsing
    vector<Statement> programStack;
    int position = 0;
    while (position < ::strlen(programText)) {
        vector<vector<bool> > read;
        vector<vector<bool> > write;
        bool valueAllowed = false;
        bool hasDivider = false;
        while (programText[position] != '\n' && position < ::strlen(programText)) {
            switch (programText[position]) {
                case '[':
                    if (valueAllowed) {
                        cerr << "Syntax error " << endl;
                        return 1;
                    }
                    valueAllowed = true;
                    break;
                case ']':
                    if (!valueAllowed) {
                        cerr << "Syntax error " << endl;
                        return 1;
                    }
                    valueAllowed = false;
                    break;
                case ':':
                    if (valueAllowed) {
                        cerr << "Syntax error " << endl;
                        return 1;
                    }
                    valueAllowed = false;
                    hasDivider = true;
                    break;
                case '0':
                case '1':
                    if (!valueAllowed) {
                        cerr << "Syntax error " << endl;
                        return 1;
                    }
                    vector<bool> stack;
                    while (position < ::strlen(programText)) {
                        stack.push_back(programText[position] == '0');
                        if (programText[position + 1] == '0' || programText[position + 1] == '1') {
                            ++position;
                        } else {
                            break;
                        }
                    }
                    if (hasDivider) write.push_back(stack);
                    else read.push_back(stack);
                    break;
            }
            position++;
        }
        position++;
        programStack.emplace_back(read, write);
    }
    //executes program stack / interpret
    bool stackChanged = true;
    while (stackChanged) {
        stackChanged = false;
        for (const Statement &statement: programStack) {
            if (executeStatement(statement, stacks)) {
                stackChanged = true;
            }
        }
    }
    //print program output
    if (stacks.size() < 2) return 0;
    string binaryOutput;
    for (bool &&e: stacks[1]) {
        binaryOutput.push_back(e ? '0' : '1');
    }
    stringstream sstream(binaryOutput);
    string asciiOutput;
    while (sstream.good()) {
        bitset<8> bits;
        sstream >> bits;
        char ch = char(bits.to_ulong());
        asciiOutput += ch;
    }
    cout << asciiOutput << endl;
    return 0;
}