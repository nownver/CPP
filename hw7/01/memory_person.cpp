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

Person* combine_fields(const vector<string>& names, const vector<int>& ages){
    int n = names.size();
    Person* people = new Person[n];
    for (int i = 0; i < n; ++i){
        people[i] = {names[i], ages[i]};
    }
    return people;
}

string* extract_names(const Person* people, int n){
    string* names = new string[n];
    for (int i = 0; i < n; ++i){
        names[i] = people[i].name;
    }
    return names;
}

int* extract_ages(const Person* people, int n){
    int* ages = new int[n];
    for (int i = 0; i < n; ++i){
        ages[i] = people[i].age;
    }
    return ages;
}

int main(){
    vector<string> names{"Gee", "Yok", "Bright", "Pao"};
    vector<int> ages{17, 19, 18, 17};

    int n = names.size();
    Person* people = combine_fields(names, ages);

    sort(people, people + n, nameAscend);
    cout << "Sort Name Ascend: " << endl;
    for (int i = 0; i < n; ++i){
        print_info(people[i]);
    }
    cout << endl;

    sort(people, people + n, nameDescend);
    cout << "Sort Name Descend: " << endl;
    for (int i = 0; i < n; ++i){
        print_info(people[i]);
    }
    cout << endl;

    sort(people, people + n, ageAscend);
    cout << "Sort Age Ascend: " << endl;
    for (int i = 0; i < n; ++i){
        print_info(people[i]);
    }
    cout << endl;

    sort(people, people + n, ageDescend);
    cout << "Sort Age Descend: " << endl;
    for (int i = 0; i < n; ++i){
        print_info(people[i]);
    }
    cout << endl;

    string* extracted_names = extract_names(people, n);
    cout << "Names: ";
    for (int i = 0; i < n; ++i){
        cout << extracted_names[i] << " ";
    }
    cout << endl;
    delete[] extracted_names;

    int* extracted_ages = extract_ages(people, n);
    cout << "Ages: ";
    for (int i = 0; i < n; ++i){
        cout << extracted_ages[i] << " ";
    }
    cout << endl;
    delete[] extracted_ages;

    delete[] people;
}
