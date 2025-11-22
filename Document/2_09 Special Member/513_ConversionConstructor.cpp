// 변환 생성자 ( Conversion Constructor ) - 매개변수 1개인 생성자
//		이름없는 임시객체가 생길 수 있다.
//		변환 함수(허용된 변환)과 혼동할 우려.  

// 변환 함수 ( Conversion Function ), 변환 연산자(Conversion operator) 
//		C++ 연산자 함수의 특별한 형태이다. 사용자 정의 강제 데이터형 변환 기능을 구현하는 수단.
//		operator 타입() { }
//		dataType variables = objectName;  과 같은 구문을 가능하게 만든다.
// 
//		변환 생성자는 일반 타입에서 클래스의 객체를 생성하는 역할을 하지만
//		변환 연산자는 반대로 객체에서 일반 타입 값을 받을 수 있습니다.

#include <iostream>
using namespace std;

class CTest {
private:
    int age;
public:
    CTest(int p_age)        // 변환 생성자
    {
        age = p_age;
    }
    operator int()          // 변환 함수 // 변환 연산자 // 허용된 변환
    {
        return age;
    }
};

int main(void) {
    CTest obj = 11;         //변환 생성
    int age = obj;          //int로 형 변환
    return 0;
}

// 변환 생성, 변환 연산 // 복사 생성, 복사 대입 연산 ----------------------------------------------

#include <iostream>
using namespace std;

class CMyData
{
private:
	int m_nData = 0;
public:
/*
    //변환 생성자
	CMyData(int nParam) : m_nData(nParam) {	}
	//복사 생성자
	CMyData(const CMyData& rhs) : m_nData(rhs.m_nData) { }
	//이동 생성자
	CMyData(CMyData&& rhs) noexcept : m_nData(rhs.m_nData) { }
    //복사 대입 연산
	CMyData& operator=(const CMyData& rhs) : m_nData(rhs.m_nData) {	return *this; }
    //변환 함수 //형식 변환 허용
    operator int() { return m_nData; }
*/
};

// 아래 코드를 지원하는 함수를 작성하세요. 
int main()
{
	CMyData obj = 1;
	CMyData obj2 = obj;
	obj2 = obj;
	int n = obj;

	return 0;
}



//explicit -------------------------------------------------------------
// 
//		형변환을 명시적으로 하도록 한다.
//		explicit로 선언하면 CTest obj = 3; 과 같은 형태로 객체 생성 불가

class CTest {
private:
    int age;
public:
    explicit CTest(int p_age)        // 변환 생성자
    {
        age = p_age;
    }
    explicit operator int()          // 변환 함수
    {
        return age;
    }
};

int main()
{
    CTest a = 1;            //error

    CTest a = CTest(1);     //ok

    int n = CTest(1);       //error

    n = (int)a;             //ok
    n = int(a);

    return 0;
}


/*

// Ex. 변환 함수 정의 예시

CTest::operator int () const {      // CTest는 사용자 정의 클래스이다.
	return int (a + 1);             // a 는 CTest 클래스의 데이터 멤버이다.
}

// Ex. 암시적 데이터형 변환을 불허하는 변환 함수 원형의 일반형

explicit operator dataType() const;


// Ex. 변환 함수의 명시적/암시적 사용 예시

// 암시적 호출 방법
dataType variables = objectName;

// 명시적 호출 방법
dataType variables = dataType(objectName);
dataType variables = (dataType)objectName;

*/