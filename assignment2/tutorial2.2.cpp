  #include<iostream>
  using namespace std;
  
  typedef int(&rifii)(int , int);
  
  /* THE ABOVE LINE MEANS IN C++ PROGRAM IS THAT DEFINES A TYPE ALIAS NAMED riffi.
    . int (&rifii): THIS IS THE TYPE BEING ALIASED AND REFERENCE TO A FUNCTION THAT RETURNS int
    .(int, int): THIS IS THE PARAMETER TAKES TWO int ARGUMENTS 
  */
  
  int add(int a, int b){
   return (a+b);
   }
   
  int main(){
     int n1, n2;
     cout << "ENTER TWO INTEGERS : "<< endl;
     cin >> n1 >> n2;
     rifii func = add;
     int result = func(n1, n2);
     cout << "RESULT : "<< result << endl;
  
   return 0;
  }
  
  /* THIS TYPE ALIAS WOULD BE GOOD FOR
       1. FUNCION POINTERS
       2. CALLBACK FUNCTIONS
       3. GENERIC PROGRAMMING
     */
