#include <iostream>
#include <array>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

// void to_upper(char& s){
//     if (int(s) >= 97 && int(s) <= 122){
//         int temp_scii = int(s);
//         temp_scii -= 32;
//         s = char(temp_scii);
//     }
// }

void to_upper(char* str){
    int i = 0;
    while (str[i] != '\0'){
        if (97 <= str[i] && str[i] <= 122){
            str[i] -= 32;
        }
        i++;
    }
}
char* rev_dup(const char* s){
    const size_t n = strlen(s);
    char* p = new char[n + 1];
    p[n] = 0;
    for (size_t i = 0; i < n; ++i) {
        p[i] = s[n-i-1];
    }
    return p;
}

char* read_text(istream& input){
    const size_t n = 100;
    size_t capacity = n;
    size_t size = 0;
    char* buffer = new char[n];
    char c;
    while (input.get(c)){
        if (c != '!') {
            buffer[size++] = c;
            if (strlen(buffer) >= 100){
                capacity *= 2;
                char* buffer2 = new char[capacity];
                copy(buffer, buffer + size, buffer2);
                delete[] buffer;
                buffer = buffer2;
            }
        }
        else{
            break;
        }
    }
    return buffer;

}

// char* read_text(std::istream& is) {
//     const size_t chunk_size = 10; // number of characters to read at a time
//     size_t capacity = chunk_size; // initial capacity of the buffer
//     size_t size = 0; // number of characters read so far
//     char* buffer = new char[capacity]; // allocate memory for the buffer

//     char c;
//     while (is.get(c)) {
//         if (c == '!') {
//             break; // stop reading when an exclamation mark is encountered
//         }
//         buffer[size++] = c; // add the character to the buffer
//         if (size == capacity) {
//             // double the capacity of the buffer if it is full
//             capacity *= 2;
//             char* new_buffer = new char[capacity];
//             std::copy(buffer, buffer + size, new_buffer);
//             delete[] buffer;
//             buffer = new_buffer;
//         }
//     }
//     buffer[size] = '\0'; // null-terminate the C-style string

//     return buffer;
// }
int main(){
    double coords[3] = {};
    double* p1 = coords;

    array<double, 4> pt4d;
    auto arr_it = pt4d.begin();

    vector<double> vec = {1,2,3,4,5};
    auto vec_it = vec.begin();

    cout << sizeof(coords) << endl;
    cout << sizeof(p1) << endl;

    cout << sizeof(pt4d) << endl;
    cout << sizeof(arr_it) << endl;

    cout << sizeof(vec) << endl;
    cout << sizeof(vec_it) << endl;
    
    cout << "number of coords: "<< sizeof(coords) / sizeof(typeid(coords)) << endl;

    // string word = "Hello, World!";

    // for (auto c: word){
    //     to_upper(c);
    //     cout << c;
    // }

    char str[] = "Hello, World!";
    to_upper(str);
    cout << str << endl;

    cout << strlen(str) << endl;

    char str2[] = "Hello, World!";
    char* ss = rev_dup(str2);
    cout << ss << endl;
    // ss += 2;
    delete[] ss;

    string word3 = "Hello X!, Y!, Z";
    istringstream iss(word3);
    char* pointer = read_text(iss);
    cout << pointer;
}