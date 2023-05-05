// #include <iostream>
// #include <vector>
// #include <string>
// #include <list>
// #include <map>
// #include <bits/stdc++.h>

// std::map<std::string, int> pair(auto vec) {
//     std::vector<std::string> v;
//     std::vector<std::string> num;
//     std::map<std::string, int> dict;

//     for (int i = 0; i < vec.size(); i += 2) {
//         if (dict.find(vec[i]) == dict.end()) {
//             dict[vec[i]] = std::stoi(vec[i+1]);
//         } 
//         else {
//             dict[vec[i]] += std::stoi(vec[i+1]);
//         }

//     }

//     return dict;
// }

// auto split(auto& s, char d) {
//     std::vector<std::string> v;
//     std::string word = "";
//     for (const auto& c: s) {
//         if (c == d) {
//             v.push_back(word);
//             word = "";
//         }
//         else {
//             word += c;
//         }
//     }
//     v.push_back(word);
//     return v;
// }


// int main() {
//     std::cout << "Enter the list of words and number: ";
//     std::string n;
//     std::getline(std::cin,n);

//     auto words = split(n, ' ');
//     auto paired = pair(words);

//     for (auto m: paired) {
//         std::cout << m.first << ": ";
//         std::cout << m.second << std::endl;
//     }

//     return 0;
// }
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
// #include <bits/stdc++.h>

std::map<std::string, std::string> pair(auto vec) {
    std::vector<std::string> v;
    std::vector<std::string> num;
    std::map<std::string, std::string> dict;

    for (int i = 0; i < vec.size(); i += 2) {
        if (dict.find(vec[i]) == dict.end()) {
            dict[vec[i]] = vec[i+1];
        } 
        else {
            dict[vec[i]] += "," + vec[i+1];
        }

        // dict.find(vec[i]) == dict.end() ? dict[vec[i]] = vec[i+1] : dict[vec[i]] += "," + vec[i+1];


    }

    return dict;


}

auto split(auto& s, char d) {
    std::vector<std::string> v;
    std::string word = "";
    for (const auto& c: s) {
        if (c == d) {
            v.push_back(word);
            word = "";
        }
        else {
            word += c;
        }
    }
    v.push_back(word);
    return v;
}


int main() {
    std::cout << "Enter the list of words and number: ";
    std::string n;
    std::getline(std::cin,n);

    auto words = split(n, ' ');
    auto paired = pair(words);

    for (auto m: paired) {
        std::cout << m.first << ": ";
        std::cout << m.second << std::endl;
    }

    return 0;
}