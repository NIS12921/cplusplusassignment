#include<iostream>
int main(){
  char vowel1,vowel2,vowel3,vowel4,vowel5,capvowel1,capvowel2,capvowel3,capvowel4,capvowel5;
  std::cout<<"ENTER VOWELS ARE IN SMALL LETTERS : \n";
  std::cin>>vowel1>>vowel2>>vowel3>>vowel4>>vowel5;
  float a, b, A, B;
  a=vowel1-vowel2; 
  b=vowel5-vowel2;
  std::cout<<"\nTHE capvowel2-capvowel1 IS: "<< a;
  std::cout<<"\nTHE capvowel5-capvowel2 IS: "<< b;
  std::cout<<"\nENTER VOWELS ARE IN CAPITAL LETTERS : \n";
  std::cin>>capvowel1>>capvowel2>>capvowel3>>capvowel4>>capvowel5;
  A=vowel1-vowel2;
  B=vowel5-vowel2;
  std::cout<<"\nTHE capvowel2-capvowel1 IS: "<< A;
  std::cout<<"\nTHE capvowel5-capvowel2 IS: "<< B;
  std::cout<<"\n2ND PART OF THE QUESTION\n";
  float x, y, ch_x;
  std:: cout<<"ENTER Y = ";
  std :: cin>> y;
  x=y-20*6/9; 
  std::cout<<"\nTHE REQRIED X = "<<x;
  ch_x=y-20*6/9.0;
  std::cout<<"\nTHE REQRIED EXPECTED X = "<<ch_x;
  std::cout<<"\n";
  return 0;
  }
/*THOUGH ASCII VALUES FOR SMALL && CAPITAL VOWELS ARE DIFFERENT BUT THE DIFFERENCE REMAIN SAME  
HARE '20','6' AND '9' BOTH ARE INTEGER AND '20*6/9'=13.33333(EXPECTED VALUE) 
BUT 13.333 IS NOT INTEGER SO INTEGER VALUE OF 13.3333 IS 13 */
  
  

