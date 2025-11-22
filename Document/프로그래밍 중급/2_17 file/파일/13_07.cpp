#include <iostream>                        
#include <fstream>                         
using namespace std;

void main(int argc, char* argv[])
{
    cout << "\n 문자열의 수 => " << argc << "\n";

    for (int i = 0; i < argc; i++)
        cout << " argv[" << i << "]=" << argv[i] << "\n";
}