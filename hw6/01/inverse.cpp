#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

void inverse_numbers(double* v, size_t n) {
    for (size_t i = 0; i < n; i++) {
        v[i] = -v[i];
    }
}

void replace(char* s, char c1, char c2) {
    for (size_t i = 0; s[i] != '\0'; i++) {
        if (s[i] == c1) {
            s[i] = c2;
        }
    }
}

char* encode_hex(const char* s) {
    size_t len = 0;
    while (s[len] != '\0') len++;
    size_t size = 2 * len + 1;
    char* encoded = (char*) malloc(size);

    for (size_t i = 0; i < len; i++) {
        unsigned char c = (unsigned char) s[i];
        encoded[2 * i] = "0123456789ABCDEF"[c >> 4];
        encoded[2 * i + 1] = "0123456789ABCDEF"[c & 0x0F];
    }
    encoded[2 * len] = '\0';
    return encoded;
}

int main() {
    double v[] = {1.0, -2.0, 3.0, -4.0, 5.0};
    size_t n = 3;
    inverse_numbers(v, n);
    for (size_t i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    char s[] = "Hello, World!";
    char c1 = 'l';
    char c2 = 'X';
    replace(s, c1, c2);
    cout << s << endl;

    const char* test = "Hello, world!";
    char* encoded = encode_hex(test);
    cout << encoded << endl;
    free(encoded);
    return 0;
}
