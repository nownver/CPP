#include <vector>
// #include <algorithm>
#include <string>
#include <iostream>
using namespace std;

// 1.3
// vector<pair<double, double>> create_pairs(const vector<double>& arr){
//     vector<pair<double, double>> answer;
//     size_t size = arr.size();
//     if (size % 2 == 1){
//         size -= 1;
//     }

//     for(int i = 0; i < size; i+=2){
//         // answer.push_back(make_pair(arr[i], arr[i+1]));
//         answer.emplace_back(arr[i], arr[i + 1]);
//     }
//     return answer;
// }

// int main(){
//     vector<pair<double, double>> create_pairs(const vector<double>& arr);
//     vector<double> data{ 1.2, 2.3, 5, 2, 1.1, 3, 7};
//     auto pairs = create_pairs(data);

//     for (const auto& pair : pairs) {
//         cout << "{" << pair.first << ", " << pair.second << "}" << endl;
//     }
// }


// 1.4
#include <iostream>

struct Pair {
    double first;
    double second;
};

Pair* create_pairs(const double* arr, size_t size) {
    // double* answer = new double[size];
    Pair* new_p = new Pair[size / 2];

    size_t j = 0;
    for (size_t i = 0; i < size; i += 2) {
        new_p[j].first =  arr[i];
        // (answer)[i / 2] = arr[i];
        new_p[j].second =  arr[i+1];
        // (answer)[i / 2 + size / 2] = arr[i + 1];
        j++;
    }
    return new_p;
}

int main() {
    double arr[] = { 1.2, 2.3, 5, 2, 1.1, 3, 7};
    size_t size = sizeof(arr) / sizeof(double);
    
    
    Pair* result = create_pairs(arr, size);
    
    for (size_t i = 0; i < size / 2; i++) {
        cout << "{" << result[i].first << ", " << result[i].second << "}" << endl;
    }
    
    delete[] result;
    
    return 0;
}
