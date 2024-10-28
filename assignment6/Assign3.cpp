#include<iostream>
using namespace std;

struct X {
          X(){cout << "default constructor\n";};
          X(X&& x){ cout << "move constructor\n";};
          X(const X&x){cout << "copy constructor\n";};
          X& operator=(const X&){cout << "copy assignment\n"; return *this;};
          ~X(){cout << "Destructor\n";};
     };

X foo(X x){
      return x;
}

int main(){
         X obj;
         obj = foo(obj);
      return 0;
   }
/*
    OUTPUT

   default constructor
   copy constructor
   move constructor
   copy assignment
   Destructor
   Destructor
   Destructor

 EXPLAINATION
"X obj;" --> CALLED "X(){cout << "default constructor\n";};
 BECAUSE CREATE OBJECT NAMED "obj"

"foo(obj);"-->CALLED "X(const X&x){cout << "copy constructor\n";};
 BECAUSE obj COPY TEMPORARY OBJECT x "

"return x;"-->CALLED "X(X&& x){ cout << "move constructor\n";};
BECAUSE x MOVED TO main FUNCTION"

"obj = foo(obj);"-->CALLED "constexpr X& operator=(const X&){cout << "copy assignment\n"; return *this;};
BECAUSE TEMPORARY return OBJECT x IS ASSIGN TO AGAIN obj"

"THREE TIMES CALLED THIS LINE "~X(){cout << "Destructor\n";};" BECAUSE 
 TEMPORARY OBJECT x AND obj (IN THE MAIN FUNCTION)ARE DESTROYED AND OUT OF SCOPE"

*/
