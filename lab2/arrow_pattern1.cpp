#include <iostream>
using namespace std;

int arrow_pattern1(int size){

    for (int i = 0; i < size; i++){
        for (int j = 0; j <= i; j++){
            cout << "*";
        }
        cout << "" << endl;
    }

    for (int i = 0; i < size; i++){
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

    auto s = arrow_pattern1(size);

}