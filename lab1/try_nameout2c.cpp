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

    if (p1_name.size() < p2_name.size()){
        string blank(p2_name.size() - p1_name.size(), ' ');
        p1_name = p1_name + blank;
    }
    else{
        string blank(p1_name.size() - p2_name.size(), ' ');
        p2_name = p2_name + blank;
    }

    const string naming_1 = "| Player 1: " + p1_name + " |";
    const string naming_2 = "| Player 2: " + p2_name + " |";
    const string spaces(max(naming_1.size(), naming_2.size()) - 2, ' ');

    const string second = "|" + spaces + "|";
    string first(max(naming_1.size(), naming_2.size())-2, '=');
    string prethird(max(naming_1.size(), naming_2.size())-2, '-');

    first = "+" + first + "+";

    string third = "+" + prethird + "+";
    cout << endl;
    // cout << "* " << "Player 1: " << p1_name;
    // cout << " * " << "Player 2: " << p2_name << " *" << endl;


    cout << first << endl;
    cout << second << endl;
    cout << naming_1 << endl;
    cout << second << endl;
    cout << third << endl;
    cout << second << endl;
    cout << naming_2 << endl;
    cout << second << endl;
    cout << first << endl;
    
    return 0;

}