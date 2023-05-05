#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Writer {
public:
    void begin_document() const{
        cout << "<!DOCTYPE html>\n<html>\n";
    };
    void end_document() const{
        cout << "</html>\n";
    };
    void begin_tag(const string& tag_name) const{
        cout << "<" << tag_name << ">";
    };
    void end_tag(const string& tag_name) const{
        cout << "</" << tag_name << ">";
    };
    void write_text(const string& text) const{
        cout << text;
    };
    void write_newline() const{
        cout << "\n";
    };
    void write_space(int lv) const{
        for (int i = 0; i < lv; ++i) {
            cout << "  ";
        }
    };
};


class Doc_element
{
public:
    void write_document(const Writer &w) const;
    void write_to(const Writer &w, int lv) const;
    static Doc_element text(const string &t) {
        return Doc_element(t);
    }
    explicit Doc_element(const string &n) : s(n) {};
    Doc_element(
        const string &n, const vector<Doc_element> &children);

private:
    string s;
    vector<Doc_element> v;
    string tag;
};


void Doc_element::write_document(const Writer& w) const {
    w.begin_document();
    write_to(w, 0);
    w.end_document();
}

void Doc_element::write_to(const Writer& w, int lv) const {
    w.write_space(lv);
    if (!tag.empty()) {
        w.begin_tag(tag);
        for (const auto& child : v) {
            w.write_newline();
            child.write_to(w, lv + 1);
        }
        w.write_newline();
        w.write_space(lv);
        w.end_tag(tag);
    } else {
        w.write_text(s);
    }
}

Doc_element::Doc_element(const string& n, const vector<Doc_element>& children) : v(children), tag(n) {};

int main()
{
    auto t = Doc_element::text("Text001");
    auto e = Doc_element("em", {t, Doc_element("p", {t})});

    auto tr = Doc_element(
        "tr",
        {Doc_element("td", {t}), Doc_element("td", {t}),
         Doc_element("td", {t})});
    auto tbl = Doc_element("table", {tr, tr, tr});

    auto t2 = Doc_element::text("example");
    auto tr2 = Doc_element(
        "tr",
        {Doc_element("td", {Doc_element::text("abc")}), Doc_element("td", {Doc_element::text("xyz")})});
    auto tbl2 = Doc_element("table", {tr2});

    Writer writer;
    tbl.write_document(writer);
    e.write_document(writer);
    tbl2.write_document(writer);
}