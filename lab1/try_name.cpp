#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << "please enter P1 name:" ;
    string p1_name;
    cin >> p1_name;

    cout << "please enter P2 name:" ;
    string p2_name;
    cin >> p2_name;

    cout << "Player 1: " << p1_name << std::endl;
    cout << "Player 2: " << p2_name << std::endl;
    return 0;

}