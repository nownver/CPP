#ifndef RAGGEDARRAY_H
#define RAGGEDARRAY_H

#include <vector>
#include <string>

using namespace std;

class RaggedArray {
public:
    RaggedArray(const vector<vector<int>>& d);
    string repr() const;
private:
    vector<vector<int>> data;
};

#endif // RAGGEDARRAY_H
