/*
    Expression:
        Array

    Array:
        "[" Rows "]"
    Rows:
        Row
        Row ";" Rows
    Row:
        "[" Elements "]"
    Elements:
        Element
        Element "," Elements
    Element:
        Number

    Number:
        Digit
        Digit Number
    Digit:
        "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
*/



#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Array {
public:
    Array(const vector<vector<int>>& rows) : rows(rows) {}

    friend ostream& operator<<(ostream& os, const Array& arr) {
        os << "Array(";
        for (size_t i = 0; i < arr.rows.size(); i++) {
            if (i > 0) {
                os << ", ";
            }
            os << "[";
            for (size_t j = 0; j < arr.rows[i].size(); j++) {
                if (j > 0) {
                    os << ", ";
                }
                os << arr.rows[i][j];
            }
            os << "]";
        }
        os << ")";
        return os;
    }

private:
    vector<vector<int>> rows;
};

Array parse_ragged_array(const string& text) {
    vector<vector<int>> rows;
    istringstream iss(text);
    string row_str;
    while (getline(iss, row_str, ';')) {
        // Remove the square brackets from the row string
        row_str.erase(remove(row_str.begin(), row_str.end(), '['), row_str.end());
        row_str.erase(remove(row_str.begin(), row_str.end(), ']'), row_str.end());

        vector<int> row;
        istringstream row_iss(row_str);
        string elem_str;
        while (getline(row_iss, elem_str, ',')) {
            int elem = stoi(elem_str);
            row.push_back(elem);
        }
        rows.push_back(row);
    }
    return Array(rows);
}


int main() {
    string text = "[1, 2, 3; 4, 5; 6, 7, 8, 9]";
    Array arr = parse_ragged_array(text);
    cout << arr << endl;
    return 0;
}
