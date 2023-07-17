#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
    cout << "please enter Warrior name:" ;
    string p1_name;
    cin >> p1_name;

    cout << "please enter Mage name:" ;
    string p2_name;
    cin >> p2_name;

    cout << "please enter Ninja name:" ;
    string p3_name;
    cin >> p3_name;

    cout << "please enter Fighter name:" ;
    string p4_name;
    cin >> p4_name;

    const int square_1(max(p1_name.size(), p2_name.size()));
    const int square_2(max(p3_name.size(), p4_name.size()));
    const int square(max(square_1, square_2));

    int num_1 = square * 2 + 25;
    int num_2 = square + 11;
    string star(num_1, '*');
    string space(num_2, ' ');
    
    cout << star << endl;
    cout << "*" << space << "*" << space << "*" << endl;
    cout << left << setw(11) << "* Warrior: " << setw(square) << p1_name << setw(12) << " * Mage: " << setw(square) << p2_name << " *" << endl;
    cout << "*" << space << "*" << space << "*" << endl;
    cout << star << endl;
    cout << "*" << space << "*" << space << "*" << endl;
    cout << left << setw(11) << "* Ninja: " << setw(square) << p3_name << setw(11) << " * Fighter: " << setw(square) << p4_name << " *" << endl;
    cout << "*" << space << "*" << space << "*" << endl;
    cout << star << endl;

    return 0;
}
