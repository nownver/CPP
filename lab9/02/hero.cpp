#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include "nse/html.hpp"

using namespace std;

using namespace nse::html;

class Hero {
private:
    string name_;
    //string type;
public:
    Hero() {}
    Hero(string n): name_{n}{}
    virtual string name() const {
        return name_;
    }
    virtual string greeting() const {
        return "I'm the hero with no name.";
    }
    virtual void read(istream& is) {
        // is >> type >> name_;
        is >> name_;
    }
    virtual void print(ostream& os) const {
        os << "[" << name() << ": Hero]";
        /*
        if (type == "W") {
            os << "[" << name() << ": Warrior]";
        }
        else if (type == "F") {
            os << "[" << name() << ": Fighter]";
        }
        else if (type == "M") {
            os << "[" << name() << ": Mage]";
        }
        else {
            os << "[" << name() << ": Hero]";
        }
        */
    }
    virtual Element get_svg(){
            return Element(string_view());
        }
};

class Warrior : public Hero {
public:
    Warrior() : Hero("Nameless Warrior") {}
    Warrior(string n) : Hero(n) {}
    string greeting() const override {
        return "I am " + name() + ", I will save the world.";
    }
    void print(ostream& os) const {
        os << "[" << name() << ": Warrior]";}

    
};


class Fighter : public Hero {
public:
    Fighter() : Hero("Nameless Fighter") {}
    Fighter(string n) : Hero(n) {}
    string greeting() const override {
        return "I am " + name() + ", my fists will crush the evil.";
    }
    void print(ostream& os) const {
        os << "[" << name() << ": Fighter]";}
};

class Mage : public Hero {
public:
    Mage() : Hero("Nameless Mage") {}
    Mage(string n) : Hero(n) {}
    string greeting() const override {
        return "I am " + name() + ", I can cook with fire magic.";
    }
};


void generate_html_table(const vector<unique_ptr<Hero>>& heroes, ostream& os) {

    os << "<table>" << endl;
    for (const auto& hero : heroes) {
        os << "<tr>" << endl;
        os << "<td>" << hero->name() << "</td>" << endl;
        os << "<td>" << hero->greeting() << "</td>" << endl;
        os << "</tr>" << endl;
    }
}


class Stream_writer: public nse::html::Writer {
    public:
        void write(std::string_view msg) const override;
        void write(const Element& e, int lv = 0) const override;

        Stream_writer(std::ostream& o): os(o) {}
    private:
        std::ostream& os;
};

void Stream_writer::write(std::string_view msg) const
{
    os << msg;
}

void Stream_writer::write(const Element& e, int lv) const
{
    e.write_to(*this, lv);
}

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

int main(){

    using Hero_ptr = std::unique_ptr<Hero>;
    std::vector<Hero_ptr> vec;
    vec.push_back(make_unique<Warrior>("Cecil"));
    vec.push_back(make_unique<Fighter>());
    vec.push_back(make_unique<Mage>("Vivi"));

    // for (const auto& hero : vec) {
    //     hero->print(std::cout);
    //     std::cout << std::endl;
    // }



    const string& filename = "print.html";
    const string& filename_2 = "print2.html";

    ofstream outfile(filename);
    if (!outfile.is_open()) {
        cerr << "Error: failed to open file \"" << filename << "\"" << endl;
        return 0;
    }

    ofstream outfile_2(filename_2);
    generate_html_table(vec, outfile);

    string s = read_txt(filename_2);
    string_view x = s;

    std::ofstream myfile;
    myfile.open ("test.html");

    Stream_writer out(myfile);
    out.write(x);
    

    return 0;

}