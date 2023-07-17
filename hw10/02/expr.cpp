/*
Grammar
=======

Expression:
    Term
    Term '|' Expression
    Term '^' Expression
    Term '&' Expression

Term:
    Primary

Primary:
    Number
    '~' Primary
    Primary '{' Expression '}'
    Primary '(' Expression ')'
    
*/

#include <istream>

struct Token {
public:
    char kind;
    int value;

    static constexpr char print = ';';
    static constexpr char quit = 'q';
    static constexpr char number = '1';

    explicit Token(char k): kind{k}, value{} {}
    Token(char k, int v) : kind{k}, value{v} {}
};

class Token_stream {
public:
    Token get();              // get a Token
    void putback(Token t);    // put a token back

    [[noreturn]]
    static void error(const std::string& s)
    { throw std::runtime_error(s); }

    explicit Token_stream(std::istream& is): input{is} {}
private:
    std::istream& input;
    Token buffer{'0'};        // here is where putback() stores a Token
    bool full = false;        // is there a Token in the buffer?
};

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

int expression(Token_stream& ts);
int primary(Token_stream& ts);

int complement(Token_stream& ts) // COMPLEMENT
{
    int left = primary(ts);
    Token t = ts.get();

    while (true) {
        if (t.kind == '~') {
            left = ~left;

            t = ts.get();
        }
        else {
            ts.putback(t);
            break;
        }
    }

    return ~left;
}

int primary(Token_stream& ts)
{
    Token t = ts.get();
    switch (t.kind) {
    case '~':   // COMPLEMENT ~
        return complement(ts);
    case '(':    // "(" Expression ")"
        {
            int d = expression(ts);
            t = ts.get();
            if (t.kind != ')')
                Token_stream::error("')' expected");
            return d;
        }
    case '{':    // "{" Expression "}"
        {
            int d = expression(ts);
            t = ts.get();
            if (t.kind != '}')
                Token_stream::error("'}' expected");
            return d;
        }
    case Token::number:    // Number
        return t.value;
    default:
        Token_stream::error("integer expected");
    }
}

int expression(Token_stream& ts)
{
    int left = primary(ts);        
    Token t = ts.get();            // get next token from Token_stream
    for (;;) {
        switch (t.kind) {
        case '|':    // OR |
            left |= primary(ts);
            t = ts.get();
            break;
        case '^':    // XOR ^
            left ^= primary(ts);
            t = ts.get();
            break;
        case '&':    // AND &
            left &= primary(ts);
            t = ts.get();
            break;
        default:    // primary
            ts.putback(t);    // put `t' back into the Token_stream
            return left;
        }
    }
}

int main(int argc, const char* const* const argv)
try {
    std::istream& iss = std::cin;
    Token_stream ts_input(iss);

    int val = 0;
    while (iss) {
        Token t = ts_input.get();
        if (t.kind == Token::quit)
            break;
        if (t.kind == Token::print)
            std::cout << "=" << val << '\n';
        else
            ts_input.putback(t);

        val = expression(ts_input);
    }
    return 0;
}
catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    std::cerr << "Unknown exception\n";
    return 2;
}

void Token_stream::putback(Token t)
{
    buffer = t;                 // copy t to buffer
    full = true;                // buffer is now full
}

Token Token_stream::get()
{
    if (full) {             // do we already have a Token?
        full = false;       // remove Token from buffer
        return buffer;
    }

    char ch;
    input >> ch;            // note that >> skips whitespace

    switch (ch) {
    case Token::print:
    case Token::quit:
    case '(': case ')': case '{': case '}':
    case '|': case '&': case '^': case '~':
        return Token{ch};
    case '0': case '1': {
        input.putback(ch);  // put digit back into input stream

        int val;
        input >> val;
        return Token{Token::number, val};
    }
    default:
        error("Bad token");
    }
}