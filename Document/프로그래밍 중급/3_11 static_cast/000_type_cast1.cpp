//C++의 네가지 타입변환 연산자 
//	    static_cast
//      dynamic_cast
//      reinterpret_cast
//      const_cast

//static_cast<new_type>( expression )
// 
//		compile 타임에 형변환에 대한 타입을 변환.
//		논리적으로 변환 가능한 타입을 변환한다. ***
// 
//      실수와 정수, 열거형과 정수형, 실수와 실수 사이의 변환 등을 허용한다.
//      array -> pointer 로 변경 가능합니다.
//      function -> function pointer 로 변경 가능합니다.
// 
//      포인터 타입을 다른 것으로 변환 하는 것을 허용하지 않습니다. (compile error)
//      그러나, 상속 관계에 있는 포인터 끼리 변환이 가능합니다.
//      downcast(static_cast<자식클래스>(부모클래스))시에는 unsafe 하게 동작할 수 있습니다. 
//      (safe 하게 사용하려면 dynamic_cast사용)


#include <iostream>
using namespace std;

int main(void)
{
    // 일반 변수 타입간 --------------------------------------------------

    double d = 13.24;
    float f = 10.12f;

    int tmp_int; 
    tmp_int = (int)d;		            //double -> int 로 형변환
    tmp_int = static_cast<int>(d);		//double -> int 로 형변환
    cout << tmp_int << endl;

    float tmp_float;
    tmp_float = static_cast<float>(d);	//double -> float 로 

    //double tmp_double;
    //tmp_double = static_cast<double>(f); //float -> double 로 형변환 해보세요


    //배열, 포인터 타입 --------------------------------------------------

    //1. array -> pointer
    int arr[10] = { 11,13,15,17,19,21,23,25,27,29 };
    int* ptr = static_cast<int*>(arr);
    cout << "1. int array -> int* : ";
    for (int i = 0; i < 10; i++) {
        cout << ptr[i] << " ";
    }
    printf("\n");

    //2. char* -> int*
    char str[] = "Hello World";
    int* ptr2;
    ptr2 = static_cast<int*>(str); //Compile error

    //3. int* -> char*
    int tmp = 10;
    int* ptr3 = &tmp;
    char* c = static_cast<char*>(ptr3); //Compile error


	return 0;
}


//열거형(enum) static_cast --------------------------------------------------

#include <iostream>
using namespace std;

enum E_VAL {A=11, B, C};

int main(void)
{
    E_VAL e = A;
    cout << "E_VAL : " << e << endl;

    int a;
    a = static_cast<int>(e);        // enum -> int
    cout << "1. static_cast<int>(enum) : " << a << endl;

    int b;
    b = static_cast<int>(B);
    cout << "2. static_cast<int>(enum) : " << b << endl;

    E_VAL e2;
    e2 = static_cast<E_VAL>(13);    //int ->  enum
    cout << "3. static_cast<enum>(int) : " << e2 << endl;

    return 0;
}


//상속관계에서의 static_cast --------------------------------------------------
//      업캐스팅만 정상 허용

#include<iostream>
#include<cstdio>
using namespace std;

class shape {
private:
    int a;
public:
    virtual void draw() { cout << "shape : called draw()" << endl; }
};

class triangle : public shape {
private:
    int b;
public:
    triangle() { b = 30; }
    void draw() { cout << "triangle : called draw()" << endl; }

    void onlyTriangle() {
        cout << "onlyTriangle()" << endl;
        cout << b << endl;
    }
};

int main(void)
{
    //1.upcast
    shape* ps;
    triangle t;
    ps = static_cast<shape*>(&t);       // 자식 -> 부모
    cout << "1. upcast \n";
    ps->draw();

    //2.downcast
    shape s;
    triangle* pt;
    cout << "2. downcast \n";
    pt = static_cast<triangle*>(&s);    //부모 -> 자식
    pt->draw();
    pt->onlyTriangle();

    //허용은 된다. but, 자식 클래스의 멤버 함수를 부르면 예상값과 다르게 나온다.
    //부모 인스턴스가 자식 멤버함수를 부르는 것이 비 정상적인 결과를 초래할 수 있다 ***

}

// 타입변환 연산자를 쓰는 이유 ----------------------------------------------

//C언어의 형 변환 연산자는 
//  다음과 같이 정말 일반적이지 않는 형 변환도 허용하기 때문에 
//  static_cast 연산자의 사용을 권한다.
{
    const int num = 10;
    int* ptr = (int*)&num;
    *ptr = 30;                  // const int 가 변해버림
    cout << *ptr << endl;
}

//C스타일의 캐스팅은 C++의 캐스팅 연산자 4개 중 하나를 한다.
/*
    #include <iostream>
    using namespace std;
    class Test
    {
    public:
        int m_test = 10;
    };

    int main()
    {
        int a = 5;
        long long b = a;        // 묵시적 형변환. 컴파일러가 형을 변환해준다.
                                // -> 형변환이 허용되며 프로그래머가 명시적으로 형변환을 안한 경우.

        Test* t = (Test*)&a;    // 명시적 형변환. 프로그래머가 형변환을 위한 코드를 직접 작성.
        cout << t->m_test << endl;

        return 0;
    }
*/
// -> 어떤 형변환인지 명확하지 않다. (형변환의 의도를 구별하기 힘들다)
// -> 명백한 실수를 컴파일러가 캐치하지 못할 수도 있다.

//그렇기에 좀 더 안전하고, 사용자의 의도를 명확히 하기 위해, C++ 스타일의 형변환을 사용한다.

/*
    int a = 5;
    long long b = static_cast<long long>(a);    //의도를 명확히

    //int* -> Test*
    Test* t = reinterpret_cast<Test*>(&a);      //의도를 명확히
    cout << t->m_test << endl;
*/