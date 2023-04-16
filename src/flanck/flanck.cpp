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

//TODO: does not work for helloWorld.flanck but for helloWorldLoop.flanck
/**
 * Führt das Statement aus, indem die Conditions geprüft werden und bei Richtigkeit die Instructions ausgeführt werden
 * @param statement
 * @param stacks
 */
void executeStatement(const Statement &statement, vector<vector<bool>> &stacks) {
    for (int stack_index = 0; stack_index < statement.condition.size(); stack_index++) {
        if (stacks.empty()) stacks.emplace_back();
        for (int stack_position = 0; stack_position < statement.condition[stack_index].size(); stack_position++) {
            if (stacks[stack_index].empty()) stacks[stack_index].push_back({});
            if (statement.condition[stack_index][stack_position] !=
                stacks[stack_index][stacks[stack_index].size() - stack_position]) {
                return;
            }
        }
    }
    for (int stack_index = 0; stack_index < statement.instructions.size(); stack_index++) {
        if (stacks.empty()) stacks.emplace_back();
        stacks[stack_index].insert(stacks[stack_index].end(),
                                   statement.instructions[stack_index].begin(),
                                   statement.instructions[stack_index].end()
        );
    }
}

/**
 *
 * @param argc darf nicht größer als zwei sein
 * @param argv die .flanck Datei und optional einen Input in der Form: 010|00|1111 (keller durch '|' getrennt)
 * @return 0 wenn es zu keinem Fehler gekommen ist
 */
int main(int argc, char *argv[]) {
    cout << argv[0] << endl;
    cout << argv[1] << endl;
    cout << argv[2] << endl;

    if (argc > 3) {
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
    vector<vector<bool> > stacks;
    for (int i = 0; i < ::strlen(argv[2]); i++) {
        vector<bool> stack;
        while (argv[2][i] != '|' && i < ::strlen(argv[2])) {
            stack.push_back(argv[2][i] == '0');
            i++;
        }
        stacks.push_back(stack);
    }
    try {
        vector<Statement> programStack;
        int position = 0;
        //TODO: The two inner while loops can be combined
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
                        while (position < ::strlen(programText) &&
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
        } //works until here (debugging shows noting suspicious)
        //TODO: execute until nothing in 'stacks' changes
        for (const Statement &statement: programStack) {
            executeStatement(statement, stacks);
        }
        if (stacks.empty() || stacks[1].empty()) return 0;
        string binaryOutput;
        for (std::__bit_iterator<std::vector<bool>, false, 0>::reference &&e : stacks[1]) {
            cout << e << endl;
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