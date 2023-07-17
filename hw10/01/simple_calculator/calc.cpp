/*
Grammar
=======

Expression:
    Term
    Expression "+" Term    // addition
    Expression "–" Term    // subtraction
Term:
    Primary
    Term "%" Primary    // modulo
    Term "*" Primary    // multiplication
    Term "/" Primary    // division
Primary:
    Number
    "(" Expression ")"    // grouping
    "{" Expression "}"    // grouping
    "+" Primary        // unary +
    "-" Primary        // unary -
    Primary "!"         // factorial
*/

#include <istream>
#include <cmath>

struct Token {
public:
    char kind;
    double value;

    static constexpr char print = ';';
    static constexpr char quit = 'q';
    static constexpr char number = '8';

    explicit Token(char k): kind{k}, value{} {}
    Token(char k, double v) : kind{k}, value{v} {}
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

double expression(Token_stream& ts);

double primary_(Token_stream& ts);

double primary(Token_stream& ts) // Factorial
{
    double left = primary_(ts);
    Token t = ts.get();

    while (true) {
        if (t.kind == '!') {
            if (left < 0)
                Token_stream::error("factorial of a negative number");

            int fact = static_cast<int>(left);
            double result = 1;
            for (int i = 1; i <= fact; ++i)
                result *= i;
            left = result;

            t = ts.get();
        }
        else {
            ts.putback(t);
            break;
        }
    }

    return left;
}

double primary_(Token_stream& ts)
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // "(" Expression ")"
        {
            double d = expression(ts);
            t = ts.get();
            if (t.kind != ')')
                Token_stream::error("')' expected");
            return d;
        }
    case '{':    // "{" Expression "}"
        {
            double d = expression(ts);
            t = ts.get();
            if (t.kind != '}')
                Token_stream::error("'}' expected");
            return d;
        }
    case '-':       // Unary minus
        return -primary(ts);
    case '+':       // Unary plus
        return primary(ts);
    case Token::number:    // Number
        return t.value;
    default:
        Token_stream::error("primary expected");
    }
}

double term(Token_stream& ts)
{
    double left = primary(ts);
    Token t = ts.get();
    for (;;) {
        switch (t.kind) {
        case '%':    // Term "%" Primary
            {
                double d = primary(ts);
                if (d == 0)
                    Token_stream::error("modulo by zero");

                left = fmod(left, d);
                t = ts.get();
                break;
            }
        case '*':    // Term "*" Primary
            left *= primary(ts);
            t = ts.get();
            break;
        case '/':    // Term "/" Primary
            {
                double d = primary(ts);
                if (d == 0)
                    Token_stream::error("divide by zero");

                left /= d;
                t = ts.get();
                break;
            }
        default:    // Primary
            ts.putback(t);    // put `t' back into the Token_stream
            return left;
        }
    }
}

double expression(Token_stream& ts)
{   
/*
    char sign = ts.get().kind;
    if (sign == '+'){
        double left = term(ts) * 1; 
    }
    if (sign == '-'){
        double left = term(ts) * (-1); 
    }
*/
    double left = term(ts);        // read and evaluate a term

    Token t = ts.get();            // get next token from Token_stream
    for (;;) {
        switch (t.kind) {
        case '+':    // Expression "+" Term
            left += term(ts);    // evaluate term and add
            t = ts.get();
            break;
        case '-':    // Expression "-" Term
            left -= term(ts);    // evaluate term and subtract
            t = ts.get();
            break;
        default:    // Term
            ts.putback(t);    // put `t' back into the Token_stream
            return left;
        }
    }
}

int main(int argc, const char* const* const argv)
try {
/*
    if (argc < 2)
        return 0;

    std::string data{argv[1]};
    for (auto i = 2; i < argc; ++i) {
        data.append(1, ' ').append(argv[i]);
    }
*/

    //std::istringstream iss(data);
    std::istream& iss = std::cin;
    Token_stream ts_input(iss);

    double val = 0;
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
    case '(': case ')': case '{': case '}': case '!':
    case '+': case '-': case '*': case '/': case '%':
        return Token{ch};
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9': {
        input.putback(ch);  // put digit back into input stream

        double val;
        input >> val;
        return Token{Token::number, val};
    }
    default:
        error("Bad token");
    }
}
