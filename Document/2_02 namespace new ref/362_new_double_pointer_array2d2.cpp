// 2차원 포인터 배열, 2차원 배열의 포인터 - 동적할당

#include <iostream>
#include <String.h> 

using namespace std;

#define SizeX 4 // 가로 열
#define SizeY 3 // 세로 행

void ArrayPrint(int(*Array)[SizeX]);		// 2차원 배열이 인자     int(*)[SizeX]
void ArrayPtrPrint(int* (Array)[SizeX]);	// 1차원 포인터가 인자   int**

int main()
{
	// 일반 2차원 배열 -----------------------------------------------------------

	int Arr[SizeY][SizeX] = { 1, 1, 1, 1 }; // 구분을 위해

	cout << "일반 2차원 배열을 출력합니다." << endl;
	ArrayPrint(Arr);						// 일반 2차원 배열


	// 2차원 배열을 위한 동적 공간 할당 --------------------------------------------
	//		2차원 배열을 동적 선언하는 포인터 
	// 		int 4개(SizeX) 형식의 배열이 3개(SizeY) 저장되어 있으며, 
	//		여기를 int* 3개(SizeY) 배열 이 가리키고 있다.

	int** arrPtr;

	arrPtr = new int* [SizeY];				// 3개의 공간을 우선 만든다.  //new 동적할당

	for (int i = 0; i < SizeY; i++)			// 각 행에는 3개의 공간이 있다.
	{
		arrPtr[i] = new int[SizeX];			// 4개의 열로 이루어진 int 배열을 가진 배열
		memset(arrPtr[i], 0, sizeof(int) * SizeX); // 0 으로 공간을 초기화한다.
	}

	cout << "2차원 포인터 배열을 출력합니다." << endl;
	ArrayPtrPrint(arrPtr);					// 2차원 포인터 배열

	for (int i = 0; i < SizeY; i++) delete[] arrPtr[i];
	delete[] arrPtr;

	cout << endl;

}

void ArrayPrint(int(*Array)[SizeX])		//int(*)[SizeX]
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << " " << Array[i][j];
		}
		cout << endl;
	}
}

void ArrayPtrPrint(int* (Array)[SizeX])		//int**
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << " " << Array[i][j];
		}
		cout << endl;
	}
}


/*
//함수 이중포인터의 동적 배열 할당

	typedef void (*FPTR)();

	void (**p)() = new FPTR[4];				//함수포인터를 동적할당

	void (*(*p)[3])() = new FPTR[4][3];		//함수포인터 배열 동적할당

*/