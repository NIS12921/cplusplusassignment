  #include<iostream>
  #include"revwords.h"
  #include "revwords.cpp"
  using namespace std;

 int main() {
    char ss[] = "Nur Islam Sekh University of Cambridge!";
   cout << ss << endl;
   reverse_words(ss); 
   cout << ss << endl;
   
    return 0;
}
