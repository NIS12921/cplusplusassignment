  //Explain the output and the errors, if any.
   
   #include <iostream>
   const char* createString(){
    return "Practice makes a man perfect";
    }
  
   int* createInt(){
      int x = 100;
       return &x;
      }
     
   int main(){
       const char *str = createString();
       std::cout << "string = " << str << std::endl;
       int *ip = createInt();
       std::cout << "integer = " << *ip << std::endl;
    return 0;
    }
    
 /*  warning: address of local variable ‘x’ returned,
 
   createInt() , returns a pointer to a local variable x, which is destroyed when the function returns.
   the pointer ip in main() becomes a dangling pointer, pointing to invalid memory.
 
 */   
