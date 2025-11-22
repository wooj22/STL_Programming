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
    INSA man;

    ifstream fin;

    // fin.open("insa.dat");                              
    // fin.open("..\\13_02\\insa.dat");                
    fin.open("C:\\Work\\CookBook\\13_02\\insa.dat");

    if (fin.fail()) {
        cout << "파일 오픈에 실패했습니다." << endl;
        return;
    }

    fin >> man.name >> man.age >> man.address;

    cout << man.name << " " << man.age << " " << man.address << endl;

    fin.close();
}