#include <iostream>
using namespace std;

struct X {
    int i;
    X(int val) : i(val) {}  // Constructor with int
    X operator+(int val) { return X(i + val); }  // Overloaded + for int

    friend ostream& operator<<(ostream& os, const X& x) {
        return os << "X(" << x.i << ")";
    }
};

struct Y {
    int i;
    Y(int val) : i(val) {}  // Constructor with int
    Y(X x) : i(x.i) {}      // Conversion from X to Y

    Y operator+(X x) { return Y(i + x.i); }  // Y + X
    Y operator+(int val) { return Y(i + val); }  // Y + int

    Y operator*(int val) { return Y(i * val); }  // Y * int
    operator int() { return i; }  // Conversion from Y to int

    friend ostream& operator<<(ostream& os, const Y& y) {
        return os << "Y(" << y.i << ")";
    }
};

// Overloads for operator*
X operator*(X x, Y y) { return X(x.i * y.i); }  // X * Y
X operator*(X x1, X x2) { return X(x1.i * x2.i); }  // X * X
Y operator*(int val, Y y) { return Y(val * y.i); }  // int * Y

int f(X x) { return x.i; }  // Function f taking X

int main() {
    X x = 1;
    Y y = x;  // Converts X to Y using Y(X x) constructor
    int i = 2;

    // Print each expression result
    cout << "i + 10 = " << i + 10 << endl;
    cout << "y + 10 = " << y + 10 << endl;
    cout << "y + 10 * y = " << y + 10 * y << endl;
    cout << "x + y + i = " << x + y + i << endl;
    cout << "x * x + i = " << x * x + i << endl;
    cout << "f(7) = " << f(7) << endl;
    cout << "f(y) = " << f(X(y)) << endl;  // Convert Y to X for f()
    cout << "y + y = " << y + y << endl;
    cout << "106 + y = " << 106 + static_cast<int>(y) << endl;

    return 0;
}
