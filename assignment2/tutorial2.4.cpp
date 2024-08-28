 #include<iostream>
 using namespace std;
  // void func(char = '*' , int = 45);
  /* NO IT'S NOT A VALID DECLARATION OF A FUNCTION
  IF I DECLARE IN THIS WAY THEN THE COMPILER RAISE AN ERROR*/
  void func(char c='*', int n = 45){
    cout<<"====> THIS IS A VALID DECLARATION OF A FUNCTION\n";
    cout<<"\tvoid func(char c = '*' , int n = 45);\n";
  }
  
 int main(){
    char c ='*';
    int n= 45;
    cout<<"\tvoid func(char = '*' , int = 45);\n";
    cout<<"====> NO IT'S NOT A VALID DECLARATION OF A FUNCTION\n";
    func(c, n);
 return 0;
 }
