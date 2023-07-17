#include <iostream>
#include <vector>
#include <list>

using namespace std;

void lshift(vector<double>& vec, int n){
    for (int i = 0; i < n; i++){
            vec.erase(vec.begin());
    }
    // vec.erase(vec.begin(), vec.begin() + n);
}

void rshift(vector<double>& vec, int n){
    for (int i = 0; i < n; i++){
            vec.insert(vec.begin(), 0);
    }
    // vec.insert(vec.begin(), n, 0);
}

vector<double> scale(vector<double>& vec, double n){
    int size = vec.size();
    for (int i = 0; i < size; i++){
            vec[i] = vec[i] * n;
            // *it = *it * n;
    }
    return vec;
}

// vector<double>::size_type
/*
    for (vector<double>::size_type i = 0; i != vec.size(); ++i) {
        cout << vec[i];
    }

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it;
    }
*/

vector<double> add(vector<double>& v1, vector<double>& v2){

    if( v1.size() < v2.size()){
        for (int i = 0; i < v2.size() - v1.size(); i++){
            v1.push_back(0);
        }
    }
    else if ( v1.size() > v2.size()){
        for (int i = 0; i < v1.size() - v2.size(); i++){
            v2.push_back(0);
        }
    }

    vector<double> vec;
    for (int i = 0; i < v1.size(); i++){
            vec.push_back(v1[i] + v2[i]);
            
    }
    return vec;
}

vector<double>& remove_negative(vector<double>& vec){
    int size = vec.size();
    for (auto iter = vec.begin(); iter != vec.end();) {
            if (*iter < 0){
                iter = vec.erase(iter);
            }
            else{
                iter ++;
            }
    }

    return vec;
}

list<double>& remove_negative(list<double>& vec){
    //int size = vec.size();
    for (auto iter = vec.begin(); iter != vec.end();) {
            if (*iter < 0){
                iter = vec.erase(iter);
            }
            else{
                ++iter;
            }
    }

    return vec;
}

int main(){
    vector<double> vec1{2, 1, 4, 3, 7};
    vector<double> vec2{1, 3, 2, 5};
    // lshift(vec1, 3);
    // rshift(vec1, 2);
    auto vec3 = scale(vec1, 1.5);
    auto vec4 = add(vec2, vec3);
    // auto vec5 = add(vec2, scale(vec2, -2.2));

    int size = vec4.size();
    for (int i = 0; i < size; i++){
        cout << vec4[i] << ' ';
    }
}
