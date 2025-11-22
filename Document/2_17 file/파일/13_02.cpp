#include <iostream>                                  
#include <fstream>                                   
using namespace std;

struct INSA {
    char name[20];
    int age;
    char address[20];
};

void main()
{
    INSA man = { "홍길동", 20, "서울" };

    ofstream fout;

    fout.open("insa.dat");

    fout << man.name << " " << man.age << " " << man.address << endl;

    fout.close();
}