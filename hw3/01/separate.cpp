#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
//1.1
vector<int> interleave_sequences(const vector<int>& seq1, const vector<int>& seq2) {
    vector<int> result;
    auto it1 = seq1.begin();
    auto it2 = seq2.begin();

    while (it1 != seq1.end() && it2 != seq2.end()) {
        result.push_back(*it1++);
        result.push_back(*it2++);
    }

    if (it1 != seq1.end()) {
        result.insert(result.end(), it1, seq1.end());
    } else if (it2 != seq2.end()) {
        result.insert(result.end(), it2, seq2.end());
    }

    return result;
}
//1.2
int calculate_sum_of_products(const vector<int>& seq1, const vector<int>& seq2) {
    int n = seq1.size();
    int m = seq2.size();

    int sum = 0;
    for (int i = 0; i < n && i < m; i++) {
        sum += seq1[i] * seq2[i];
    }

    return sum;
}
//1.3
vector<pair<int, int>> cartesian_product(const vector<int>& v1, const vector<int>& v2) {
    vector<pair<int, int>> result;
    for (const auto& elem1 : v1) {
        for (const auto& elem2 : v2) {
            result.emplace_back(elem1, elem2);
        }
    }
    return result;
}

int main() {
    ifstream input_file("data1.txt");
    if (!input_file) {
        cerr << "Failed to open input file" << endl;
        return 1;
    }

    vector<int> seq1, seq2;
    string line;
    getline(input_file, line, ';');
    istringstream iss1(line);
    int num;
    while (iss1 >> num) {
        seq1.push_back(num);
    }

    getline(input_file, line);
    istringstream iss2(line);
    while (iss2 >> num) {
        seq2.push_back(num);
    }
//1.1
    vector<int> result = interleave_sequences(seq1, seq2);

    for (const auto& n : result) {
        cout << n << ' ';
    }
    cout << endl << endl;
//1.2
    int sum = calculate_sum_of_products(seq1, seq2);

    if (sum != -1) {
        cout << "(" << seq1[0] << " * " << seq2[0] << ")";
        for (size_t i = 1; i < seq1.size(); i++) {
            if (seq1[i] != 0 && seq2[i] != 0 && i < 4){
                cout << " + (" << seq1[i] << " * " << seq2[i] << ")";
            }
        }
        cout << " = " << sum << endl << endl;
    }
//1.3
auto pairs = cartesian_product(seq1, seq2);

int i = 0;
for (const auto& [x, y] : pairs) {
    cout << '(' << x << ", " << y << ')';
    if (i != pairs.size() - 1) {
        cout << ", ";
    }
    i++;
}
cout << endl;
    return 0;
}
