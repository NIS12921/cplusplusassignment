#include <iostream>
#include <cstring>
#include <cstdlib>

 
using cmpf = int(const void *x, const void *y);
  struct user{
  const char* name;
  const char* id;
  int dept;
  };
  
  user b[] = {
      {"Ritchie D.M.", "dmr", 11271},
      {"Sethi R.", "ravi", 11272},
       {"Szymanski T.G.", "tgs", 11273},
    { "Schryer N.L.", "nls", 11274},
    {"Kernighan B.W.", "bwk", 11275},
  };

 int cmpInt(const void *x, const void *y){
      int *a = (int*) x;
      int *b = (int*) y;  
      return *a - *b ;
      }
      
/* A comparison function for two users based on their name */

    int cmpUserName(const void *x, const void *y){
              user *a = (user*) x;
              user *b = (user*) y;
              return strcmp(a-> name , b-> name);
       }
       
/* A comparison function for two users based on their dept */
    
      int cmpUserDept(const void *x, const void *y){
              user *a = (user*) x;
              user *b = (user*) y;
              return a->dept - b->dept;
           }
/* A parameterized sorting algorithm to sort array of various types of object.
* a: base address of the array to be sorted
* n: number of elements in a
* elem_size : the size of an object in the array
* cmp: the function pointer that compares two objects of the array.
*/

   void sort(void *a, unsigned int n, unsigned int elem_size, cmpf cmp){
   for(unsigned int i=0;i<n-1;i++){
         char *base = static_cast<char*>(a);
         char *small = static_cast<char*>(base + i*elem_size); // &a[i]
         unsigned int indx = i;
      for(unsigned int j=i+1;j<n;j++){
       char *x = static_cast<char*>(base + j*elem_size); // &a[j]
       if(cmp(x,small) < 0){
         small = x;
         indx = j; }
     }
// swap a[i] with a[indx]

    char *small_copy = new char[elem_size];
   std::memcpy(small_copy,small,elem_size);
   
//copy a[i] into a[indx]

      char *ai = static_cast<char*>(base + i*elem_size); // &a[i]
      std::memcpy(small,ai,elem_size); //copy a[] into a[i]
      std::memcpy(ai,small_copy,elem_size);}
    }
    
    void print(int a[], int n){
        for(unsigned int i=0;i<n;i++)
             std::cout << a[i] << " " ;
             std::cout << std::endl; }
             
    void print_user(user a[], int n){
       for(unsigned int i=0;i<n;i++)
          std::cout << a[i].name << " " ;
      std::cout << std::endl; }
      
      
   int main(){
       int a[] {5, 1, 2, 7, 6, 4, 3, 9, 0, 8};
       
/*sort an array of integers */

     sort(a, 10, sizeof(int), cmpInt);
     print(a,10); // print the sorted array
     
/*sort an array of users based on their name */

     sort(b, 5, sizeof(user), cmpUserName);
     print_user(b,5); 
     
/*sort an array of users based on their dept */

    sort(b, 5, sizeof(user), cmpUserDept);
    print_user(b,5);
    
   return 0; }
   
   /* 
       OUTPUT
       
       0 1 2 3 4 5 6 7 8 9 
       Kernighan B.W. Ritchie D.M. Schryer N.L. Sethi R. Szymanski T.G. 
       Ritchie D.M. Sethi R. Szymanski T.G. Schryer N.L. Kernighan B.W. 
    */



