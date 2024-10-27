#include <iostream>
#include <cstring>

class myvector {
    int *p; // base pointer of the vector
    unsigned int size; // size of the vector
    bool shallow; // flag indicating whether this is a shallow copy of another myvector

public:
    // Create an empty vector
    myvector() : p(nullptr), size(0), shallow(false) {}

    // Create a vector of length n initialized to 0
    myvector(unsigned int n) : size(n), shallow(false) {
        p = new int[size];
        std::memset(p, 0, size * sizeof(int)); // Initialize to 0
    }

    myvector(myvector& v, bool shallow = true) : size(v.size), shallow(shallow) {
        if (shallow) {
            p = v.p; 
        } else {
            p = new int[size]; 
            std::memcpy(p, v.p, size * sizeof(int)); 
        }
    }

    // Return the base pointer to the vector
    int* get_ptr() const { return p; }

    // Return the size of the vector
    constexpr unsigned int get_size() const { return size; }

    // Return the shallow flag
    bool is_shallow() const { return shallow; }

    // Update the element at index i with val
    void update(unsigned int i, int val) {
        if (i < size) {
            p[i] = val;
        }
    }

    // Return the element at index i
    constexpr int get(unsigned int i) const {
        return (i < size) ? p[i] : 0;
    }

    // Print the vector contents in the console
    void print() const {
        for (unsigned int i = 0; i < size; ++i) {
            std::cout << p[i] << " ";
        }
        std::cout << std::endl;
    }

    // Expand the vector and insert a new value at the end
    void push_back(int val) {
        int* new_p = new int[size + 1];
        std::memcpy(new_p, p, size * sizeof(int)); 
        new_p[size] = val; 
        delete[] p; 
        p = new_p;
        ++size; 
    }

    ~myvector() {
        if (!shallow) {
            delete[] p; 
        }
    }
};

int main() {
    myvector x(7); // Create a vector of size 7 initialized to 0
    for (unsigned int i = 0; i < 7; i++)
        x.update(i, 10 + 5 * i);
    
    myvector v{x}; // Shallow copy
    v.update(1, 100);
    v.print(); 

    // Print the contents of x and verify that x has also changed on updating v
    x.print(); 

    myvector y{x, false}; // Deep copy
    y.update(1, 200);
    y.print(); 

    // Print the contents of x and verify that x has NOT changed on updating y
    x.print(); 

    // Push back 500 on y and verify
    y.push_back(500);
    y.print(); 

    return 0;
}
