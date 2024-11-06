#include <iostream>
#include <vector>
#include <list>

using namespace std;

class base {
    int x;
    vector<double> v;
public:
   base(int y, vector<double> z) : x{y}, v{z} {}
    int get_x() const { return x; }
    const vector<double>& get_v() const { return v; }
};

class derived : public base {
    list<bool> l;
public:
   derived(int y, vector<double> z) : base(y, z), l() {}
   derived(int y, vector<double> z, list<bool> el) : base(y, z), l(el) {}
   void print() {
        cout << "x: " << get_x() << endl;
        cout << "v: ";
        for (double val : get_v()) {
            cout << val << " ";
        }
        cout << endl; 
        cout << "list: ";
        for (bool b : l) {
            cout << (b ? "true" : "false") << " ";
        }
        cout << endl;
    }
};

int main() {
        derived d {10, {1.5, 2.5, 3.5}, {true, false}};
        d.print();
    
    return 0;
}
