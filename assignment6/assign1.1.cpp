#include <iostream>
#include <cstring>
using namespace std;

class MyVector {
    int *p; // base pointer of the vector
    unsigned int *size; // shared size of the vector
    unsigned int capacity; // capacity of allocated memory
    bool shallow; // shallow copy flag
    static int count;

public:
    // Default constructor
    MyVector() : p(nullptr), size(new unsigned int(0)), capacity(0), shallow(false) {}

    // Constructor with specified size, initializes values to 0
    MyVector(unsigned int n) : size(new unsigned int(n)), capacity(n), shallow(false) {
        p = new int[capacity]();
    }

    // Copy constructor with option for shallow or deep copy
    MyVector(MyVector &v, bool shallow_copy = true)
        : size(v.size), capacity(v.capacity), shallow(shallow_copy) {
        if (shallow_copy) {
            p = v.p;
            count++;
            cout << "Shallow copy constracter. Count: " << count << endl;
        } else {
            p = new int[capacity];
            std::copy(v.p, v.p + *size, p);
            cout << "deep copy constracter" << endl;
        }
    }

    // Accessors
    int* get_ptr() const { return p; }
    unsigned int get_size() const { return *size; }
    bool is_shallow() const { return shallow; }

    // Update element at index
    void update(unsigned int i, int val) {
        if (i < *size) p[i] = val;
    }

    // Access element at index
    int get(unsigned int i) const {
        return (i < *size) ? p[i] : 0;
    }

    // Print vector contents
    void print() const {
        for (unsigned int i = 0; i < *size; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }

    // Add element at the end, resizing if necessary
    void push_back(int val) {
        if (*size == capacity) { // Check if resizing is needed
            capacity = (capacity == 0) ? 1 : capacity * 2;
            int* new_p = new int[capacity];
            std::copy(p, p + *size, new_p);
            delete[] p;
            p = new_p;
        }
        p[*size -1] = val; // Insert value at the correct position
        (*size)++;
    }

    // Destructor with shallow copy tracking
    ~MyVector() {
        if (shallow) {
            count--;
            cout << "Shallow copy destroyed. Count: " << count << endl;
            if (count == 0) {
                delete[] p;
                cout << "Shallow copy destroyed full array" << endl;
            }
        } else {
            delete[] p;
            cout << "deep copy destroyed" << endl;
        }
    }
};

int MyVector::count = 0;

int main() {
    MyVector x(7); // Vector of size 7 initialized to 0
    for (unsigned int i = 0; i < 7; i++) x.update(i, 10 + 5 * i);

    MyVector v{x}; // Shallow copy
    MyVector w{x}; // Another shallow copy
    
    w.update(1, 400);
    w.print(); 

    v.update(1, 100);
    v.print(); // v: [10, 100, 20, 25, 30, 35, 40]
    x.print(); // x: [10, 100, 20, 25, 30, 35, 40] (also updated due to shallow copy)

    MyVector y{x, false}; // Deep copy
    y.update(1, 200);
    y.print(); // y: [10, 200, 20, 25, 30, 35, 40]
    x.print(); // x: [10, 100, 20, 25, 30, 35, 40] (remains unaffected by changes in `y`)

    y.push_back(500);
    y.print(); // y: [10, 200, 20, 25, 30, 35, 40, 500]

    v.push_back(300);
    cout << "PRINT v AFTER 300 PUSH BACK" << endl;
    v.print(); // v: [10, 100, 20, 25, 30, 35, 40, 300]

    cout << "PRINT X" << endl;
    x.print(); // x: [10, 100, 20, 25, 30, 35, 40, 300]

    cout << "PRINT w" << endl;
    w.print();

    return 0;
}
