//C++의 네가지 타입변환 연산자 
//	    satic_cast, dynamic_cast, reinterpret_cast, const_cast

//reinterpret_cast<new_type>(expression)
//		임의의 포인터 타입끼리 변환을 허용하는 캐스트 연산자
//		정수형을 포인터로 바꿀 수도 있습니다
//      expression에 해당하는 것을 new_type으로 비트단위로 바꾸는 것

#include <iostream>
using namespace std;

int main(void)
{
    int a = 0x0102;

    //1. int -> int * 로 타입캐스팅
    //      변수 a의 값을 절대주소로 받는 포인터 ptr1
    //      이 경우에는 주소 ooo번지를 가리키고 있는 poiner가 됩니다. 
    //      어느 곳을 가리킬지 모르기 때문에 위험합니다.
    int* ptr1;
    ptr1 = reinterpret_cast<int*>(a);


    //2. int * -> char * 로 타입캐스팅
    //      컴파일러에 따라 다르게 나옵니다.
    int* ptr2 = &a;
    char* c;
    c = reinterpret_cast<char*>(ptr2);
    cout << "2. int* -> char * (cout) : " << *c << endl;
    printf("2. int* -> char * (printf int type) : %d\n", *c);


    //3. struct 내의 첫번째 int -> int *
    //      struct cube에는 int 형 변수 하나만 존재하므로, 
    //      ptr3은 int a변수의 시작점을 잘 가리키고 있습니다.
    struct Cube { int a; };
    Cube cb;
    cb.a = 20;

    int* ptr3;
    ptr3 = reinterpret_cast<int*>(&cb);
    cout << "3. struct -> int * : " << *ptr3 << endl;

    return 0;
}

/*
 //명시적 형 변환 ------------------------------

#include <iostream>

int main()
{
    int *int_ptr = new int(10);
    std::cout << *int_ptr << std::endl;

    char *char_ptr;
    char_ptr = reinterpret_cast<char*>(int_ptr);

    *char_ptr = 20;         // int_ptr 의 값을 변경

    std::cout << *int_ptr << std::endl;

    return 0;
}


// const 지정자 사용 시, 명시적 형 변환 ----------------------------

#include <iostream>

int main()
{
    const int *int_ptr = new int(10);           //const
    std::cout << *int_ptr << std::endl;

    char *char_ptr;
    char_ptr = reinterpret_cast<char*>(const_cast<int*>(int_ptr));  //const_cast<>
    *char_ptr = 20;     // int_ptr 의 값을 변경

    std::cout << *int_ptr << std::endl;

    return 0;
}
*/