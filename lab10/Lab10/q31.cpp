#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> createRaggedArray(string input) {
    vector<vector<int>> raggedArray;
    vector<int> row;
    string buffer;

    for (char c : input) {
        if (c == '[') {
            continue;
        } else if (isdigit(c)) {
            buffer += c;
        } else if (c == ',' || c == ';') {
            if (!buffer.empty()) {
                row.push_back(stoi(buffer));
                buffer.clear();
            }
            if (c == ';') {
                raggedArray.push_back(row);
                row.clear();
            }
        } else if (c == ']') {
            if (!buffer.empty()) {
                row.push_back(stoi(buffer));
                buffer.clear();
            }
            if (!row.empty()) {
                raggedArray.push_back(row);
            }
        }
    }

    return raggedArray;
}

int main() {
    string input = "[1, 2, 3; 4, 5; 6, 7, 8, 9]";
    vector<vector<int>> raggedArray = createRaggedArray(input);

    for (auto row : raggedArray) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
