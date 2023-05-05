#include <vector>
#include <list>
#include <iostream>
using namespace std;

// template <class T>
// T remove_negative(T &vec){

//     vector<double> newvec;
//     for (const auto i: vec){
//         newvec.push_back(i);
//     }

//     // T it = remove_if(newvec.begin(), newvec.end(),  [](const int i) {return i < 0; });
//     // newvec.erase(it, newvec.end());
//     for (auto iter = newvec.begin(); iter != newvec.end();){
//         if (*iter < 0){
//             iter = newvec.erase(iter);
//         }
//         else{
//             ++iter;
//         }
//     }
//     T newveclist(newvec.begin(), newvec.end());

//     return newveclist;
// }

// int main() {

// vector<double> vec1{0.8, -5.1, 1.6, -6.5, 10.5};
// auto vec2 = remove_negative(vec1);

// for (const auto& i: vec1){
//         cout << i << " ";
// }

// cout << endl;

// for (const auto& i: vec2){
//         cout << i << " ";
// }

// cout << endl;

// list<double> li1(vec1.rbegin(), vec1.rend());
// auto li2 = remove_negative(li1);

// for (const auto& j: li1){
//         cout << j << " ";
// }

// cout << endl;

// for (const auto& j: li2){
//         cout << j << " ";
// }

// }
//--------------------
//2.2
// template <class T>
// bool all_zeroes(T vec){
    
//     vector<int> newvec;
//     for (const auto &i: vec){
//         newvec.push_back(i);
//     }

//     for (const auto &j: newvec){
//         if (j == 0){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
//     return true;
// }

// int main(){
//     vector<int> vec1{1, 0, 2, 3};
//     vector<int> vec2(10);

//     bool z1 = all_zeroes(vec1);
//     bool z2 = all_zeroes(vec2);

//     cout << z1 << endl;
//     cout << z2 << endl;

//     list<int> li1(vec1.rbegin(), vec1.rend());
//     list<int> li2(10);

//     bool zz1 = all_zeroes(li1);
//     bool zz2 = all_zeroes(li2);

//     cout << zz1 << endl;
//     cout << zz2 << endl;
// }
//------------------------------
//2.3
// template <class T>
// T str_join(T str){

//     vector<string> vec;
//     for (const auto &i:str){
//         vec.push_back(i);
//     }

//     string a = "";
//     for (const auto &j:vec){
//         if (j == vec.begin()){
//             a + '"';
//         }
//         if (j == vec.end()){
//             cout << j << '"';
//         }
//         cout << j << ",";
//     }

//     return 

    // const first = '"' + vec.begin() + ',';
    // const last = vec.end() + '"';

    // vec.erase(vec.begin())
    // vec.erase(vec.end() - 1);

    // vector<string> newvec;
    // newvec.push_back(first);

    // for (const auto &j:vec){
    //     newvec.push_back(j);
    // }
    // newvec.push_back(last);

    // T finalvec(newvec.begin(), newvec.end());

    // return finalvec;

// }

template <class T>
string str_join(string sep, T begin, T end)
{
    string str;
    for (auto it = begin; it != end; it++) {
        str += *it;
        if (std::next(it) != end) {
            str += sep;
        }
    }
    return str;
}

int main() {
    auto words = vector<string>{"C", "Rust", "C++", "Python"};
    auto str1 = str_join((", "), words.begin(), words.end());
    cout << str1 << endl;

    auto words2 = list<string>(words.rbegin(), words.rend());
    auto str2 = str_join((", "), words2.begin(), words2.end());
    cout << str2 << endl;
}
