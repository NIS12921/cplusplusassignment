#include <iostream>
#include <stdexcept>
using namespace std;

class Tiny {
    char v;
    void assign(int i){
          if(i&~077) throw Bad_range();
          v = i;
       }

public:
       class Bad_range : public std::exception {
        public:
            const char* what() const throw() {
                return "Tiny value out of range";
            }
    };

    Tiny(int i = 0) { assign(i); }

    operator int() const { return v; }

    Tiny& operator=(const Tiny& other) {
        v = other.v;
        return *this;
    }

    Tiny operator+(int i) { return Tiny(v + i); }
    Tiny operator+(int i) const {
        return Tiny(v + i);
    }



    Tiny operator-(int i) { return Tiny(v - i); }


    Tiny operator+(Tiny& t) { return Tiny(v + t.v); }

    Tiny operator-(Tiny& t) { return Tiny(v - t.v); }
};

int main() {
    try {
        Tiny c1 = 2; // Perform range check
        Tiny c2 = 62; // perform range check
        Tiny c3 = c2 - c1; // c3 = 60;
        cout<<c3<<endl;
        Tiny c4 = c3; // no range check required
        cout<<c3<<endl;

        int i = int(c1) + int(c2); // i = 64
        cout << "c1 + c2 = " << i << endl;

        c1 = c1 + c2; // range error: c1 can’t be 64
        cout << "c1 = c1 + c2 = " << c1 <<endl;


        i = int(c3) - 64; //i = -4
        cout << "c3 - 64 = " << i << endl;

        c2 = c3 - 64; // range error: c2 can’t be -4
         cout << "c2 = c3 - 64 = " << c2<<endl;

        c3 = c4; // no range check required
        cout << "c3 = c4 = " << c3 << endl;

    }catch (Tiny::Bad_range&) {
        cerr << "Range error occurred!" << endl;
    }
}
