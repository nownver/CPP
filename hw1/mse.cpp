#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

int main(){
    int N;
    cout << "Enter N: ";
    cin >> N;

    double sum = 0.0;
    srand(time(0));

    for (int i = 0; i < N; i++) {
        double r = (float)(rand()) / (float)(RAND_MAX);
        sum = sum + (0.5 - r) * (0.5 - r);
        // cout << fixed << setprecision(2) << (float)(rand()) / (float)(RAND_MAX) << endl;
    }
    sum = sum / N;
    cout << sum;
}