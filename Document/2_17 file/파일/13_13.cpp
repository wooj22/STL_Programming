//구조체 데이타 파일 바이너리로 읽기

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

    fin.open("..\\13_12\\insa.bin");

    if (fin.fail()) {
        printf("Error: file open error\n");
        return;
    }

    cout << " >> 파일에서 읽어온 데이터 << \n";
    cout << "-----------------------------------\n";
    cout << " 이름 나이 주소 \n";
    cout << "-----------------------------------\n";
    while (fin.read((char*)&man, sizeof(man)))
        cout << man.name << " " << man.age << " " << man.address << endl;

    fin.close();
}