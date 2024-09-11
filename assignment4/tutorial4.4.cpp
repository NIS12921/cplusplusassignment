 //The following program generates runtime error. Explain the reason(s) and rectify the program.

  int main()
 {
   char *str = "India vs Pakistan, Asia Cup 2023";
   str[7] = ’V’;
   double darr[] = {2.3, 4.5, 5.5};
  *(darr+3) = 6.5;
  extern float f;
   float g = f * 100.5;
   short int i = 89;
   void *v = &i;
  int *ip = static_cast<int*>(v);
  cout << "integer = " << *ip;
    return 0;
    }
    
    /*
      1. str[7] = 'V'; tries to modify the string "India vs Pakistan, Asia Cup 2023",
             which is a string literal stored in read_only_memory.
          if char str[] = "India vs Pakistan, Asia Cup 2023"; (make str a char array) 
           then it will modify.
           
      2. int *ip = static_cast<int*>(v); casts a void* pointer pointing to a short int to an int* pointer,
          correct casting: short int *ip = static_cast<int*>(v);
          
      3. extern float f; declares f as an external variable but it's not defined anywhere in the program. 

    */
