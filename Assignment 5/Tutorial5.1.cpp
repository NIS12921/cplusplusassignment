#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

class Expr {
private:
    string expr;
    size_t i;
    int Expression();
    int Term();
    int Factor();
    void skipWhitespace();
public:
    Expr(const char* e) : expr(e), i(0) {}
    int eval();
    void print();
};

void Expr::print() {
    cout << expr << endl;
}

void Expr::skipWhitespace() {
    while (i < expr.size() && isspace(expr[i])) {
        i++;
    }
}

int Expr::eval() {
    i = 0;
    return Expression();
}

int Expr::Expression() {
    int result = Term();
    while (i < expr.size()) {
        skipWhitespace();
        if (i < expr.size() && (expr[i] == '+' || expr[i] == '-')) {
            char op = expr[i++];
            skipWhitespace();
            int right = Term();
            result = (op == '+') ? result + right : result - right;
        } else {
            break;
        }
    }
    return result;
}

int Expr::Term() {
    int result = Factor();
    while (i < expr.size()) {
        skipWhitespace();
        if (i < expr.size() && (expr[i] == '*' || expr[i] == '/')) {
            char op = expr[i++];
            skipWhitespace();
            int right = Factor();
            if (op == '/') {
                if (right == 0) {
                    throw std::runtime_error("Division by zero error");
                }
                result = result / right;
            } else {
                result = result * right;
            }
        } else {
            break;
        }
    }
    return result;
}

int Expr::Factor() {
    int value = 0;
    skipWhitespace();
    while (i < expr.size() && isdigit(expr[i])) {
        value = value * 10 + (expr[i] - '0');
        i++;
    }
    return value;
}

int main() {
    try {
        Expr x("8 / 4 +3 * 4 - 3 ");
        cout << "x = " << x.eval() << endl;
        x.print();
    } catch (const std::runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
