#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

void print_info(Person p){
    cout << p.name << " " << p.age << endl;
}

bool nameAscend(const Person& p1, const Person& p2){
    return p1.name < p2.name;
}

bool nameDescend(const Person& p1, const Person& p2){
    return p1.name > p2.name;
}

bool ageAscend(const Person& p1, const Person& p2){
    return p1.age < p2.age;
}

bool ageDescend(const Person& p1, const Person& p2){
    return p1.age > p2.age;
}

vector<Person> combine_fields(const vector<string>& names, const vector<int>& ages){
    vector<Person> people;
    for (int i = 0; i < names.size(); ++i){
        people.push_back({names[i], ages[i]});
    }
    return people;
}

vector<string> extract_names(const vector<Person>& people){
    vector<string> names;
    for (int i = 0; i < people.size(); ++i){
        names.push_back(people[i].name);
    }
    return names;
}

vector<int> extract_ages(const vector<Person>& people){
    vector<int> ages;
    for (int i = 0; i < people.size(); ++i){
        ages.push_back(people[i].age);
    }
    return ages;
}

int main(){
    vector<Person> people {{"Gee", 17}, {"Yok", 19}, {"Bright", 18}, {"Pao", 17}};

    sort(people.begin(), people.end(), nameAscend);
    cout << "Sort Name Ascend: " << endl;
    for (auto p: people){
        print_info(p);
    }
    cout << endl;

    sort(people.begin(), people.end(), nameDescend);
    cout << "Sort Name Descend: " << endl;
    for (auto p: people){
        print_info(p);
    }
    cout << endl;

    sort(people.begin(), people.end(), ageAscend);
    cout << "Sort Age Ascend: " << endl;
    for (auto p: people){
        print_info(p);
    }
    cout << endl;

    sort(people.begin(), people.end(), ageDescend);
    cout << "Sort Age Descend: " << endl;
    for (auto p: people){
        print_info(p);
    }
    cout << endl;

    vector<string> names{"Nice", "Happy", "TT"};
    vector<int> ages{11, 10, 9};

    vector<Person> all_people = combine_fields(names, ages);
    cout << "Combined: " << endl;
    for (auto p: all_people){
        print_info(p);
    }
    cout << endl;

    auto extracted_names = extract_names(all_people);
    cout << "Names: ";
    for (auto n: extracted_names){
        cout << n << " ";
    }
    cout << endl;

    auto extracted_ages = extract_ages(all_people);
    cout << "Ages: ";
    for (auto a: extracted_ages){
        cout << a << " ";
    }
    cout << endl;
}