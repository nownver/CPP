#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
// #include <initializer_list>
using namespace std;

#include "style_functions.hpp"

int main(){
    // auto words = {"C", "**", "*C++*", "*Java", "*Python*", "Rust*"};

    vector<string> words;
    string x ;
    while (cin >> x){
        words.push_back(x);

    }

    cout << "<table>\n";
    for (const auto& w: words){
        cout << "<tr>\n";
        //cout << left << setw(15) << w << setw(15) << unstylize(w) << setw(15) << stylize(w) << endl;
        cout << "<td>" << w << "</td>\n";
        cout << "<td>" << unstylize(w) << "</td>\n";
        cout << "<td>" << stylize(w) << "</td>\n";
        cout << "</tr>\n";
    }
    cout << "</table>\n";

    // for (const auto& w: words){
    //     cout << stylize(w);
    // }

}
