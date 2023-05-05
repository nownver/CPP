#include <string>
#include <iostream>

using namespace std;


class Hero {
public:
    Hero(): name_{"Nameless Hero"}{}
    Hero(string n): name_{n}{}

    string name() const {return name_;}
    // virtual string greeting() const = 0;
    virtual string greetings() const {return "I'm the hero with no name";}
    private:
        string name_;
};

class Warrior : public Hero{
    public:
        Warrior(): Hero{"Nameless Warrior"} {}
        Warrior(string n): Hero{n} {}

        string greetings() const override {return "I'm " + name() +", I will save the world.";}

};

class Fighter : public Hero {
public:
    Fighter(): Hero{"Nameless Fighter"} {}
    Fighter(string n): Hero{n} {}

    string greetings() const override {return "I'm " + name() +", my fists will crush the evil.";}
};

class Mage : public Hero {
public:
    Mage(): Hero{"Nameless Mage"} {}
    Mage(string n): Hero{n} {}

    string greetings() const override {return "I'm " + name() +", I can cook with fire magic.";}
};

int main(){
// Example use cases for `2.2)'
Warrior warrior1("Cecil");
Fighter fighter1;
Mage mage1("Vivi");
const Hero& hero1 = warrior1;
const Hero& hero2 = fighter1;
const Hero& hero3 = mage1;
// "Cecil"
auto name = hero1.name();
// "Nameless Fighter"
name = hero2.name();
// "Vivi"
name = hero3.name();

// // ...
// // "I'm Cecil, I will save the world."
// std::cout << hero1.greetings() << std::endl;
// // "I'm Nameless Fighter, I will crush the evil."
// std::cout << hero2.greetings() << std::endl;
// // "I'm Vivi, I can cook with fire magic."
// std::cout << hero3.greetings() << std::endl;
const Hero hero4 = warrior1;
// // "I'm the hero with no name."
std::cout << hero4.greetings() << std::endl;
}