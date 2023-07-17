#include <vector>
// #include <algorithm>
#include <string>
#include <iostream>
using namespace std;
#include <stdlib.h>


// string substitute(string text, string word, string rep){
//     if (word.length() == 0 || rep.length() == 0){
//         return text;
//     }
//     while (text.find(word) != string::npos){
//         text.replace(text.find(word), word.length(),rep);
//     }
//     return text;
// }

// char* substitute(const char* text, const char* word, const char* rep) {
//     int text_len = 0, word_len = 0, rep_len = 0;
//     int count = 0, i = 0, j = 0, k = 0;
//     char* result = NULL;
    
//     while (text[text_len] != '\0') text_len++;
//     while (word[word_len] != '\0') word_len++;
//     while (rep[rep_len] != '\0') rep_len++;
    
//     for (i = 0; i <= text_len - word_len; i++) {
//         int match = 1;
//         for (j = 0; j < word_len; j++) {
//             if (text[i+j] != word[j]) {
//                 match = 0;
//                 break;
//             }
//         }
//         if (match) count++;
//     }
    
//     result = (char*) malloc(text_len + count * (rep_len - word_len) + 1);
    
//     i = 0;
//     while (i <= text_len - word_len) {
//         int match = 1;
//         for (j = 0; j < word_len; j++) {
//             if (text[i+j] != word[j]) {
//                 match = 0;
//                 break;
//             }
//         }
//         if (match) {
//             for (j = 0; j < rep_len; j++) {
//                 result[k++] = rep[j];
//             }
//             i += word_len;
//         } else {
//             result[k++] = text[i++];
//         }
//     }
//     while (i < text_len) {
//         result[k++] = text[i++];
//     }

//     result[k] = '\0';
//     return result;
// }

char* substitute(const char* text, const char* word, const char* rep) {
    if (word == nullptr || rep == nullptr) {
        return nullptr;
    }

    size_t text_len = strlen(text);
    const size_t word_len = strlen(word);
    const size_t rep_len = strlen(rep);
    char* result = new char[text_len + 1];
    strcpy(result, text);
    if (word_len == 0 || rep_len == 0) {
        return result;
    }
    char* pos = result;
    while ((pos = strstr(pos, word)) != nullptr) {
        const size_t remaining_len = strlen(pos + word_len);
        char* temp = new char[text_len - remaining_len + rep_len + 1];
        const size_t prefix_len = pos - result;
        strncpy(temp, result, prefix_len);
        strncpy(temp + prefix_len, rep, rep_len);
        strcpy(temp + prefix_len + rep_len, pos + word_len);
        delete[] result;
        result = temp;
        pos = result + prefix_len + rep_len;
        text_len += rep_len - word_len;
    }
    
    return result;
}

int main(){
    // string text1 = "abc python javapythonx";
    // string text2 = "abcx yja helx yz01 23";

    char text1[] = "abc python javapythonx";
    char text2[] = "abcx yja helx yz01 23";

    cout << substitute(text1, "python", "rust") << endl;
    cout << substitute(text1, "", "rust") << endl;

    cout << substitute(text2, "python", "rust") << endl;
    cout << substitute(text2, "x y", "a b") << endl;

    // vector<pair<double, double>> create_pairs(const vector<double>& arr);
    // vector<double> data{ 1.2, 2.3, 5, 2, 1.1, 3, 7 };
    // auto pairs = create_pairs(data);
}