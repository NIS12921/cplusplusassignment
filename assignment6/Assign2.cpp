#include<iostream>
using namespace std;


struct foo{
foo(){cout << "foo()\n" ;}
~foo(){cout <<"~foo()\n";}
int i {5};
};


struct obj{
const foo& getFoo(){return my_foo;};
foo my_foo;
};


int main(){
obj *o = new obj();
const foo& val = o->getFoo();
cout << "val.i=" << val.i << std::endl;
delete o;
cout << "val.i=" << val.i << std::endl;
return 0;
}

/*
     OUTPUT
   foo()
   val.i=5
   ~foo()
   val.i=-2082420416

EXPLANATION:
CALLED "foo()" AS constructed. 
"int i {5}"--> INITALIZE "val.i=5"
"~foo()"--> AS destroyed.

ERROR LINE:
 "cout << "val.i=" << val.i << std::endl;"

   "val" is now a dangling reference, pointing to a deallocated "foo" object."val.i" results in undefined behavior and prints an invalid (random) value:
     val.i=-2082420416

*/
