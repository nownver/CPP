#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

class Book {
    public:
        enum class Genre {fiction, nonfiction, periodical, biography, children};
    private:
        string isbn;
        string title;
        string author;
        int copyYear ;
        bool check = 0;
        
        Genre gen = Genre::fiction;

    public:
        Book(): isbn{}, title{}, author{}, copyYear{}
        {
        }
        Book( string a_isbn, string a_title, string a_author, int a_copyYear)
        : isbn{a_isbn}, title{a_title}, author{a_author}, copyYear{a_copyYear}
        {
        }
        // Book(istream);
        // std::istream& read(std::istream&);
        string get_isbn() const { return isbn; }
        string get_title() const { return title; }
        string get_author() const { return author; }
        int get_copyYear() const { return copyYear; }


        void check_in() {check = 1;}
        void check_out() {check = 0;}
        bool get_check() const{
            return check;
        }

        bool compare_ibsn(Book b2) const {
            return b2.isbn == isbn;
        }

        void print_info(){
            cout << "\nISBN:" << isbn << "\ntitle:" << title << "\nauthor:" << author << "\ncopyYear:" << copyYear << "\ncheck:" << check << endl;
        }

        Genre get_genre() const{return gen;}
};

string print_genre(Book::Genre gen){
    switch(gen) {
    case Book::Genre::fiction:
        return "fiction";
    case Book::Genre::nonfiction:
        return "nonfiction";
    case Book::Genre::periodical:
        return "periodical";
    case Book::Genre::biography:
        return "biography";
    case Book::Genre::children:
        return "children";
}
}

// Book read(istream& is) {
//     vector<string> inputs;
//     string input;
//     while (getline(is, input)){
//         inputs.push_back(input);
//     }
//     Book book(inputs[0], inputs[1], stoi(inputs[3]), true, print_genre(inputs[4]));
//     return book;
// }

int main(){

    Book x;
    Book x2("123", "love", "yok", 2022);
    cout << x2.get_author();
    x2.check_in();
    // x2.check_out();
    cout << x2.get_check();
    cout << x2.compare_ibsn(x);
    x2.print_info();
    cout << print_genre(x2.get_genre());

}