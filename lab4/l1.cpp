// bool is_prime(int n)
// {
//     if (n <= 1) {
//         return false;
//     }

//     else if (n <= 3) {
//         return true;
//     }

//     else if (n % 2 == 0 || n % 3 == 0){
//        return false;
//     }

//     // check through all numbers of the form i = 6k - 1 and i = 6k + 1
//     for (int i = 5; i * i < n; i += 6) {
//         if (n % i == 0 || n % (i + 2) == 0){
//             return false; // n is divisible by i or i + 2
//         }
//     }
    
//     return true; // no divisor within [5, n) found
// }

// #include <iostream>

// int main()
// {
//     using std::cout;
//     using std::cin;
//     using std::endl;

//     cout << "Enter the upper limit: ";
//     int n;
//     cin >> n;

//     for (int i = 2; i <= n; i += 1) {
//         if (is_prime(i)){
//         cout << i << endl;
//         }
//     }

//     return 0;
// }
//-----------------------------

//1.2
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <class T>
T median(vector<T> vec)
{

    sort(vec.begin(), vec.end());
    const int size = vec.size();
    const int mid = size / 2;
    const auto mid_even = size % 2 == 0? (vec[mid] + vec[mid - 1]) / 2: vec[mid];
    return mid_even;
    // if (size % 2 == 0){
    //     return mid_even;
    // }
    // else {
    //     return vec[mid];
    // }
}

int main(){

    vector<int> vec{2,10,6,8};
    cout << median(vec);
}