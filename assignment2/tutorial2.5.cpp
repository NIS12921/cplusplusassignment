#include <iostream> 
using namespace std;
void f1(int m[][5],int dim1){ 
for(unsigned int i=0;i<dim1;i++) 
for(unsigned int j=0;j<5;j++) 
m[i][j] = m[i][j]+2; 
} 
int main(){ 
// initialize a 2d array. 
int m[3][5] {{1,2,3,4,5},{11,12,13,14,15}, {21,22,23,34,25}}; 
f1(m,3); 
for(unsigned int i=0;i<3;i++){ 
for(unsigned int j=0;j<5;j++) 
cout << m[i][j] << " "; 
cout << "\n"; } 
return 0;
}
/*
   EXPLANATION :
   OUTPUT WILL BE 3*5 MATRIX
   I.E. 
       3  4  5  6  7
       13 14 15 16 17
       23 24 25 26 27
       
    IN 2D ARRAY 1ST DIMENSION IS NOT REQUIRED BUT 2ND DIMENSION (5) IS MUST REQUIRED
    OTHERWISE COMPILER WILL THROW AN ERROR.
    
    'YES', IT IS VALID WAY TO PASS 2D ARRAY.
    BECAUSE : 
           1. THE FUNCTION ONLY NEEDS TO KHON THE COLUMNS NUMBER(2ND DIMENSION) TO ACCESS ELEMENTS.
           2. THE FUNCTION CAN ITERATE OVER THE ROWS
           
     
   */

