 /*
  struct S{
  S(const char*){};
  S(double*){};
 };
 
Which C++ statement(s) will result in an ambiguous overload resolution and why?

  a. S s1 {"hello"};
 THIS IS NOT AMBIGUOUS OVERLOAD .
 HERE CALL THE STRUCT MEMBER S(const char*){}; AS "hello" IS CONST CHARECTER.

  b. S s1 {new double(1.5)};
  THIS IS NOT AMBIGUOUS OVERLOAD .
   HERE CALL THE STRUCT MEMBER S(double*){}; AS new double(1.5) IS CONSIDER AS DOUBLE POINTER TYPE.
    
  c. S s1 {nullptr};
  THIS IS AMBIGUOUS OVERLOAD.
  HARE nullptr CONVERT BOTH CONST CHAR POINTER AND DOUBLE POINTER.
   
  RESOLVE IT IN THIS WAY USING STATIC CAST NULLPTR TO CONST CHAR POINTER OR DOUBLE POINTER CLEARLY MENTION.
  
  d. S s1 {(char*)nullptr};
  THIS IS NOT AMBIGUOUS OVERLOAD .
  HERE CALL THE STRUCT MEMBER S(const char*){}; AS CHAR POINTER IS CONSIDER AS CONST CHARECTER.
  */
  
  

