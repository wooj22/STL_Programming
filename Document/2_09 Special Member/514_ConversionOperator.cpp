// 변환 생성자 ( Conversion Constructor ) - 매개변수 1개인 생성자
//		이름없는 임시객체가 생길 수 있다.
//		변환 함수(허용된 변환)과 혼동할 우려.  

// 변환 함수 ( Conversion Function ), 변환 연산자(Conversion operator) 
//		C++ 연산자 함수의 특별한 형태이다. 사용자 정의 강제 데이터형 변환 기능을 구현하는 수단.
//		operator 타입() { }
//		dataType variables = objectName;  과 같은 구문을 가능하게 만든다.
// 
//		변환 생성자와 반대되는 개념
//		변환 생성자는 일반 타입에서 클래스의 객체를 생성하는 역할을 하지만
//		변환 연산자는 반대로 객체에서 일반 타입 값을 받을 수 있습니다.

//explicit
//		형변환을 명시적으로 하도록 한다.
//		explicit로 선언하면 CTest obj = 3; 과 같은 형태로 객체 생성 불가


#include <iostream>
#include <cstring>
using namespace std;

#include <iostream>
class Person {
private:
    int age;
public:
    Person(int p_age)   //
    {
        age = p_age;
    }

    operator int()      //
    {
        return age;
    }
};
int main(void) {
    Person per1 = 11;
    int age = per1;         //가능
    return 0;
}

//변환 함수의 모호함
//  객체에서 변환 함수가 여러 개가 정의되어 있고 
//  그것을 cout 같은 여러 가지 자료형을 지원하는 것에서 변환 함수의 모호함이 발생합니다.

#include <iostream>
class Person {
private:
    int age;
public:
    Person(int p_age) {
        age = p_age;
    }
    operator int() { return age; }              //변환 함수가 여러 개
    operator double() { return double(age); }   //변환 함수가 여러 개
    operator long() { return long(age); }       //변환 함수가 여러 개
};
int main(void) {
    Person per1 = 11;
    std::cout << per1;                          //컴파일 에러
    return 0;
}

//이럴 때는 명시적 형변환을 사용해야 합니다. 
//  explicit

#include <iostream>
class Person {
private:
    int age;
public:
    Person(int p_age) {
        age = p_age;
    }
    explicit operator int() { return age; }
    explicit operator double() { return double(age); }
    explicit operator long() { return long(age); }
};
int main(void) {
    Person per1 = 11;
    int a = per1;               //컴파일 에러
    std::cout << int(per1);     //문제없음
    return 0;
}

//C++에서의 제한
//프로그래머가 코드 작성 방식에 제한을 걸 수 있는 다양한 방법들이 C++에 존재한다.
//
//이를테면 암시적 형변환을 차단하는 explicit, 
//데이터를 변경시킬 권한이 있는 멤버 함수의 사용을 제한하는 const, 
//그 밖에도 여러가지가 있다.
// 
//이렇게 많은 제한들이 존재하는 이유는, 
//실행 시에 일어나는 에러보다도 컴파일 단계에서 일어나는 에러가 여러모로 낫기 때문이다.