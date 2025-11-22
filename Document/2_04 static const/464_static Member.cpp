//정적 맴버 변수
//		객체 별로 할당되지 않고 클래스의 모든 객체가 '공유'하는 멤버를 의미한다.
//		멤버 변수가 정적(static)으로 선언되면, 
//      해당 클래스의 모든 객체에 대해 '하나'의 데이터만이 유지 관리
//		정적 멤버 변수는 클래스 영역에서 선언되지만, 정의는 파일 영역에서 수행한다.

//정적 멤버 함수(static member function)
//		C++에서는 클래스의 멤버 함수도 정적(static)으로 선언할 수 있습니다.
//		이렇게 선언된 정적 멤버 함수는 해당 클래스의 객체를 생성하지 않고도, 
//      클래스 이름만으로 호출할 수 있습니다.
// 
//		1. 객체를 생성하지 않고 클래스 이름만으로 호출할 수 있습니다.
//		2. 객체를 생성하지 않으므로, this 포인터를 가지지 않습니다.
//		3. 특정 객체와 결합하지 않으므로, 정적 멤버 변수밖에 사용할 수 없습니다. ***

#include <iostream>
using namespace std;

class CTest
{
	static int g_count;		//static 맴버 변수
public:
	CTest()
	{
		g_count++;
		cout << g_count << "번째 CTest 객체" << endl;
	}
	static void func() { }	//static 맴버 함수
};

int CTest::g_count = 0;		//static 변수의 초기화 ***

//static 변수는 객체 별로 존재하는 변수가 아닌, 프로그램 전체 영역에서 하나만 존재하는 변수



//public static 변수 -------------------------------------------------------------

#include <iostream>
using namespace std;

class CTest
{
public:
	static int g_count;		//접근 허용
public:
	CTest()
	{
		g_count++;
	}
};
int CTest::g_count = 0;		//static 변수의 초기화

int main(void)
{
	cout << CTest::g_count << "번째 객체" << endl;
	CTest sim1;
	CTest sim2;

	cout << CTest::g_count << "번째 객체" << endl;	//클래스이름으로 접근
	cout << sim1.g_count << "번째 객체" << endl;		//객체이름으로 접근 ( 객체맴버가 아님 )
	cout << sim2.g_count << "번째 객체" << endl;		//객체이름으로 접근

	return 0;
}

// private static 변수 --------------------------------------------------------------

#include <iostream>
using namespace std;

class CItem
{
private:
	static int objCount;		//CItem 클래스에서 사용, 모든 객체에서 공유.
public:
	CItem()
	{
		objCount++;
		cout << objCount << "번째 객체" << endl;
	}
	CItem(const CItem& copy)
	{
		objCount++;
		cout << objCount << "번째 객체" << endl;
	}
	//static void print() { cout << "count: " << objCount << endl; }
};
int CItem::objCount = 0;		//전역 초기화

int main(void)
{
	CItem sim1;
	CItem sim2;

	CItem cmx1;			//objCount 로 카운팅
	CItem cmx2 = cmx1;
	CItem();

	cout << "count: " << CItem::objCount << endl;		//error //private

	//문제) objCount 를 출력하는 함수를 만들어 호출하세요.
	//	CItem::print();

	return 0;
}
