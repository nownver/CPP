#include <iostream>
#include <vector>
using namespace std;

struct Point{
    double first;
    double second;
};

template <typename C>
double** create_ragged_array(const C& c, double val) {
    std::size_t size = 0;
    for (auto n : c) {
        size += n;
    }

    double** out = new double*[size];
    double* data = new double[size];
    std::size_t i = 0;
    for (auto n : c) {
        out[i] = data;
        for (std::size_t j = 0; j < n; j++) {
            *data = val;
            data++;
        }
        i++;
    }

    return out;
}

int main() {
    std::size_t dims[] = {2, 5, 3};
    double** rg_arr = create_ragged_array(dims, 1.3);
    for (std::size_t i = 0; i < dims[0]; i++) {
        for (std::size_t j = 0; j < dims[1]; j++) {
            for (std::size_t k = 0; k < dims[2]; k++) {
                std::cout << rg_arr[i][j*dims[2] + k] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;

    std::size_t size = 0;
    for (std::size_t i = 0; i < dims[0]; i++) {
        size += dims[i] * dims[2];
        delete[] rg_arr[i];
    }
    delete[] rg_arr;
    rg_arr = nullptr;
}