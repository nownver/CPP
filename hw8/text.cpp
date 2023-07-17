#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

class Text_base {
protected:
    string txt;
    string opening;
    string closing;

public:
    virtual string text() const { return txt; }

    Text_base() : txt{""}, opening{" "}, closing{" "} {}

    Text_base(const string& t, const string& o, const string& c)
        : txt{t}, opening{o}, closing{c} {}

    Text_base(const string& t, const string& o)
        : txt{t}, opening{o}, closing{o} {}

    Text_base(const string& t)
        : txt{t}, opening{""}, closing{""} {}
};

class Quoted_text : public Text_base {
public:
    string text() const { return opening + txt + closing; }

    Quoted_text() : Text_base{"", " ", " "} {}

    Quoted_text(const string& t, const string& o, const string& c)
        : Text_base{t, o, c} {}

    Quoted_text(const string& t, const string& o)
        : Text_base{t, o, o} {}

    Quoted_text(const string& t)
        : Text_base{t, "", ""} {}
};

class Crypted_text : public Text_base {
private:
    string encrypt(string& txt) {
        for (auto i = 0u; i < txt.length(); ++i) {
            if (txt[i] >= 'a' && txt[i] <= 'z') {
                txt[i] = 'a' + ('z' - txt[i]);
            } else if (txt[i] >= 'A' && txt[i] <= 'Z') {
                txt[i] = 'A' + ('Z' - txt[i]);
            }
        }
        return txt;
    }

public:
    string text() { return encrypt(txt); }

    Crypted_text() : Text_base{""} {}

    Crypted_text(const string& t)
        : Text_base{t} {}
};
class Text {
private:
    shared_ptr<Text_base> ptr_;

public:
    Text(const string& t, const string& o, const string& c)
        : ptr_(new Quoted_text{t, o, c}) {}

    Text(const string& t, const string& o)
        : ptr_(new Quoted_text{t, o}) {}

    Text(const string& t)
        : ptr_(new Text_base{t}) {}

    Text(Crypted_text c)
        : ptr_(new Crypted_text{c.text()}) {}

    string text() const { return ptr_->text(); }
};


int main(){
    Text_base q0("Python", "*");
    auto text = q0.text(); // "Python"
    cout << text << endl;

    Quoted_text q("Python", "*");
    const Text_base& rq = q;
    text = q.text(); // "*Python*" 
    cout << text << endl;
    text = rq.text(); // "*Python*"
    cout << text << endl;

    q = Quoted_text("Python", "<em>", "</em>"); 
    text = q.text(); // "<em>Python</em>" 
    cout << text << endl;
    text = rq.text(); // "<em>Python</em>"
    cout << text << endl;

    Crypted_text ct("Abc101");
    const Text_base& rct = ct;
    text = ct.text(); // "Zyx101"
    cout << text << endl;
    text = rct.text(); // "Zyx101"
    cout << text << endl;

    ct = Crypted_text{"PYthoN101"};
    text = ct.text(); // "KBgslM101"
    cout << text << endl;
    text = rct.text(); // "KBgslM101"
    cout << text << endl;

    vector<Text> words{ 
        Text("C++", "<i>", "</i>"), // Quoted_text
        Text("Zidane"), // Crypted_text
        Text("Rust", "*"), // Quoted_text
        Text("Python", "[[", "]]"), // Quoted_text
        Text(Crypted_text("Vivi")) // Text_base
    };

    for (const auto& w: words) {
        cout << w.text() << endl; 
    }
    
}
