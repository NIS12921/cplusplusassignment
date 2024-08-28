 #include<iostream>
 using namespace std;
 
 int count = 0;// GLOBAL VARIABLE 
 
 void display_count(void){
  count++;
  cout << "I HAVE BEEN CALLED " << count << " TIMES" << endl; }
  
  
  void display_count_static_localvari(void){
  static int count = 0;// LOCAL STATIC VARIABLE 
  count++;
  cout << "I HAVE BEEN CALLED " << count << " TIMES" << endl;}
  
  void display_count_localvari(void){
  int count = 0;// LOCAL VARIABLE 
  count++;
  cout << "I HAVE BEEN CALLED " << count << " TIMES" << endl;}
  
  
 int main(){
    cout << "IT'S FROM GLOBAL VARIABLE\n";
    for(int i = 0; i < 10; i++)
       display_count();
       
    cout << "\n\nIT'S FROM LOCAL STATIC VARIABLE\n";  
    for(int i = 0; i < 10; i++)
       display_count_static_localvari();
       cout<<"THE LOCAL STATIC VARIABLE IS MORE APPROPRIATE";
       
       cout << "\n\nIT'S FROM LOCAL VARIABLE\n";  
    for(int i = 0; i < 10; i++)
       display_count_localvari();
       cout<<"WHEN I CALL THE FUNCTION 'COUNT' VARIABLE REINITIALIZED TO 0 EVERY TIMES\n";
       
    return 0;
   }
