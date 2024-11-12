#include <iostream>
#include <fstream>

using namespace std;

int  main(int argc, char *argv[ ])
{

     ifstream myfile("filein.txt",ios::in);
      
     if (!myfile) 
     {
        cerr << "Unable to open file." << endl;
        return 1;
     }

     ofstream outfile("fileout.txt", ios::out);
     string line;
     
    while( getline(myfile, line))
    { 
      outfile << line <<endl;
    }   

        return 0;
}
