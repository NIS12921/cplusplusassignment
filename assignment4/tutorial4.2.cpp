 //Explain the output of this program.
  
  #include <iostream>
    
    int main(){
      const char* str1 = "We love C++ programming\n";
      char str2[100];
      char *p = str2;/*name of an array is implicitly converted
                       to pointer to the first element.*/
      while(*p++ = *str1++){}
      std::cout << str2;
   }
   
   /*
     OUTPUT:
           We love C++ programming
   */
