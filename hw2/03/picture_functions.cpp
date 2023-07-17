#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cmath>

using namespace std;

bool findCircleCenter(const string& svgFilename, double& cx, double& cy) {
    ifstream infile(svgFilename);
    string line;
    while (getline(infile, line)) {
        size_t cxPos = line.find("cx=");
        if (cxPos != string::npos) {
            cxPos += 4; 
            size_t endPos = line.find("\"", cxPos);
            cx = stod(line.substr(cxPos, endPos - cxPos));
            size_t cyPos = line.find("cy=", endPos);
            if (cyPos != string::npos) {
                cyPos += 4; 
                endPos = line.find("\"", cyPos);
                cy = stod(line.substr(cyPos, endPos - cyPos));
                return true;
            }
        }
    }
    return false;
}

void generateRandomPoints(int N, double cx, double cy, double r) {
    mt19937 rng(time(nullptr));
    uniform_real_distribution<double> dist(-r, r);

    for (int i = 0; i < N; i++) {
        double x, y;
        do {
            x = dist(rng);
            y = dist(rng);
        } while (x*x + y*y > r*r);
        x += cx;
        y += cy;
        cout << "Point " << i+1 << ": (" << x << ", " << y << ")\n";
    }
}
