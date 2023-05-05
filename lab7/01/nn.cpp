#include <vector>
// #include <algorithm>
#include <string>
#include <iostream>
using namespace std;


struct Row {
    double* ptr;
    size_t n;
};

Row create_ragged_arry(size_t* dims, size_t n_dims, double num){

    double* pp = new double[n_dims];
    for (size_t i = 0; i < n_dims; ++i) {
        double* p = new double[dims[i]];
    
    
        pp
    }

}


int main()
{
    double* pp = new double[5];
    for (size_t i = 0; i < 5; ++i) {
        pp[i] = 1.3;
    }

    Row* r = new Row[10];
}
