#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Picture {
    private:
        int width;
        int height;
        vector<string> content;

    public:
        Picture(): width{}, height{}, content{}
        {
        }
        Picture(int w, int h)
        : width{w}, height{h}, content(h, string(w, ' '))
        {
        }

        int get_width() const {return width; }
        int get_height() const {return height; }

        void set_content(const vector<string>& c) { content = c; }

        Picture hcat(const Picture& others) {
            int width_new = width + others.width;
            int height_new = max(height, others.height);

            Picture result(width_new, height_new);

            for (int i = 0; i < height; ++i) {
                const string& row = content[i];
                result.set_row(i, row + ' ');
            }

            for (int i = 0; i < others.height; ++i) {
                const string& row = others.get_row(i);
                result.set_row(i, result.get_row(i) + row);
            }

            return result;
        }


        Picture vcat(const Picture& others) {
            int width_new = max(width, others.width);
            int height_new = height + others.height;
            Picture result(width_new, height_new);
            for (int i = 0; i < height; ++i) {
                const string& row = content[i];
                result.set_row(i, row);
            }
            for (int i = 0; i < others.height; ++i) {
                result.set_row(i+height, others.get_row(i));
            }
            return result;
        }

        void print_content() {
            for (auto& row : content) {
                cout << row << endl;
            }
            cout << endl;
        }

        void resize(int width_new, int height_new) {
            vector<string> new_content(height_new, string(width_new, ' '));
            for (int i = 0; i < min(height, height_new); ++i) {
                if (width <= width_new) {
                    new_content[i] = content[i] + string(width_new - width, ' ');
                } 
                else {
                    new_content[i] = content[i].substr(0, width_new);
                }
            }
            if (height <= height_new) {
                for (int i = height; i < height_new; ++i) {
                    new_content[i] = string(width_new, ' ');
                }
            } 
            else {
                new_content.resize(height_new);
            }
            content = new_content;
            width = width_new;
            height = height_new;
        }

        string get_row(int i) const {
            return content[i];
        }

        void set_row(int i, const string& row) {
            content[i] = row;
        }
};

int main() {
    Picture p1(7, 3);
    p1.set_row(0, "*******");
    p1.set_row(1, "*     *");
    p1.set_row(2, "*******");
    cout << "Picture 1:" << endl;
    p1.print_content();

    Picture p2(12, 2);
    p2.set_row(0, "************");
    p2.set_row(1, "*** *  * ***");
    cout << "Picture 2:" << endl;
    p2.print_content();

    cout << "hcat:" << endl;
    Picture p3 = p1.hcat(p2);
    p3.print_content();

    cout << "vcat:" << endl;
    Picture p4 = p1.vcat(p2);
    p4.print_content();

    cout << "resized:" << endl;
    p4.resize(5, 10);
    p4.print_content();

    return 0;
}