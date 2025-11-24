#include <iostream>
using namespace std;

int main()
{
	// [ 동적 할당 ]
	{
		// 1byte (heap)
		char* pchar = new char;
		*pchar = 'c';
		cout << "메모리주소 :" << &pchar << "\t값 :" << *pchar << endl;  //void*로 형변환
		cout << "heap 크기: " << sizeof(*pchar) << endl;
		delete pchar;

		// 4byte (heap)
		int* pint = new int;
		*pint = 1;
		delete pint;

		// 8byte (heap)
		double* pdouble = new double;
		*pdouble = 1;
		delete pdouble;

		// 40byte (heap)
		float* pfarray = new float[10];
		delete[] pfarray;
	}

	// [ 동적 할당하면서 초기화 ]
	// new는 초기화가 가능함
	{
		// 10으로 초기화
		int* pint = new int(10);
		delete pint;

		// 3.14로 초기화
		float* pfloat = new float(3.14f);
		delete pfloat;

		// {0,0,0,0,0} 으로 초기화
		float* pfarray1 = new float[5] {};
		delete[] pfarray1;

		// {1,2,3,4,5} 으로 초기화
		float* pfarray2 = new float[5] {1,2,3,4,5};
		delete[] pfarray2;

		// "Hellow World!"로 초기화
		char* pchar = new char[20] {"Hellow World!"};
		delete[] pchar;
	}

	// 1.1, 2.2, 3.1, 4.1 데이타를 동적할당하여 초기화 후 출력해보기
	float* ptr{ new float[4] {1.1, 2.2, 3.1, 4.1} };
	for (int i = 0; i < 4; i++)
	{
		cout << "ptr[i] : " << ptr[i] << endl;
	}
	delete[] ptr;
}