//구조체 데이타 파일에 텍스트로 쓰기

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
    INSA man[5] = { 
        {"성윤정", 20, "서울"},
        {"전혜영", 30, "부산"},
        {"이은정", 24, "대구"},
        {"오경주", 34, "서울"},
        {"채제원", 25, "마산"}
    };
    ofstream fout;
    fout.open("insa.dat");

    for (int i = 0; i < 5; i++)
        fout << man[i].name << " " << man[i].age << " " << man[i].address << endl;

    fout.close();
}