#include <iostream>
using namespace std;

int tri_pattern(int size){
    
    for (int i = 0; i < size; i++){
        for (int j = 0; j <= i; j++){
            cout << "*";
        }
        cout << "" << endl;
    }
}

int main(){
    cout << "Output size: ";
    int size;
    cin >> size;

    auto s = tri_pattern(size);
    // cout << s;

    return 0;
}