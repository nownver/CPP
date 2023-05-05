#include <iostream>
#include <memory>
#include <string>
#include <sstream>

using namespace std;


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

int main() {
    std::istringstream iss("W Cecil F Ryu M Vivi");
    auto hero1 = make_unique<Hero>();
    hero1->read(iss);
    auto hero2 = make_unique<Hero>();
    hero2->read(iss);
    auto hero3 = make_unique<Hero>();
    hero3->read(iss);

    // [Cecil: Warrior]
    hero1->print(cout);
    cout << endl;

    // [Ryu: Fighter]
    hero2->print(cout);
    cout << endl;

    // [Vivi: Mage]
    hero3->print(cout);
    cout << endl;

    return 0;
}
