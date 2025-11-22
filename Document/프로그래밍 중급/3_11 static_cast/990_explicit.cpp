#include <iostream>

class A 
{
public:
    int num;
    explicit A(int n) : num(n) {};    //명시적 형변환
};

void printA(A a) {
    std::cout << a.num << std::endl;
}

int main() 
{
    int n = 26;
    printA(n);      // int -> A
}