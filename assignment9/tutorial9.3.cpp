#include <iostream>
#include <fstream>
#include <bitset>

void printBitSequenceFromFile(std::string filename){
    std::fstream fhand(filename, fhand.binary | fhand.in);
    // One char is exactly one byte
    char c;
    while (fhand.read(reinterpret_cast<char*>(&c), sizeof(c))){
        if (!fhand.eof()) {
            std::cout << std::bitset<8>(c) << " ";
        }
    }
    std::cout << std::endl;
    fhand.close();
}
int main(){
    std::string filename = "data.bin";
    signed int a = -10000;
    unsigned short b = 100;
    const char c[] = "WE";
    const size_t str_size = sizeof(c);
    std::cout << "Encoding values:" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::fstream fhand;
    // trunc will clear the file
    fhand.open(filename, fhand.binary | fhand.trunc | fhand.out);
    fhand.write(reinterpret_cast<char*>(&a), sizeof(a));
    fhand.write(reinterpret_cast<char*>(&b), sizeof(b));
    fhand.write(c, str_size);
    fhand.close();
    std::cout << "Bit sequence in the file: " << std::endl;
    printBitSequenceFromFile(filename);
    signed int d;
    unsigned short e;
    char f[str_size];
    fhand.open(filename, fhand.binary | fhand.in);
    fhand.read(reinterpret_cast<char*>(&d), sizeof(d));
    fhand.read(reinterpret_cast<char*>(&e), sizeof(e));
    fhand.read(f, str_size);
    std::cout << "Decoded values:" << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << f << std::endl;
    fhand.close();
}

/*
   The provided code demonstrates binary file manipulation in C++.
   It first encodes three variables (a signed integer, an unsigned short, and a string) 
   into a binary file ("data.bin") using `std::fstream`. After encoding,
   it prints the bit sequence of the file using `printBitSequenceFromFile()`.
   Then, the code decodes the values back from the binary file into corresponding variables and 
   prints the decoded values to verify the encoding process. The `bitset` is used to display the raw binary content of the file.
*/  
