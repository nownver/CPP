#include <string>

using namespace std;

string unstylize(string w){

    int last = w.length();
    if (w[0] == '*' && w[last-1] == '*'){
        w = w.substr(1,last-2);
    }
    return w;
}

string stylize(string w){

    int last = w.length();
    string new_string = "<strong>";

    if (w[0] == '*' && w[last-1] == '*'){
        for (int i = 1; i-1 < last; i++){
            new_string = new_string + w[i];
        }
        new_string = new_string + "<strong>";
        return new_string;
    }
    return w;
}