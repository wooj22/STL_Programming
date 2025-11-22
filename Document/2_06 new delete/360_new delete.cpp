//메모리 관리와 메모리의 동적 할당  // new delete

#include <iostream>
using namespace std;

int main(void)
{
	char* pchar = new char;						//1바이트만큼 heap에 공간 할당
	*pchar = 'a';
	cout << "메모리주소 :" << (void*)pchar << "\t값 :" << *pchar << endl;   //void*로 형변환
	cout << "heap 크기: " << sizeof(*pchar) << endl;
	delete pchar;

	int* pnum = new int;						//4바이트만큼 heap에 공간 할당
	*pnum = 3;
	cout << "메모리주소 :" << pnum << "\t값 :" << *pnum << endl;
	cout << "heap 크기: " << sizeof(*pnum) << endl;
	delete pnum;

	double* pdouble{ new double };				//8바이트만큼 heap에 공간 할당
	*pdouble = 3.141592;
	cout << "메모리주소 :" << pdouble << "\t값 :" << *pdouble << endl;
	cout << "heap 크기: " << sizeof(*pdouble) << endl;
	delete pdouble;


	//new 하면서 초기화하기 //new는 초기화가 가능하다. ------------------

	int* p = new int(10);
	cout << "*p:" << *p << endl;
	delete p;

	float* pfloat = new float(75.25);				//float 로 설정해 보세요.
	cout << "*pfloat:" << *pfloat << endl;
	delete pfloat;

	int* pary1 = new int[3] {};						//배열 //0으로 초기화 
	cout << "pary1[0]:" << pary1[0] << endl;
	delete[] pary1;

	int* pary2{ new int[3] {} };					//배열 //0으로 초기화 //{} 초기화
	delete[] pary2;

	int* pary3{ new int[5] { 1, 2, 3, 4, 5 } };		//배열, 값으로 초기화
	delete[] pary3;

	char* pary4 = new char[20] { "Hello World!" };	//문자열
	cout << "pary3:" << pary4 << endl;
	delete[] pary4;

	int num = 6;												//변수로 할당할 값 설정 가능 ***
	auto* pary5{ new float[num] { 1.1, 2.2, 3.1, 4.1 } };		//auto* - float*
	for (int i = 0; i < num; i++)
		cout << "pary5[" << i << "]:\t" << pary5[i] << "  ";
	cout << endl;
	delete[] pary5;

	return 0;
}

/*

new 의 동작 방식 ***
	1. operator new()를 이용하여 메모리 할당
	2. 생성자 호출
	3. 메모리 주소를 해당 타입으로 반환

delete 의 동작 방식
	1. 소멸자 호출
	2. operator delete()를 이용하여 메모리 해지


//------------------------------------------------------------------------
C++에는 C언어의 malloc free 함수이외에 new delete 연산자가 하나 더 있다.
	둘다 사용이 가능하지만 C++ 연산자가 더 쉽고 간단하기 때문에 더 많이 사용된다.
	특히 '클래스'의 경우는 반드시 new delete 연산자를 사용해야 한다. ***

	int *p = (int *)malloc(sizeof(int));
	int *p = new int;
	//주소를 저장할 포인터 = new 할당하고 싶은 크기의 자료형;

배열을 사용하여 동일한 크기의 메모리를 동적 메모리를 할당 하려면, 아래의 방법처럼 해주면 된다.

	int *p = (int *)malloc(sizeof(int)*10);		// int[10]
	int *p = new int[10];

C언어에서 free를 해주 듯 new 연산자에서도 delete 연산자가 있다.
표현 방법은 아래와 같다.

	free(p);
	delete p;

// new delete 배열 사용 ------------------------------------------------

하지만 delete연산자에서는 주의해야 할 점이 있는데,
new 연산자와 같은 형태로 해제를 해 주어야 한다는 것이다. ***

	int *p = new int;
	delete p;

	int *p = new int[10];
	delete[] p;				// 배열은 배열로 해제

*/
