#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<int>> parseRaggedArray(string input) {
    vector<vector<int>> raggedArray;
    stringstream ss(input);
    string rowString;
    while (getline(ss, rowString, ';')) {
        vector<int> row;
        stringstream rowSS(rowString);
        string elementString;
        while (getline(rowSS >> ws, elementString, ',')) {
            string digits;
            for (char c : elementString) {
                if (isdigit(c) || c == '-') {
                    digits += c;
                }
            }
            try {
                row.push_back(stoi(digits));
            } catch (const invalid_argument& e) {
                cerr << "Error: " << elementString << " is not a valid integer." << endl;

            }
        }
        raggedArray.push_back(row);
    }
    return raggedArray;
}

string raggedArrayToString(const vector<vector<int>>& raggedArray) {
    string result = "Array(";
    for (int i = 0; i < raggedArray.size(); i++) {
        result += "[";
        for (int j = 0; j < raggedArray[i].size(); j++) {
            result += to_string(raggedArray[i][j]);
            if (j < raggedArray[i].size() - 1) {
                result += ", ";
            }
        }
        result += "]";
        if (i < raggedArray.size() - 1) {
            result += ", ";
        }
    }
    result += ")";
    return result;
}

int main() {
    string input = "[1, 2, 3; 4, 5; 6, 7, 8, 9]";
    vector<vector<int>> raggedArray = parseRaggedArray(input);
    string output = raggedArrayToString(raggedArray);
    cout << output << endl;
    return 0;
}