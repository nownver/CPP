#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string input;
    cout << "Enter a sentence: ";
    getline(cin, input);

    vector<string> wordsWithQuotes, wordsWithoutQuotes;

    string word = "";
    bool inQuotes = false;
    for (char c : input) {
        if (c == ' ') {
            if (inQuotes) {
                word += c;
            }
            else {
                if (!word.empty()) {
                    wordsWithoutQuotes.push_back(word);
                    word = "";
                }
            }
        }
        else if (c == '*') {
            inQuotes = !inQuotes;
            if (inQuotes) {
                wordsWithQuotes.push_back("");
            }
            else {
                wordsWithQuotes.back() = word;
                word = "";
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        wordsWithoutQuotes.push_back(word);
    }

    cout << "Pairs of words:\n";
    for (string wq : wordsWithQuotes) {
        if (!wq.empty()) {
            for (string woq : wordsWithoutQuotes) {
                cout << "(*" << wq << "*" << ", " << woq << ")\n";
            }
        }
    }
    return 0;
}
