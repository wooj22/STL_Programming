// 2차원 포인터 배열, 2차원 배열의 포인터  비교

#include <iostream>
#include <String.h> 

using namespace std;

#define SizeX 4 // 가로 열
#define SizeY 4 // 세로 행

void Array2DPrint(int (*Array)[SizeX]);		//2차원 배열의 포인터	 // 배열을 전달
void ArrayPtrPrint(int* (Array)[SizeY]);	//2차원 포인터 배열 	 // 포인터를 전달


int main()
{
	// 일반 2차원 배열 ------------------------------------------------------------

	int Arr[SizeY][SizeX] = { 1, 1, 1, 1 }; // 구분을 위해

	//cout << "일반 2차원 배열을 출력합니다." << endl;
	Array2DPrint(Arr);						// 일반 2차원 배열


	// 2차원 배열을 위한 동적 공간 할당 --------------------------------------------	 
	
	// 2차원 배열을 동적 선언하는 포인터 
	// 	int 형식의 배열 (SizeX)4개가 저장되어 있으며, 여기를 다시 배열 (SizeY)4개가 가리키고 있다.

	int** ArrPtr;	

	ArrPtr = new int*[SizeY];				// 4개의 공간을 우선 만든다.  //new 동적할당
	for (int i = 0; i < SizeY; i++)			// 행에는 4개의 공간이 있다.
	{
		ArrPtr[i] = new int[SizeX] {};		// 각각 동적 공간 할당
		//memset(ArrPtr[i], 0, sizeof(int) * SizeX);	// 0 으로 공간을 초기화한다.
	}

	//cout << "2차원 포인터 배열을 출력합니다." << endl;
	ArrayPtrPrint(ArrPtr);					// 2차원 포인터 배열

}

void ArrayPrint(int (*Array)[SizeX])		//int(*)[N]
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << " " << Array[i][j];
		}
		cout << endl;
	}
}

void ArrayPtrPrint(int* (Array)[SizeY])		//int**
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < SizeX; j++)
		{
			cout << " " << Array[i][j];
		}
		cout << endl;
	}
}