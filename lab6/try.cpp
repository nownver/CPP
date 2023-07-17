#include <iostream>
#include <cmath>

class Nd_vec {
public:
    // Constructor that takes the number of dimensions and initializes all elements to zero
    Nd_vec(int n) : size(n), data(new double[n]) {
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    // Constructor that takes the number of dimensions and an array of values
    Nd_vec(int n, double* values) : size(n), data(new double[n]) {
        for (int i = 0; i < size; i++) {
            data[i] = values[i];
        }
    }

    // Copy constructor
    Nd_vec(const Nd_vec& other) : size(other.size), data(new double[other.size]) {
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Destructor
    ~Nd_vec() {
        delete[] data;
    }

    // Assignment operator
    Nd_vec& operator=(const Nd_vec& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new double[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Indexing operator
    double& operator[](int i) {
        return data[i];
    }

    // Addition operator
    Nd_vec operator+(const Nd_vec& other) const {
        Nd_vec result(size);
        for (int i = 0; i < size; i++) {
            result[i] = data[i] + other.data[i];
        }
        return result;
    }

    // Subtraction operator
    Nd_vec operator-(const Nd_vec& other) const {
        Nd_vec result(size);
        for (int i = 0; i < size; i++) {
            result[i] = data[i] - other.data[i];
        }
        return result;
    }

    // Dot product
    double dot(const Nd_vec& other) const {
        double result = 0;
        for (int i = 0; i < size; i++) {
            result += data[i] * other.data[i];
        }
        return result;
    }

    // Magnitude of vector
    double mag() const {
        double result = 0;
        for (int i = 0; i < size; i++) {
            result += data[i] * data[i];
        }
        return sqrt(result);
    }

    // Print function
    void print() const {
        std::cout << "[";
        for (int i = 0; i < size; i++) {
            std::cout << data[i];
            if (i < size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

private:
    int size;
    double* data;
};

int main() {
    // Create a 3D vector with all elements initialized to 0
    Nd_vec v1(3);
    v1.print();  // Output: [0, 0, 0]

    // Create a 3D vector with the given values
    double values[3] = {1, 2, 3};
    Nd_vec v2(3, values);
    v2.print();  // Output: [1, 2, 3]

// Create a copy of v2
Nd_vec v3 = v2;
v3.print();  // Output: [1, 2, 3]

// Modify an element of v3
v3[1] = 4;
v3.print();  // Output: [1, 4, 3]

// Add v2 and v3
Nd_vec v4 = v2 + v3;
v4.print();  // Output: [2, 6, 6]

// Subtract v2 from v3
Nd_vec v5 = v3 - v2;
v5.print();  // Output: [0, 2, 0]

// Compute the dot product of v2 and v3
double dot_product = v2.dot(v3);
std::cout << "Dot product: " << dot_product << std::endl;  // Output: Dot product: 14

// Compute the magnitude of v3
double mag = v3.mag();
std::cout << "Magnitude: " << mag << std::endl;  // Output: Magnitude: 4.24264

return 0;
}
