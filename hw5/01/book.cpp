#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

enum class Genre {fiction, nonfiction, periodical, biography, children};

class Book {
    private:
        string isbn;
        string title;
        string author;
        int copyright_year;
        bool status;
        Genre gen;

    public:
        Book(): isbn{}, title{}, author{}, copyright_year{}, gen{}
        {
        }
        Book(string _isbn, string _title, string _author, int _copyright_year, Genre _gen)
        : isbn{_isbn}, title{}, author{}, copyright_year{}, gen{_gen}
        {
        }

        string get_isbn() const {return isbn; }
        string get_title() const {return title; }
        string get_author() const {return author; }
        int get_copyright_year() const {return copyright_year; }
        Genre get_genre() const {return gen;}

        void check_in() {status = true;}
        void check_out() {status = false;}
        bool avail() {
            return status;
        }

        bool compare(Book b2) {
            return isbn == b2.isbn;
        }

        void print_info(){
            cout << endl <<"\nISBN: " << isbn << endl;
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Copyright year: " << copyright_year << endl;
            cout << "Status: " << avail() << endl;
            cout << "Genre: " << genre_check() << endl;
        }

        string genre_check(){
            switch(gen){
                case Genre::fiction:
                    return "Fiction";
                case Genre::nonfiction:
                    return "Nonfiction";
                case Genre::periodical:
                    return "Periodical";
                case Genre::biography:
                    return "Biography";
                case Genre::children:
                    return "Children";
            }
        }
};

Book read_book(istream& is){
    string isbn, title, author, genre_str;
    int year;
    Genre genre;

    cout << endl << "Enter ISBN: ";
    getline(is, isbn);
    cout << "Enter Title: ";
    getline(is, title);
    cout << "Enter Author: ";
    getline(is, author);
    cout << "Enter Year: ";
    is >> year;
    is.ignore();
    cout << "Enter Genre: ";
    getline(is, genre_str);
    cout << endl;

    if (genre_str == "fiction")
        genre = Genre::fiction;
    else if (genre_str == "nonfiction")
        genre = Genre::nonfiction;
    else if (genre_str == "periodical")
        genre = Genre::periodical;
    else if (genre_str == "biography")
        genre = Genre::biography;
    else if (genre_str == "children")
        genre = Genre::children;
    else
        genre = Genre::fiction;

    return Book(isbn, title, author, year, genre);
}

Book find_book_by_title(const vector<Book>& books, const string& title) {
    for (const auto& book : books) {
        if (book.get_title() == title) {
            return book;
        }
    }
    return Book();
}

Book find_book_by_isbn(const vector<Book>& books, const string& isbn) {
    for (const auto& book : books) {
        if (book.get_isbn() == isbn) {
            return book;
        }
    }
    return Book();
}

vector<Book> find_books_by_genre(const vector<Book>& books, Genre genre) {
    vector<Book> match_books;
    for (const auto& book : books) {
        if (book.get_genre() == genre) {
            match_books.push_back(book);
        }
    }
    return match_books;
}

void sort_books_by_title(vector<Book>& books) {
    sort(books.begin(), books.end(), [](const Book& book1, const Book& book2) {
        return book1.get_title() < book2.get_title();
    });
}

void sort_books_by_isbn(vector<Book>& books) {
    sort(books.begin(), books.end(), [](const Book& book1, const Book& book2) {
        return book1.get_isbn() < book2.get_isbn();
    });
}

int main(){

    vector<Book> books = {
        Book("9783161484100", "Anna The Fat", "Urawee", 2011, Genre::nonfiction),
        Book("9780134997834", "Harry Bottle", "Jon", 2008, Genre::nonfiction),
        Book("9780596007126", "Bell Ringing", "Kyle Loudon", 2022, Genre::nonfiction),
        Book("9781451673319", "Anne Frank", "Bayer", 2011, Genre::biography),
        Book("9780590353427", "Whawkin", "J.K. Rowling", 1997, Genre::children)
    };

    Book new_book = read_book(cin);
    new_book.print_info();
    books.push_back(new_book);
    
    string search_title = "Anna The Fat";
    Book matched_book = find_book_by_title(books, search_title);
    cout << "Books match title '" << search_title << "':" << endl;
    matched_book.print_info();
    
    string search_isbn = "9780596007126";
    Book match_book = find_book_by_isbn(books, search_isbn);
    cout << "Book match ISBN '" << search_isbn << "':" << endl;
    match_book.print_info();
    
    Genre search_genre = Genre::nonfiction;
    vector<Book> genre_books = find_books_by_genre(books, search_genre);
    cout << "Books match genre: " << endl;
    for (auto& book : genre_books) {
        book.print_info();
    }
    
    sort_books_by_title(books);
    cout << "Books sorted by title:" << endl;
    for (auto& book : books) {
        book.print_info();
    }
    
    sort_books_by_isbn(books);
    cout << "Books sorted by ISBN:" << endl;
    for (auto& book : books) {
        book.print_info();
    }

    return 0;
}