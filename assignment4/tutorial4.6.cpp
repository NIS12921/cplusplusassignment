  #include<iostream>
  
  struct Month {
      const char* name;
      int days;
  };
  
  int main(){
        Month months[] = {
        {"JANUARY", 31}, {"FEBRUARY", 28}, {"MARCH", 31}, {"APRIL", 30}, {"MAY", 31}, {"JUNE", 30}, {"JULY", 31},
        {"AUGUST", 31}, {"SEPTEMBER", 30}, {"OCTOBER", 31}, {"NOVEMBER", 30}, {"DECEMBER", 31} };
        
    std::cout << "Month\tDays\n";
         for(int i =0; i < 12; i++)
    std :: cout << months[i].name << "\t" << months[i].days << "\n";     
              
  return 0;
  }
