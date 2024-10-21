  #include<iostream>
  using namespace std;
  
    class fraction{
    
     public:
     
/* necessary constructors and member functions*/
    
    constexpr fraction sum(int n=0, int d=1) : num(n), denom(d){}
    
    constexpr int get_num() const { 
          return num;
       }
       
     constexpr int get_denom() const { 
          return denom;
       }
       
   private:
           int num;
           int denom;
  };
  
  
/* Returns the sum of two fractions */


constexpr fraction sum(const fraction& a, const fraction& b){
        int new_num = a.num * b.denom + b.num * a.denom;
        int new_denom = a.denom * b.denom ;
        int gcd = _gcd(new_num, new_denom);
      return fraction(new_num / gcd , new_denom / gcd);
   }
   
   
   int main(){
      constexpr fraction f = sum(20,fraction(10,20));
      cout << "f.num = " << f.get_num() << " ";
      cout << "f.denom = " << f.get_denom() << " ";
     return 0;
    }
