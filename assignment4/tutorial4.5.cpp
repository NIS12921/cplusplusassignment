#include <iostream>
using namespace std;

 void swap_int_ptr(int* a, int* b){
     int i= *a;
     *a = *b;
     *b = i;
 }
 
 void swap_int_ref(int& a, int& b){
     int i=a;
     a = b;
     b = i;
 }

int main(){
    int x, y;
   cout<<"ENTER TWO INTEGERS : " << endl;
   cin>> x >> y; 
   swap_int_ptr(&x, &y);
   cout << x <<"\t"<< y << endl;
   swap_int_ref(x, y);
    cout << x << "\t" << y << endl;
   return 0;
    }
    
