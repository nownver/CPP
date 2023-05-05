#include <iostream>
#include <cstring>

using namespace std;

class Picture {
private:
    int width, height;
    char** content;

public:
    Picture() : width{}, height{}, content(nullptr) {}

    Picture(int w, int h) : width{w}, height{h} {
        content = new char*[height];
        for (int i = 0; i < height; ++i) {
            content[i] = new char[width];
            memset(content[i], ' ', width);
        }
    }

    Picture(const Picture& other) : width{other.width}, height{other.height} {
        content = new char*[height];
        for (int i = 0; i < height; ++i) {
            content[i] = new char[width];
            memcpy(content[i], other.content[i], width);
        }
    }

    Picture& operator=(const Picture& other) {
        if (this != &other) {
            for (int i = 0; i < height; ++i) {
                delete[] content[i];
            }
            delete[] content;
            width = other.width;
            height = other.height;
            content = new char*[height];
            for (int i = 0; i < height; ++i) {
                content[i] = new char[width];
                memcpy(content[i], other.content[i], width);
            }
        }
        return *this;
    }

    ~Picture() {
        for (int i = 0; i < height; ++i) {
            delete[] content[i];
        }
        delete[] content;
    }

    int get_width() const { return width; }
    int get_height() const { return height; }

    void set_width(int w) { 
        char** new_content = new char*[height];
        for (int i = 0; i < height; ++i) {
            new_content[i] = new char[w];
            if (w > width) {
                memcpy(new_content[i], content[i], width);
                memset(new_content[i]+width, ' ', w-width);
            } else {
                memcpy(new_content[i], content[i], w);
            }
            delete[] content[i];
        }
        delete[] content;
        content = new_content;
        width = w;
    }

    void set_height(int h) {
        char** new_content = new char*[h];
        for (int i = 0; i < h; ++i) {
            if (i < height) {
                new_content[i] = content[i];
            } else {
                new_content[i] = new char[width];
                memset(new_content[i], ' ', width);
            }
        }
        for (int i = h; i < height; ++i) {
            delete[] content[i];
        }
        delete[] content;
        content = new_content;
        height = h;
    }

    void set_content(char** c) {
        for (int i = 0; i < height; ++i) {
            memcpy(content[i], c[i], width);
        }
    }

    void print_content() {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                std::cout << content[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    char* get_row(int i) const {
        return content[i];
    }

    void set_row(int i, const char* row) {
        for (int j = 0; j < width; ++j) {
            content[i][j] = row[j];
        }
        content[i][width] = '\0';
    }

    Picture hcat(const Picture& left, const Picture& right) {
        int new_width = left.get_width() + right.get_width();
        Picture result(new_width, left.get_height());
        for (int i = 0; i < result.get_height(); ++i) {
            char* row = result.get_row(i);
            const char* left_row = left.get_row(i);
            const char* right_row = right.get_row(i);
            for (int j = 0; j < left.get_width(); ++j) {
                row[j] = left_row[j];
            }
            for (int j = 0; j < right.get_width(); ++j) {
                row[left.get_width() + j] = right_row[j];
            }
            row[new_width] = '\0';
        }
        return result;
    }

    Picture vcat(const Picture& top, const Picture& bottom) {
        int new_height = top.get_height() + bottom.get_height();
        Picture result(top.get_width(), new_height);
        for (int i = 0; i < top.get_height(); ++i) {
            result.set_row(i, top.get_row(i));
        }
        for (int i = 0; i < bottom.get_height(); ++i) {
            result.set_row(top.get_height() + i, bottom.get_row(i));
        }
        return result;
    }

    void clear() {
        for (int i = 0; i < height; ++i) {
            delete[] content[i];
        }
        delete[] content;
        width = 0;
        height = 0;
        content = nullptr;
    }

    void resize(int newWidth, int newHeight) {
        if (newWidth == width && newHeight == height) {
            return;
        }

        char** newContent = new char*[newHeight];
        for (int i = 0; i < newHeight; ++i) {
            newContent[i] = new char[newWidth+1];
            for (int j = 0; j < newWidth; ++j) {
                newContent[i][j] = ' ';
            }
            newContent[i][newWidth] = '\0';
        }

        int copyWidth = min(width, newWidth);
        int copyHeight = min(height, newHeight);
        for (int i = 0; i < copyHeight; ++i) {
            for (int j = 0; j < copyWidth; ++j) {
                newContent[i][j] = content[i][j];
            }
        }

        for (int i = 0; i < height; ++i) {
            delete[] content[i];
        }
        delete[] content;
        content = newContent;
        width = newWidth;
        height = newHeight;
    }

};

int main() {
    Picture pic(5, 3, '*');

    cout << "Width: " << pic.get_width() << endl;
    cout << "Height: " << pic.get_height() << endl;

    pic.print_content();

    Picture(pic);

    // Picture newPic = Picture(4, 2, '#');
    // newPic.print_content();

    Picture copyPic(pic);
    copyPic.print_content();

    Picture copiedPic = pic;
    copiedPic.print_content();

    return 0;
}