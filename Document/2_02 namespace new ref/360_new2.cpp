//메모리 관리와 메모리의 동적 할당  // new delete

#include <iostream>
using namespace std;

int main(void)
{
	//동적할당 //heap에 공간 할당하기

	char* pchar = new char;		//1바이트만큼 heap에 공간 할당
	*pchar = 'a';
	cout << "메모리주소 :" << (void*)pchar << "\t값 :" << *pchar << endl;  //void*로 형변환
	cout << "heap 크기: " << sizeof(*pchar) << endl;
	delete pchar;

	int* pnum = new int;				//4바이트만큼 heap에 공간 할당
	*pnum = 3;
	delete pnum;

	double* pdouble{ new double };		//8바이트만큼 heap에 공간 할당
	*pdouble = 3.141592;
	delete pdouble;


	//new 하면서 초기화하기 //new는 초기화가 가능하다. ***

	int* p = new int(10);				// int 10 으로 초기화
	cout << "*p:" << *p << endl;
	delete p;

	float* pfloat = new float(75.25f);
	cout << "*pfloat: " << *pfloat << endl;
	delete pfloat;

	int* pary1 = new int[3] {};			// 배열 new	// 0으로 초기화 
	cout << "pary1[0]: " << pary1[0] << endl;
	delete[] pary1;						// 배열 delete

	int* pary2{ new int[3] {} };
	delete[] pary2;

	char* pary3 = new char[20] { "Hello World!" };		//문자열
	cout << "pary3: " << pary3 << endl;
	delete[] pary3;

	int* pary4{ new int[5] { 1, 2, 3, 4, 5 } };
	delete[] pary4;

	/*
		// 1.1, 2.2, 3.1, 4.1 데이타를 동적할당하여 초기화 후 출력하세요.

		int num = 6;
		auto* pary{ new float[num] { 1.1, 2.2, 3.1, 4.1 } };
		for (int i = 0; i < num; i++)
			cout << "pary[" << i << "]: " << pary[i] << "  ";
		cout << endl;
		delete[] pary;
	*/

	return 0;
}