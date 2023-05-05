#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, double> registers;

int main() {
    string cmd;
    while (true) {
        cout << "cmd> ";
        getline(cin, cmd);

        if (cmd.find("set") == 0) {
            size_t space_pos = cmd.find(' ', 4);
            string reg_name = cmd.substr(4, space_pos - 4);
            double reg_value = stod(cmd.substr(space_pos + 1));

            registers[reg_name] = reg_value;
        }
        else if (cmd.find("get") == 0) {
            string reg_name = cmd.substr(4);

            if (registers.count(reg_name) == 0) {
                cout << reg_name << ": <N/A>" << endl;
            }
            else {
                double reg_value = registers[reg_name];
                cout << reg_name << ": " << reg_value << endl;
            }
        }
        else if (cmd.find("add") == 0) {
            string reg_name1 = cmd.substr(4, cmd.find(" ", 4) - 4);
            string reg_name2 = cmd.substr(cmd.find(" ", 4) + 1);

            if (registers.count(reg_name1) == 0) {
                cout << reg_name1 << ": <N/A>" << endl;
            }
            else if (registers.count(reg_name2) == 0) {
                cout << reg_name2 << ": <N/A>" << endl;
            }
            else {
                double reg_value1 = registers[reg_name1];
                double reg_value2 = registers[reg_name2];
                double result = reg_value1 + reg_value2;

                cout << reg_name1 << " + " << reg_name2 << ": " << result << endl;
            }
        }
        else if (cmd.find("sub") == 0) {
            string reg_name1 = cmd.substr(4, cmd.find(" ", 4) - 4);
            string reg_name2 = cmd.substr(cmd.find(" ", 4) + 1);

            if (registers.count(reg_name1) == 0) {
                cout << reg_name1 << ": <N/A>" << endl;
            }
            else if (registers.count(reg_name2) == 0) {
                cout << reg_name2 << ": <N/A>" << endl;
            }
            else {
                double reg_value1 = registers[reg_name1];
                double reg_value2 = registers[reg_name2];
                double result = reg_value1 - reg_value2;

                cout << reg_name1 << " - " << reg_name2 << " = " << result << endl;
            }
        }
        else {
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}
