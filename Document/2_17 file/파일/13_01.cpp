#include <iostream>                                  
using namespace std;

struct INSA {
    char name[20];
    int age;
    char address[20];
};

void main()
{
    INSA man = { "홍길동", 20, "서울" };

    cout << man.name << " " << man.age << " " << man.address << endl;
}