 #include <iostream>
  
  int main(){
  
     // POINTER TO A CHARACTER
     char *ptr_character = NULL;
     
     //ARRAY OF 10 INEGERS
     int arr_integer[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     
     //REFERENCE TO AN ARRAY OF 10 INTEGERS
       int (&ref_arr_int) = arr_integer;
       
     //POINTER TO AN ARRAY OF CHARACTER STRINGS
       char *ptr_arr_str[5] = {"hello", "my", "name", "is", "NUR"};
       
     //POINTER TO A POINTER TO A CHARACTER
       char **ptr_ptr_char = &ptr_character;
       
     //CONSTANT INTEGER
       const int n = 6;
       
     //POINTER TO A CONSTANT INTEGER
       const int *ptr_const_int = &n;
       
     //CONSTANT POINTER TO AN INTEGER
        int *const const_ptr_int = new int(10);
        
      //CONSTANT POINTER TO A CONSTANT DOUBLE
        const double *const const_ptr_const_double = new double(5.55);          
  
  
  return 0;
  }
