// #include <iostream>
// #include <string>
// #include <stdexcept>

// // Forward declaration of the Core class
// class Core;

// class Student_info {
// public:
//     // Constructors and copy control
//     Student_info() : cp(nullptr) { }
//     Student_info(std::istream& is) : cp(nullptr) { read(is); }
//     Student_info(const Student_info&);
//     Student_info& operator=(const Student_info&);
//     ~Student_info() { delete cp; }

//     // Operations
//     std::istream& read(std::istream&);
//     std::string name() const {
//         if (cp) return cp->name();
//         else throw std::runtime_error("Uninitialized Student");
//     }
//     double grade() const {
//         if (cp) return cp->grade();
//         else throw std::runtime_error("Uninitialized Student");
//     }
    
//     // Static function for comparing Student_info objects by name
//     static bool compare(const Student_info& s1, const Student_info& s2) {
//         return s1.name() < s2.name();
//     }

// private:
//     Core* cp;  // Pointer to Core object
// };

// // Definition of the Core class
// class Core {
// public:
//     Core(): student_name{"Name"}, student_grade{0.0} {}
//     Core(std::string std_name = "Name" ,double grade = 0.0): student_name(std_name),student_grade(grade){}

//     // Core class implementation goes here
//     std::string name() const {
//         return student_name;
//     }
    
//     double grade() const {
//         return student_grade;
//     }
    
//     // Additional member functions and data for the Core class

// private:
//     std::string student_name;
//     double student_grade;
// };

// // Definition of the member functions for Student_info class

// std::istream& Student_info::read(std::istream& is) {
//     // Implementation of read function goes here
//     // Read data from the input stream and create a new Core object

//     return is;
// }

// Student_info::Student_info(const Student_info& other) : cp(nullptr) {
//     // Implementation of copy constructor goes here
//     // Perform a deep copy of the Core object

// }

// Student_info& Student_info::operator=(const Student_info& other) {
//     // Implementation of assignment operator goes here
//     // Perform a deep copy of the Core object
    
//     if (this != &other) {
//         // Clean up existing data
//         delete cp;
//         cp = nullptr;

//         // Perform a deep copy
//         if (other.cp)
//             cp = new Core(*other.cp);
//     }

//     return *this;
// }

// int main(){
//     Core c1();
// }

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include<memory> //smart pointer

using namespace std;

string read_txt(string textfile){
    ifstream file(textfile);
    string result;
    if (file.is_open()){
        string line;
        while(getline(file,line)){
            result += line + " ";
        }
    }
    return result;

}

vector<int> separateint_from_str(string thatstr){
    istringstream iss(thatstr);
    vector<int> result;
    string value;
    while(iss >> value){
        result.push_back(stoi(value));
    }
    return result;

}

void findminmax(vector<int> data,int* min,int* max){
    *min = data[0];
    *max = data[0];
    for (int value : data){
        if (value<*min){
            *min = value;
        }
        if (value>*max){
            *max = value;
        }
    }
}

void arrayatruntime(){
    int size;
    cout<<"size : ";
    cin >> size;
    int* myArray = new int[size]; //allocate dynamic memory
    for (int i = 0;i<size;i++){
        cout << "Array [" << i << "] = " << endl;
        cout << *myArray << endl;
        cin >> *(myArray+i);
    }
    for (int i = 0;i<size;i++){
        cout << "Array [" << i << "]" << " = " << *(myArray+i) << endl; /*always remember that myArray -> the pointer will point 
        to the location of first element of array it will give you the same result as &myArray[0] 
        when you dereference it you will get the value of myArray[0]*/ 
    }

    //when not using it anymore you must always deallocate it
    delete[]myArray;
    /*after delete the pointer will point to the memory address 
    that don't belong to us so we need to set it io NULL ,so that
    the next to we use pointer it doesn't point to invalid memory*/
    myArray = NULL;
}

void multidimension_array_at_runtime(){
    int rows,columns;
    cout << "rows, cols : ";
    cin >> rows >> columns;

    //create pointer to a pointer
    int** table = new int*[rows];

    //create dynamic memory address to each rows in table
    for (int i =0;i<rows;i++){
        table[i] = new int[columns];
    }

    //set value
    table[1][2] = 88;

    //don't forget to deallocate
    /*when deallocate multidimension you 
    need to do the reverse of allocate it*/
    for (int i =0;i<rows;i++){
        delete[] table[i];
    }

    delete[]table;

    table = NULL;


}

class Myclass{
public:
    Myclass(){
        cout << "Constructor Invoked" << endl;
    }
    ~Myclass(){
        cout << "Destructor Invoked" << endl;
    }

};


void theunique_pointer(){
    unique_ptr<int>unPtr1 = make_unique<int>(25); //created unique pointer to integer

    //when printing address for smart ptr you should always .get()
    cout << unPtr1.get() << endl;
    //deref the smart pointer
    cout << *unPtr1;

    //THE UNIQUE POINTER ADDRESS CAN'T BE SHARED
    //However, you can move the ownership.
    unique_ptr<int>unPtr2 = move(unPtr1);
}



int main(){
    arrayatruntime();
    // int min=0,max=0;
    // string text = "test.txt";
    // string data = read_txt(text);
    // vector<int> seperated = separateint_from_str(data); 
    // findminmax(seperated,&min,&max);
    // cout << min << " " << max << endl;
    // arrayatruntime();
    // theunique_pointer();


    // {
    // unique_ptr<Myclass>unPtr1 = make_unique<Myclass>(); //demonstrate that pointer will be destroyed when out of scope
    // }
    // system("pause>nul");


    // {
    // shared_ptr<Myclass>shPtr1 = make_shared<Myclass>(); //shared pointer can share the address
    // //you can count the number of owner
    // cout << "Shared count " << shPtr1.use_count() << endl;
    // {
    // shared_ptr<Myclass>shPtr2 = shPtr1;
    // cout << "Shared count " << shPtr1.use_count() << endl;
    // } //shPtr2 is destroy
    // cout << "Shared count " << shPtr1.use_count() << endl;
    // //every shared ptr need to be destroy in order to deallocate
    // }
    // system("pause>nul");

    // weak_ptr<int>weakPtr1 ;
    // {
    //     shared_ptr<int>shPtr1 = make_shared<int>(25);
    //     weakPtr1 = shPtr1;
    // } //if owner(for this situation is shPtr1) left the scope the weak pointer will expired itself
}
