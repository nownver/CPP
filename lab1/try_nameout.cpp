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

    const string naming = "* Player 1: " + p1_name + " * " + "Player 2: " + p2_name + " *";
    const string spaces(naming.size(), ' ');

    const string first(spaces.size(), '*');

    cout << endl;
    // cout << "* " << "Player 1: " << p1_name;
    // cout << " * " << "Player 2: " << p2_name << " *" << endl;
    cout << first << endl;
    cout << naming << endl;
    cout << first << endl;
    return 0;

}