#include <iostream>
using namespace std;

class Char_vec {
    int size;
    char* element; 
public:
    static Char_vec* new_char_vec(int s); 
       Char_vec(int s) : size(s) {
        element = new char[s]; 
        for (int i = 0; i < s; ++i) {
            element[i] = 'a' + i; 
        }
    }

    ~Char_vec() {
        delete[] element; 
    }

    char& operator[](int i) {
        return element[i];
    }
};

Char_vec* Char_vec::new_char_vec(int s) {
       void* memory = operator new(sizeof(Char_vec) + s * sizeof(char));
    Char_vec* obj = new (memory) Char_vec(s);

    return obj;
}

int main() {
       Char_vec* cobj = Char_vec::new_char_vec(3);   
    for (int i = 0; i < 3; ++i) {
        cout << cobj->operator[](i) << endl;      }
    delete cobj;
    return 0;
}
