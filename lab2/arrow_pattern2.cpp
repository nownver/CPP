#include <iostream>
using namespace std;

int arrow_pattern2(int size){

    for (int i = 0; i < size; i++){
        string space(size-i, ' ');
        cout << space;
        for (int j = 0; j <= i; j++){
            cout << "*";
        }
        cout << "" << endl;
    }
    // int j =5;
    for (int i = 0; i < size; i++){
        string space_2(i+2, ' ');
        cout << space_2;
        for (int j = size-1; j > i; j--){
            cout << "*";
        }
        cout << "" << endl;
    }
}

int main(){
    cout << "Output size: ";
    int size;
    cin >> size;

    auto s = arrow_pattern2(size);
}