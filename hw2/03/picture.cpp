#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cmath>

#include "picture_functions.hpp"

using namespace std;

int main() {
    double cx, cy;
    if (!findCircleCenter("image.svg", cx, cy)) {
        cerr << "Error: could not find circle center in SVG file.\n";
        return 1;
    }

    int N;
    cout << "Enter number of points to generate: ";
    cin >> N;

    generateRandomPoints(N, cx, cy, 1.0);
    return 0;
}