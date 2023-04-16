#include <iostream>
#include <fstream>
#include <utility>

using namespace std;

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
    vector<pair<vector<vector<bool> >, vector<vector<bool> > > > programStack; //first=conditions, second=instructions
    int position = 0;
    while (position < ::strlen(programText)) {
        vector<vector<bool> > read;
        vector<vector<bool> > write;
        bool valueAllowed = false;
        bool hasDivider = false;
        vector<bool> stack;
        while (programText[position] != '\n' && position < ::strlen(programText)) {
            switch (programText[position]) {
                case '[':
                    if (valueAllowed) {
                        cerr << "Syntax error " << endl;
                        return 1;
                    }
                    stack.clear();
                    valueAllowed = true;
                    break;
                case ']':
                    if (!valueAllowed) {
                        cerr << "Syntax error " << endl;
                        return 1;
                    }
                    valueAllowed = false;
                    if (hasDivider) write.push_back(stack);
                    else read.push_back(stack);
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
                    while (position < ::strlen(programText)) {
                        stack.push_back(programText[position] == '0');
                        if (programText[position + 1] == '0' || programText[position + 1] == '1') {
                            ++position;
                        } else {
                            break;
                        }
                    }
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
        for (const auto &statement: programStack) {
            //dynamically add stacks
            int count_of_stacks = int(max(statement.first.size(), statement.second.size()));
            while (stacks.size() < count_of_stacks) stacks.push_back(*new vector<bool>());
            //validate conditions
            for (int stack_index = 0; stack_index < statement.first.size(); stack_index++) {
                if(statement.first[stack_index].size() > stacks[stack_index].size()) goto next_statement;
                for(int stack_position = 0; stack_position < statement.first[stack_index].size(); stack_position++) {
                    if(statement.first[stack_index][stack_position] != stacks[stack_index][stacks[stack_index].size() -1 - stack_position]) {
                        goto next_statement;
                    }
                }
            }
            //remove conditions from stacks
            for (int stack_index = 0; stack_index < statement.first.size(); stack_index++) {
                if (stacks[stack_index].size() > statement.first[stack_index].size())
                    stacks[stack_index].erase(stacks[stack_index].begin() + int(stacks[stack_index].size() - statement.first[stack_index].size()),
                                              stacks[stack_index].end());
                else stacks[stack_index].erase(stacks[stack_index].begin(), stacks[stack_index].end());
            }
            //execute instructions
            for (int stack_index = 0; stack_index < statement.second.size(); stack_index++) {
                for (int stack_position = int(statement.second[stack_index].size()); stack_position > 0; stack_position--) {
                    stacks[stack_index].push_back(statement.second[stack_index][stack_position - 1]);
                    stackChanged = true;
                }
            }
            next_statement:;
        }
    }
    //print program output
    if (stacks.size() < 2) return 0;
    int size = int(stacks[1].size() - (stacks[1].size() % 8));
    for (int i = 0; i < size; i += 8) {
        std::bitset<8> byte;
        for (int j = 0; j < 8; j++) {
            byte[7-j] = (!stacks[1][i + j]);
        }
        cout << char(byte.to_ulong());
    }
    return 0;
}