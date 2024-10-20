
#include<iostream>
int main()
{
  int x,y,d,w;
  std::cout<<"ENTER DAYS ARE : ";
  std::cin>>x;
  y=x/365;
  x=x%365;
  w=x/7;
  d=d%7;
  std::cout<<" years: "<<y<< " weeks: "<< w <<" days: "<<d<< "\n";
  return 0; 
}

