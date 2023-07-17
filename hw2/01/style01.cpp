#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string unstylize(string w){
    int last = w.length();
    if (last < 2){
        return w;
    }
    if (w[0] == '*' && w[last-1] == '*'){
        w = w.substr(1,last-2);
    }
    return w;
}

void printWord(vector<string> vec){
    for (const auto& v: vec){
        cout << v << ' ';
    }
    cout << endl;
}

vector<string> reverse(vector<string> vec){
    reverse(vec.begin(), vec.end());

    return vec;
}

vector<string> sort_alphabet(vector<string> vec){
    sort(vec.begin(), vec.end());
    return vec;
}

int main(){
    vector<string> words;
    string x ;
    while (cin >> x){
    words.push_back(x);
    }

    for (auto& w: words){
        w = unstylize(w);
    }

    vector<string> reversed_words = reverse(words);
    vector<string> sorted_words = sort_alphabet(reversed_words);

    printWord(words);
    printWord(reversed_words);
    printWord(sorted_words);
    return 0;
}