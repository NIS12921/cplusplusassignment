#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    int sum = 0;
    
    ifstream myfile("filein.txt", ios::in);

    if (!myfile) 
    {
        cerr << "Unable to open file." << endl;
        return 1;
    }

    char ch;

    while (myfile.get(ch)) 
    { 
        cout << ch << endl;    
        sum += ch;            
    }

    cout << "Total Sum: " << sum << endl;
    return 0;
}
